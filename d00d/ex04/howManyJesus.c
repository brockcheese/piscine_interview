/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   howManyJesus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpace <bpace@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 21:42:47 by bpace             #+#    #+#             */
/*   Updated: 2020/02/22 22:30:20 by bpace            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		h = (h * 256) % 2147483647;
	p = 0;
	t = 0;
	for (i = 0; i < m; i++) {
		p = (256*p + jesus[i]) % 2147483647;
		t = (256*t + bible[i]) % 2147483647;
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
			t = (256 * (t - bible[i] * h) + bible[i + m]) % 2147483647;
		}
	}
	return (ans);
}
