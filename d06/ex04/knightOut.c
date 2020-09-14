/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   knightOut.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpace <bpace@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 20:40:59 by bpace             #+#    #+#             */
/*   Updated: 2020/03/05 22:22:12 by bpace            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	getInitialPos(uint64_t board) {
	int ans = -1;
	while(board > 0) {
		board <<= 1;
		ans++;
	}
	return (ans);
}

double	knightOH(int p, int n) {
	double bp[8][8][n + 1];
	int nextmovex[] = {1, 2, 2, 1, -1, -2, -2, -1};
	int nextmovey[] = {-2, -1, 1, 2, -2, -1, 1, 2};

	for (int i = 0; i < 8; i++)
		for(int j = 0; j < 8; j++)
			bp[i][j][0] = 1;
	for (int ni = 1; ni <= n; ni++) {
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				double ans = 0.0;
				for (int k = 0; k < 8; k++) {
					int newi = i + nextmovex[k];
					int newj = j + nextmovey[k];
					if (newi >= 0 && newi < 8 && newj >= 0 && newj < 8)
						ans += bp[newi][newj][ni - 1] / 8.0;
				}
				bp[i][j][ni] = ans;
			}
		}
	}

	return (bp[p / 8][p % 8][n]);
}

double	knightOut(uint64_t board, int n) {
	if (n < 1)
		return (0);
	int p = getInitialPos(board);
	return (1 - knightOH(p, n));
}
