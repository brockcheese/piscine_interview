#ifndef HEADER_H
# define HEADER_H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/*--------------------------------
  !! required structure
  --------------------------------*/
struct s_node {
	char	*name;
	struct s_node **children;
};


/*--------------------------------
  :) function you must implement
  --------------------------------*/
struct s_node *findParent(struct s_node *root, char *firstSpecies, char *secondSpecies);


/*--------------------------------
  ?? test function used in main
  --------------------------------*/
struct s_node *getTreeOfLife(void);


/*--------------------------------
  &  your own other function
  --------------------------------*/


#endif
