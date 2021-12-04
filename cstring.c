#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

typedef struct CString
{
    char* str;
    unsigned len;
} CString;

CString* cstring_new(const char* str)
{
    if (str != NULL)
    {
        int i = -1;
        do 
            i++;
        while (*(str + sizeof(char) * i) != '\0');
        CString* string = malloc(sizeof(char*) + sizeof(unsigned));
        string->len = i;
        string->str = (char*)malloc(sizeof(char) * (string->len + 1));
        i = 0;
        do
        {
            *(string->str + sizeof(char) * i) = *(str + sizeof(char) * i);
            i++;
        }
        while (i < string->len);
        return string;
    }
    return 0;
}

char getChar(const CString* str, int n)
{
    if (str != NULL && n >= 0 && n <= str->len)
        return *(str->str + (n-1)*sizeof(char));
    return 0;
}

int setChar(CString* str, int n, char ch)
{
    if (str != NULL && n >= 0 && n <= str->len)
    {
        *(str->str + (n-1)*sizeof(char)) = ch;
        return ch;
    }
    return 0;
}

char* getString(const CString* str)
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
    str = cstring_new("");
    test(str);
    return 0;
}
