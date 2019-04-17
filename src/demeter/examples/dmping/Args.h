#pragma once
#include <WinHeap.h>
#include "json.h"

enum role_e {
    role_none = 0,
    role_client = 1,
    role_server = 2
};

class ARGS
{
public:
    ARGS(HEAP *pHeap, const char* file_path);
    ~ARGS();

    role_e get_role() const
    {
        return m_role;
    }
    int get_count() const
    {
        return m_count;
    }
private:
    json_value_s *m_root;
    HEAP * const m_pHeap;
    role_e m_role;
    int m_count;
    ARGS() = delete;
    void Init(const char* file_path);
    void InitHelper(struct json_value_s *root);
};

