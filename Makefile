# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ensebast <ensebast@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/25 00:14:38 by ensebast          #+#    #+#              #
#    Updated: 2021/12/04 17:43:17 by ensebast         ###   ########.br        #
#    Updated: 2021/10/25 00:14:39 by ensebast         ###   ########.br        #
#                                                                              #
# **************************************************************************** #

CC:=gcc
CFLAGS:= -O3 -lXext -lX11 -lm -I
FLAG:= -Wall -Wextra -Werror

PROGRAM:=fractol

UTILS_DIR:= utils/
UTILS_FILE:= complex_operation.c distance.c draw.c free_all.c ft_atof.c ft_strcmp.c\
			 init.c init_complex.c init_struct.c key_event.c mandelbrot.c mapper.c\
			 mouse_event.c parsing.c zoom_panning.c julia.c burning_ship.c main.c

UTILS:= $(addprefix $(UTILS_DIR), $(UTILS_FILE))

OBJ:= $(UTILS:c=o)

LIBX_DIR:= minilibx/
LIBX:= $(LIBX_DIR)libmlx.a

.PHONY: re fclean clean

$(UTILS_DIR)%.o: $(UTILS_DIR)%.c
	$(CC) $(FLAG) -Iinclude/ -c $^ -o $@

$(PROGRAM): $(LIBX) $(OBJ) 	
	$(CC) $(OBJ) -o $(PROGRAM) $(FLAG) $(LIBX) $(CFLAGS) ./include

.PHONY: re fclean clean

$(UTILS_DIR)%.o: $(UTILS_DIR)%.c
	gcc -Iinclude/ -c $^ -o $@

$(PROGRAM): $(LIBX) $(OBJ) 	
	$(CC) $(CFLAGS)include/ $(MAIN) $(UTILS) $(LIBX) -o $(PROGRAM)

$(LIBX): $(LIBX_DIR)Makefile
	make -C  $(LIBX_DIR)

clean:
	rm -f $(OBJ) $(PROGRAM)

fclean: clean
	make -C $(LIBX_DIR) clean

re: fclean $(PROGRAM)
