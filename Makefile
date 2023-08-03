# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nkeyani- < nkeyani-@student.42barcelona    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/08 15:03:56 by nkeyani-          #+#    #+#              #
#    Updated: 2023/07/23 19:19:20 by nkeyani-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER = $(BINDIR)/server
CLIENT = $(BINDIR)/client
CFLAGS = -Wall -Werror -Wextra -MMD -L./$(LIBFT) libft/bin/libft.a -I./$(LIBFT)
LIBFT= libft/
SRCDIR = src
OBJDIR = obj
BINDIR = bin
OBJECTS_SRV = server.c
OBJECTS_CLNT = client.c
COLOR_RESET = \033[0m
COLOR = \033[32m
KAOMOJI_SUCCESS = (づ ᴗ _ᴗ)づ♡
KAOMOJI_REMOVE = (ノಠ益ಠ)ノ彡┻━┻

SOURCES = $(OBJECTS_SRV) $(OBJECTS_CLNT)
OBJECTS = $(patsubst $(SRCDIR)/%.c,$(OBJDIR)/%.o,$(SOURCES))

DEPS = $(patsubst $(OBJDIR)/%.o,$(OBJDIR)/%.d,$(OBJECTS))

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@printf "$(COLOR)\rCompiling (╮°-°)╮┳━┳ : $(COLOR_RESET)$<"
	@mkdir -p $(@D)
	@gcc $(CFLAGS) -c $< -o $@

${SERVER}: ${OBJDIR}/server.o
	@mkdir -p $(@D)
	@$(MAKE) -C include/libft
	@gcc $(CFLAGS) -o ${NAME} ${OBJECTS} -Linclude/libft include/libft/bin/libft.a
	@printf "\n$(COLOR)$(KAOMOJI_SUCCESS) Successfully compiled SERVER!$(COLOR_RESET)"

${CLIENT}: ${OBJDIR}/client.o
	@mkdir -p $(@D)
	@$(MAKE) -C include/libft
	@gcc $(CFLAGS) -o ${NAME} ${OBJECTS} -Linclude/libft include/libft/bin/libft.a
	@printf "\n$(COLOR)$(KAOMOJI_SUCCESS) Successfully compiled SERVER!$(COLOR_RESET)"

-include $(DEPS)

all: ${SERVER} ${CLIENT}

fclean: clean
	@rm -rf ${BINDIR}
	@$(MAKE) -C include/libft fclean

clean:
	@echo "$(COLOR)$(KAOMOJI_REMOVE)$(COLOR_RESET)"
	@rm -rf ${OBJDIR}

re: fclean all

pull: 
	git submodule update --recursive --remote
	@printf "\n$(COLOR)$(KAOMOJI_SUCCESS) Pull submodule success!$(COLOR_RESET)"
	git pull

git: fclean
	git submodule update --recursive --remote
	@echo "Pulled recursive"
	@echo "Commit:"
	@read MSG; \
	git commit -am "$$MSG"
	git push

.PHONY: clean all fclean re git pull