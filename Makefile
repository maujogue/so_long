.PHONY:     			all $(NAME) clear mkbuild lib minilibx clear clean fclean re sanitize

NAME					= so_long

BUILD_DIR				= build/
	
HEADER_DIR				= header/

HEADER_FILE				= so_long.h

DIR						= src/

SRC			 			=	sl_main.c	sl_path_finding.c	sl_utils.c	sl_check_map.c	sl_draw.c	sl_keypress.c	sl_init_images.c	sl_parse_map.c
							
OBJECTS			    	= $(SRC:%.c=$(BUILD_DIR)%.o)
	
LIBFT					= libft.a
LIB_HEADER				= libft.h
LIB_DIR					= libft/

	
CC						= cc
CFLAGS					= -Wall -Wextra -Werror
SANITIZE				= $(CFLAGS) -fsanitize=address

RM 						= rm -rf
CLEAR					= clear

MINILIB					= libmlx.a

# MINILIB_DIR			= minilibx_macos/
# MAC					= -framework OpenGL -framework AppKit 

MINILIB_DIR				= minilibx_linux/
LINUX					= -Lminilibx_linux -L/usr/lib -Iminilibx_linux -lXext -lX11 -lm -lz 

$(BUILD_DIR)%.o:		$(DIR)%.c $(HEADER_DIR)/$(HEADER_FILE) ${LIB_DIR}*.c ${LIB_DIR}/${LIB_HEADER} ${LIB_DIR}Makefile  Makefile
						@mkdir -p $(@D)
						$(CC) $(CFLAGS) -I$(HEADER_DIR) -I$(LIB_DIR) -I$(MINILIB_DIR) -c $< -o $@

all: 					clear mkbuild lib minilibx $(HEADER_DIR) $(NAME)

mkbuild:
						@mkdir -p build

clear:
						$(CLEAR)
						
$(NAME): 				$(OBJECTS) $(LIB_DIR)$(LIBFT)
						$(CC) $(OBJECTS) -o $(NAME) $(LIB_DIR)$(LIBFT) $(MINILIB_DIR)$(MINILIB)  $(MAC) $(LINUX)

sanitize :				$(OBJECTS) $(LIB_DIR)$(LIBFT)
						$(CC) $(SANITIZE) $(OBJECTS) -o $(NAME) $(LIB_DIR) $(LIBFT) $(MINILIB_DIR)$(MINILIB) $(MAC) $(LINUX)

lib:
						@make -C $(LIB_DIR) --no-print-directory
						

minilibx:
						@make -C $(MINILIB_DIR) --no-print-directory
						
clean:					
						@${RM} $(OBJECTS)
						@make clean -C $(LIB_DIR) --no-print-directory
						@make clean -C $(MINILIB_DIR) --no-print-directory
						@${RM} $(BUILD_DIR)

fclean:					clean
						@${RM} ${NAME}
						@make fclean -C $(LIB_DIR) --no-print-directory

re:						fclean all
						$(MAKE) all