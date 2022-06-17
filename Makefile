# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wfermey <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/11 09:41:54 by wfermey           #+#    #+#              #
#    Updated: 2022/06/16 21:46:45 by wilhelmfermey    ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		cub3d

FLAGS =		

FILES = 	main.c parsing.c utils/utils1.c utils/get_next_line.c \
			utils/split.c color.c utils/utils2.c map_check.c map.c

${NAME}:
			gcc -g ${FLAGS} ${FILES} libmlx.a -o ${NAME}

all:		${NAME}

clean:		
			rm ${NAME}	

fclean:		
			rm ${NAME}	

re:			fclean all	
