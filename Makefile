################################################################################
# DIRECTORIES ##################################################################
################################################################################

# Includes
INC_DIR = inc/ libft/inc/

# Objects and dependencies
OBJ_DIR = obj/

# Source directories
SRC_DIR = $(sort $(dir $(wildcard src/*/))) src/ bonus/

# Target directory
TARGET_DIR = ./

# Library directories
LIB_DIR = libft/

################################################################################
# BASIC ########################################################################
################################################################################

# Target name
NAME = $(TARGET_DIR)push_swap

NAME_BONUS = $(TARGET_DIR)checker

SRCS_BONUS =\
stacks.c\
iqueue.c\
iqueue_util.c\
iqueue_sort.c\
iqueue_unique.c\
iqueue_rotate.c\
iqueue_pushpop.c\
parse.c\
ilimits.c\
ft_strtok.c\
ft_strtonum.c\
ft_isspace.c\
stacks_rotate.c\
stacks_rev_rotate.c\
stacks_push.c\
stacks_swap.c\
util.c\
stacks_rotate_both.c\
stacks_swap_both.c\
main_bonus.c

SRCS =\
parse.c\
ilimits.c\
ft_strtonum.c\
ft_strtok.c\
ft_isspace.c\
util.c\
iqueue.c\
iqueue_util.c\
iqueue_lcs.c \
iqueue_iter.c\
iqueue_sort.c\
iqueue_unique.c\
iqueue_rotate.c\
iqueue_minmax.c\
iqueue_pushpop.c\
stacks.c\
stacks_rotate_by.c\
stacks_rotate.c\
stacks_rev_rotate.c\
stacks_swap.c\
stacks_push.c \
stacks_sort_small.c\
stacks_sort_util.c\
stacks_sort_large.c\
stacks_rotate_both.c\
stacks_swap_both.c\
main.c

# Compiler
CC = cc

# Libraries
LIB = ft

################################################################################
# CONFIG #######################################################################
################################################################################

vpath %.c $(SRC_DIR)
.PHONY: all clean fclean re debug d libft mandatory bonus

OBJS := $(SRCS:%.c=$(OBJ_DIR)%.o)
OBJS_BONUS = $(SRCS_BONUS:%.c=$(OBJ_DIR)%.o)
DEPS = $(SRCS:%.c=$(OBJ_DIR)%.d) $(SRCS_BONUS:%.c=$(OBJ_DIR)%.d)

L = $(LIB_DIR:%=-L%)
l = $(LIB:%=-l%)
I = $(INC_DIR:%=-I%) $(SRC_DIR:%=-I%)
O = #-O3
W = -Wall -Wextra -Werror
DBG = #-g #-fsanitize=address

CFLAGS = -c $W $O $I $M $(DBG)
LDFLAGS = $W $O $I $M $l $L $(DBG)

################################################################################
# RULES ########################################################################
################################################################################

# Default rule
all: mandatory bonus

$(OBJ_DIR)%.o: %.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -o $@ $<

# Target
$(NAME): $(OBJS) | $(TARGET_DIR) libft
	$(CC) $(LDFLAGS) -o $@ $^

$(NAME_BONUS): $(OBJS_BONUS) | $(TARGET_DIR) libft
	$(CC) $(LDFLAGS) -o $@ $^

libft:
	make -C libft

bonus:
	make $(NAME_BONUS)

mandatory:
	make $(NAME)

# Cleanup
clean_local:
	rm -rf $(OBJS) $(DEPS)

clean:
	rm -rf $(OBJ_DIR)

fclean_local: clean
	rm -rf $(NAME)

fclean: fclean_local
	make fclean -C libft

# Debug
debug:
	make fclean
	make all FLAGS="-g -fsanitize=address"

# Aliases
re: fclean all
d: debug

# Dir creation
$(OBJ_DIR) $(TARGET_DIR):
	@mkdir -p $@

-include $(DEPS)