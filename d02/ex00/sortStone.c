/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortStone.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpace <bpace@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 00:44:03 by bpace             #+#    #+#             */
/*   Updated: 2020/02/27 02:54:45 by bpace            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void sortStones(struct s_stone **stone) {
	struct s_stone *start;
	struct s_stone *leftswap;
	struct s_stone *rightswap;
	struct s_stone *middleswap;
	int max = -1;
	int check = 0;

	if (*stone == NULL || (*stone)->next == NULL)
		return;
	start = *stone;
	while(start) {
		max = (start->size > max) ? start->size : max;
		start = start->next;
	}
	max++;
	while(check == 0) {
		check = 1;
		leftswap = *stone;
		while (leftswap->next && leftswap->size != max) {
			middleswap = leftswap;
			while (middleswap->next && middleswap->next->size == leftswap->size)
				middleswap = middleswap->next;
			rightswap = middleswap;
			while (rightswap->next && rightswap->next->size == middleswap->next->size)
				rightswap = rightswap->next;
			if (leftswap->size > rightswap->size) {
				check = 0;
				if (leftswap == (*stone))
					*stone = middleswap->next;
				else
					start->next = middleswap->next;
				middleswap->next = rightswap->next;
				rightswap->next = leftswap;
				start = rightswap;
			}
			else {
				start = middleswap;
				leftswap = (start && start->next) ? start->next : start;
			}
		}
		max = leftswap->size;
	}
}
