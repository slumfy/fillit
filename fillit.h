/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varuiz <varuiz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 08:18:29 by varuiz            #+#    #+#             */
/*   Updated: 2018/11/25 22:27:41 by rvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "./libft/libft.h"
# include <fcntl.h>
# include <stdio.h>

char	**taballoc(int l, int c);
int		tab_len(char **tab);
int		check_pieces(char **pieces, int l);
int		fillit(char **pieces, char **square, int l);
char	**solve(char **pieces, int size);
int		count_pieces(char *pieces);
void	create_tab(char *pieces, char **tab);
char	**check_error(char *pieces);
char	**save_pieces(int fd);
void	ft_put_piece(char *piece, char **square, int j, int k);
void	ft_piece_letter(char **tab);
int		ft_piece_fit(char *piece, char **square, int j, int k);
int		map_min_size(char **tab);
char	**ft_create_map(int size);
void	reset_piece(char *piece, char **square);
int		valid(char *str, int j, int i, int x);
int		valid_piece(char *str, int n);
void	ft_freetab(void ***tab);
void	ft_freemap(void ***tab);
#endif
