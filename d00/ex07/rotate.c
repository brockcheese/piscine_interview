/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpace <bpace@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 23:05:37 by bpace             #+#    #+#             */
/*   Updated: 2020/02/25 23:30:29 by bpace            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//rotates an image 90 degrees clockwise

void	rotate(int **picture, int n) {
	int i, j, temp; //declare variables

	for(i = 0; i < n/2; i++) { //iterate through each row
		for(j = i; j < n - i - 1; j++) { //iterate through each column
			temp = picture[i][j]; //store one pixel to swap
			//swap top left pixel with bottom left pixel
			picture[i][j] = picture[n - j - 1][i];
			//swap bottom left pixel with bottom right pixel
			picture[n - j - 1][i] = picture[n - i - 1][n - j - 1];
			//swap bottom right pixel with top right pixel
			picture[n - i - 1][n - j - 1] = picture[j][n - i - 1];
			//swap top right pixel with temp
			picture[j][n - i - 1] = temp;
		}
	}
}
