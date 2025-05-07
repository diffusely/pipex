NAME		= pipex

PRINTF		= lib/ft_printf/
LIBFT		= lib/libft/
INCLUDES	= includes
SRC_DIR		= src/

SRC			= main.c $(SRC_DIR)get_path.c $(SRC_DIR)error.c $(SRC_DIR)init.c $(SRC_DIR)pipex.c

OBJ			= $(SRC:%.c=%.o)

LIB_FLAGS	= -L$(LIBFT) -lft -L$(PRINTF) -lftprintf
IFLAG		= -I$(INCLUDES) -I$(LIBFT) -I$(PRINTF)
FFLAG		= -g3 -fsanitize=address
CFLAG		= -Wall -Wextra -Werror 
 
CC			= cc
AR			= ar rcs
RM			= rm -rf


all:				$(NAME)

.c.o:
					$(CC) -c $(CFLAG) $(IFLAG) -I/usr/include -O3 -c $< -o $(<:.c=.o)

$(NAME):			$(OBJ)
					make -C $(PRINTF)
					make -C $(LIBFT)
					$(CC) $(CFLAG) $(OBJ) $(LIB_FLAGS) -o $(NAME)

bonus:				$(OBJ)
					make -C $(PRINTF)
					make -C $(LIBFT)
					$(CC) $(CFLAG) $(OBJ) $(LIB_FLAGS) -o $(BNAME)

clean:				
					make -C $(PRINTF) clean
					make -C $(LIBFT) clean
					$(RM) $(OBJ)

fclean: 			clean
					make -C $(PRINTF) fclean
					make -C $(LIBFT) fclean
					$(RM) $(NAME)

re:					fclean all

.PHONY: 			all clean fclean re