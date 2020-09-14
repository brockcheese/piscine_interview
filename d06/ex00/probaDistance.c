/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   probaDistance.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpace <bpace@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 16:15:06 by bpace             #+#    #+#             */
/*   Updated: 2020/03/05 16:25:53 by bpace            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

double probaDistance(int dist, int *locations, int n) {
	int top, bottom, t, li;
	double ans;

	top = bottom = 0;
	for(int i = 0; i < n; i++) {
		li = locations[i];
		for(int j = i + 1; j < n; j++) {
			t = li - locations[j];
			if (t < 0)
				t = -(t);
			if (t > dist)
				top++;
			bottom++;
		}
	}
	ans = ((double) top) / ((double) bottom);
	return (ans);
}
