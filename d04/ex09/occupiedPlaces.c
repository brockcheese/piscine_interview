/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   occupiedPlaces.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpace <bpace@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 05:28:09 by bpace             #+#    #+#             */
/*   Updated: 2020/03/05 15:41:40 by bpace            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int minus(unsigned int parkingRow, unsigned int plus) {
	if (plus) {
		return(minus(parkingRow ^ plus, (~parkingRow & plus) << 1));
	}
	return (parkingRow);
}

unsigned int add(unsigned int parkingRow, unsigned int plus) {
	if (plus) {
		return(add(parkingRow ^ plus, (parkingRow & plus) << 1));
	}
	return (parkingRow);
}

int occupiedPlaces(unsigned int parkingRow) {
	if (parkingRow) {
		return(add(occupiedPlaces(parkingRow & minus(parkingRow, 1)), 1));
	}
	return (0);
}
