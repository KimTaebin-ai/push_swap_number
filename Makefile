NAME = push_swap
BO_NAME = checker

SRC = main.c stack_utils.c stack_utils2.c push_swap.c push_swap2.c push_swap3.c clear.c sort.c
SRCS = $(addprefix src/, $(SRC))

BNS_SRC = 
BNS_SRCS = $(addprefix checker/, $(BNS_SRC))

OBJS = $(SRCS:%.c=%.o)
BONUS_OBJS = $(BNS_SRCS:%.c=%.o)

LIBFT = lib/libft/libft.a
INCLUDE_HEADER = -Iincludes -Ilib/libft
CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	cc $(CFLAGS) $(INCLUDE_HEADER) $^ -o $@

$(LIBFT):
	make -C lib/libft

%.o : %.c
	cc $(CFLAGS) $(INCLUDE_HEADER) -c $< -o $@

clean :
	rm -f $(OBJS) $(BONUS_OBJS)
	make -C lib/libft clean

fclean :
	make clean
	rm -f $(NAME) $(BO_NAME)
	make -C lib/libft fclean

re : 
	make fclean
	make all

bonus : $(BO_NAME)

$(BO_NAME): $(BONUS_OBJS) $(LIBFT)
	cc $(CFLAGS) $(INCLUDE_HEADER) $^ -o $@

.PHONY : all clean fclean re bonus
