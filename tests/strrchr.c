/*
** EPITECH PROJECT, 2024
** B-ASM-400-LYN-4-1-asmminilibc-mathieu.borel
** File description:
** strlen.c
*/

#include <criterion/criterion.h>
#include <dlfcn.h>
#include <stdio.h>

#define PROTO   char* (*my_strrchr)(char *, char)

static void basic(PROTO)
{
    char test[] = "hello";
    cr_assert_str_eq(my_strrchr(test, 'l'), strrchr(test, 'l'));
    cr_assert_str_eq(my_strrchr(test, 'h'), strrchr(test, 'h'));
    cr_assert_str_eq(my_strrchr(test, 'o'), strrchr(test, 'o'));
    cr_assert_str_eq(my_strrchr(test, '\0'), strrchr(test, '\0'));
}

static void empty(PROTO)
{
    char test[] = "hello";
    char test2 = 'a';
    cr_assert_null(my_strrchr(test, test2));
}

static void null(PROTO)
{
    char *test = NULL;
    char test2 = 'a';
    cr_assert_null(my_strrchr(test, test2));
}

Test(strrchr, basic)
{
    void *handle = dlopen("./libasm.so", RTLD_LAZY);
    if (!handle) {
        return;
    }
    PROTO = dlsym(handle, "strrchr");
    basic(my_strrchr);
    empty(my_strrchr);
    null(my_strrchr);
    dlclose(handle);
}

