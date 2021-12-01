NAME = my_mouse

FLAGS = -Wall -Wextra -Werror

SRC = main.c \
		debugMaterial.c  \
		maze.c \
		getNextLine.c \

INCLUDE = dataStructure.h  \

SRCPATH = src
OBJPATH = obj
INCLUDESPATH = includes

CC = gcc
INCLUDES = $(addprefix $(INCLUDESPATH)/,$(INCLUDE))
SRCS = $(addprefix $(SRC_PATH)/,$(SRC))
OBJ = $(SRCS:/%.c=$(OBJPATH)/%.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAG) $(OBJ) $(LIBS) -o $(NAME)

$(OBJ): $(OBJPATH)/%.o : $(SRCPATH)/%.c
	@mkdir -p $(dir $@)
	$(CC) -o $@ $(FLAGS) -I $(INCLUDESPATH) -c $< 

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: re fclean all clean