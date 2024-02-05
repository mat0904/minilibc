/*
** EPITECH PROJECT, 2024
** B-ASM-400-LYN-4-1-asmminilibc-mathieu.borel
** File description:
** strlen.c
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../include/minilib.h"

void redirect_all_std(void)
{
    cr_redirect_stderr();
    cr_redirect_stdout();
}

Test(strlen, basic, .init = redirect_all_std) {
    cr_assert_eq(strlen("hello"), 5);
}

Test(strlen, empty, .init = redirect_all_std) {
    cr_assert_eq(strlen(""), 0);
}

Test(strlen, null, .init = redirect_all_std) {
    cr_assert_eq(strlen(NULL), 0);
}
