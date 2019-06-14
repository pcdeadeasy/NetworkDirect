#pragma once

typedef struct _KVP {
    const char *key;
    const char *val;
} KVP;

typedef struct _KEYERROR {
} KEYERROR;

class CSV_DICT
{
public:
    CSV_DICT(HEAP& heap, const char *csv_path, size_t increment = 16);
    ~CSV_DICT();
    const char* lookup(const char *key);
private:
    CSV_DICT() = delete;
    HEAP& m_heap;
    size_t m_count;  // number of KVP's in the buffer
    BUFFER<char> m_csvs;
    BUFFER<KVP> m_kvps;
};
