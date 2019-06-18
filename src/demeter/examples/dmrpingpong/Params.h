#pragma once
#include <stdio.h>
#include <stdlib.h>

class Params
{
public:
    Params(int argc, char **argv);
    ~Params();
    static void ShowUsage();

    struct Exception {};

    bool Server;
    bool Client;
    bool Blocking;
    bool Polling;
    bool Write;
    bool Read;
    size_t nSge;
    size_t nPipeline;
    size_t MaxXfer;
    size_t HdrLen;
    size_t MaxVolume;
    size_t MaxIterations;
    size_t Version;
    char Logfile[_MAX_PATH + 1];
    char Ip[_MAX_PATH + 1];
    unsigned short Port;

    void Print(FILE* file = stdout);
    void Save(const char *file_path);
    int WriteToBuffer(char* buffer, size_t buffer_size) const;
};
