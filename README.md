# CString
---
Char wrapper for C.
## Building
---
Only requires `gcc`.
```
git clone https://github.com/tozaist/CString.git && cd ./CString
```
```
make
```
## Usage examples
---
Create new string:

```
CString* myNewString = cstring_new("Hello world");
```

Get individual character:

```
char ch = getChar(myNewString, 2);
printf("%c", ch);
```
`> e`

Set individual character:

```
setChar(myNewString, 2, 'r');
char ch = getChar(myNewString, 2);
printf("%c", ch);
```
`> r`


Get string:

```
char *str = getString(myNewString);
printf("%s", str);
```
`> Hrllo world!`

Get length:
```
int len = getLength(myNewString);
printf("%d", len);
```
`> 11`
