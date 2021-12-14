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
void	cleanerSentence(t_sentence **sentence, t_sentence **cursor);
void	printSentence(t_sentence **sentence, t_sentence *cursor);
int		equalSentence(t_sentence *first, t_sentence *second);
#endif