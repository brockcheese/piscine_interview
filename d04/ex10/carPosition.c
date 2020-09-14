/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   carPosition.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpace <bpace@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 06:06:41 by bpace             #+#    #+#             */
/*   Updated: 2020/03/03 06:33:13 by bpace            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int minus(unsigned int parkingRow, unsigned int plus) {
	if (plus) {
		return(minus(parkingRow ^ plus, (~parkingRow & plus) << 1));
	}
	return (parkingRow);
}

int carPositionHelp(unsigned int parkingRow) {
	if (parkingRow) {
		return (carPositionHelp(parkingRow >> 1) + 1);
	}
	return(0);
}

int carPosition(unsigned int parkingRow) {
	if (parkingRow) {
		if (parkingRow & minus(parkingRow, 1))
			return(-1);
		return (carPositionHelp(parkingRow >> 1));
	}
	return (-1);
}
