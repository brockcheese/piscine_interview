/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hotspots.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpace <bpace@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 16:35:39 by bpace             #+#    #+#             */
/*   Updated: 2020/03/05 19:05:19 by bpace            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int selectHotspots(struct s_hotspot **hotspots) {
	int max, cr, cp;
	if (!hotspots || !hotspots[0])
		return (0);
	for (max = 0; hotspots[max]; max++);
	cr = hotspots[0]->radius;
	cp = hotspots[0]->pos;
	for(int i = 1; hotspots[i]; i++) {
		if (hotspots[i]->pos - hotspots[i]->radius > cp) {
			if (hotspots[i]->pos - cr <= cp)
				max--;
			cr = hotspots[i]->radius;
			cp = hotspots[i]->pos;
		}
		else
			max--;
	}
	return (max);
}
