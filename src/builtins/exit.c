/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irazafim <irazafim@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 07:35:40 by irazafim          #+#    #+#             */
/*   Updated: 2024/10/17 15:30:46 by irazafim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void    exit_minishell(char **argv)
{
	int exit_code;

	exit_code = 0;
	if (argv != NULL && argv[1] != NULL)
		exit_code = ft_atoi(argv[1]);
	exit(exit_code);
}
