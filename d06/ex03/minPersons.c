/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minPersons.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpace <bpace@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 19:52:50 by bpace             #+#    #+#             */
/*   Updated: 2020/03/05 20:29:09 by bpace            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		minPersons(int element, int minPercentage) {
	double currp = 1.0;
	int nop = 1;
	while(nop <= element && 1.0 - currp < (double) minPercentage / 100) {
		currp *= ((double)(element - nop)) / ((double)(element));
		nop++;
	}
	return(nop);
}
