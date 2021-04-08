# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dda-silv <dda-silv@student.42lisboa.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/11 09:33:15 by dda-silv          #+#    #+#              #
#    Updated: 2021/04/08 09:59:47 by dda-silv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Name of the program built
NAME_CHECKER		:=		checker
NAME_PUSH_SWAP		:=		push_swap

# Name directory
PATH_SRC			:=		src
PATH_CHECKER		:=		$(PATH_SRC)/checker
PATH_PUSH_SWAP		:=		$(PATH_SRC)/push_swap
PATH_BUILD			:=		build
PATH_LIBFT			:=		libft

# List of sources
SRCS_CHECKER		:=		$(shell find $(PATH_CHECKER) -name *.c)
OBJS_CHECKER		:=		$(SRCS_CHECKER:%.c=$(PATH_BUILD)/%.o)
SRCS_PUSH_SWAP		:=		$(shell find $(PATH_PUSH_SWAP) -name *.c)
OBJS_PUSH_SWAP		:=		$(SRCS_PUSH_SWAP:%.c=$(PATH_BUILD)/%.o)
DEPS				:=		$(OBJS:.o=.d)
INC_DIRS			:=		$(shell find $(PATH_SRC) -type d)

# Compiler
CC					:=		gcc

# Flags - compilation
FLAG_WARNING		:=		-O3 -Wall -Wextra -Werror
FLAG_INC			:= 		$(addprefix -I, $(INC_DIRS))
FLAG_MAKEFILE		:=		-MMD -MP
FLAG_DEBUG			:= 		-g
FLAGS_COMP			:= 		$(FLAG_WARNING) $(FLAG_INC) $(FLAG_MAKEFILE) $(FLAG_DEBUG)

# Flags - memory leak check
FLAG_MEM_LEAK		:= 		-fsanitize=address

# Flags - linking
FLAG_LIBFT			:=		-L$(PATH_LIBFT) -lft 

# Others commands
RM					:=		rm -rf

# Color Code and template code
_YELLOW				:=		\e[38;5;184m
_GREEN				:=		\e[38;5;46m
_RESET				:=		\e[0m
_INFO				:=		[$(_YELLOW)INFO$(_RESET)]
_SUCCESS			:=		[$(_GREEN)SUCCESS$(_RESET)]

# General functions
all:						init $(NAME_CHECKER) $(NAME_PUSH_SWAP)
							@ printf "$(_SUCCESS) Compilation done\n"

init:
							@ printf "$(_INFO) Initialize $(NAME_CHECKER) and $(NAME_PUSH_SWAP)\n"
							@ make -C $(PATH_LIBFT)

$(NAME_CHECKER):			$(OBJS_CHECKER)
							@ $(CC) $(FLAGS_COMP) -o $@ $(OBJS_CHECKER) $(FLAG_LIBFT)

$(NAME_PUSH_SWAP):			$(OBJS_PUSH_SWAP)
							@ $(CC) $(FLAGS_COMP) -o $@ $(OBJS_PUSH_SWAP) $(FLAG_LIBFT)

$(PATH_BUILD)/%.o:	%.c
							@ mkdir -p $(dir $@)
							@ $(CC) $(FLAGS_COMP) -c $< -o $@

bonus:						all

clean:
							@ $(RM) $(PATH_BUILD)
							@ make -C $(PATH_LIBFT) clean
							@ printf "$(_INFO) Deleted files and directory\n"

fclean:						clean
							@ $(RM) $(NAME_CHECKER) $(NAME_PUSH_SWAP)
							@ make -C $(PATH_LIBFT) fclean

re:							fclean all

# Debugging functions

debug:						FLAGS_COMP += $(FLAG_MEM_LEAK)
debug:						re

# Format functions

normH:
							@ norminette $(shell find $(PATH_SRC) -name *.h)
							@ make -C $(PATH_LIBFT) normH

normC:
							@ norminette $(SRCS_CHECKER) $(SRCS_PUSH_SWAP)
							@ make -C $(PATH_LIBFT) normC

norm:						normH normC

.PHONY:						all clean fclean re

-include $(DEPS)

# Source for some pieces of this Makefile: 
# https://makefiletutorial.com/#makefile-cookbook
