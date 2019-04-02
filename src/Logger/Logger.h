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
#ifdef _LOGGING
    fprintf(LoggerWorker::Stream, "[\n");
#endif
  }

  ~Logger()
  {
#ifdef _LOGGING
    fprintf(LoggerWorker::Stream, "]\n");
#endif
    if (m_isFile)
    {
      int rc = fclose(LoggerWorker::Stream);
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
