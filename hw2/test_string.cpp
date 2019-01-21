#include <iostream>
#include "mystring.h"
using namespace std;

#define require(e) \
    if (!(e))      \
    fprintf(stderr, "FAILED line %d        %s: %s       %s\n", __LINE__, __FILE__, __func__, #e)

void test_strlen()
{
    cout << "1. Testing strlen..." << endl;
    require(strlen("") == 0);
    require(strlen("hello") == 5);
    require(strlen("hello\0") == 5);
}

void test_strcmp()
{
    cout << "2. Testing strcmp..." << endl;
    char r[] = "hello", s[] = "hello", t[] = "he";
    require(strcmp(r, s) == 0);
    require(strcmp(t, r) < 0);
    require(strcmp(s, t) > 0);
}

void test_strncmp()
{
    cout << "3. Testing strncmp..." << endl;
    char r[] = "hello", s[] = "hello", t[] = "he";
    require(strncmp(r, s, 5) == 0);
    require(strncmp(r, s, 2) == 0);
    require(strncmp(r, s, 7) == 0);
    require(strncmp(t, r, 2) == 0);
    require(strncmp(t, r, 1) == 0);
    require(strncmp(t, r, 3) < 0);
    require(strncmp(s, t, 2) == 0);
    require(strncmp(s, t, 3) > 0);
}

void test_strcpy()
{
    cout << "4. Testing strcpy..." << endl;
    char dest1[] = "abc", src1[] = "def";
    strcpy(dest1, src1);
    require(strcmp(src1, dest1) == 0);

    char dest2[] = "abcdef", src2[] = "d";
    strcpy(dest2, src2);
    require(strcmp(src2, dest2) == 0);

    char dest3[4], src3[] = "bcd";
    strcpy(dest3, src3);
    require(strcmp(src3, dest3) == 0);
}

void test_strcat()
{
    cout << "5. Testing strcat..." << endl;
    char src1[50] = "Source", dest1[50] = "Destination-";
    strcat(dest1, src1);
    require(strcmp(dest1, "Destination-Source") == 0);

    char src2[50] = "", dest2[50] = "Some very long sentence......";
    strcat(dest2, src2);
    require(strcmp(dest2, "Some very long sentence......") == 0);

    char src3[50] = "Some very long sentence......", dest3[50] = "";
    strcat(dest3, src3);
    require(strcmp(dest3, "Some very long sentence......") == 0);
}

void test_strchr()
{
    cout << "6. Testing strchr..." << endl;
    char str1[] = "Test string";

    require(strcmp(strchr(str1, 'e'), "est string") == 0);
    require(strcmp(strchr(str1, ' '), " string") == 0);
    require(strchr(str1, 'B') == NULL);
}

void test_strpbrk()
{
    cout << "7. Testing strpbrk..." << endl;
    char str1[] = "Test string";

    require(strcmp(strpbrk(str1, "Best"), "est string") == 0);
    require(strcmp(strpbrk(str1, "Foo "), " string") == 0);
    require(strpbrk(str1, "F") == NULL);
}

void test_strstr()
{
    cout << "8. Testing strstr..." << endl;
    char haystack[] = "Beat";

    require(strstr(haystack, "eat") == haystack + 1);
    require(strstr(haystack, "t") == haystack + 3);
    require(strstr(haystack, "Foo") == NULL);
}

void test_strspn()
{
    cout << "9. Testing strspn..." << endl;
    require(strspn("ABCDEFG019874", "ABCD") == 4);
    require(strspn("1234 6789BC", "123456789 ") == 9);
    require(strspn("ABCDEFG019874", "123456789 ") == 0);
}

void test_strtok()
{
    cout << "10. Testing strtok..." << endl;
    char str[] = "Testing--this--tokenizer!";
    require(strcmp(strtok(str, "--"), "Testing") == 0);
    require(strcmp(strtok(nullptr, "--"), "this") == 0);
    require(strcmp(strtok(nullptr, "--"), "tokenizer!") == 0);
    require(strtok(nullptr, "--") == NULL);

    char str2[] = "Some other example  ";
    require(strcmp(strtok(str2, " "), "Some") == 0);
    require(strcmp(strtok(nullptr, " "), "other") == 0);
    require(strcmp(strtok(nullptr, " "), "example") == 0);
    require(strcmp(strtok(nullptr, " "), "") == 0);
    require(strtok(nullptr, " ") == NULL);
}

int main()
{
    test_strlen();
    test_strcmp();
    test_strncmp();
    test_strcpy();
    test_strcat();
    test_strchr();
    test_strpbrk();
    test_strstr();
    test_strspn();
    test_strtok();

    return 0;
}
