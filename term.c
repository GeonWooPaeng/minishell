/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsok <hyeonsok@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 21:12:37 by hyeonsok          #+#    #+#             */
/*   Updated: 2021/10/18 10:37:49 by hyeonsok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <term.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>

/*
Try using functions:
		isatty, ttyname, ttyslot
		https://man7.org/linux/man-pages/man3/ttyslot.3.html
*/
int	main(int argc, char *argv[])
{
	char	*name;
	int		fd;

	if (argc != 2 || argv[1] == NULL)
		return (1);
	fd = atoi(argv[1]);
	if (isatty(fd) == 0)
	{
		perror("isatty");
		return (errno);
	}
	printf("fd[%d] is connected to ", fd);
	if ((name = ttyname(fd)) == NULL)
	{
		perror("ttyname");
		return (errno);
	}
	printf("%s\n", name);
	printf("ttyslot() returned `%d'\n", ttyslot());
	return (0);
}
