/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dictionnary.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoste <acoste@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 23:59:26 by acoste            #+#    #+#             */
/*   Updated: 2025/10/07 00:47:21 by acoste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DICTIONNARY_H
# define DICTIONNARY_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

typedef struct s_dico
{

	char *first_part;
	char *second_part;
	struct s_dico	*next;

}	t_dico;

//packet
int	compose_number(char *nb, t_dico **dico);
char	*next_words(char *nb, t_dico **dico);
char	*first_nb(int diff, char *nb, char *str, t_dico **dico);
int	search_book_index1(char c1, char *nb, t_dico **dico, char **ns);
int	search_book_index2(char c1, char *nb, t_dico **dico, char **ns);
int	search_book_index3(char c1, char *nb, t_dico **dico, char **ns);

//utils
int		ft_strlen(char *str);
void	ft_putstr(char *str);
void	ft_putchar(char c);
int		err(char *str);
int		err_nbr(char *str, int e);
void	ft_putnbr(int nb);
char	*parse_nb(char *nb);


//ft_split
char	**ft_split(char const *s, char c);
void	free_split(char **split);
char	**split_du_pauvre(char *str, char c);
void	tab_split(char **tab, char *str, char c);
void	write_words2(char *tab, char*s, char c);
void	write_words(char *tab, char*s, char c);

//split_pauvre
int	translate_dictionnary(char *nb);


//gnl
char	*get_next_line(int fd);
char	*ft_malloc(int height);
int		ft_search(char *str, char c);

//chain
t_dico	*ft_lstnew(void *fp, void *sp);
void	ft_lstadd_back(t_dico **lst, t_dico *new);


char	*ft_strjoin(char *s1, char *s2);
char	*ft_strjoin_without_nl(char *stash, char *buffer);
char	*found_hundred(t_dico **dico);

//dictionnary
char	*ft_strlcpy(char *nb, int size);
char	*ft_strdup(char *src);
char	**prep_tab(int i);
int		case_exist(char *nb, t_dico **dico);
int		ft_strcmp(char *s1, char *s2);
void	aff_list(t_dico *dico);
void	free_list(t_dico **dico);

//split_du_pauvre
char **split_du_pauvre(char *str, char c);
void	free_split(char **split);
void	tab_split(char **tab, char *str, char c);
void	write_words2(char *tab, char*s, char c);
void	write_words(char *tab, char*s, char c);

//parsing
int	parse_dictionnary();
int	verif_line(char *str);
int	verif_arg(char *str);

//main
char	*is_in_my_book(t_dico **dico, char *nb);
int	ft_packages(char *nb);
char	*ft_calloc(int height);
char	*ft_realloc(char *stock, int size);

#endif