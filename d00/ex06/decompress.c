/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decompress.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpace <bpace@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 20:34:11 by bpace             #+#    #+#             */
/*   Updated: 2020/02/25 22:49:20 by bpace            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

//initializes a dynamic string

struct s_string *stringInit(void) {
	struct s_string	*dyString; //dynamic string

	//allocates memory for string
	if (!(dyString = malloc(sizeof(struct s_string))))
		return (NULL);
	//initializes string
	dyString->content = NULL;
	dyString->length = 0;
	dyString->capacity = 0;
	return (dyString); //return string
}

//append a string to the dynamic string

int		stringAppend(struct s_string *dyString, char *str) {
	int realloccheck; //checks if dynamic string needs to be reallocated

	//calculate the new length of the dynamic string
	int newlen = str ? strlen(str) + dyString->length : dyString->length;
	realloccheck = 0; //initialize the check
	//check if there is enough memory in the string
	while(newlen + 1 > dyString->capacity) {
		dyString->capacity += 1000000;
		realloccheck = 1;
	}
	//reallocate memory for the dynamic string
	if (realloccheck == 1) {
		if (!(dyString->content = realloc(dyString->content, dyString->capacity)))
			return (0);
	}
	//copy content from string to dynamic string
	if (str) {
		strcpy(dyString->content + dyString->length, str);
		dyString->length = newlen;
		dyString->content[dyString->length] = '\0';
	}
	return (1);
}

//decompresses a file given a compressed file and header

char *decompress(char *cBook) {
	char *header[255];
	char *ans, ch;
	int i, j, comma;

	struct s_string *s = stringInit(); //initialize dynamic string
	i = -1;
	while (++i < 255) //initialize the header
		header[i] = NULL;
	i = -1;
	j = -1;
	comma = 0;
	//copy info from compression to header
	while(cBook[++i] != '>') {
		if (cBook[i] == ',') {
			header[++j] = strndup(cBook + comma + 1, i - comma - 1);
			comma = i;
		}
	}
	//final copy from compression to header
	header[++j] = strndup(cBook + comma + 1, i - comma - 1);
	comma = i;
	//go through book char by char to find @ symbol compressed words
	while((ch = cBook[++i])) {
		if (ch == '@') {
			//copy everything before the @ to new string
			ans = strndup(cBook + comma + 1, i - comma - 1);
			//append everything before the @ to dynamic string
			if (!(stringAppend(s, ans)))
				return (ans);
			free(ans); //free the memory allocated by strndup
			//moves past the @ to see what word it should be
			ch = cBook[++i];
			//append the word from the header to dynamic string
			if (!(stringAppend(s, header[(unsigned char) ch - 1])))
				return (header[(unsigned char) ch - 1]);
			comma = i; //set the breakpoint to current index
		}
	}
	ans = strdup(cBook + comma + 1); //copies rest of book to temp string
	stringAppend(s, ans); //appends the rest of the book to dyn string
	free(ans); //free the memory allocated by strndup
	for(int k = 0; header[k]; k++) //free contents of header
		free(header[k]);
	ans = s->content; //set return value to dynamic string
	free(s); //free dynamic string
	return (ans); //return decompressed book
}
