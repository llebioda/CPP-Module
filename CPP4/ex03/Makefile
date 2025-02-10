CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

SRCFILES = main.cpp AMateria.cpp Character.cpp Cure.cpp Ice.cpp MateriaSource.cpp
SRCDIR = ./srcs/
SRCS = $(addprefix $(SRCDIR), $(SRCFILES))
OBJDIR = ./build/
OBJS = $(addprefix $(OBJDIR), $(SRCFILES:.cpp=.o))

INCLUDES = -I ./includes

NAME = main

all: $(NAME)

$(NAME): $(OBJDIR) $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

$(OBJDIR)%.o: $(SRCDIR)%.cpp
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJDIR):
	@mkdir -p $(OBJDIR)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re