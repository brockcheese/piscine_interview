/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpace <bpace@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 02:49:02 by bpace             #+#    #+#             */
/*   Updated: 2020/03/05 15:37:49 by bpace            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//cast a binary string to int

int toInt(char *bits) {
	int ans = 0; //initialize return value
	int b = 1; //initialize power of 2
	for(int i = 5; i >= 0; i--) {
		ans += (bits[i] - '0') * b; //add current digit
		b *= 2; //multiply by base
	}
	if (ans > 31) //convert answer to negative
		ans -= 64;
	return (ans); //return integer
}

//applies an arithmetical left shift to a binary string bin k shifts

char *leftShift(char *bin, int k) {
	int i; //index declaration

	for(i = 0; i < 6 - k; i++) { //move digits k places left
		bin[i] = bin[i + k];
	}
	while(i < 6) //replace remaining digits with unset bits
		bin[i++] = '0';
	return (bin); //return shifted binary string
}

//applies an arithmetical right shift to a binary string bin k shifts

char *rightShift(char *bin, int k) {
	int i; //index declaration
	int sign; //integer that stores the sign of the binary string

	sign = bin[0]; //stores the sign of the binary string
	for(i = 5; i >= k; i--) {
		bin[i] = bin[i - k]; //move digits k places right
	}
	while (i > -1) //replace remaining digits with the sign
		bin[i--] = sign;
	return (bin); //return shifted binary string
}
