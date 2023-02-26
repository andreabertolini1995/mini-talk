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

int	*g_signals;

static void	initialize_array(int *arr, int binary_size)
{
	int	i;

	i = 0;
	while (i < binary_size)
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

static void	store_signals(int n)
{
	int	i;

	i = 0;
	while (g_signals[i] != -1)
		i++;
	g_signals[i] = n;
	if (i == 7)
	{
		ft_printf("%c", ft_binary_to_dec(g_signals, 8));
		initialize_array(g_signals, 8);
	}
}

static void	sig_handler(int signo)
{
	if (signo == SIGUSR1)
		store_signals(0);
	else if (signo == SIGUSR2)
		store_signals(1);
	pause();
}

int	main(void)
{
	pid_t				process_id;
	struct sigaction	sigact;
	int					binary_size;

	binary_size = 8;
	g_signals = (int *) malloc (sizeof(int) * binary_size);
	if (g_signals == NULL)
		return (0);
	initialize_array(g_signals, binary_size);
	sigemptyset(&sigact.sa_mask);
	sigact.sa_flags = 0;
	sigact.sa_flags = sigact.sa_flags | SA_NODEFER;
	sigact.sa_handler = sig_handler;
	sigaction(SIGUSR1, &sigact, NULL);
	sigaction(SIGUSR2, &sigact, NULL);
	process_id = getpid();
	ft_printf("%d\n", process_id);
	pause();
	free(g_signals);
	return (0);
}
