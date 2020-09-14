/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   correctSong.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpace <bpace@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 08:16:02 by bpace             #+#    #+#             */
/*   Updated: 2020/03/03 08:26:47 by bpace            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	correctSong(struct s_bit *bit, int l, int row, int col, int dist) {
	int note;

	note = 1;
	while (col--)
		note *= 2;
	for(int i = row; i < row + dist && i < l; i++)
		bit->arr[i] = note;
}
