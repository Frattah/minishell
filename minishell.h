#ifndef MINISHELL_H
# define MINISHELL_H
# include <stdio.h>
# include <stdlib.h> // free malloc getenv
# include <unistd.h> // getcwd
# include <readline/readline.h> // readline 

typedef struct s_cmd
{
	int				fdin;
	int				fdout;
	char			**args;
	char			*path;
}	t_cmd;

//-------------------------------------------------------------------------

typedef struct s_entry {
   char	*key;
   char	*val;
   struct s_entry* next;
} t_entry;

typedef t_entry	*t_lst;

t_entry	*init_entry(char *key, char *val);
t_entry *get_lst(t_lst l, char *key);
void	put_lst(t_lst l, char *key, char *val);
void	remove_lst(t_lst l, char *key);

// ---------------------------------------------------------------------------

typedef struct s_shell
{
	t_lst	en;
}	t_shell;

t_shell	*init_shell(char **en);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int	first_occ(char *str, char c);

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	cntword(char const *s);
char	*skpstr(char *s);
size_t	word_len(const char *s);
char	**ft_split(char const *s);

size_t	ft_strlen(const char *s, char c);
int	ft_strncmp(const char *s1, const char *s2, size_t n);
int	is_space(char c);

char	*find_env_var(t_lst en, char *key);
void	expand(char **args, t_lst en);
char	*delimit_env(char *s);

void	free_split(char **args);
void	free_lst(t_lst l);

void	cd(char *path, t_lst en);
void	unset(char *key, t_lst en);
void	env(t_lst en);
void	pwd(t_lst en);
void	echo(char **args);

void	export(char *entry, t_lst en);

void	main_loop(void);
#endif
