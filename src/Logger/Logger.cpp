#include "stdafx.h"
#include <stdarg.h>
#include <stdio.h>
#include "Logger.h"

void emit(int, FILE*);
void emit_string(FILE*, const char*);
void define_string(FILE *, const char *, const char *);
void define_number(FILE *, const char *, int);

bool LoggerWorker::IsFirst = true;
FILE* LoggerWorker::Stream = 0;
char LoggerWorker::Buffer[1024];

void LoggerWorker::log(const char *function, const char *file, unsigned int line, const char *fmt, ...)
{
  static char buffer[1024];
  va_list args;
  va_start(args, fmt);
  {
    if (!IsFirst)
      fprintf(Stream, "  ,\n");
    fprintf(Stream, "  {\n");

    fprintf(Stream, "    \"comment\" : ");
    vsprintf_s(buffer, sizeof(buffer), fmt, args);
    emit_string(Stream, buffer);
    fprintf(Stream, ",\n");

    define_string(Stream, "function", function);
    fprintf(Stream, ",\n");

    define_string(Stream, "file", file);
    fprintf(Stream, ",\n");

    define_number(Stream, "line", line);

    fprintf(Stream, "\n");
    fprintf(Stream, "  }\n");
    fflush(Stream);
  }
  va_end(args);
  IsFirst = false;
}


void emit_string(FILE *stream, const char *psz)
{
  fputc('\"', stream);
  while (*psz)
  {
    emit(*psz++, stream);
  }
  fputc('\"', stream);
}

void define_string(FILE *stream, const char *symbol, const char *value)
{
  fprintf(stream, "    \"%s\" : ", symbol);
  emit_string(stream, value);
}

void define_number(FILE *stream, const char *symbol, int value)
{
  fprintf(stream, "    \"%s\" : %d", symbol, value);
}

void emit(int ch, FILE *stream)
{
  switch (ch)
  {
  case '\n':
    fputc('\\', stream);
    fputc('n', stream);
    break;
  case '\\':
    fputc('\\', stream);
    fputc('\\', stream);
    break;
  case '\"':
    fputc('\\', stream);
    fputc('\"', stream);
    break;
  default:
    fputc(ch, stream);
    break;
  }
}
