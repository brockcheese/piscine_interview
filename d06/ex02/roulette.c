/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   roulette.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpace <bpace@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 19:12:54 by bpace             #+#    #+#             */
/*   Updated: 2020/03/05 19:41:40 by bpace            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

double	probabilityWinHelper(double initDollars, double wantedDollars, int nbGame) {
	double ans;

	if (initDollars <= 0 || initDollars >= wantedDollars || nbGame <= 0)
		return ((initDollars >= wantedDollars) ? 1 : 0);
	ans = ((((double) 18) / ((double) 37)) * probabilityWinHelper(initDollars * 2, wantedDollars, nbGame - 1)) +
		((((double) 18) / ((double) 37)) * probabilityWinHelper(initDollars * 0, wantedDollars, nbGame - 1)) +
		((((double) 1) / ((double) 37)) * probabilityWinHelper(initDollars / 2, wantedDollars, nbGame - 1));
	return (ans);
}

double	probabilityWin(double initDollars, double wantedDollars, int nbGame) {
	return (probabilityWinHelper(initDollars, wantedDollars, nbGame));
}
