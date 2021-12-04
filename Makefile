# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ensebast <ensebast@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/25 00:14:38 by ensebast          #+#    #+#              #
<<<<<<< HEAD
#    Updated: 2021/11/08 19:44:06 by ensebast         ###   ########.br        #
=======
#    Updated: 2021/10/25 00:14:39 by ensebast         ###   ########.br        #
>>>>>>> b2c0f17 (project)
#                                                                              #
# **************************************************************************** #

CC:=gcc
<<<<<<< HEAD
CFLAGS:= -O3 -lXext -lX11 -lm -I
FLAG:= -Wall -Wextra -Werror
=======
CFLAGS:= -O3 -Wall -Wextra -Werror -lXext -lX11 -lm -I
>>>>>>> b2c0f17 (project)

PROGRAM:=fractol

UTILS_DIR:= utils/
UTILS_FILE:= complex_operation.c distance.c draw.c free_all.c ft_atof.c ft_strcmp.c\
			 init.c init_complex.c init_struct.c key_event.c mandelbrot.c mapper.c\
<<<<<<< HEAD
			 mouse_event.c parsing.c zoom_panning.c julia.c burning_ship.c main.c

UTILS:= $(addprefix $(UTILS_DIR), $(UTILS_FILE))

OBJ:= $(UTILS:c=o)
=======
			 mouse_event.c parsing.c zoom_panning.c julia.c burning_ship.c

UTILS:= $(addprefix $(UTILS_DIR), $(UTILS_FILE))

OBJ= $(UTILS:c=o)
>>>>>>> b2c0f17 (project)

LIBX_DIR:= minilibx-linux/
LIBX:= $(LIBX_DIR)libmlx.a

<<<<<<< HEAD
.PHONY: re fclean clean

$(UTILS_DIR)%.o: $(UTILS_DIR)%.c
	$(CC) $(FLAG) -Iinclude/ -c $^ -o $@

$(PROGRAM): $(LIBX) $(OBJ) 	
	$(CC) $(OBJ) -o $(PROGRAM) $(FLAG) $(LIBX) $(CFLAGS) ./include
=======
MAIN:= main.c

.PHONY: re fclean clean

$(UTILS_DIR)%.o: $(UTILS_DIR)%.c
	gcc -Iinclude/ -c $^ -o $@

$(PROGRAM): $(LIBX) $(OBJ) 	
	$(CC) $(CFLAGS)include/ $(MAIN) $(UTILS) $(LIBX) -o $(PROGRAM)
>>>>>>> b2c0f17 (project)

$(LIBX): $(LIBX_DIR)Makefile
	make -C  $(LIBX_DIR)

clean:
	rm -f $(OBJ) $(PROGRAM)

fclean: clean
	make -C $(LIBX_DIR) clean

re: fclean $(PROGRAM)
