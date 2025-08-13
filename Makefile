# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adjeuken <adjeuken@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/13 11:56:15 by adjeuken          #+#    #+#              #
#    Updated: 2025/08/13 11:56:16 by adjeuken         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME        = push_swap
BONUS_NAME  = checker

CC          = cc
CFLAGS      = -Wall -Wextra -Werror -MMD -MP \
              -I./libft -I./utils -I./data
LDFLAGS     = -L./libft
LDLIBS      = -lft

RM          = rm -f

LIBFT_DIR   = ./libft
LIBFT_LIB   = $(LIBFT_DIR)/libft.a

SRC_COMMON  = \
  data/ft_clean.c data/ft_init.c data/ft_is_sorted.c data/ft_try_to_parse_int.c \
  utils/ft_action.c utils/ft_lists.c utils/ft_m_actions.c \
  utils/ft_move_handellers.c utils/ft_move_l1.c \
  utils/ft_quicksort.c utils/ft_sort.c utils/ft_wrappers1.c \
  utils/small.c utils/ft_wrappers2.c

SRCS_MAIN   = main.c $(SRC_COMMON)
SRCS_BONUS  = main_bonus.c help_bonus.c $(SRC_COMMON)

OBJS_MAIN   = $(SRCS_MAIN:.c=.o)
OBJS_BONUS  = $(SRCS_BONUS:.c=.o)
DEPS_MAIN   = $(OBJS_MAIN:.o=.d)
DEPS_BONUS  = $(OBJS_BONUS:.o=.d)

# Default
all: $(NAME)

# Build mandatory
$(NAME): $(OBJS_MAIN) $(LIBFT_LIB)
	$(CC) $(CFLAGS) $(OBJS_MAIN) $(LDFLAGS) $(LDLIBS) -o $@

# Build bonus
bonus: $(BONUS_NAME)

$(BONUS_NAME): $(OBJS_BONUS) $(LIBFT_LIB)
	$(CC) $(CFLAGS) $(OBJS_BONUS) $(LDFLAGS) $(LDLIBS) -o $@

# libft auto-build
$(LIBFT_LIB):
	$(MAKE) -C $(LIBFT_DIR)

# Compile C -> o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean
clean:
	$(RM) $(OBJS_MAIN) $(OBJS_BONUS) $(DEPS_MAIN) $(DEPS_BONUS)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME) $(BONUS_NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

-include $(DEPS_MAIN) $(DEPS_BONUS)

.PHONY: all bonus clean fclean re

# ARG=$(python3 -c "import random; print(' '.join(map(str, random.sample(range(-300, 300), 600))))")
