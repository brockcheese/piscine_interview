/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clearBits.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpace <bpace@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 06:48:21 by bpace             #+#    #+#             */
/*   Updated: 2020/03/03 06:52:26 by bpace            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int clearBits(unsigned int parkingRow, int n) {
	unsigned int mask = -1 << n;
	return (parkingRow & mask);
}
