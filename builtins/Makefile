NAME = minishell

CC = cc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

SRC = main.c  cd.c  echo.c  env.c  exit.c  pwd.c export.c\
    	utils_export.c  utils1.c   utils2.c  utils3.c lst_utils.c\

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -lreadline $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ) $(OBJ_BONUS)

fclean: clean
	$(RM) $(NAME) $(CHECKER_BONUS)

re: fclean all