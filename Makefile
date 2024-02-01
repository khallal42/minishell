NAME = minishell
COM = cc
CFLAGS = -Wall -Wextra -Werror
LDFLAGS= -L ~/goinfre/.brew/opt/readline/lib -lreadline
RM = rm -rf

FUN=    main.c    \
		main_helper_1.c	\
		ft_free_helper.c	\
        synt_err.c  \
        err_msg.c    \
        break_cmd.c    \
        ft_list.c    \
        divide_vers.c    \
		divide_vers_2.c    \
		divide_vers_3.c    \
		divide_vers_4.c    \
        multiple_pipe.c \
        ft_strjoin0.c	\
		ft_putendl_fd.c	\
		ft_isascii.c	\
		ft_putchar_fd.c	\
        mul_pipe.c \
		ft_split.c	\
		ft_strjoin.c	\
		ft_substr.c	\
        ft_pwd.c    \
        break_helper_1.c    \
		break_helper_2.c    \
        open_files.c    \
        here_doc.c \
        get_next_line.c\
        get_next_line_utils.c \
        export.c\
        ft_exit.c    \
        expande_helper_1.c    \
        expande_helper_2.c    \
		expande_helper_3.c    \
		expande_helper_4.c    \
		expande_helper_5.c    \
		expand_helper_6.c    \
		exp_herdoc.c	\
		expande.c    \
        builtin.c \
        ft_env.c \
        mi_utils.c \
        ft_unset.c \
        one_commande.c \
        open_in_out_file.c \
        ft_cd.c \
        ft_echo.c \
        print_export.c \
        export_use1.c\
        export_use2.c \
        export_use3.c \
        export_use4.c \
        mi_utils2.c \
        mi_utils3.c	\
		signals.c	\
		ft_atoi.c	\
		ft_isalnum.c	\
		ft_isalpha.c	\
		ft_isdigit.c	\
		ft_itoa.c	\
		ft_strdup.c	\
		ft_strlen.c	\
		ft_strncmp.c	\
		ft_strtrim_0.c	\
		ft_strtrim.c	\

OBJ= $(FUN:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(COM) $(CFLAGS) $(LDFLAGS) -I ~/goinfre/.brew/opt/readline/include $(OBJ) -o $(NAME)  

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re:    fclean all