#ifndef SENTENCE_H
# define SENTENCE_H
# include "header.h"
# include <string.h>
typedef struct s_sentence
{
	char				*word;
	struct s_sentence	*next;
} t_sentence;

void	sentenceMenu(t_sentence	**sentence);
#endif