/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bestPrice.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpace <bpace@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 16:17:05 by bpace             #+#    #+#             */
/*   Updated: 2020/03/04 16:40:33 by bpace            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

double	bestpricehelper(int pizzasize, double *prices, double currmax) {
	int		i;
	double	tempmax;
	double	currprice = prices[pizzasize] + currmax;

	for (i = pizzasize - 1; i > 0; i--) {
		tempmax = bestpricehelper(pizzasize - i, prices, currmax + prices[i]);
		if (tempmax > currprice)
			currprice = tempmax;
	}
	return (currprice);
}

double	bestPrice(int pizzaSize, double *prices) {
	return (bestpricehelper(pizzaSize, prices, 0));
}
