/*
** EPITECH PROJECT, 2024
** B-ASM-400-LYN-4-1-asmminilibc-mathieu.borel
** File description:
** strlen.c
*/

#include <criterion/criterion.h>
#include <dlfcn.h>
#include <stdio.h>

#define PROTO   int (*my_strcasecmp)(char *, char *)

static void basic(PROTO)
{
    cr_assert_leq(my_strcasecmp("ab", "ae"), -3);
    cr_assert_eq(my_strcasecmp("hello", "hellow"), -119);
    cr_assert_eq(my_strcasecmp("hellow", "hello"), 119);
    cr_assert_eq(my_strcasecmp("hello", "HELLO"), 0);
    cr_assert_eq(my_strcasecmp("hello", "HELLA"), 14);
}

static void basic_2(PROTO)
{
    char test[] = "hello";
    char test2[] = "hello";
    cr_assert_eq(my_strcasecmp(test, test2), 0);
}

static void null(PROTO)
{
    char *test = NULL;
    char test2[] = "hello";
    cr_assert_eq(my_strcasecmp(test, test2), 0);
}

Test(strcasecmp, basic)
{
    void *handle = dlopen("./libasm.so", RTLD_LAZY);
    if (!handle) {
        return;
    }
    PROTO = dlsym(handle, "strcasecmp");
    basic(my_strcasecmp);
    basic_2(my_strcasecmp);
    null(my_strcasecmp);
    dlclose(handle);
}

