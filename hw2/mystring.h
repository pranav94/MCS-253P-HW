size_t strlen(const char *str)
{
    size_t i;
    for (i = 0; str[i] != '\0'; i++)
        ;
    return i;
}

char *strcpy(char *dest, const char *src)
{
    int i = 0;
    for (; src[i] != '\0'; i++)
        dest[i] = src[i];
    dest[i] = '\0';
    return dest;
}

int strcmp(const char *str1, const char *str2)
{
    int i = 0;
    for (; str1[i] != '\0' && str2[i] != '\0'; i++)
        if (str1[i] != str2[i])
            return str1[i] - str2[i];
    return str1[i] - str2[i];
}

int strncmp(const char *str1, const char *str2, size_t n)
{
    int i = 0;
    for (; str1[i] != '\0' && str2[i] != '\0' && i < (int)(n - 1); i++)
        if (str1[i] != str2[i])
            return str1[i] - str2[i];
    return str1[i] - str2[i];
}

char *strcat(char *dest, const char *src)
{
    int i = 0;
    for (; dest[i] != '\0'; i++);
    for (; *src != '\0'; i++, src++)
        dest[i] = *src;
    dest[i] = '\0';
    return dest;
}

char *strchr(const char *str, int c)
{
    for (; *str != '\0' && *str != c; str++);
    return *str == c ? (char *)str : nullptr;
}

char *strpbrk(const char *str1, const char *str2)
{
    for (; *str1 != '\0'; str1++)
        for (const char *t = str2; *t != '\0'; t++)
            if (*str1 == *t)
                return (char *)str1;
    return nullptr;
}

char *strstr(const char *haystack, const char *needle)
{
    for (; *haystack != '\0'; haystack++)
        for (const char *s = haystack, *t = needle; *s == *t; s++, t++)
            if (*t == '\0')
                return (char *)haystack;
    return nullptr;
}

size_t strspn(const char *str1, const char *str2)
{
    size_t i = 0;
    for (; str1[i] != '\0' && strchr(str2, str1[i]) != nullptr; i++);
    return i;
}

int isdelimiter(char *str, const char *delim)
{
    for (; *str == *delim && *delim != '\0'; str++, delim++)
        if (*str == '\0')
            return 0;
    return *delim == '\0' ? 1 : 0;
}

char *strtok(char *str, const char *delim)
{
    static char token[100], *it = str;
    int k = 0, n = strlen(delim);

    if (str)
        it = str;

    if (*it == '\0')
        return nullptr;

    for (; *it != '\0'; it++)
        if (isdelimiter(it, delim))
        {
            it += n;
            token[k] = '\0';
            return token;
        }
        else
            token[k++] = *it;

    token[k] = '\0';
    return token;
}