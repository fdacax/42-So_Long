/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdacax-m <fdacax-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 15:28:14 by fdacax-m          #+#    #+#             */
/*   Updated: 2024/06/17 15:28:14 by fdacax-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	check_extension(char *file)
{
	char	*extension;

	extension = strrchr(file, '.');
	if(ft_strcmp(extension, ".ber") == 0)
		return (true);
	return (false);
}

bool is_opening(char *file)
{
	int fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (false);
	close(fd);
	return (true);
}

void	cria_pra_mim_gpt(char *file)
{
	if(!check_extension( file))
		printf("Error\nInvalid extension\n");
	if (!is_opening(file))
		printf("Error\nCan't open this file\n");

}

int main(int argc, char *argv[])
{
	(void)argc;
	cria_pra_mim_gpt( argv[1]);

	return 0;
}
