/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decrypt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpace <bpace@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 22:49:08 by bpace             #+#    #+#             */
/*   Updated: 2020/03/02 23:11:27 by bpace            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//converts a binary string given as parameter to an integer

int toInt(char *bits) {
	int ans = 0; //initialize return value
	int b = 1; //initializes the power of 2
	for(int i = 5; i >= 0; i--) { //for each character in the binary string
		ans += (bits[i] - '0') * b; //add character to return value
		b *= 2; //multiply by base
	}
	return (ans); //return integer
}

//gets the sum of two binary string s passed as parameters (a and b)

char *getSum(char *a, char *b) {
	int r = 0; //initialize digit sum
	for(int i = 5; i >= 0; i--) {
		r += a[i] - '0' + b[i] - '0'; //calculate sum of digits
		b[i] = (char)(r % 2 + '0'); //store digit place
		r /= 2; //compute remainder
	}
	return (b); //return binary string sum
}
