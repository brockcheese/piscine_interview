/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   makeThemEat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpace <bpace@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 22:25:33 by bpace             #+#    #+#             */
/*   Updated: 2020/03/04 23:17:45 by bpace            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	iph(struct s_people **people, int *tab, int i, int nbtable, int totaltime) {
	int	j;
	int	ans;

	if (!people[i])
		return (1);
	for (j = 0; j < nbtable; j++) {
		if (people[i]->time > totaltime)
			return (0);
		else if (people[i]->time <= tab[j]) {
			tab[j] -= people[i]->time;
			ans = iph(people, tab, i + 1, nbtable, totaltime);
			if (ans == 1)
				return (1);
			tab[j] += people[i]->time;
		}
	}
	return (0);
}

int	isPossible(struct s_people **people, int nbTable, int totalTime) {
	int	tab[nbTable];
	int	i;

	for (i = 0; i < nbTable; i++)
	tab[i] = totalTime;
	return ((iph(people, tab, 0, nbTable, totalTime)) ? 1 : 0);
}
