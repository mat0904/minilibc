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
    char test[10];
    my_memset(test, 2, 10);
    cr_assert_eq(test[1], 2);
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

