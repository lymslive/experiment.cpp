#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

// like vprintf, last arg is va_list
int Format(const char* format, va_list vlist)
{
    printf("in Format:");
    vprintf(format, vlist);
    printf("\n");
}

// like printf, last arg is ...
int Print(const char* file, int line, const char* func, const char* format, ...)
{
    printf("[%s:%d %s()]", file, line, func);
    va_list vlist;
    va_start(vlist, format);
    Format(format, vlist);
    va_end(vlist);
}

#define LOG(...) Print(__FILE__, __LINE__, __FUNCTION__, __VA_ARGS__)

int main(int argc, char* argv[])
{
    LOG("this is a log for int %d, float %f, string %s", 123, 456.789, "abcdefg");
    return 0;
}
