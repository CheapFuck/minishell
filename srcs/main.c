#include "header.h"

int main(void)
{
	char *user_input;
	int i = 0;
	
	printf("PATH : %s\n", getenv("PATH"));
	printf("HOME : %s\n", getenv("HOME"));
	printf("ROOT : %s\n", getenv("ROOT"));
	
	// test readline.
	while(i < 3)
	{
		printf("%d - ", i);
		user_input = readline("Enter text: ");
		add_history(user_input);
		printf("%s", user_input);
		printf("\n");
		i++;
	}
	return (0);
}