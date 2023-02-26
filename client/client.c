/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abertoli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 17:33:54 by abertoli          #+#    #+#             */
/*   Updated: 2022/10/21 18:29:38 by abertoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_talk.h"

static void	send_signals(int *binary, int binary_size, int server_pid)
{
	int	i;

	i = 0;
	while (i < binary_size)
	{
		if (binary[i] == 0)
			kill(server_pid, SIGUSR1);
		else
			kill(server_pid, SIGUSR2);
		i++;
		usleep(100);
	}
}

static void	ascii_to_binary(char *str, int binary_size, int server_pid)
{
	int	i;
	int	*binary;

	i = 0;
	while (str[i] != '\0')
	{
		binary = ft_dec_to_binary(str[i], binary_size);
		send_signals(binary, binary_size, server_pid);
		i++;
	}
	free(binary);
}

int	main(int argc, char **argv)
{
	pid_t	server_pid;
	char	*str;
	int		binary_size;

	(void) argc;
	binary_size = 8;
	server_pid = ft_atoi(argv[1]);
	str = argv[2];
	ascii_to_binary(str, binary_size, server_pid);
	return (0);
}
