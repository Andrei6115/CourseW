#ifndef PLENTY_H
# define PLENTY_H
# include "text.h"

typedef struct s_plenty
{
	struct s_text	*text;
	struct s_plenty	*next;
	struct s_plenty	*prev;
} t_plenty;

void	plentyMenu();
#endif