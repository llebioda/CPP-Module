CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

SRCFILES = Account.cpp tests.cpp
SRCDIR = ./
SRCS = $(addprefix $(SRCDIR), $(SRCFILES))
OBJDIR = ./build/
OBJS = $(addprefix $(OBJDIR), $(SRCFILES:.cpp=.o))

INCLUDES = -I ./

NAME = tests

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

#diff <(./tests | cut -c 17-) <(cut -c 17- 19920104_091532.log)