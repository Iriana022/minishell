/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irazafim <irazafim@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 09:57:02 by irazafim          #+#    #+#             */
/*   Updated: 2024/10/17 15:21:08 by irazafim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <errno.h>

void    cd_minishell(char *argv[])
{
    if (chdir(argv[1]) == ENOENT)
        printf("No such file or directory");
    else
        chdir(argv[1]);
}
