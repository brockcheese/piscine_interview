/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpace <bpace@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 23:23:59 by bpace             #+#    #+#             */
/*   Updated: 2020/03/10 16:08:52 by bpace            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

//converts a binary string given as parameter to an integer

int toInt(char *bits) {
	int ans = 0; //initializes return value
	int b = 1; //initializes power of 2
	for(int i = 3; i >= 0; i--) {
		ans += (bits[i] - '0') * b; //add current digit
		b *= 2; //multiply by base
	}
	return (ans); //return integer
}

//returns new string of the product of an and operation between two strings

char *getAnd(char *a, char *b) {
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
			b[j] = (b[j] == '1') ? '0' : '1';
		//calculate and values of current digit
		ans[k++] = (a[i++] == '1' && b[j] == '1') ? '1' : '0';
		j++; //increment index
	}
	return (ans); //return string
}

//returns new string of the product of an or operation between two strings

char *getOr(char *a, char *b) {
	int i, j, k, an, bn;
	//alloates memory for return string
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
			b[j] = (b[j] == '1') ? '0' : '1';
		//calculate or values of current digit
		ans[k++] = (a[i++] == '1' || b[j] == '1') ? '1' : '0';
		j++; //increment index
	}
	return (ans); //return string 
}
