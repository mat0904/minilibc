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

#define PROTO   char* (*my_memmove)(void *, void *, unsigned int)

static void basic(PROTO)
{
    char test[] = "hello world";
    char test2[20];
    my_memmove(test2, test, strlen(test) + 1);
    cr_assert_str_eq(test2, test);
}

static void overlap(PROTO)
{
    char test[] = "hello world";
    char realtest[] = "hello world";
    my_memmove(test, &test[6], 5);
    memmove(realtest, &realtest[6], 5);
    cr_assert_str_eq(test, realtest);
}

static void overlap2(PROTO)
{
    char test[] = "hello world";
    my_memmove(&test[6], test, 5);
    cr_assert_str_eq(test, "hello hello");
}

static void overlap3(PROTO)
{
    char str[100] = "Hello, world!";
    char *ptr = str + 6;

    my_memmove(str + 13, ptr, strlen(ptr) + 1);

    cr_assert_str_eq(str, "Hello, world! world!");
}

Test(memmove, basic)
{
    void *handle = dlopen("./libasm.so", RTLD_LAZY);
    if (!handle) {
        return;
    }
    PROTO = dlsym(handle, "memmove");
    basic(my_memmove);
    overlap(my_memmove);
    overlap2(my_memmove);
    overlap3(my_memmove);
    dlclose(handle);
}
