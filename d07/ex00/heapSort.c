/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heapSort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpace <bpace@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 01:26:20 by bpace             #+#    #+#             */
/*   Updated: 2020/03/06 02:13:22 by bpace            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	heapify(struct s_art **masterpiece, int n, int i) {
	struct s_art *temp;
	int max = i;
	int l = i * 2 + 1;
	int r = i * 2 + 2;
	if (l < n && masterpiece[l] && strcmp(masterpiece[max]->name, masterpiece[l]->name) < 0)
		max = l;
	if (r < n && masterpiece[r] && strcmp(masterpiece[max]->name, masterpiece[r]->name) < 0)
		max = r;
	if (max != i) {
		temp = masterpiece[i];
		masterpiece[i] = masterpiece[max];
		masterpiece[max] = temp;
		heapify(masterpiece, n, max);
	}
}

void	heapSort(struct s_art **masterpiece, int n) {
	struct s_art *temp;

	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(masterpiece, n, i);
	for (int i = n - 1; i > 0; i--) {
		temp = masterpiece[i];
		masterpiece[i] = masterpiece[0];
		masterpiece[0] = temp;
		heapify(masterpiece, i, 0);
	}
}
