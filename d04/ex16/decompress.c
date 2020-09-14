/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piano.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpace <bpace@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 07:56:00 by bpace             #+#    #+#             */
/*   Updated: 2020/03/03 08:05:01 by bpace            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		**pianoDecompress(struct s_bit *bit, int l) {
	int **ans, d;

	ans = malloc(sizeof(int *) * bit->n);
	for(int i = 0; i < bit->n; i++) {
		ans[i] = malloc(sizeof(int) * l);
		d = 1;
		for(int j = 0; j < l; j++) {
			if (bit->arr[i] == d)
				ans[i][j] = 1;
			else
				ans[i][j] = 0;
			d *= 2;
		}
	}
	return (ans);
}
