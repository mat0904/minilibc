/*
** EPITECH PROJECT, 2024
** B-ASM-400-LYN-4-1-asmminilibc-mathieu.borel
** File description:
** strlen.c
*/

#include <criterion/criterion.h>
#include <dlfcn.h>
#include <stdio.h>

#define PROTO   int (*my_strcmp)(char *, char *)

static void basic(PROTO)
{
    int res = my_strcmp("ab", "ae");
    int res2 = my_strcmp("hello", "hellow");
    int res3 = my_strcmp("hellow", "hello");
    cr_assert_leq(res, 0);
    cr_assert_eq(res2, -119);
    cr_assert_eq(res3, 119);
}

static void basic_2(PROTO)
{
    char test[] = "hello";
    char test2[] = "hello";
    cr_assert_eq(my_strcmp(test, test2), 0);
}

static void null(PROTO)
{
    char *test = NULL;
    char test2[] = "hello";
    cr_assert_eq(my_strcmp(test, test2), 0);
}

Test(strcmp, basic)
{
    void *handle = dlopen("./libasm.so", RTLD_LAZY);
    if (!handle) {
        return;
    }
    PROTO = dlsym(handle, "strcmp");
    basic(my_strcmp);
    basic_2(my_strcmp);
    null(my_strcmp);
    dlclose(handle);
}

