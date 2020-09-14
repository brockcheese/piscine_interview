/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rightmostCar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpace <bpace@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 07:29:44 by bpace             #+#    #+#             */
/*   Updated: 2020/03/03 07:35:51 by bpace            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int add(unsigned int parkingRow, unsigned int plus) {
	if (plus) {
		return(add(parkingRow ^ plus, (parkingRow & plus) << 1));
	}
	return (parkingRow);
}

unsigned int minus(unsigned int parkingRow, unsigned int plus) {
	if (plus) {
		return(minus(parkingRow ^ plus, (~parkingRow & plus) << 1));
	}
	return (parkingRow);
}

#include "header.h"

int rightmostCar(unsigned int parkingRow) {
	return log2(parkingRow & minus(0, parkingRow));
}
