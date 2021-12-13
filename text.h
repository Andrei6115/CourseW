#ifndef TEXT_H
# define TEXT_H
# include "sentence.h"

typedef struct s_text
{
	struct s_sentence	*sentence;
	struct s_text		*next;
} t_text;

void	textMenu(t_text	**text);
#endif