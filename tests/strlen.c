/*
** EPITECH PROJECT, 2024
** B-ASM-400-LYN-4-1-asmminilibc-mathieu.borel
** File description:
** strlen.c
*/

#include <criterion/criterion.h>
#include <dlfcn.h>

#define PROTO   unsigned int (*my_strlen)(char *)

static void basic(PROTO)
{
    char test[] = "hello";
    cr_assert_eq(my_strlen(test), strlen(test));
}

static void empty(PROTO)
{
    char test[] = "";
    cr_assert_eq(my_strlen(test), strlen(test));
}

static void null(PROTO)
{
    char *test = NULL;
    cr_assert_eq(my_strlen(test), 0);
}

Test(strlen, basic)
{
    void *handle = dlopen("./libasm.so", RTLD_LAZY);
    if (!handle) {
        return;
    }
    unsigned int (*my_strlen)(char*) = dlsym(handle, "strlen");
    basic(my_strlen);
    empty(my_strlen);
    null(my_strlen);
    dlclose(handle);
}

