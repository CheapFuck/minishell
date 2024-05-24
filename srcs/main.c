#include "header.h"

int main(void)
{
	char *user_input;
	int i = 0;
	while(i < 3)
	{
		user_input = readline("Enter text: ");
		add_history(user_input);
		printf("%s", user_input);
		printf("\n");
		i++;
	}
	return (0);
}