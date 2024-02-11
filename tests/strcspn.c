/*
** EPITECH PROJECT, 2024
** B-ASM-400-LYN-4-1-asmminilibc-mathieu.borel
** File description:
** strlen.c
*/

#include <criterion/criterion.h>
#include <dlfcn.h>
#include <stdio.h>

#define PROTO   size_t (*my_strcspn)(char *, char *)

static void basic(PROTO)
{
    printf("%ld\n", my_strcspn("hello", "o"));
    printf("%ld\n", strcspn("hello", "o"));
    cr_assert_eq(my_strcspn("hello", "l"), 2);
    cr_assert_eq(my_strcspn("hello", "e"), 1);
}

static void empty(PROTO)
{
    cr_assert_eq(my_strcspn("", NULL), 0);
}

static void null(PROTO)
{
    char *test = NULL;
    cr_assert_null(my_strcspn(test, NULL));
}

Test(strcspn, basic)
{
    void *handle = dlopen("./libasm.so", RTLD_LAZY);
    if (!handle) {
        return;
    }
    size_t(*my_strcspn)(char*, char *) = dlsym(handle, "strcspn");
    basic(my_strcspn);
    empty(my_strcspn);
    null(my_strcspn);
    dlclose(handle);
}

