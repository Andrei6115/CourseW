#ifndef SENTENCE_H
# define SENTENCE_H
# include "header.h"
typedef struct s_sentence
{
	char				*word;
	struct s_sentence	*next;
} t_sentence;

#endif