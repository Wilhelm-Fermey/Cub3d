# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wfermey <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/11 09:41:54 by wfermey           #+#    #+#              #
#    Updated: 2022/07/02 12:15:17 by wilhelmfermey    ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		cub3d

FLAGS =		-Wall -Wextra -Werror	

FILES = 	main.c parsing.c utils/utils1.c utils/get_next_line.c \
			utils/split.c color.c utils/utils2.c map_check.c map.c \
			map_check2.c map_check3.c check_basics.c info.c check_info.c\
			check_color.c texture.c texture2.c map_check2_bis.c \
			free.c
			

${NAME}:
			gcc ${FLAGS} ${FILES} -o ${NAME}

all:		${NAME}

clean:		
			rm ${NAME}	

fclean:		
			rm ${NAME}	

re:			fclean all	
