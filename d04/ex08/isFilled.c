/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isFilled.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpace <bpace@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 04:40:16 by bpace             #+#    #+#             */
/*   Updated: 2020/03/03 05:07:49 by bpace            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int add(unsigned int parkingRow, unsigned int plus) {
	if (plus) {
		return(add(parkingRow ^ plus, (parkingRow & plus) << 1));
	}
	return (parkingRow);
}

int isFilled(unsigned int parkingRow) {
	if (parkingRow) {
		if (add(parkingRow, 1) & parkingRow)
			return (0);
		return (1);
	}
	return (0);
}
