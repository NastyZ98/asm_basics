#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

int get42(void)
{
    return (42);
}

void my_putstr(char const *buff)
{
    int i = -1;

    while (buff[++i])
        write(1, &buff[i], 1);
}

size_t my_strlen(char const *str)
{
    size_t i = -1;

    while (str[++i]);
    return (i);
}

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;
	int result = 0;

	while (i < my_strlen(s1)) {
		if (s1[i] != s2[i])
			break;
		i++;
	}
	result = s1[i] - s2[i];
	return (result);
}

void caller(void (*f)(int), int arg)
{
    f(arg);
}

void my_map(int *arr, size_t size, void (*f)(int))
{
    for (int i = 0; i < size; i++) {
        f(arr[i]);
    }
}

char *my_strcpy(char *dest, char *src)
{
	int i = -1;

	while (dest[++i])
		dest[i] = src[i];
	return (dest);
}

char *my_strcat(char *dest, char const *src)
{
    size_t dest_len = strlen(dest);
    size_t i;

    for (i = 0 ; i < my_strlen(dest); i++)
        dest[dest_len + i] = src[i];
    dest[dest_len + i] = '\0';

    return dest;
}