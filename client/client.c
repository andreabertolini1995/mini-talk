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

int main(int argc, char **argv)
{
    pid_t   server_pid;
    char    *str;

    server_pid = ft_atoi(argv[1]);
    str = argv[2];
    ft_printf("Number of arguments: %d\n", argc - 1);
    ft_printf("Server PID: %d\n", server_pid);
    ft_printf("String: %s\n", str);
    ft_printf("Signal: %d\n", kill(server_pid, SIGUSR1));
    pause();
    signal(SIGUSR1, SIG_IGN); //handling the signals
    
    return (0);
}