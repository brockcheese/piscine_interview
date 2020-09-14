/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bestPriceV2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpace <bpace@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 16:17:05 by bpace             #+#    #+#             */
/*   Updated: 2020/03/04 19:23:49 by bpace            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

double	bestpricehelper(int ps, double *prices, double *rp) {
	int		i;
	double	tempmax;

	rp[ps] = prices[ps];
	for (i = 1; i < ps; i++) {
		if (rp[ps - 1] >= 1)
			tempmax = rp[i] + rp[ps - i];
		else
			tempmax = rp[i] + bestpricehelper(ps - i, prices, rp);
		if (tempmax > rp[ps])
			rp[ps] = tempmax;
	}
	return (rp[ps]);
}

double	optimizedBestPrice(int pizzaSize, double *prices) {
	double	realprice[pizzaSize];

	if (pizzaSize < 1)
		return (0);
	bzero(realprice, pizzaSize * 8);
	realprice[1] = prices[1];
	return (bestpricehelper(pizzaSize, prices, realprice));
}
