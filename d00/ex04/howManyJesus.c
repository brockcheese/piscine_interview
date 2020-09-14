/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   howManyJesus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpace <bpace@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 21:42:47 by bpace             #+#    #+#             */
/*   Updated: 2020/02/24 15:03:18 by bpace            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int howManyJesus(char *bible, char *jesus) {
	int n;
	int m;
	int h;
	int p;
	int t;
	int i;
	int j;
	int ans;

	ans = 0;
	n = -1;
	while (bible[++n]);
	m = -1;
	while (jesus[++m]);
	h = 1;
	for (i = 0; i < m-1; i++)
		h = (h * 256) % INT_MAX;
	p = 0;
	t = 0;
	for (i = 0; i < m; i++) {
		p = (256*p + jesus[i]) % INT_MAX;
		t = (256*t + bible[i]) % INT_MAX;
	}
	for (i = 0; i <= n - m; i++) {
		if (p == t) {
			for (j = 0; j < m; j++) {
				if (bible[i+j] != jesus[j])
					break;
			}
			if (j == m)
				ans++;
		}
		if (i < n - m) {
			t = (256 * (t - bible[i] * h) + bible[i + m]) % INT_MAX;
		}
	}
	return (ans);
}
