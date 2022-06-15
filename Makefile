# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wfermey <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/11 09:41:54 by wfermey           #+#    #+#              #
#    Updated: 2022/06/15 16:43:17 by wfermey          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		cub3d

FLAGS =		

FILES = 	main.c parsing.c utils/utils1.c utils/get_next_line.c \
			utils/split.c color.c map.c utils/utils2.c

${NAME}:
			gcc -g ${FLAGS} ${FILES} -L/usr/local/lib -lmlx -framework OpenGL \
		   	-framework AppKit -o ${NAME}

all:		${NAME}

clean:		
			rm ${NAME}	

fclean:		
			rm ${NAME}	

re:			fclean all	
