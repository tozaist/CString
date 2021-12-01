#include <stdlib.h>

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
        *string->str = 'o';
        *(string->str + sizeof(char) * i) = *(str + sizeof(char) * i);
        i++;
    }
    while (i < string->len);
    return string;
}

int main()
{
    char* tmp = "test";
    CString* string = cstring_new(tmp);
    return string->len;
}
