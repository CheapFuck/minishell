#include "header.h"

void	handle_signal(int signal, siginfo_t *info, void *ucontext)
{
	(void) ucontext;
	(void) info;

	if (signal == 9)
		printf("no exit\n");
}

void	initialize_signals(void)
{
	struct sigaction	sa;
	sigset_t			set;

	sigemptyset(&set);
	sigaddset(&set, 9);
	sigaddset(&set, 10);
	sa.sa_mask = set;
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = handle_signal;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
}
