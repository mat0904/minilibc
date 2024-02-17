/*
** EPITECH PROJECT, 2024
** B-ASM-400-LYN-4-1-asmminilibc-mathieu.borel
** File description:
** strlen.c
*/

#include <criterion/criterion.h>
#include <dlfcn.h>
#include <stdio.h>

#define PROTO   char* (*my_strstr)(char *, char *)

static void basic(PROTO)
{
    char haystack[] = "hello world";
    char needle[] = "wo";
    char needle2[] = "hello world";
    char needle3[] = "d";
    char needle4[] = "qsd";
    cr_assert_str_eq(my_strstr(haystack, needle), strstr(haystack, needle));
    cr_assert_str_eq(my_strstr(haystack, needle2), strstr(haystack, needle2));
    cr_assert_str_eq(my_strstr(haystack, needle3), strstr(haystack, needle3));
    cr_assert_null(my_strstr(haystack, needle4));
}

static void null(PROTO)
{
    char *test = NULL;
    char test2[] = "hello";
    cr_assert_eq(my_strstr(test, test2), 0);
}

Test(strstr, basic)
{
    void *handle = dlopen("./libasm.so", RTLD_LAZY);
    if (!handle) {
        return;
    }
    PROTO = dlsym(handle, "strstr");
    basic(my_strstr);
    null(my_strstr);
    dlclose(handle);
}

