#ifndef SHELL_H
# define SHELL_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>

#include <sys/types.h>
#include <sys/wait.h>

typedef struct s_list
{
	int				index;
	int				type;
	char			*content;
	struct s_list	*next;
	struct s_list	*prev;
}					t_list;

typedef struct s_table
{
	int		index;
	char	*cmd;
	char	*options;
	char	*args;
	char	*in_redir;
	char	*out_redir;
	char	*mode_out;
}			t_table;

/*---PROTOTYPES---*/
/* main.c */
void	print_that_table(t_table *array, int count); //tmp

/* new_split.c */
char	**ft2_split(char *str);

/* libft_utils.c */
int		ft2_strlen(char *str);
int		ft2_strncmp(const char *s1, const char *s2, size_t n);
void	*ft2_memccpy(void *dest, const void *src, int c, size_t n);
char	*ft2_strjoin(char *s1, char *s2);
char	*ft2_substr(char const *s1, unsigned int start, size_t len);
void	ft2_bzero(void *s, size_t n);

/* list_utils.c */
void	new_print_list(t_list **head);	//tmp
void	print_list(t_list **head);		//tmp
t_list	*ft2_lstnew(char *content, int nbr, int type);
void	ft2_lstadd_back(t_list **head, t_list *new);
void	ft2_clean_list(t_list *head);

/* parse_quotes.c */
void	new_find_quotes(t_list **head);
void	check_for_dollah(t_list **head);

/* parse_quotes2.c */
void	remove_quotes_from_args(t_list **head); //tmp this can be done better.
int		merge_quoted_shit(t_list **head, int skip, char c);

/* parser00.c */
int		count_cmds(t_list **head);
t_table	*handle_that_list(t_list **head);
t_table	*parse_that_input(char *user_input);

/* lst_parsing_utils.c */
void	set_prev_pointers(t_list **head);
// void	some_func_for_rest(t_list **head);	//changed to static
// void	set_list_types(t_list **head);		//changed to static
void	set_list_types_redir(t_list **head);

#endif
