/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xor.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpace <bpace@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 03:18:27 by bpace             #+#    #+#             */
/*   Updated: 2020/03/03 03:22:41 by bpace            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

//cast a binary string to int

int toInt(char *bits) {
	int ans = 0; //initialize return value
	int b = 1; //initialize power of 2
	for(int i = 5; i >= 0; i--) {
		ans += (bits[i] - '0') * b; //add current digit
		b *= 2; //multiply by base
	}
	return (ans); //return integer
}

//returns a xor product of two binary strings given as parameters

char *getXor(char *a, char *b) {
	int i, j, k, an, bn;
	//allocates memory for return string
	char *ans = malloc(sizeof(char) * 5);
	ans[4] = '\0'; //null terminate the string
	i = j = k = an = bn = 0; //initialize all integer values to 0
	if (a[0] == '~') { //checks if first string is negative
		an = 1;
		i++;
	}
	if (b[0] == '~') { //checks if second string is negative
		bn = 1;
		j++;
	}
	while(a[i] && b[j]) {
		if (an == 1) //if first string is negative inverse characters
			a[i] = (a[i] == '1') ? '0' : '1';
		if (bn == 1) //if second string is negative inverse characters
			b[i] = (b[i] == '1') ? '0' : '1';
		//calculate xor values of current digit
		ans[k++] = ((a[i] == '1' && b[j] == '0') || (a[i] == '0' && b[j] == '1')) ? '1' : '0';
		i++; //increment indexes
		j++;
	}
	return (ans); //return string
}
