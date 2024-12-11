#gcc so_long.c map.c check_map.c MLX42/libmlx42.a libft/libft.a -Iinclude -lglfw -L "/Users/pximenez/.brew/opt/glfw/lib/" -o so_long
#gcc so_long.c map.c check_map.c MLX42/libmlx42.a libft/libft.a -Iinclude -ldl -lglfw -pthread -lm -o so_long

#//= Colors =//#
BOLD	:= \033[1m
BLACK	:= \033[30;1m
RED		:= \033[31;1m
GREEN	:= \033[32;1m
YELLOW	:= \033[33;1m
BLUE	:= \033[34;1m
MAGENTA	:= \033[35;1m
CYAN	:= \033[36;1m
WHITE	:= \033[37;1m
RESET	:= \033[0m

# Compilers
CC = cc
CFLAGS = -g 
LIB_DIR = libft/
MLX_PATH = MLX42/
LIBFT_PATH = libft/
MLX_DIR = MLX42/
MLX = $(MLX_PATH)/libmlx42.a
LIBS = $(LIB_DIR)libft.a $(MLX_DIR)libmlx42.a
INCLUDES = -I $(LIB_DIR) -I $(MLX_DIR) -I.
GLFW = -Iinclude -lglfw

SRC_LOC = srcs
SRCB_LOC = srcsb


LIB_SYS = -L "/Users/pximenez/.brew/opt/glfw/lib/"

# Executable name
NAME = so_long
NAME_BONUS = so_long_bonus

# Files
SRCS = $(SRC_LOC)/correct_map.c $(SRC_LOC)/display.c $(SRC_LOC)/images.c \
	$(SRC_LOC)/keys.c $(SRC_LOC)/read_extra1.c $(SRC_LOC)/read_extra2.c \
	$(SRC_LOC)/read.c $(SRC_LOC)/so_long_extra.c $(SRC_LOC)/so_long.c \
	$(SRC_LOC)/additional.c 

OBJS = $(SRCS:.c=.o)

SRCS_BONUS = $(SRCB_LOC)/correct_map.c $(SRCB_LOC)/display.c $(SRCB_LOC)/images.c \
	$(SRCB_LOC)/keys.c $(SRCB_LOC)/read_extra1.c $(SRCB_LOC)/read_extra2.c \
	$(SRCB_LOC)/read.c $(SRCB_LOC)/so_long_extra.c $(SRCB_LOC)/so_long.c \
	$(SRCB_LOC)/additional.c $(SRCB_LOC)/images2.c 


OBJS_BONUS = $(SRCS_BONUS:.c=.o)

# Executable name
NAME = so_long

# Rules
all : $(NAME)

$(NAME): $(OBJS) $(LIBS) $(MLX)
	@echo "$(MAGENTA)$(BOLD)Compiling so_long...$(RESET)"
	@$(CC) $(CFLAGS) $(INCLUDES) $(GLFW) $(LIB_SYS) -o $@ $(OBJS) $(LIBS)
	@echo "$(CYAN)$(BOLD)Done$(RESET)"

$(LIBS):
	@make -C $(LIB_DIR)

$(MLX):
			@make -s -C $(MLX_PATH)

%.o: %.c so_long.h
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(OBJS_BONUS) $(LIBS) $(MLX)
	@echo "$(MAGENTA)$(BOLD)Compiling so_long_bonus...$(RESET)"
	@$(CC) $(CFLAGS) $(INCLUDES) $(GLFW) $(LIB_SYS) -o $@ $(OBJS_BONUS) $(LIBS)
	@echo "$(CYAN)$(BOLD)Done$(RESET)"

clean:
			@echo "$(RED)$(BOLD)Cleaning objects from so_long...$(RESET)"
			@rm -f $(OBJS) $(OBJS_BONUS)
			@echo "$(GREEN)$(BOLD)Done.$(RESET)"
			@make clean -s -C $(MLX_PATH)
			@make clean -s -C $(LIBFT_PATH)

fclean:
			@echo "$(RED)$(BOLD)Cleaning all files from so_long...$(RESET)"
			@rm -f $(NAME) $(NAME_BONUS) $(OBJS) $(OBJS_BONUS) $(SO_LONG) $(SO_LONG_BONUS) $(LIBFT) $(MLX)
			@echo "$(GREEN)$(BOLD)Done.$(RESET)"
			@make fclean -s -C $(MLX_PATH)
			@make fclean -s -C $(LIBFT_PATH)

re : fclean all

.PHONY : all re fclean clean
