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

static void	initialize_array(int *arr)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		arr[i] = -1;
		i++;
	}
}

static int	ft_binary_to_dec(int *binary, int binary_size)
{
	int	i;
	int	n;

	n = 0;
	i = 0;
	while (i < binary_size)
	{
		if (binary[i] == 1)
			n = n * 2 + 1;
		else if (binary[i] == 0)
			n = n * 2;
		i++;
	}
	return (n);
}

static void	store_signals(int n, int signals[8])
{
	int	i;

	i = 0;
	while (signals[i] != -1)
		i++;
	signals[i] = n;
	if (i == 7)
	{
		ft_printf("%c", ft_binary_to_dec(signals, 8));
		initialize_array(signals);
	}
}

static void	sig_handler(int signo)
{
	static int	signals[8] = {-1, -1, -1, -1, -1, -1, -1, -1};

	if (signo == SIGUSR1)
		store_signals(0, signals);
	else if (signo == SIGUSR2)
		store_signals(1, signals);
	pause();
}

int	main(void)
{
	pid_t				process_id;
	struct sigaction	sigact;

	sigemptyset(&sigact.sa_mask);
	sigact.sa_flags = 0;
	sigact.sa_flags = sigact.sa_flags | SA_NODEFER;
	sigact.sa_handler = sig_handler;
	sigaction(SIGUSR1, &sigact, NULL);
	sigaction(SIGUSR2, &sigact, NULL);
	process_id = getpid();
	ft_printf("%d\n", process_id);
	pause();
	return (0);
}
