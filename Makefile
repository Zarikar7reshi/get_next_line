NAME = lib_get_next_line.a
BONUS_NAME = lib_get_next_line_bonus.a	
CFLAGS = -Wall -Wextra -Werror -c

SRC = get_next_line.c get_next_line_utils.c
OBJ = $(SRC:.c=.o)
BONUS_SRC = get_next_line_bonus.c get_next_line_utils_bonus.c
BONUS_OBJ = $(BONUS_SRC:.c=.o)

$(NAME): $(OBJ)
	ar -rcs $(NAME) $(OBJ)

$(OBJ) : $(SRC)
	cc $(CFLAGS) $^

all: $(NAME) bonus clean

clean:
	rm -f $(OBJ) $(BONUS_OBJ)

fclean:
	rm -f $(NAME)

re: fclean all

bonus: $(BONUS_OBJ) $(NAME)
	ar -rcs $(BONUS_NAME) $(OBJ)

$(BONUS_OBJ): $(BONUS_SRC)
	cc $(CFLAGS) $^