#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>

typedef struct CString
{
    size_t len;
    char* str;
} CString;

CString* cstring_new(const char* str)
{
    CString* string = NULL;

    if (str == NULL)
    {
        goto error;
    }

    if (NULL == (string = malloc(sizeof(size_t) + sizeof(char*))))
    {
        goto error;
    }

    string->len = strlen(str);
    if (NULL == (string->str = malloc(string->len * sizeof(char))))
    {
        goto error;
    }
    string->str = memcpy(string->str, str, string->len);

    return string;

    error:
        free(string);
        return NULL;
}

char getChar(const CString* str, unsigned n)
{
    if (str != NULL && n <= str->len)
        return str->str[n-1];
    return 0;
}

int setChar(CString* str, unsigned n, char ch)
{
    if (str != NULL && n <= str->len)
    {
        str->str[n-1] = ch;
        return ch;
    }
    return 0;
}

const char* getString(const CString* str)
{
    if (str != NULL)
        return str->str;
    return 0;
}

const int getLength(const CString* str)
{
    if (str != NULL)
        return str->len;
    return 0;
}

void test(CString* string)
{
    assert(string);
    if (string->len >= 2)
        assert(getChar(string, 2) == *(string->str+(2-1)*sizeof(char)));
    if (setChar(string, 2, 'r'))
        assert(*(string->str+(2-1)*sizeof(char))=='r');
    assert(getLength(string) == string->len);
}

int main()
{
    CString* str = cstring_new("test");

    test(str);
    free(str->str);
    free(str);

    str = cstring_new("");
    test(str);
    free(str->str);
    free(str);
    
    return 0;
}
