/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   longestSequence.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpace <bpace@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 07:38:09 by bpace             #+#    #+#             */
/*   Updated: 2020/03/03 07:43:55 by bpace            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int longestSequence(unsigned int parkingRow) {
	if(parkingRow)
		return(longestSequence(parkingRow & (parkingRow << 1)) + 1);
	return (0);
}
