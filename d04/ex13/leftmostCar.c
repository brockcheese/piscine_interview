/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leftmostCar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpace <bpace@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 06:56:29 by bpace             #+#    #+#             */
/*   Updated: 2020/03/03 07:32:37 by bpace            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int add(unsigned int parkingRow, unsigned int plus) {
	if (plus) {
		return(add(parkingRow ^ plus, (parkingRow & plus) << 1));
	}
	return (parkingRow);
}

int	leftmostCar(unsigned int parkingRow) {
	if (parkingRow) {
		return (add(leftmostCar(parkingRow >> 1), 1));
	}
	return (-1);
}
