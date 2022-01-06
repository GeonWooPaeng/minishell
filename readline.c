/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsok <hyeonsok@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 10:53:34 by hyeonsok          #+#    #+#             */
/*   Updated: 2021/10/18 18:53:07 by hyeonsok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <readline/readline.h>
#include <readline/history.h>


//https://tiswww.case.edu/php/chet/readline/rltop.html
//snprintf

/*
Always use the proper secure idiom:
			snprintf(buffer, sizeof(buffer), "%s", string);
*/

/*
**	[Sample Code](https://en.wikipedia.org/wiki/GNU_Readline)
**	int main()
**	{
**		char* input, shell_prompt[100];
**	
**		// Configure readline to auto-complete paths when the tab key is hit.
**		rl_bind_key('\t', rl_complete);
**	
**		for(;;) {
**			// Create prompt string from user name and current working directory.
**			snprintf(shell_prompt, sizeof(shell_prompt), "%s:%s $ ", getenv("USER"), getcwd(NULL, 1024));
**	
**			// Display prompt and read input (n.b. input must be freed after use)...
**			input = readline(shell_prompt);
**	
**			// Check for EOF.
**			if (!input)
**				break;
**	
**			// Add input to history.
**			add_history(input);
**	
**			// Do stuff...
**	
**			// Free input.
**			free(input);
**		}
**	}
*/

void	sighandler(int signum)
{
	if (signum != SIGINT)
		return ;
	write(1, "\n", 1);
	rl_replace_line("", 1);
	rl_on_new_line();
	rl_redisplay();
}

int		main(void)
{
	char	*input;
	char	*shell_prompt[100];

	signal(SIGINT, sighandler);
	while (1)
	{
		snprintf((char *)shell_prompt, sizeof(shell_prompt), "%s:%s $ ", getenv("USER"), getcwd(NULL, 1024));
		input = readline((const char *)shell_prompt);
		if (input == NULL)
			break ;
		add_history(input);
		free(input);
	}
	return (0);
}
