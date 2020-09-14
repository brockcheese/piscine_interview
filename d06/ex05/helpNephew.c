/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpNephew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpace <bpace@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 22:34:05 by bpace             #+#    #+#             */
/*   Updated: 2020/03/05 23:46:23 by bpace            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

double	probaNephewWillLive(int nStairs, int nPunch, int nephewStair) {
	double ans = 0;

	if (nStairs <= nephewStair || nPunch == 0)
		return (nStairs <= nephewStair ? 0 : 1);
	double temp = ((double) (nStairs - 1) / ((double) nStairs);
	for (int stairsLeft = nStairs - 1; stairsLeft >= 0; stairsLeft--) {
		ans += temp * probaNephewWillLive(stairsLeft, nPunch - 1, nephewStair);
	}
	return (ans);
}
