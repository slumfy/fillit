/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varuiz <varuiz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 02:19:14 by varuiz            #+#    #+#             */
/*   Updated: 2018/11/25 22:13:42 by rvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		return_error(int argc, char **argv, char ***pieces, int fd)
{
	if (argc != 2)
	{
		ft_putendl("usage: fillit [valid file]");
		return (0);
	}
	if ((fd = open(argv[1], O_RDONLY)) == -1 ||
			(*pieces = save_pieces(fd)) == NULL)
	{
		ft_putstr("error\n");
		return (0);
	}
	return (1);
}

int		main(int argc, char **argv)
{
	int		fd;
	char	**pieces;
	char	**square;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (return_error(argc, argv, &pieces, fd) == 0)
		return (0);
	j = map_min_size(pieces);
	ft_piece_letter(pieces);
	square = solve(pieces, j);
	while (ft_strcmp(square[i], "end"))
	{
		ft_putstr(square[i]);
		i++;
	}
	ft_freetab((void ***)&square);
	ft_freetab((void ***)&pieces);
	return (0);
}
