/*
** EPITECH PROJECT, 2024
** B-ASM-400-LYN-4-1-asmminilibc-mathieu.borel
** File description:
** strlen.c
*/

#include <criterion/criterion.h>
#include <dlfcn.h>

#define PROTO   char* (*my_memset)(void *, int, unsigned int)

static void basic(PROTO)
{
    char *test = malloc(5);
    my_memset(test, 1, 5);
    cr_assert_eq(test[1], 1);
    free(test);
}

Test(memset, basic)
{
    void *handle = dlopen("./libasm.so", RTLD_LAZY);
    if (!handle) {
        return;
    }
    PROTO = dlsym(handle, "memset");
    basic(my_memset);
    dlclose(handle);
}

