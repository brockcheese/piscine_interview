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

//finds least populated cities given a linked list

char *NthLastCity(struct s_city *city, int n) {
	struct s_city *ans; //leading node to find nth last item

	ans = city; //sets leading node to current node
	if (!city) //error checking
		return (NULL);
	while (ans && n--) //send leading node n nodes away from curr
		ans = ans->next;
	while(ans && ans->next) { //increment both nodes until end of the list
		city = city->next;
		ans = ans->next;
	}
	return (city->name); //current node is now n places from end of list
}
