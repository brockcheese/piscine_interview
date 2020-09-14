#ifndef HEADER_H
# define HEADER_H

#include <stdlib.h>
#include <string.h>

/*--------------------------------
  !! required structure
  --------------------------------*/
# define DEPTH 4


/*--------------------------------
  :) function you must implement
  --------------------------------*/

# define ALPHAS "abcdefghijklmnopqrstuvwxyz"

char    *delete(char *word, int pos);
char    *replace(char *word, int pos, char c);
char    *add(char *word, int pos, char c);

char	*whatWasThat(char *word, char **dict);


/*--------------------------------
  ?? test function used in main
  --------------------------------*/


/*--------------------------------
  &  your own other function
  --------------------------------*/


#endif
