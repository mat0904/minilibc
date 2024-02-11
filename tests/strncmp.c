/*
** EPITECH PROJECT, 2024
** B-ASM-400-LYN-4-1-asmminilibc-mathieu.borel
** File description:
** strlen.c
*/

#include <criterion/criterion.h>
#include <dlfcn.h>
#include <stdio.h>

#define PROTO   int (*my_strncmp)(char *, char *, int)

static void basic(PROTO)
{
    cr_assert_leq(my_strncmp("ab", "ae", 2), -3);
    cr_assert_eq(my_strncmp("hello", "hellow", 5), 0);
    cr_assert_eq(my_strncmp("hellow", "hello", 6), 119);
    cr_assert_eq(my_strncmp("hello", "hellow", 6), -119);
    cr_assert_eq(my_strncmp("hellow", "hello", 10), 119);
}

static void basic_2(PROTO)
{
    char test[] = "hello";
    char test2[] = "hello";
    cr_assert_eq(my_strncmp(test, test2, 5), 0);
}

static void null(PROTO)
{
    char *test = NULL;
    char test2[] = "hello";
    cr_assert_eq(my_strncmp(test, test2, 500), 0);
}

Test(strncmp, basic)
{
    void *handle = dlopen("./libasm.so", RTLD_LAZY);
    if (!handle) {
        return;
    }
    PROTO = dlsym(handle, "strncmp");
    basic(my_strncmp);
    basic_2(my_strncmp);
    null(my_strncmp);
    dlclose(handle);
}

