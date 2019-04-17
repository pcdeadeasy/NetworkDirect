#include "pch.h"
#include "Args.h"
#include <Winshim.h>
#include "json.h"
#include <Logger.h>


class FILE_IMAGE
{
public:
    FILE_IMAGE(HEAP *pHeap, const char *file_path);
    ~FILE_IMAGE();

    void* get_address()
    {
        return m_src;
    }

    size_t get_size()
    {
        return m_size;
    }

    operator void*()
    {
        return m_src;
    }

private:
    void *m_src;
    size_t m_size;
    HEAP *m_pHeap;
    FILE_IMAGE() = delete;
};

FILE_IMAGE::FILE_IMAGE(HEAP *pHeap, const char *file_path) : m_pHeap(pHeap), m_src(0), m_size(0)
{
    HANDLE const hFile = Win::CreateFileA(file_path, GENERIC_READ, 0, 0, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);
    try
    {
        m_size = Win::GetFileSize(hFile);
        m_src = m_pHeap->Alloc(0, m_size);
        DWORD NumberOfBytesRead = 0;
        Win::ReadFile(hFile, m_src, (DWORD)m_size, &NumberOfBytesRead, 0);
    }
    catch (...)
    {
        Win::CloseHandle(hFile);
        throw;
    }
    Win::CloseHandle(hFile);
}

FILE_IMAGE::~FILE_IMAGE()
{
    if (m_src)
    {
        m_pHeap->Free(0, m_src);
    }
}

ARGS::ARGS(HEAP *pHeap, const char* file_path) : m_pHeap(pHeap), m_root(0), m_role(role_none), m_count(0)
{
    LOG_ENTER();
    Init(file_path);
    LOG_VOID_RETURN();
}

static void* allocate(void* context, size_t size)
{
    LOG_ENTER();
    HEAP *pHeap = (HEAP*)context;
    void *ans = pHeap->Alloc(0, size);
    LOG_PVOID_RETURN(ans);
    return ans;
}

static const char* get_json_type(size_t x)
{
    switch (x)
    {
    case json_type_string:
        return "json_type_string";
    case json_type_number:
        return "json_type_number";
    case json_type_object:
        return "json_type_object";
    case json_type_array:
        return "json_type_array";
    case json_type_true:
        return "json_type_true";
    case json_type_false:
        return "json_type_false";
    case json_type_null:
        return "jsaon_type_null";
    default:
        throw "bad json type";
    }

}

void ARGS::Init(const char *file_path)
{
    LOG_ENTER();
    FILE_IMAGE src(m_pHeap, file_path);
    struct json_parse_result_s result = { 0 };
    struct json_value_s *root = json_parse_ex(src.get_address(), src.get_size(), 0, allocate, m_pHeap, &result);
    if (root)
    {
        try
        {
            InitHelper(root);
        }
        catch (...)
        {
            m_pHeap->Free(0, root);
            root = 0;
            throw;
        }
        m_pHeap->Free(0, root);
        root = 0;
    }
    LOG_VOID_RETURN();
}

void ARGS::InitHelper(struct json_value_s *root)
{
    LOG_ENTER();
    if (root->type != json_type_object)
        throw "root->type != json_type_object";
    if (root->payload == 0)
        throw "root->payload == 0";
    struct json_object_s *object = (struct json_object_s*)root->payload;
    for (json_object_element_s *element = object->start; element != 0; element = element->next)
    {
        if (element->name->string_size > 0 && element->name->string != 0)
        {
            if (strcmp(element->name->string, "role") == 0)
            {
                json_value_s *value = element->value;
                if (value != 0 && value->type == json_type_string)
                {
                    json_string_s* role = (json_string_s*)value->payload;
                    if (role->string != 0 && role->string_size > 0)
                    {
                        if (strcmp(role->string, "client") == 0)
                        {
                            m_role = role_client;
                        }
                        else if (strcmp(role->string, "server") == 0)
                        {
                            m_role = role_server;
                        }
                    }
                }
            }
            else if (strcmp(element->name->string, "count") == 0)
            {
                json_value_s *value = element->value;
                if (value != 0 && value->type == json_type_number && value->payload != 0)
                {
                    json_number_s* count = (json_number_s*)value->payload;
                    if (count->number != 0 && 0 < count->number_size && count->number_size < 10)
                    {
                        m_count = atoi(count->number);
                    }
                }
            }
        }
    }
    
    LOG_VOID_RETURN();
}

ARGS::~ARGS()
{
    LOG_ENTER();
    if (m_root) 
    {
        m_pHeap->Free(0, m_root);
        m_root = 0;
    }
    LOG_VOID_RETURN();
}
