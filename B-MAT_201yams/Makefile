##
## EPITECH PROJECT, 2021
## 201yams
## File description:
## Makefile
##

NAME	=	201yams

SRC		=	src/main.c				\
			src/display_help.c		\
			src/error_handling.c	\
			src/fill_struct.c		\
			src/compute.c			\
			src/display_res.c		\
			src/count_good.c		\
			src/yams.c

OBJ		=	$(SRC:.c=.o)

CPPFLAGS=	-I./include/

CFLAGS	=	-Wall -Wextra -Werror -g -lm

TEST_SRC	=	src/display_help.c		\
				src/error_handling.c	\
				src/fill_struct.c		\
				src/compute.c			\
				src/display_res.c		\
				src/count_good.c		\
				src/yams.c

TEST_NAME	=	unit_tests
TEST_PATH	=	tests/test_files.c
TEST_CSFLAGS	=	--coverage -lcriterion

all		:	$(OBJ)
			gcc $(CFLAGS) -o $(NAME) $(SRC) $(CPPFLAGS)

tests_run:
			gcc -o $(TEST_NAME) $(TEST_SRC) $(TEST_PATH) $(TEST_CSFLAGS) $(CPPFLAGS) -lm
			./$(TEST_NAME)

coverage:
			gcovr --exclude tests/
			gcovr --exclude tests/ --branches

clean	:
			rm -f $(OBJ)
			rm -f ${TEST_NAME}
			rm -f *.gcno *.gcda

fclean	:	clean
			rm -f $(NAME)

re		:	fclean all

.PHONY	:	all tests_run coverage clean fclean re