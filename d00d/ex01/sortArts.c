/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortArts.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpace <bpace@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 22:22:45 by bpace             #+#    #+#             */
/*   Updated: 2020/02/21 15:50:51 by bpace            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	sortArtsHelper(struct s_art **arts, int start, int end) {
	int i;
	int p;
	struct s_art*	pivot;
	struct s_art*	temp;
	char*			check1;
	char*			check2;

	if (start >= end)
		return;
	pivot = arts[end];
	p = start;
	i = start;
	while(i <= end) {
		check1 = arts[i]->name;
		check2 = pivot->name;
		if (strcmp(arts[i]->name, pivot->name) <= 0) {
			temp = arts[i];
			arts[i] = arts[p];
			arts[p] = temp;
			p++;
		}
		i++;
	}
	sortArtsHelper(arts, start, p-2);
	sortArtsHelper(arts, p, end);
}

void	sortArts(struct s_art **arts) {
	int len;

	len = -1;
	while(arts[++len])
		;
	sortArtsHelper(arts, 0, len - 1);
}
