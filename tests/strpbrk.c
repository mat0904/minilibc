/*
** EPITECH PROJECT, 2024
** B-ASM-400-LYN-4-1-asmminilibc-mathieu.borel
** File description:
** strlen.c
*/

#include <criterion/criterion.h>
#include <dlfcn.h>
#include <stdio.h>

#define PROTO   char * (*my_strpbrk)(char *, char *)

static void basic(PROTO)
{
    cr_assert_str_eq(my_strpbrk("hello", "h"), "hello");
    cr_assert_str_eq(my_strpbrk("hello", "llo"), "llo");
}

static void empty(PROTO)
{
    cr_assert_null(my_strpbrk("", "llo"));
    cr_assert_null(my_strpbrk("", NULL));
}

static void null(PROTO)
{
    char *test = NULL;
    cr_assert_null(my_strpbrk(test, NULL));
}

Test(strpbrk, basic)
{
    void *handle = dlopen("./libasm.so", RTLD_LAZY);
    if (!handle) {
        return;
    }
    char *(*my_strpbrk)(char*, char *) = dlsym(handle, "strpbrk");
    basic(my_strpbrk);
    empty(my_strpbrk);
    null(my_strpbrk);
    dlclose(handle);
}

