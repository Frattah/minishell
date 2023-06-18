#ifndef MINISHELL_H
# define MINISHELL_H
# include <stdio.h>
# include <stdlib.h> // free malloc
# include <unistd.h> // getcwd

typedef struct s_cmd
{
	int				fdin;
	int				fdout;
	char			**args;
	char			*path;
}	t_cmd;

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	cntword(char const *s);
char	*skpstr(char *s);
size_t	word_len(const char *s);
char	**ft_split(char const *s);

size_t	ft_strlen(const char *s, char c);
int	ft_strncmp(const char *s1, const char *s2, size_t n);

char	*find_env_var(char **envp, char *var);
void	*expand(char **args, char **en);
char	*delimit_env(char *s);

int		cmd_count(char **args);

void	free_split(char **args);

void	cd(char *path, char **en);
void	env(char **en);
void	pwd(char **en);
void	echo(char **args, char **en);

#endif
