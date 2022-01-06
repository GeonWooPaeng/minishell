# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include <readline/readline.h>
# include <readline/history.h>

void    handler(int signum)
{
    if (signum == SIGINT)
    {
        // printf("\n");
        // rl_on_new_line();
        // rl_replace_line("ddd", 0);
        // rl_redisplay();
    }
}

int main(int argc, char *argv[])
{

    for (int i = 0; i < argc; i++) {
        printf("*argv >> %s\n", *argv);
        argv++;
    }
    
}
