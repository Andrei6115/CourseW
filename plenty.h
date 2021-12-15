#ifndef PLENTY_H
# define PLENTY_H
# include "text.h"

typedef struct s_plenty
{
	struct s_text	*text;
	struct s_plenty	*next;
} t_plenty;

void	plentyMenu();
#endif