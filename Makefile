NAME		= pipex

PRINTF		= lib/ft_printf/
LIBFT		= lib/libft/
INCLUDES	= includes
SRC_DIR		= src/

SRC			= main.c $(SRC_DIR)get_path.c $(SRC_DIR)error.c $(SRC_DIR)init.c $(SRC_DIR)pipex.c \
			  $(SRC_DIR)utils.c $(SRC_DIR)here_doc_bonus.c

BSC			= main_bonus.c $(SRC_DIR)get_path.c $(SRC_DIR)error.c $(SRC_DIR)init.c $(SRC_DIR)pipex.c \
			  $(SRC_DIR)utils.c $(SRC_DIR)here_doc_bonus.c

OBJ			= $(SRC:%.c=%.o)
BOBJ		= $(BSC:%.c=%.o)

LIB_FLAGS	= -L$(LIBFT) -lft -L$(PRINTF) -lftprintf
IFLAG		= -I$(INCLUDES) -I$(LIBFT) -I$(PRINTF)
CFLAG		= -Wall -Wextra -Werror
 
CC			= cc
RM			= rm -rf


all:				$(NAME)

.c.o:
					$(CC) -c $(CFLAG) $(IFLAG) -I/usr/include -O3 -c $< -o $(<:.c=.o)

$(NAME):			$(OBJ)
					make -C $(PRINTF)
					make -C $(LIBFT)
					$(CC) $(CFLAG) $(OBJ) $(LIB_FLAGS) -o $(NAME)

bonus:				$(BOBJ)
					make -C $(PRINTF)
					make -C $(LIBFT)
					$(CC) $(CFLAG) $(BOBJ) $(LIB_FLAGS) -o $(NAME)

clean:				
					make -C $(PRINTF) clean
					make -C $(LIBFT) clean
					$(RM) $(OBJ) $(BOBJ)

fclean: 			clean
					make -C $(PRINTF) fclean
					make -C $(LIBFT) fclean
					$(RM) $(NAME)

re:					fclean all

.PHONY: 			all clean fclean re