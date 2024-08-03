# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aaskal <aaskal@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/07 15:26:27 by aaskal            #+#    #+#              #
#    Updated: 2024/05/09 14:20:38 by aaskal           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror

LIBS =  -lmlx -framework OpenGL -framework AppKit -L ./libft -lft
INCLUDES =  -I ./libft

SRCS = Mandatory_part/fdf.c Mandatory_part/MapSize.c gnl/get_next_line_utils.c gnl/get_next_line.c Mandatory_part/dda.c  Mandatory_part/check_args.c \
 Mandatory_part/draw_map.c Mandatory_part/mlx_functions.c  Mandatory_part/get_color.c  Mandatory_part/get_points.c  Mandatory_part/zoom_isometric.c \
 Mandatory_part/rotate_and_trasnlate.c 
OBJS = $(SRCS:.c=.o)

SRCS_BONUS = Bonus_part/dda_bonus.c  Bonus_part/get_points_bonus.c  Bonus_part/restore_points_bonus.c Bonus_part/MapSize_bonus.c \
Bonus_part/display_key_usage_bonus.c  Bonus_part/fdf_bonus.c  Bonus_part/keycode_bonus.c Bonus_part/rotate_and_trasnlate_bonus.c Bonus_part/check_args_bonus.c \
 Bonus_part/draw_map_bonus.c Bonus_part/get_color_bonus.c  Bonus_part/mlx_functions_bonus.c Bonus_part/zoom_isometric_bonus.c \
  gnl/get_next_line_utils.c gnl/get_next_line.c 
OBJS_BONUS = $(SRCS_BONUS:.c=.o)
NAME = fdf
NAME_BONUS = fdf_bonus

all:  $(NAME)


	
$(NAME): $(OBJS)
	@echo "\033[0;32mCompiling...\033[0m"
	@make    -s re -C libft
	@$(CC) $(CFLAGS) $(INCLUDES) -o $(NAME) $(OBJS) $(LIBS)
	@echo "\033[0;32mCompilation successful! ✅\033[0m"


	
bonus:  $(NAME_BONUS)

$(NAME_BONUS): $(OBJS_BONUS)
	@echo "\033[0;32mCompiling bonus...\033[0m"
	@make -s -C libft
	@$(CC) $(CFLAGS) $(INCLUDES) -o $(NAME_BONUS) $(OBJS_BONUS) $(LIBS)
	@echo "\033[0;32mCompilation of bonus successful! ✅\033[0m"

.c.o: Mandatory_part/fdf.h  Bonus_part/fdf_bonus.h
	@$(CC) $(CFLAGS) $(INCLUDES) -c $<  -o $@

clean:
	@echo "\033[0;32mCleaning...\033[0m"
	@-rm -f $(OBJS) $(OBJS_BONUS)  libft/*.o
	@echo "\033[0;32mCleaning successful! ✅\033[0m"

fclean: clean
	@-rm -f $(NAME) $(NAME_BONUS) libft/libft.a

re: fclean all
42: all  bonus clean
.Phony : all clean fclean re