#ifndef TEXT_H
# define TEXT_H
# include "sentence.h"

typedef struct s_text
{
	struct s_sentence	*sentence;
	struct s_text		*next;
} t_text;

void	textMenu(t_text	**text);
void	cleanerText(t_text **text, t_text **cursor);
void	printText(t_text **text, t_text *cursor);
int		equalText(t_text *first, t_text *second);
#endif