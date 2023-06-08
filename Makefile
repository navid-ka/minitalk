# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nkeyani- < nkeyani-@student.42barcelona    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/08 15:03:56 by nkeyani-          #+#    #+#              #
#    Updated: 2023/06/08 16:30:26 by nkeyani-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER = server
CLIENT = client
CFLAGS = -Wall -Werror -Wextra
OBJECTS_SRV = server.c
OBJECTS_CLNT = client.c
COLOR_RESET = \033[0m
COLOR = \033[32m
KAOMOJI_SUCCESS = (づ ᴗ _ᴗ)づ♡
KAOMOJI_REMOVE = (ノಠ益ಠ)ノ彡┻━┻

server: ${OBJECTS}
	@cc ${CFLAGS} ${OBJECTS_SRV} -o ${SERVER}
	@printf "$(COLOR)Server program compiled successfully!$(COLOR_RESET)\n"

client: ${OBJECTS}
	@cc ${CFLAGS} ${OBJECTS_CLNT} -o ${CLIENT}
	@printf "$(COLOR)Client program compiled successfully!$(COLOR_RESET)\n"

all: ${CLIENT} ${SERVER}

fclean: clean
	@rm -rf  ${CLIENT} ${SERVER}
	@printf "$(COLOR)Cleaned directory! $(KAOMOJI_REMOVE)$(COLOR_RESET)\n"

clean:
	@rm -f ${OBJECTS_CLNT} ${OBJECTS_SRV}
	@printf "$(COLOR)Cleaned object files! $(KAOMOJI_REMOVE)$(COLOR_RESET)\n"

re: fclean all

git: fclean
	@echo "Commit:"
	@read MSG; \
	git commit -am "$$MSG"
	git push

.PHONY: clean all fclean re server client