#include <stdlib.h>
#include <stdio.h>

typedef struct CString
{
    char* str;
    unsigned len;
} CString;

CString* cstring_new(const char* str)
{
    int i = 0;
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

char getChar(CString* str, int n)
{
    return *(str->str + n*sizeof(char));
}

void setChar(CString* str, int n, char ch)
{
    *(str->str + n*sizeof(char)) = ch;
}

const char* getString(CString* str)
{
    return *(str->str)
}

int main()
{
    char* tmp = "test";
    CString* string = cstring_new(tmp);
    return string->len;
}
