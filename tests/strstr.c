/*
** EPITECH PROJECT, 2024
** B-ASM-400-LYN-4-1-asmminilibc-mathieu.borel
** File description:
** strlen.c
*/

#include <criterion/criterion.h>
#include <dlfcn.h>
#include <stdio.h>

#define PROTO   int (*my_strstr)(char *, char *)

static void basic(PROTO)
{
    char haystack[] = "hello world";
    char needle[] = "wo";
    printf("%s\n", strstr(haystack, needle));
}

static void basic_2(PROTO)
{
    char test[] = "hello";
    char test2[] = "hello";
    cr_assert_eq(my_strstr(test, test2), 0);
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
    //basic_2(my_strstr);
    //null(my_strstr);
    dlclose(handle);
}

