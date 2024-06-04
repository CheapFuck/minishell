#ifndef SHELL_H
# define SHELL_H

/*---LIBRARIES---*/
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
}					t_list;

/*---Signal stuff---*/
// # include <asm-generic/signal.h>
// # include <asm-generic/siginfo.h>
// # include <bits/types/sigset_t.h>

/*---PROTOTYPES---*/
/* main.c */

/* new_split.c */
char	**ft_split(char *str);

/* libft_utils.c */
int		ft_strlen(char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	*ft_memccpy(void *dest, const void *src, int c, size_t n);
char	*ft_strjoin(char *s1, char *s2);

/* list_utils.c */
void	print_list(t_list **head); //tmp;
t_list	*ft_lstnew(char *content, int nbr);
void	ft_lstadd_back(t_list **head, t_list *new);
int		ft_lstsize(t_list *head);
t_list	*ft_lstlast(t_list *lst);
void	clean_list(t_list *head);

/* changedir.c */
void	handle_chdir(char *str);

/* new_test.c */
void	check_spelling(t_list **head);

#endif
