/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khallal <khallal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 15:41:21 by hrakik            #+#    #+#             */
/*   Updated: 2023/03/27 22:58:59 by khallal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <fcntl.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <stdio.h>
# include <stdlib.h>
# include <termios.h>
# include <unistd.h>
# include <dirent.h>

typedef struct s_divide_input
{
	char				**infile;
	char				**outfile;
	char				**full_cmd;
	int					out_open;
}						t_divide;

typedef struct s_expnd
{
	char				*iren;
	char				*cmd;
	char				*str;
	int					pos;
	int					size;
	int					m;
	int					t;
	int					y;
	int					all;
}						t_expnd;

typedef struct s_data
{
	char				**full_cmd;
	char				**infile;
	char				**outfile;
	int					out_open;
	struct s_data		*next;
}						t_data;
typedef struct s_list1
{
	char				*data;
	struct s_list1		*next;
}						t_list1;
typedef struct s_here_doc
{
	int					x;
	struct s_here_doc	*next;
}						t_here_doc;

typedef struct s_minishell
{
	int					q;
	char				**a;
	char				**k;
	char				**env;
	char				*cmd;
	int					i;
	int					fd;
	int					fd1;
	int					j;
	int					her;
	int					fail_open;
	int					pid;
	int					track;
	int					h;
	int					fdp[2];
	int					*exits;
	char				*cmds_redline;
	t_here_doc			*x;

}						t_minishell;
int				g_exit_status;

int						ft_strcmp_un(char *tmp, char *mv);
int						helper_var_count_spt(char *s, int i);
void					check_if_ambiguous(char **s, char **env);
void					signal_ctr(int sig);
char					**ft_split(char *s, char c);
char					*ft_substr(char const *s,
							unsigned int start, size_t len);
void					ft_putchar_fd(char c, int fd);
void					ft_putstr_fd(char *s, int fd);
int						ft_isascii(int c);
char					*ft_strjoin(char const *s1, char const *s2);
void					ft_putendl_fd(char *s, int fd);
char					*ft_strchr(char *s, int c);
char					*ft_strtrim_1(char const *s1, char const *set);
char					*ft_strtrim(char *s1, char *set);
int						ft_strcmp_1(const char *s1, const char *s2);
int						ft_strncmp(const char *s1,
							const char *s2, size_t n, int i);
size_t					ft_strlen(const char *s);
char					*ft_strdup(const char *s1);
char					*ft_itoa(int n);
int						ft_isdigit(int c);
int						ft_isalpha(int c);
int						ft_isalnum(int c);
int						ft_atoi(const char *str);
void					*ft_calloc(size_t count, size_t size);
void					ft_bzero(void *s, size_t n);
void					init_signals(void);
void					handle_global_signal_2(int sig);
void					end_of_pg(void);
void					handle_global_signal(int sig);
char					*handle_signal_1(void);
void					ft_free(char **k);
void					ft_free_her(t_here_doc *x);
void					ft_freema(t_data **data);
void					close_heredoc(t_here_doc **x);
void					count_heredoc(t_data **data);
void					init(t_minishell *mini);
int						ft_check_empt(char *s);
int						ft_last(t_here_doc **her);
void					envcpy_helper(char **env, t_list1 **m,
							t_list1 **export);
char					**ft_split(char *s, char c);
char					**expand_Path(char **a, char **env);
char					**ft_fill_list(char **av, char *s, int i, int len);
void					msg_err(char *err);
void					msg_error(char *err);
void					msg_err_cmd(char *s);
void					msg_err_cmd_seconde(char *s, char *s2);
int						count_var_2(char *s, int index);
int						if_sp_char(char c);
int						count_set(char *s, int i, char c);
int						ft_not_sp_chr(char c);
char					*hold_sin_quots(char *s, int i, char c);
char					*hold_var_env(char *s, int i);
char					*hold_string(char *s, int i);
char					**split_str(char *s, int i, int j);
int						ft_split_count_str(char *s);
int						ft_cherche_new(char *s);
char					*expand_herdoc(char *a, char **env);
int						check_argument(char **a);
void					ft_free_1(char **str);
void					check_if_ambiguous_inf(char **s);
int						ft_tokens(char c);
void					ft_lstdelone1(t_data *lst, void (*del)(char **));
int						ft_strlen_sp(char *s, int index);
int						count_pipe(char **av);
int						find_first_node(char **av, int b);
int						find_pipe(char **av, int i);
char					**check_outfile(char **av, int b, int y);
char					**check_infile(char **av, int b, int y);
int						ft_search(char *s, char c);
char					*fill_inf_out(char *av, char *cmd, int her);
int						count_inf_out(char **av, int b, int y, char r);
char					*fill_inf_out_helper(char *av, char *cmd, int her,
							char c);
int						count_inf_out(char **av, int b, int y, char r);
char					*fill_inf_out_helper(char *av, char *cmd, int her,
							char c);
char					*fill_inf_out(char *av, char *cmd, int her);
int						ft_search(char *s, char c);
int						check_if_in_out(char *s);
int						ft_herdoc(char *s, int i);
void					check_if_ambiguous(char **s, char **env);
int						ft_check_quots(char *s);
int						ft_skip(char *s, int i);
int						ft_search_exp(char *s, char c);
int						ft_cherche(char *s, char c);
int						ft_cherche_me(char *s, char c, char f);
int						find_vare_2(char *s, int index);
int						count_var(char *s, int index);
char					*skip_var(char *yum);
int						ft_count_len(char *s, int index, char c);
char					*ft_copy_str(char *s, int index, int len, char *b);
char					*ft_copy_str_1(char *s, int index, int len);
char					*linke_str(t_expnd *exp);
char					*change_string(char *cmd, char *s, int count);
int						check_the_env(char *s1, char *s2, int df);
char					*split_str_vers(char *s, int index);
char					**split_with_dol(char *s, int nb);
char					*handle_global_signal_1(void);
int						count_dollar(char *s);
int						find_set(char *s, int i, char c);
char					**ft_free_10(char **h);
char					*epur_str(char *cmd);
char					**ft_cmdtrim(char const *s, char *set);
char					**break_cmd(char *s);
int						count_word(char *s, int i);
void					ft_cmdsubsplit(char *s, char *set);
void					divide_input(char **av, t_data **data);
void					create_node(t_data **data, t_divide *dive);
t_data					*l_lstlast(t_data **lst);
t_data					*l_lstnew(t_divide *dive);
void					l_lstadd_back(t_data **lst, t_data *new);
void					l_lstadd_back(t_data **lst, t_data *new);
int						l_lstsize(t_data *lst);
int						skip_infile(char **s);
void					multiple(t_data *m, char **env);
size_t					ft_strlen0(char *s);
char					*ft_strjoin0(char *s1, char *s2);
int						ft_strcmp_un(char *tmp, char *mv);
char					**split_path(char **env);
char					*ft_access(char **s_path, char *cmd);
void					divide_input_2(char **av, t_data **data, char **env);
void					mul_pipe(t_data **data, t_minishell *mini, t_list1 **m,
							t_list1 **export);
int						ft_pwd(int fd1);
void					ft_lstdelone1(t_data *lst, void (*del)(char **));
int						ft_strcmp(char *tmp, char *mv);
int						count_inf_open(char **av, int b, int y);
int						here_doc_open(t_data **data, t_minishell *mini);
t_here_doc				*ft_lstnew0(int content);
int						ft_last(t_here_doc **her);
int						check_heredoc(char **k, int i);
int						here_doc(char *dat, char **env);
void					open_outfile(t_minishell *mini, t_data **data);
void					open_infile(t_minishell *mini, t_data **data,
							t_here_doc **x, char **env);
void					ft_lstadd_back3(t_here_doc **lst, t_here_doc *new);
void					open_infile_multiple(t_minishell *mini, t_data **data,
							t_here_doc **x);
int						ft_unset(t_list1 **head_ref, t_list1 **export,
							t_data *data);
int						ft_export(t_data *data, t_list1 **m, t_list1 **export);
t_list1					*ft_lstnew1(char *content);
int						builtin(t_data *data, t_list1 **m, t_list1 **export,
							t_minishell *mini);
int						is_builtin(char *k);
int						ft_exit(t_data *data);
int						count_var(char *s, int index);
int						ft_cherche(char *s, char c);
char					*env_var_2(char **k, char **env);
char					**expand_path_2(char **a, char **env);
char					*expande_var(char *s, char **env, int nb, int i);
void					sort_export(t_list1 **export);
int						ft_atoi_exit(char *str);
char					**list_tabl(t_list1 **m);
int						ft_lstsize2(t_list1 *lst);
int						ft_strncmp1(const char *s1, const char *s2,
							unsigned int n);
void					one_command(t_data **data, t_minishell *mini,
							t_list1 **m, t_list1 **export);
void					envcpy(char **env, t_list1 **m);
int						print_env(t_list1 **m, int fd1);
int						ft_echo(t_data *data, int fd1);
int						ft_cd1(t_list1 **m, t_data *data);
void					rl_replace_line(const char *str, int undo);
int						print_exp_oonly(t_list1 **m, int fd1);
char					*check_ex_(t_list1 **m, char *str);
int						ft_strcmp_ex(char *tmp, char *mv);
char					*cherch(t_list1 **m, char *str);
char					*ft_add(char *add, t_list1 **m);
int						check(char *k);
int						check11(char *k);
int						check_data11(t_data *data, int i);
char					*uns(char *k);
char					*check_ex_add(t_list1 **m, char *str);
char					*ft_rem_plus(char *k);
char					*plus_egal(char *k);
int						check_pleg(char *k);
int						check_data(t_data *data, int i);
void					export1(t_data *data, t_list1 **m, t_list1 **export,
							int i);
void					export2(t_data *data, t_list1 **m, t_list1 **export,
							int i);
void					export3(t_data *data, t_list1 **m, t_list1 **export,
							int i);
void					export4(t_data *data, t_list1 **m, t_list1 **export,
							int i);
void					export5(t_data *data, t_list1 **m, t_list1 **export,
							int i);
int						open_infile_builtin(t_minishell *mini, t_data **data,
							t_here_doc **x);
int						ft_unset1(t_list1 **head_ref, char *key);
int						count_dollar(char *s);
void					ft_free(char **k);
void					here_doc_open1(t_data *tmp, t_minishell *mini);
int						her_norm(t_minishell *mini, int j);
int						ft_strcmp1(char *tmp, char *mv);
char					*cd_home(t_list1 **m);
void					first_command(t_minishell *mini, t_data **data,
							t_list1 **m, t_list1 **export);
void					last_command(t_minishell *mini, t_data **data,
							t_list1 **m, t_list1 **export);
void					ft_hhh(t_list1 **m, t_list1 **export, char *s);
void					rl_replace_line(const char *str, int undo);
int						ft_strcmp_un1(char *tmp, char *mv);
void					ft_here(struct termios a2, char **env,
							char *lim, int fdp);
void					doc(int sin);
void					here_doc1(char **env, char *lim, int fdp);

#endif
