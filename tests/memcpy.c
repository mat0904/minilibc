/*
** EPITECH PROJECT, 2024
** B-ASM-400-LYN-4-1-asmminilibc-mathieu.borel
** File description:
** strlen.c
*/

#include <criterion/criterion.h>
#include <dlfcn.h>
#include <unistd.h>
#include <stdio.h>

#define PROTO   char* (*my_memcpy)(void *, void *, unsigned int)

static void basic(PROTO)
{
    int test[5] = {1, 2, 3, 4, 5};
    int test2[5] = {0, 0, 0, 0, 0};
    my_memcpy(test2, test, sizeof(int) * 5);
    cr_assert_eq(test2[0], 1);
    cr_assert_eq(test2[1], 2);
    cr_assert_eq(test2[4], 5);
}

static void crash(PROTO)
{
    int *test = NULL;
    int *test2 = NULL;
    my_memcpy(test, test2, 5);
}

Test(memcpy, basic)
{
    void *handle = dlopen("./libasm.so", RTLD_LAZY);
    if (!handle) {
        return;
    }
    PROTO = dlsym(handle, "memcpy");
    basic(my_memcpy);
    crash(my_memcpy);
    dlclose(handle);
}

