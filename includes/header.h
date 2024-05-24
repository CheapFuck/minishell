#ifndef SHELL_HEAD
# define SHELL_HEAD

#define _POSIX_SOURCE

# include <stdio.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>

# include <asm-generic/signal.h>
# include <asm-generic/siginfo.h>
# include <bits/types/sigset_t.h>

void	initialize_signals(void);

#endif
