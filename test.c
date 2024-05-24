#include "libft/libft.h"
#include <readline/readline.h>
#include <readline/history.h>
#include <stdio.h>
// # include <stdlib.h>

// void main()
// {
//     ft_printf("hoi hallo\n");
// }

// void enableBlinkingCursor() {
//     printf("\033[?12h"); // Enable cursor blinking
// }

// void disableBlinkingCursor() {
//     printf("\033[?12l"); // Disable cursor blinking
// }


// int main() {

// while(1)
//  readline("Enter something: ");    // enableBlinkingCursor();

//     // ft_printf("Blinking cursor enabled. Press Enter to exit...\n");

//     // getchar(); // Wait for user input

//     // disableBlinkingCursor();

//     // printf("Blinking cursor disabled.\n");

//     // return 0;
// }


int main() {
    char *input;
    int status ;
    
    while(1)
    {
        input = readline("myshell> ");
    if (input && *input)
        add_history(input);
    // printf("input = %s\n", input);
    // status = system(input);
    if (ft_strncmp(input, "echo -n", ft_strlen(input)) == 0)
        printf("echo min n\n");
    if (ft_strncmp(input, "cd", ft_strlen(input)) == 0)
        printf("cd\n");
    if (ft_strncmp(input, "pwd", ft_strlen(input)) == 0)
        printf("pwd\n");
    if (ft_strncmp(input, "export", ft_strlen(input)) == 0)
        printf("export\n");
    if (ft_strncmp(input, "unset", ft_strlen(input)) == 0)
        printf("unset\n");
    if (ft_strncmp(input, "env", ft_strlen(input)) == 0)
        printf("env\n");
    if (ft_strncmp(input, "exit", ft_strlen(input)) == 0)
        printf("exit\n");
    }
    free(input);

    return 0;
}