#= Colors =#
BOLD    := \033[1m
RED     := \033[31;1m
GREEN   := \033[32;1m
MAGENTA := \033[35;1m
CYAN    := \033[36;1m
RESET   := \033[0m

#= Compiler and Flags =#
CC      = cc
CFLAGS  = -g
INCLUDES = -I $(LIB_DIR) -I $(MLX_DIR) -I. -I/Users/pximenez/.brew/opt/glfw/include

#= Paths =#
LIB_DIR = libft/
MLX_DIR = MLX42/
GLFW_LIB = /Users/pximenez/.brew/opt/glfw/lib
LIBS    = $(LIB_DIR)libft.a $(MLX_DIR)libmlx42.a
GLFW    = -L$(GLFW_LIB) -lglfw -ldl -pthread -lm

#= Files =#
SRC_LOC = srcs
SRCB_LOC = srcsb
SRCS    = $(SRC_LOC)/correct_map.c $(SRC_LOC)/display.c $(SRC_LOC)/images.c \
           $(SRC_LOC)/keys.c $(SRC_LOC)/read_extra1.c $(SRC_LOC)/read_extra2.c \
           $(SRC_LOC)/read.c $(SRC_LOC)/so_long_extra.c $(SRC_LOC)/so_long.c \
           $(SRC_LOC)/additional.c
OBJS    = $(SRCS:.c=.o)

SRCS_BONUS = $(SRCB_LOC)/correct_map.c $(SRCB_LOC)/display.c $(SRCB_LOC)/images.c \
	$(SRCB_LOC)/keys.c $(SRCB_LOC)/read_extra1.c $(SRCB_LOC)/read_extra2.c \
	$(SRCB_LOC)/read.c $(SRCB_LOC)/so_long_extra.c $(SRCB_LOC)/so_long.c \
	$(SRCB_LOC)/additional.c $(SRCB_LOC)/images2.c 


OBJS_BONUS = $(SRCS_BONUS:.c=.o)


#= Executables =#
NAME_BONUS = so_long_bonus
NAME    = so_long

#= Rules =#
all: $(NAME)

$(NAME): $(OBJS) $(LIBS)
	@echo "$(MAGENTA)$(BOLD)Compiling so_long...$(RESET)"
	@$(CC) $(CFLAGS) $(INCLUDES) -o $@ $(OBJS) $(LIBS) $(GLFW)
	@echo "$(CYAN)$(BOLD)Done$(RESET)"


bonus: $(NAME_BONUS)

$(NAME_BONUS): $(OBJS_BONUS) $(LIBS) $(MLX)
	@echo "$(MAGENTA)$(BOLD)Compiling so_long...$(RESET)"
	@$(CC) $(CFLAGS) $(INCLUDES) -o $@ $(OBJS_BONUS) $(LIBS) $(GLFW)
	@echo "$(CYAN)$(BOLD)Done$(RESET)"

%.o: %.c so_long.h
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBS):
	@make -C $(LIB_DIR)
	@make -s -C $(MLX_DIR)

clean:
	@echo "$(RED)$(BOLD)Cleaning objects...$(RESET)"
	@rm -f $(OBJS)
	@make clean -s -C $(LIB_DIR)
	@make clean -s -C $(MLX_DIR)
	@echo "$(GREEN)$(BOLD)Done.$(RESET)"

fclean: clean
	@echo "$(RED)$(BOLD)Removing executables...$(RESET)"
	@rm -f $(NAME)
	@make fclean -s -C $(LIB_DIR)
	@make fclean -s -C $(MLX_DIR)
	@echo "$(GREEN)$(BOLD)Done.$(RESET)"

re: fclean all

.PHONY: all clean fclean re
