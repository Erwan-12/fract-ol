NAME = fract-ol
CC = cc
CFLAGS = -Wall -Wextra -Werror -Iincludes -Imlx_linux -O3
MLXFLAGS = -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

# Directories
SRCDIR = srcs
INCDIR = includes

# Source files
SRCS = 	main.c \
		ft_putendl_fd.c \
		ft_strcmp.c \
		init.c \
		utils.c \
		mouse.c \


OBJS = $(addprefix $(SRCDIR)/,$(SRCS:.c=.o))


# Rules
all: $(NAME)
$(NAME): $(OBJS)
	$(CC) $(OBJS) $(MLXFLAGS) -o $(NAME)
$(SRCDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	rm -rf $(OBJS)
fclean: clean
	rm -rf $(NAME)
re: fclean all