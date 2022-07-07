define Intro

					░██████╗░█████╗░██╗░░░░░░█████╗░███╗░░██╗░██████╗░
					██╔════╝██╔══██╗██║░░░░░██╔══██╗████╗░██║██╔════╝░
					╚█████╗░██║░░██║██║░░░░░██║░░██║██╔██╗██║██║░░██╗░
					░╚═══██╗██║░░██║██║░░░░░██║░░██║██║╚████║██║░░╚██╗
					██████╔╝╚█████╔╝███████╗╚█████╔╝██║░╚███║╚██████╔╝
					╚═════╝░░╚════╝░╚══════╝░╚════╝░╚═╝░░╚══╝░╚═════╝░		By : Ziko909 👨🏼‍💻
endef
export
CC = cc

Tab=\t\t\t\t\t

NAME = so_long

CCFLAGS = -Wall -Wextra -Werror

HEADER_M = Header/so_long.h

HEADER_B = Header/so_long_bonus.h

HEADER_GNL = get_next_line/get_next_line.h

GNL = get_next_line/get_next_line.c get_next_line/get_next_line_utils.c

OBJ_GNL = $(GNL:.c=.o)

SRC_M = Mandatory/so_long.c Mandatory/map_hundling.c Mandatory/win_mng.c Mandatory/tools.c Mandatory/jerry.c Mandatory/ft_animation.c Mandatory/memory_managment.c

SRC_B = Bonus/so_long.c Bonus/map_hundling.c Bonus/win_mng.c Bonus/jerry.c Bonus/tom_work.c  Bonus/tom_mov.c Bonus/ft_animation.c Bonus/tools.c Bonus/tools_2.c Bonus/convert_img.c Bonus/memory_managment.c

OBJ_M = $(SRC_M:.c=.o)

OBJ_B = $(SRC_B:.c=.o)

all : Intro $(NAME)

%.o : %.c $(HEADER_M) $(HEADER_GNL) $(HEADER_B)
	@$(CC) $(CCFLAGS) -Imlx -c $< -o $@
	@tput sc; printf "$(Tab)\x1b[35m The Object File Of $< Is Created  \x1b[35m";sleep 0.42;tput rc;tput el;

$(NAME) : $(OBJ_M) $(OBJ_GNL)
	@$(CC) -lmlx -framework OpenGL -framework AppKit $(OBJ_M) $(OBJ_GNL) -o $(NAME)
	@printf "$(Tab)";for i in `seq 25`;do printf "\x1b[33m #" && sleep 0.1;done;echo "\n\t$(Tab)\x1b[33m The Mndatory Part Is Ready To Use \x1b[0m"

bonus : Intro $(OBJ_B) $(OBJ_GNL)
	@$(CC) -lmlx -framework OpenGL -framework AppKit $(OBJ_B) $(OBJ_GNL) -o $(NAME)
	@printf "$(Tab)";for i in `seq 25`;do printf "\x1b[33m #" && sleep 0.1;done;echo "\n\t$(Tab)\x1b[33m The Bonus Part Is Ready To Use \x1b[0m"

re : fclean all

clean :
	@rm -f $(OBJ_B)
	@rm -f $(OBJ_M)
	@rm -f $(OBJ_GNL)

fclean : clean
	@rm -f $(NAME)

Intro :
	@echo "\x1b[32m $$Intro \x1b[0m"

.PHONY : fclean clean
