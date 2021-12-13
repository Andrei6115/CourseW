#include "sentence.h"
void	cleanerSentence(t_sentence **sentence, t_sentence *cursor)
{
	t_sentence	*tmp;
	t_sentence	*list;

	if (*sentence)
	{	
		list = *sentence;
		while (list)
		{
			tmp = list->next;
			if (list && list->word)
				free(list->word);
			free(list);
			list = tmp;
		}
		*sentence = NULL;
		cursor = *sentence;
	}
	else
	{
		printf("List clear\n");
	}
}

void	emptySentence(t_sentence **sentence)
{
	if (*sentence == NULL)
		printf("List empty\n");
	else
		printf("List not empty\n");
}

void	cursorToStart(t_sentence **sentence, t_sentence *cursor)
{
	if(*sentence)
	{
		cursor = *sentence;
	}
	else
	{
		printf("List clear\n");
	}
}

void	sentenceMenu(t_sentence	**sentence)
{
	int			flag;
	t_sentence	*cursor;
	t_sentence	*tmp;
	char		word[100];

	if(!startWorkWithStruct("Sentence"))
		return;
	flag = 1;
	scanf("%d", &flag);
	printf("\n");
	system("cls");
	cursor = *sentence;
	switch (flag)
	{
	case 1:
		cleanerSentence(sentence, cursor);
		break;
	case 2:
		emptySentence(sentence);
		break;
	case 3:
		cursorToStart(sentence, cursor);
		break;
	case 4:
		
		break;
	case 5:
		break;
	case 6:
		break;
	case 7:
		break;
	case 8:
		break;
	case 9:
		break;
	default:
		break;
	}
}