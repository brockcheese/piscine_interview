/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   carPosition.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpace <bpace@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 06:41:20 by bpace             #+#    #+#             */
/*   Updated: 2020/03/03 06:46:44 by bpace            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int Log2n(unsigned int n) {
	return (n > 1) ? 1 + Log2n(n / 2) : 0;
}

int PowerofTwo(unsigned int n) {
	return n && (!(n & (n - 1)));
}

int carPosition(unsigned int parkingRow) {
	if (!PowerofTwo(parkingRow))
		return -1;
	return Log2n(parkingRow);
}
