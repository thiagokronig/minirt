NAME = minirt
CFLAGS = -O3 -Wall -Wextra -Werror

all: minirt

clean:
	@rm -f *.o *.d

fclean: clean
	@rm -f "$(NAME)"

re: fclean all

.PHONY: clean fclean test_norminette

test_norminette:
	bash ./norminette.sh

test: all test_norminette
