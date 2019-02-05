#include <stdio.h>
#include <string.h>
#include <stdlib.h>

extern int get42(void);
extern size_t my_strlen(char const *str);
extern void my_putstr(char const *buff);
extern int my_strcmp(char const *s1, char const *s2);
extern char *my_strcpy(char *dest, char const *src);
extern char *my_strcat(char *dest, char const *src);
extern void caller(void (*f)(int), int arg);
extern int *my_map(int *arr, size_t size, void (*f)(int));

static void test_get42(void)
{
    puts("==========");
    puts("test get42 :");

    int n = get42();
    printf("excepted %d - got %d\n", 42, n);
}

static void test_strlen(void)
{
    puts("==========");
    puts("test strlen :");

    char str[] = "hello world !";
    size_t s1 = strlen(str);
    size_t s2 = my_strlen(str);

    printf("excepted %ld - got %ld\n", s1, s2);
}

static void test_putstr(void)
{
    puts("==========");
    puts("test putstr :");

    printf("excepted \"hello world !\" - got \"");
    fflush(stdout);
    my_putstr("hello world !");
    printf("\"\n");
}

static void test_strcmp(void)
{
    puts("==========");
    puts("test strcmp :");

    {
        char s1[] = "hello";
        char s2[] = "helIo";

        printf("excepted %d - got %d\n", strcmp(s1, s2), my_strcmp(s1, s2));
    }
    {
        char s1[] = "";
        char s2[] = "";

        printf("excepted %d - got %d\n", strcmp(s1, s2), my_strcmp(s1, s2));
    }
}
/*
static void test_strcpy(void)
{
    puts("==========");
    puts("test strcpy :");

    {
        char s1[] = "hello";
        char s2[] = "hello";
        char s3[] = "helIo";

        strcpy(s1, s3);
        my_strcpy(s2, s3);

        printf("excepted \"%s\" - got \"%s\"\n", s1, s2);
    }
    {
        char s1[] = "hello";
        char s2[] = "hello";
        char s3[] = "bla";

        strcpy(s1, s3);
        my_strcpy(s2, s3);

        printf("excepted \"%s\" - got \"%s\"\n", s1, s2);
    }
}

static void test_strcat(void)
{
    puts("==========");
    puts("test strcat :");

    char s1[] = "hello darkness !";
    char s2[] = "hello darkness !";
    char s3[] = "world !";

    s1[6] = '\0';
    s2[6] = '\0';
    strcat(s1, s3);
    my_strcat(s2, s3);

    printf("excepted \"%s\" - got \"%s\"\n", s1, s2);
}

static void print_int(int i)
{
    printf("%d\n", i);
}

static void test_caller(void)
{
    puts("==========");
    puts("test caller :");

    printf("excepted %d - got ", 42);
    caller(&print_int, 42);
}

static void test_map(void)
{
    puts("==========");
    puts("test map :");

    int arr[] = {0, 3, 6, 9, 12, 15, 18};
    my_map(arr, 7, &print_int);
}*/


int main()
{
    test_get42();
    test_strlen();
    test_putstr();
    test_strcmp();/*
    test_strcpy();
    test_strcat();
    test_caller();
    test_map();*/
}