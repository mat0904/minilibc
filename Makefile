##
## EPITECH PROJECT, 2023
## mat
## File description:
## Makefile
##

MAIN_SRC	=	src/main.c

ASM_SRC	=	src/strlen.asm \
			src/strchr.asm \
			src/strrchr.asm \
			src/memset.asm \
			src/memcpy.asm \
			src/strcmp.asm \
			src/memmove.asm \
			src/strncmp.asm \
			src/strcasecmp.asm \
			src/strpbrk.asm \
			src/strcspn.asm \
			src/strstr.asm

TEST_SRC	=	tests/strlen.c \
				tests/strchr.c \
				tests/strrchr.c \
				tests/memset.c \
				tests/memcpy.c \
				tests/strcmp.c \
				tests/memmove.c \
				tests/strncmp.c \
				tests/strcasecmp.c \
				tests/strpbrk.c \
				tests/strcspn.c \
				tests/strstr.c

MAIN_OBJ	=	$(MAIN_SRC:.c=.o)
ASM_OBJ	=	$(ASM_SRC:.asm=.o)
TEST_OBJ	=	$(TEST_SRC:.c=_test.o)

CC	=	gcc
NASM	=	nasm

ASMFLAGS	=	-f elf64

CFLAGS	=
LIB	=	-L. -lasm
LDFLAGS	=	$(LIB)

COVERAGE	=	--coverage -lcriterion

DLIB	=	libasm.so
EXE	=	binary
TEST_EXE	=	$(EXE)_test

all:	$(DLIB)

%.o:	%.c
		$(CC) -o $@ -c $< $(CFLAGS) -g3

%.o	:	%.asm
		$(NASM) -o $@ $< $(ASMFLAGS)

%_test.o:	%.c
			$(CC) -o $@ -c $<

$(DLIB):	$(ASM_OBJ)
			ld -shared -o $@ $^

run:	$(DLIB) $(MAIN_OBJ)
		$(CC) -o $(EXE) $(MAIN_OBJ) $(LDFLAGS) -L. -lasm

clean:
		rm -rf $(MAIN_OBJ)
		rm -rf $(TEST_OBJ)
		rm -rf $(ASM_OBJ)
		$(shell find * -name "*.gcda" -delete)
		$(shell find * -name "*.gcno" -delete)
		$(shell find * -name "vgcore.*" -delete)

fclean:	clean
		rm -rf $(EXE)
		rm -rf $(DLIB)
		rm -rf $(TEST_EXE)

re:	fclean all

unit_tests:	CFLAGS += $(COVERAGE)
unit_tests: LDFLAGS += $(COVERAGE)
unit_tests: $(DLIB) $(FILE_OBJ) $(TEST_OBJ)
			$(CC) -o $(TEST_EXE) $(FILE_OBJ) $(TEST_OBJ) $(LDFLAGS) -L. -lasm

tests_run:	clean unit_tests
			./$(TEST_EXE)

.PHONY: all clean re fclean tests_run
