/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minishell.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: thivan-d <thivan-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/23 17:29:14 by thivan-d      #+#    #+#                 */
/*   Updated: 2024/06/07 16:20:40 by thivan-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "minishell.h"
#include "libft/libft.h"
#include <readline/readline.h>
#include <readline/history.h>

typedef void (*Handler)(void);    /* A pointer to a handler function */

/* The functions */
void builtin_echon (void) { printf( "echon\n" ); }
void builtin_cd (char *location) 
{
    //     char s[100]; 
    //  printf("%s\n", getcwd(s, 100)); 
 
    // using the command 
    // chdir(".."); 
 
    // printing current working directory 
    // printf("%s\n", getcwd(s, 100)); 


        chdir(location); 
    // printf( "cd\n" );
}
void builtin_pwd (void)
{
    printf("%s",getenv("PWD"));
    // printf( "pwd\n" );
}
void builtin_export (void) { printf( "export\n" ); }
void builtin_unset (void) { printf( "unset\n" ); }
void builtin_env (void) { printf( "env\n" ); }

// void builtin_env (char *envp)
// { 
//     printf( "%s\n",envp );
// }

void builtin_exit (void) { printf( "exit_builtin\n" ); }

enum{
    ECHON,
    CD,
    PWD,
    EXPORT,
    UNSET,
    ENV,
    EXIT
};

// Handler jump_table[7] = {builtin_echon, builtin_cd, builtin_pwd, builtin_export, builtin_unset, builtin_env, builtin_exit};

// int main (int argc, char **argv) {
int main (int argc, char **argv, char **envp)
{


      char *input;
    int status ;
    	char *s = NULL;
            // char s[100]; 

printf("DOE IETSS!!!\n");
      while(1)
    {
        // printf("%s",getcwd(s, 100));
        printf("minishell");
        input = readline("\\> ");
    if (input && *input)
        add_history(input);
   
    if (ft_strncmp(input, "cd", 2) == 0)
    {
        builtin_cd ("..");
    }
     if (ft_strncmp(input, "pwd", 3) == 0)
    {
        ft_pwd();
    }
  if (ft_strncmp(input, "env", 3) == 0)
   {
        // printf( "envp = %s\n",*envp );
        // printf("PATH : %s\n", getenv("HOME"));
    //    printf("HOME : %s\n", getenv("HOME"));
    //   printf("ROOT : %s\n", getenv("ROOT"));
     ft_env(envp);
   }
     if (ft_strncmp(input, "echo -n", 7) == 0)
   {
     ft_echo(input, envp);
  }
    if (ft_strncmp(input, "exit", 4) == 0)
        ft_exit();
    

//    printf("ft_strlen(input) = %i\n",ft_strlen(input) );
//     printf("ft_strncompare(input)) = %i\n", ft_strncmp("ls", "ls", ft_strlen(input)));
   
    if (ft_strncmp(input, "ls", 2) == 0)
{
    printf("LSS\n");
  pid_t pid = fork();


    if (pid == -1) {
        // Fork failed
        perror("fork");
        return 1;
    } else if (pid == 0) {
        // Child process
        char *args[] = {"ls", "-a", NULL};
        execve("/bin/ls", args, envp);
        // If execve returns, it means an error occurred
        perror("execve");
        return 1;
    } else {
        // Parent process
        int status;
        waitpid(pid, &status, 0);
        if (WIFEXITED(status)) {
            printf("Child process exited with status %d\n", WEXITSTATUS(status));
        } else {
            printf("Child process terminated abnormally\n");
        }
    //    printf("ft_strlen(input) = %i\n",ft_strlen(input) );
    // printf("ft_strncompare(input)) = %i\n", ft_strncmp("en", "env", ft_strlen(input)));
    //   printf("minishell");
    //     input = readline("\\> ");
    }
    
}
}

    



    free(input);
    return 0;
}