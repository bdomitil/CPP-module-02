files.c = main.cpp Fixed.cpp

CFLAGS = -Wall -Wextra -Werror

NAME = fixed

all : $(NAME)

$(NAME) : $(files.c)
		clang++ $(CFLAGS) $(files.c) -o $(NAME)


%.o : %.c
		@gcc $(CFLAGS)  -c  $<  -o $@
		@echo  "\033[36m$<\033[0m \033[35m is compiled!\033[0m" 


fclean :
		@rm  -f $(NAME)
		@echo "\033[7mfclean is done!\033[0m"

re	:  fclean all	


.PHONY : all clean  fclean