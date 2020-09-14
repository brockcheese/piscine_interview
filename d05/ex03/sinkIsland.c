/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sinkIsland.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpace <bpace@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 19:42:31 by bpace             #+#    #+#             */
/*   Updated: 2020/03/04 20:03:39 by bpace            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	sinkIsland(int **map, int row, int col) {
	if (row >= 0 && col >= 0 && map[row] && map[row][col] == 1) {
		map[row][col] = 0;
		sinkIsland(map, row - 1, col);
		sinkIsland(map, row + 1, col);
		sinkIsland(map, row, col - 1);
		sinkIsland(map, row, col + 1);
	}
}
