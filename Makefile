NAME = minirt
CFLAGS = -O3 -Wall -Wextra -Werror -Wconversion
LDLIBS = -lm
SRCS = \
	color_test.c \
	color.c \
	math.c \
	minirt.c \
	tuple_dot.c \
	tuple_point.c \
	tuple_test.c \
	tuple.c

all: minirt

clean:
	@rm -f *.o *.d

fclean: clean
	@rm -f "$(NAME)"

re: fclean all

# Generate makefile for each .c, add both .o and .d as dependent on .c
# See https://www.gnu.org/software/make/manual/html_node/Automatic-Prerequisites.html
%.d: %.c
	@set -e; rm -f $@; \
	$(CC) -MM $(CFLAGS) $< > $@.$$$$; \
	sed 's,\($*\)\.o[ :]*,\1.o $@ : ,g' < $@.$$$$ > $@; \
	rm -f $@.$$$$

include $(SRCS:.c=.d)

.PHONY: clean fclean test_norminette test_tuple

test: re test_norminette test_tuple test_color

test_norminette:
	bash ./norminette.sh

test_tuple: tuple_test
	./tuple_test

tuple_test: tuple.o tuple_point.o tuple_add.o tuple_dot.o math.o

test_color: color_test
	./color_test

color_test: color.o math.o
