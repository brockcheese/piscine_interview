/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   updatePlace.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpace <bpace@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 03:51:43 by bpace             #+#    #+#             */
/*   Updated: 2020/03/03 04:34:22 by bpace            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int updatePlace(unsigned int parkingRow, int pos, int value) {
	return ((parkingRow | (value << pos)) & (~((1 ^ value) << pos)));
}
