NAME        = push_swap
BONUS_NAME  = checker

CC          = cc
CFLAGS      = -Wall -Wextra -Werror \
              -I./libft \
              -I./utils \
              -I./data
LDFLAGS     = -L./libft -lft

LIBFT_DIR   = ./libft
LIBFT_LIB   = $(LIBFT_DIR)/libft.a

SRC         = data/ft_clean.c data/ft_init.c \
              data/ft_is_sorted.c\
              data/ft_try_to_parse_int.c \
              utils/ft_action.c utils/ft_lists.c \
              utils/ft_m_actions.c \
              utils/ft_move_handellers.c utils/ft_move_l1.c \
              utils/ft_quicksort.c utils/ft_sort.c \
              utils/ft_wrappers1.c utils/small.c utils/ft_wrappers2.c

SRCS_MAIN   = main.c $(SRC)
OBJS_MAIN   = $(SRCS_MAIN:.c=.o)

SRCS_BONUS  = main_bonus.c help_bonus.c $(SRC)
OBJS_BONUS  = $(SRCS_BONUS:.c=.o)

# Default rule
all: $(NAME)

$(NAME): $(OBJS_MAIN) $(LIBFT_LIB)
	$(CC) $(OBJS_MAIN) $(LDFLAGS) -o $@

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(OBJS_BONUS) $(LIBFT_LIB)
	$(CC) $(OBJS_BONUS) $(LDFLAGS) -o $@

$(LIBFT_LIB):
	@$(MAKE) -C $(LIBFT_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS_MAIN) $(OBJS_BONUS)
	@$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME) $(BONUS_NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all bonus clean fclean re


# ARG=$(python3 -c "import random; print(' '.join(map(str, random.sample(range(-300, 300), 600))))")
