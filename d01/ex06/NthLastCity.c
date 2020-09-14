/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NthLastCity.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpace <bpace@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 19:55:25 by bpace             #+#    #+#             */
/*   Updated: 2020/03/05 02:00:27 by bpace            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char *NthLastCity(struct s_city *city, int n) {
	struct s_city *ans;

	ans = city;
	if (!city)
		return (NULL);
	while (ans && n--)
		ans = ans->next;
	while(ans && ans->next) {
		city = city->next;
		ans = ans->next;
	}
	return (city->name);
}
