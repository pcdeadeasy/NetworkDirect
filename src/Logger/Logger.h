#pragma once
#include <stdio.h>

class LoggerWorker
{
  static char Buffer[];
public:
  static bool IsFirst;
  static FILE* Stream;
  static void log(const char *function, const char *file, unsigned int line, const char *fmt, ...);
};

class Logger
{
  bool m_isFile;
  Logger() = delete;
public:
  Logger(const char *file_path = 0) : m_isFile(false)
  {
    if (file_path)
    {
      if (fopen_s(&LoggerWorker::Stream, file_path, "w") == 0)
      {
        m_isFile = true;
      }
      else
      {
        LoggerWorker::Stream = stdout;
      }
    }
    else
    {
      LoggerWorker::Stream = stdout;
    }
    fprintf(LoggerWorker::Stream, "[\n");
  }

  ~Logger()
  {
    fprintf(LoggerWorker::Stream, "]\n");
    if (m_isFile)
    {
      fclose(LoggerWorker::Stream);
      LoggerWorker::Stream = 0;
    }
  }
};

#define LOG(...)                                                            \
    do {                                                                      \
      if (LoggerWorker::Stream != 0)                                          \
      {                                                                       \
        LoggerWorker::log(__FUNCTION__, __FILE__, __LINE__, __VA_ARGS__);     \
      }                                                                       \
    } while(false)

#define LOG_ENTER() LOG("Entering %s", __FUNCTION__)
#define LOG_RETURN(_fmt, _value) LOG("Exiting %s -> " _fmt, __FUNCTION__, _value)
#define LOG_VOID_RETURN() LOG_RETURN("%s", "void")
#define LOG_HRESULT_RETURN(_hr) LOG_RETURN("%08X", _hr)
#define LOG_ULONG_RETURN(_ul) LOG_RETURN("%08X", _ul)
#define LOG_INT_RETURN(_i) LOG_RETURN("%d", _i)
#define LOG_SIZET_RETURN(_zu) LOG_RETURN("%zu", _zu)
#define LOG_ERROR_RETURN() LOG_RETURN("%s", "Error")
#define LOG_ERROR_UNEQUAL(_a, _b) if (_a != _b) LOG_ERROR_RETURN()
#define LOG_BOOLEAN_RETURN(_b) LOG_RETURN("%s", _b ? "true" : "false")
#define LOG_PVOID_RETURN(_pv) LOG_RETURN("%p", _pv)
