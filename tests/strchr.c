/*
** EPITECH PROJECT, 2024
** B-ASM-400-LYN-4-1-asmminilibc-mathieu.borel
** File description:
** strlen.c
*/

#include <criterion/criterion.h>
#include <dlfcn.h>

#define PROTO   char* (*my_strchr)(char *, char)

static void basic(PROTO)
{
    char test[] = "hello";
    cr_assert_eq(my_strchr(test, 'l'), strchr(test, 'l'));
    cr_assert_eq(my_strchr(test, 'h'), strchr(test, 'h'));
    cr_assert_eq(my_strchr(test, 'o'), strchr(test, 'o'));
    cr_assert_eq(my_strchr(test, '\0'), strchr(test, '\0'));
}

static void empty(PROTO)
{
    char test[] = "hello";
    char test2 = 'a';
    cr_assert_null(my_strchr(test, test2));
}

static void null(PROTO)
{
    char *test = NULL;
    char test2 = 'a';
    cr_assert_null(my_strchr(test, test2));
}

Test(strchr, basic)
{
    void *handle = dlopen("./libasm.so", RTLD_LAZY);
    if (!handle) {
        return;
    }
    PROTO = dlsym(handle, "strchr");
    basic(my_strchr);
    empty(my_strchr);
    null(my_strchr);
    dlclose(handle);
}

