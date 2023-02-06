# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ael-maar <ael-maar@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/31 20:20:01 by ael-maar          #+#    #+#              #
#    Updated: 2023/02/06 17:22:27 by ael-maar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# The required paths
SRCS_PATH = ./srcs
OBJS_PATH = ./objs

# MANDATORY SOURCE FILES 
SRCS = $(SRCS_PATH)/run.c $(SRCS_PATH)/read_from_map.c $(SRCS_PATH)/check_map.c $(SRCS_PATH)/map_components_checks.c \
$(SRCS_PATH)/map_path_checks.c $(SRCS_PATH)/play.c $(SRCS_PATH)/play_utils.c $(SRCS_PATH)/draw.c $(SRCS_PATH)/player_moves.c \
$(SRCS_PATH)/utils.c

# BONUS SOURCE FILES
BSRCS = $(SRCS_PATH)/run.c $(SRCS_PATH)/read_from_map.c $(SRCS_PATH)/check_map.c $(SRCS_PATH)/map_components_checks.c \
$(SRCS_PATH)/map_path_checks.c $(SRCS_PATH)/play_bonus.c $(SRCS_PATH)/play_utils_bonus.c $(SRCS_PATH)/draw_bonus.c $(SRCS_PATH)/player_moves_bonus.c \
$(SRCS_PATH)/enemy_moves.c $(SRCS_PATH)/enemy_utils.c $(SRCS_PATH)/utils.c

# MANDATORY OBJECT FILES
OBJS = $(SRCS:$(SRCS_PATH)/%.c=$(OBJS_PATH)/%.o)

# BONUS OBJECT FILES
BOBJS = $(BSRCS:$(SRCS_PATH)/%.c=$(OBJS_PATH)/%.o)

# GNL FILES
GNL_PATH = ./get_next_line
GNL_SRCS = $(GNL_PATH)/get_next_line.c $(GNL_PATH)/get_next_line_utils.c
GNL_OBJS = $(GNL_SRCS:.c=.o)

# LIBFT FILES
LIBFT_PATH = ./libft
LIB_LIBFT = $(LIBFT_PATH)/libft.a

# PRINTF FILES
PRINTF_PATH = ./printf
LIB_PRINTF = $(PRINTF_PATH)/libftprintf.a

# INCLUDE HEADER FILES
HEADER_FILES = -Imlx -IIncludes -Ilibft -Iget_next_line -Iprintf

# MLX FLAGS
MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit

#EXTRA FLAGS FOR CC
CFLAGS = -Wall -Wextra -Werror -c

# FORCE REMOVE FILES
RM = rm -rf

# PROGRAM NAME
NAME = so_long
BNAME = so_long_bonus

all: $(NAME)

$(NAME): $(LIB_LIBFT) $(LIB_PRINTF) $(GNL_OBJS)  | $(OBJS)
	@$(CC) $(MLX_FLAGS) $^ $| -o $@
	@echo "\n\033[32m <==== COMPILING MANDATORY SUCCESSFULY ====> \033[0m"

# COMPILING LIBFT
$(LIB_LIBFT):
	@make bonus -C libft
	@echo "\033[32m <==== COMPILING LIBFT SUCCESSFULY ====> \033[0m"

# COMPILING PRINTF
$(LIB_PRINTF):
	@make -C printf
	@echo "\033[32m <==== COMPILING PRINTF SUCCESSFULY ====> \033[0m"

# COMPILING GNL
$(GNL_PATH)/%.o: $(GNL_PATH)/%.c
	@$(CC) $(CFLAGS) $< -o $@
	@echo "Compiling object ==> \c"
	@echo $@

# COMPILING EVERY SOURCE FILE TO DIRECTORY OBJS
$(OBJS_PATH)/%.o: $(SRCS_PATH)/%.c
	@mkdir -p $(dir $@)
	@echo "Compiling object ==> \c"
	@echo $@
	@$(CC) $(HEADER_FILES) -c $< -o $@
	@sleep 0.100

bonus: $(BNAME)

$(BNAME): $(LIB_LIBFT) $(LIB_PRINTF) $(GNL_OBJS) | $(BOBJS)
	@$(CC) $(MLX_FLAGS) $^ $| -o $@
	@echo "\n\033[32m <==== COMPILING BONUS SUCCESSFULY ====> \033[0m"

clean:
	@make clean -C $(LIBFT_PATH)
	@make clean -C $(PRINTF_PATH)
	@$(RM) $(GNL_OBJS) $(OBJS_PATH)
	@echo "\n\033[32m <==== CLEANED SUCCESSFULY ====> \033[0m"

fclean:
	@make fclean -C $(LIBFT_PATH)
	@make fclean -C $(PRINTF_PATH)
	@$(RM) $(GNL_OBJS) $(OBJS) $(OBJS_PATH)
	@$(RM) $(NAME) $(BNAME)
	@echo "\n\033[32m <==== FULLY CLEANED SUCCESSFULY ====> \033[0m\n"

re: fclean all

.PHONY: all clean fclean re
