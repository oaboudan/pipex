NAME = pipex

CC = cc

CFLAGS = -Wall -Wextra -Werror

HEADER = pipex.h

SRC = pipex.c utils.c functions.c getpath.c

OFILES = $(SRC:c=o)


all : ${NAME}

${NAME} : ${OFILES}
	${CC} -o ${NAME} ${OFILES}
	
%.o:%.c pipex.h
	${CC} -c ${CFLAGS} ${SRC}  $<

clean :
	rm -f ${OFILES} ${BONUSO}

fclean : clean
	rm -f ${NAME}

re : fclean all

.PHONY: clean fclean re all














# all: $(NAME)

# $(NAME): $(OBJ)
# 	@echo "\033[0;32m\n\nCompiling pipex..."
# 	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ)
# 	@echo "\n\033[0mDone !"

# %.o: %.c
# 	@printf "\033[0;33mGenerating pipex objects... %-10.10s\r" $@
# 	@${CC} ${CFLAGS} -c $< -o $@

# clean:
# 	@echo "\033[0;31m\nDeleting objects..."
# 	@rm -f $(OBJ) $(OBJB)
# 	@echo "\033[0m"

# fclean:
# 	@echo "\033[0;31m\nDeleting objects..."
# 	@rm -f $(OBJ) $(OBJB)
# 	@echo "\nDeleting executable..."
# 	@rm -f $(NAME)
# 	@echo "\033[0m"

# re: fclean all

# bonus: $(OBJB)
# 	@echo "\033[0;32m\n\nCompiling pipex (with bonuses)..."
# 	@$(CC) $(CFLAGS) -o $(NAME) $(OBJB)
# 	@echo "\n\033[0mDone !"

# .PHONY: clean fclean re bonus
