/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimumMoves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpace <bpace@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 21:22:28 by bpace             #+#    #+#             */
/*   Updated: 2020/02/26 21:55:48 by bpace            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int minimumMoves(struct s_node *node) {
	int minn;
	int minr;

	if (!node || node->isFinal == -1)
		return (-1);
	if (node->isFinal == 1)
		return (0);
	node->isFinal = -1;
	minn = minimumMoves(node->next) + 1;
	minr = minimumMoves(node->random) + 1;
	node->isFinal = 0;
	if (minn == 0) {
		if (minr == 0)
			return -1;
		return (minr);
	}
	if (minr == 0)
		return (minn);
	return ((minn < minr) ? minn : minr);
}
