NAME = philo_one

CC = clang

MKD = mkdir

RM = rm -rf

SRCS = 	srcs/main.c \
		srcs/utils/ft_atoi.c \
		srcs/utils/ft_isdigit.c \
		srcs/utils/ft_isnumber.c \
		srcs/utils/time.c \
		srcs/simulation/create_simulation.c \
		srcs/simulation/run_simulation.c \
		srcs/simulation/delete_simulation.c \
		srcs/philos/run_philo.c \
		srcs/philos/actions.c

OBJ = $(SRCS:%.c=%.o)

IFLAGS = ./includes/

CFLAGS = -Wall -Wextra -Werror -pthread

SRCS_DIR = srcs/

STRT_STYLE = \033[1;32m

END_STYLE = \033[0m

all: $(NAME)

%.o: %.c
	@($(CC) $(CFLAGS) -c -I$(IFLAGS) $< -o $(<:.c=.o))

$(NAME): $(OBJ)
	@(echo "$(STRT_STYLE)Compiling...$(END_STYLE)")
	@($(CC) -o $(NAME) -I$(IFLAGS) $(OBJ) $(CFLAGS))
	@(echo "$(STRT_STYLE)Done.$(END_STYLE)")

clean:
	@(echo "$(STRT_STYLE)Cleaning...$(END_STYLE)")
	@($(RM) $(SRCS_DIR)/*.o)
	@($(RM) $(SRCS_DIR)/*/*.o)
	@($(RM) $(SRCS_DIR)/*/*/*.o)
	@(echo "$(STRT_STYLE)Done.$(END_STYLE)")

fclean: clean
	@(echo "$(STRT_STYLE)Fcleaning...$(END_STYLE)")
	@($(RM) $(NAME))
	@(echo "$(STRT_STYLE)Done.$(END_STYLE)")

re: fclean all

.PHONY: all clean fclean re
