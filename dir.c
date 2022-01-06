/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsok <hyeonsok@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 18:47:25 by hyeonsok          #+#    #+#             */
/*   Updated: 2021/10/17 21:10:24 by hyeonsok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dirent.h>
#include <stdio.h>
#include <errno.h>

/*
The following table lists the types available for d_type and the corresponding ones used in the struct stat (see stat(2)), respectively:

	   Dirent	  Stat		 Description
	   DT_UNKNOWN	  -		 unknown file type
	   DT_FIFO	  S_IFIFO	 named pipe
	   DT_CHR	  S_IFCHR	 character device
	   DT_DIR	  S_IFDIR	 directory
	   DT_BLK	  S_IFBLK	 block device
	   DT_REG	  S_IFREG	 regular file
	   DT_LNK	  S_IFLNK	 symbolic link
	   DT_SOCK	  S_IFSOCK	 UNIX domain socket
	   DT_WHT	  S_IFWHT	 dummy ``whiteout inode''
	   
	   https://www.unix.com/man-page/netbsd/3/DTTOIF/
*/

int	corresnpond_type(struct dirent *dir)
{
	printf("%-24s\t", dir->d_name);
	if (dir->d_type == DT_BLK)
		printf("block device\n");
	else if (dir->d_type == DT_CHR)
		printf("character device\n");
	else if (dir->d_type == DT_DIR)
		printf("directory\n");
	else if (dir->d_type == DT_REG)
		printf("regular File\n");
	else if (dir->d_type == DT_LNK)
		printf("symbolic Link\n");
	else if (dir->d_type == DT_SOCK)
		printf("UNIX domain socket\n");
	else if (dir->d_type == DT_WHT)
		printf("dummy ``whiteout inode''\n");
	else if (dir->d_type == DT_UNKNOWN)
		printf("unkown file type");
	else
		return (1);
	return (0);	
}

int		main(int argc, char *argv[])
{
	DIR				*dirp;
	struct dirent	*file;

	if (argc != 2 || argv[argc - 1] == NULL)
		return (1);
	if ((dirp = opendir(argv[1])) == NULL)
	{
		perror("opendir");
		return (1);
	}
	while (1)
	{
		if ((file = readdir(dirp)) == NULL)
			break ;
		if (corresnpond_type(file) != 0)
			break ;
	}
	if (errno != 0)
		perror("readdir");
	closedir(dirp);
	return (errno);
}
