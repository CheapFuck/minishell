#include "header.h"


void	handle_chdir(char *str)
{
	char *s = NULL;

	if (!str)
		return ;
	printf("old dir: ");
	printf("%s\n", getcwd(s, 100));

	if (chdir(str) != 0)
		perror("chdir() failed"); 

	printf("new dir: ");
	printf("%s\n", getcwd(s, 100));

	free(s);
}

// void	handle_chdir(char *str)
// {
// 	char s[100];

// 	if (!str)
// 		return ;
// 	printf("current dir: ");
// 	printf("%s\n", getcwd(s, 100));

// 	if (ft_strncmp(str, "..", ft_strlen(str)) == 0)
// 	{
// 		chdir("..");
// 		printf("new dir: ");
// 		printf("%s\n\n", getcwd(s, 100));
// 	}

// 	// misschien chdir(<insert str>) =? maar str validation ?
// }