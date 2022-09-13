# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: krochefo <krochefo@student.42quebec.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/02 23:33:38 by krochefo          #+#    #+#              #
#    Updated: 2022/08/31 00:49:18 by krochefo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

# Fichiers sources.
SRCS_FILES = main.c fractol_events.c frac_mandelbrot.c frac_julia.c fractol_color.c \
				fractol_utils.c ft_atof.c
SRCS_PATH = ./
SRCS = $(addprefix $(SRCS_PATH), $(SRCS_FILES))

# Compilateurs
AR = ar
CC = gcc
RM = rm -f

# Flags
ARFLAGS = rcs
CFLAGS = -Wall -Wextra -Werror -g

# Macros
REMOVE = rm -rf
COMMIT = $(shell date "+%d %B %T")

# Transforme les fichiers .c en fichiers .o
# La premiere utilise le contenu de la 2e pour compiler.
# J'imprime des points (sans newline) pour créer ma ligne de progression.
OBJS= $(SRCS:%.c=%.o)
%.o: %.c
	@printf "▆▆"
	@$(CC) $(CFLAGS) -o $@ -c $<

# On appel la commande INIT et NAME puis on imprime le message final.
all: init $(NAME)
	@echo "\n"
	@echo "\033[32m     _    _\033[0m"
	@echo "\033[32m    (\033[33m\033[3m0\033[0m\033[32m)--(\033[33m0\033[32m)\033[0m"
	@echo "\033[32m   /  )___. \ \033[0m    Done!"
	@echo "\033[32m   \________/\033[0m     $(NAME) Compiled!"
	@echo "\033[32m  ./        \.\033[0m"
	@echo "\033[32m ( .        , )\033[0m"
	@echo "\033[32m  \ \_\\//_/ /\033[0m"
	@echo "\033[32m___~~  ~~  ~~___\033[0m"

# On Appel le fichier Make de la librairie Libft et on imprime
# le début de la compilation de pipex à l'écran (sans newline).4
init:
	@echo "Preparing $(NAME)"
	@printf "Compiling :"

# On appel la création des OBJS et ensuite on compile le programme.
$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) -lmlx -framework OpenGL -framework AppKit -o $@ $^

# Commande de nettoyage.
clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

# On nettoie et recompile.
re:	fclean all
