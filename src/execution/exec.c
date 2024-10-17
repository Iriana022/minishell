/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irazafim <irazafim@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 11:56:52 by irazafim          #+#    #+#             */
/*   Updated: 2024/10/17 15:24:27 by irazafim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

//eg: echo donto > output.txt

void redirect_in_builtins(char *out, char *filename)
{
    int fd;

    fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0666);
    if (fd == -1)
    {
        perror("Couldn't open file");
        return ;
    }
    dup2(fd, STDOUT_FILENO);
    close(fd);
}

void	exec_command(char *cmd, char **argv, char **env)
{
	if (ft_strncmp(cmd, "echo", 4) == 0)
		echo_minishell(argv);
	else if (ft_strncmp(cmd, "env", 3) == 0)
		env_minishell(env);
	else if (ft_strncmp(cmd, "pwd", 3) == 0)
		pwd_minishell();
}


void	exec_ast(t_ast *ast, char **env)
{
	int		fd;
	pid_t	pid;

	if (!ast)
		return ;
	exec_ast(ast->left, env);
	exec_ast(ast->right, env);
	if (ast->identifier == RIGHT_REDIRECTION)
	{
		pid = fork();
		if (pid == 0)
		{
			fd = open(ast->right->text, O_WRONLY | O_CREAT | O_TRUNC, 0666);
			if (fd == -1)
			{
				perror("Error open");
				return ;
			}
			dup2(fd, STDOUT_FILENO);
			close(fd);
			exec_command(ast->left->text, ast->left->argv, env);
			exit(EXIT_SUCCESS);
		}
		else
			wait(NULL);
	}
}
