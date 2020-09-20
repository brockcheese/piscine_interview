/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   howManyJesus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpace <bpace@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 21:42:47 by bpace             #+#    #+#             */
/*   Updated: 2020/02/24 15:03:18 by bpace            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

//Rabin-Karp algorithm for finding the number of times a word is in the bible

int howManyJesus(char *bible, char *jesus) {
	int n; //number of letters in the bible
	int m; //number of letters in the needle
	int h; //hash value
	int p; //hash value for pattern
	int t; //hash value for txt
	int i;
	int j;
	int ans; //return value

	ans = 0; //initialize return value
	n = -1; //initialize n
	while (bible[++n]); //counts number of letters in the bible
	m = -1; //initialize m
	while (jesus[++m]); //counts number of letters in the needle
	h = 1; //initialize hash
	for (i = 0; i < m-1; i++)
		h = (h * 256) % INT_MAX; //calculate simple hash
	p = 0;
	t = 0;
	for (i = 0; i < m; i++) {
		//calculate hash value of pattern
		p = (256*p + jesus[i]) % INT_MAX;
		//calculate the hash value of first
		t = (256*t + bible[i]) % INT_MAX;
	}
	for (i = 0; i <= n - m; i++) { //check hash value for each character
		if (p == t) {
			//check if letters match one by one
			for (j = 0; j < m; j++) {
				if (bible[i+j] != jesus[j])
					break;
			}
			if (j == m) //if words match increment answer
				ans++;
		}
		//rolling hash removes letter from the front and adds the end
		if (i < n - m) {
			t = (256 * (t - bible[i] * h) + bible[i + m]) % INT_MAX;
		}
	}
	return (ans); //returns value
}
