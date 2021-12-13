#include "sentence.h"
int	equalSentence(t_sentence *first, t_sentence *second)
{
	int i;
	int	len;


	while (first && second)
	{
		len = strlen(first);
		if (len != strlen(second))
			return (0);
		i = 0;
		while (i < len)
		{
			if (first->word[i] != second->word[i])
				return (0);
			i++;
		}
		first = first->next;
		second = second->next;
	}
	if (first != second)
		return (0);
	return (1);	
}

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
		printf("List clear\n");
	else
		printf("List not clear\n");
}

void	cursorToStart(t_sentence **sentence, t_sentence **cursor)
{
	if(*sentence)
	{
		*cursor = *sentence;
	}
	else
	{
		printf("List clear\n");
	}
}

void	cursorInStart(t_sentence **sentence, t_sentence *cursor)
{
	if(*sentence)
	{
		if (cursor == *sentence)
			printf("Cursor in start\n");
		else
			printf("Cursor not in start\n");
	}
	else
	{
		printf("List clear\n");
	}
}

t_sentence	*lastWord(t_sentence *lst)
{
	while (lst)
	{
		if (!lst->next)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}

void cursorToEnd(t_sentence **sentence, t_sentence **cursor)
{
	
	if (*sentence)
	{
		*cursor = lastWord(*sentence);
	}
	else
	{
		printf("List clear\n");
	}
}

void cursorInEnd(t_sentence **sentence, t_sentence *cursor)
{
	if (*sentence)
	{
		if (!cursor->next)
			printf("Cursor in end\n");
		else
			printf("Cursor not in end\n");
	}
	else
	{
		printf("List clear\n");
	}
}

void	nextEl(t_sentence **sentence, t_sentence **cursor)
{
	if (*sentence)
	{
		if ((*cursor)->next)
			*cursor = (*cursor)->next;
		else
			printf("No el\n");
	}
	else
	{
		printf("List clear\n");
	}
}

void	viewNextEl(t_sentence **sentence, t_sentence *cursor)
{
	if (sentence)
	{
		if (cursor->next)
			printf("%s\n", cursor->next->word);
		else
			printf("No el\n");
	}
	else
	{
		printf("List clear\n");
	}
}

void	deleteNextEl(t_sentence **sentence, t_sentence *cursor)
{
	t_sentence	*temp;

	if (*sentence)
	{
		if (!cursor->next)
		{
			printf("No el\n");
			return ;
		}
		temp = cursor->next;
		if (temp->next)
		{
			cursor->next = temp->next;
		}
		else
		{
			cursor->next = NULL;
		}
		free(temp->word);
		free(temp);
	}
	else
	{
		printf("List clear\n");
	}
}

void	takeEl(t_sentence **sentence, t_sentence *cursor, t_sentence **taked)
{
	if ((*taked))
	{
		free((*taked)->word);
		free((*taked));
		(*taked) = NULL;
	}
	if (*sentence)
	{
		if (cursor->next)
		{
			(*taked) = cursor->next;
			if ((*taked)->next)
			{
				cursor->next = (*taked)->next;
			}
			else
			{
				cursor->next = NULL;
			}
			printf("Taked el: %s\n", (*taked)->word);
		}
		else
		{
			printf("No el\n");
		}
	}
	else
	{
		printf("List clear");
	}
}

void	changeNextEl(t_sentence **sentence, t_sentence *cursor)
{
	if (*sentence)
	{
		if (cursor->next)
		{
			printf("Enter data for el:");
			scanf("%s", (cursor->next->word));
			printf("\n");
		}
		else
		{
			printf("no elem\n");
		}
	}
	else
	{
		printf("list clear\n");
	}
}

t_sentence	*newSentence(char *word)
{
	t_sentence	*ret;

	ret = malloc(sizeof(t_sentence));
	if (!ret)
	{
		printf("MEM ERROR\n");
		exit(1);
	}
	ret->word = malloc(strlen(word) * sizeof(char));
	if (!ret->word)
	{
		printf("MEM ERROR\n");
		exit(1);
	}
	strcpy(ret->word, word);
	ret->next = NULL;
	return (ret);
}

void	addEl(t_sentence **sentence, t_sentence **cursor)
{
	t_sentence	*temp;
	char		buf[100];

	printf("Enter data for el:");
	scanf("%s", buf);
	printf("\n");


	temp = newSentence(buf);
	if (!*sentence)
	{
		*sentence = temp;
		*cursor = *sentence;
	}
	else
	{
		if ((*cursor)->next)
		{
			temp->next = (*cursor)->next;
			(*cursor)->next = temp;
		}
		else
		{
			(*cursor)->next = temp;
		}

	}
}

void	printSentence(t_sentence **sentence, t_sentence *cursor)
{
	t_sentence *list;

	list = *sentence;
	if (!list)
	{
		printf("List clear\n");
		return;
	}
	while (list)
	{
		if (*sentence != list)
			printf("->");
		printf("[%s]", list->word);
		if (list == cursor)
			printf("*");
		list = list->next;
	}
	printf("\n");
}

void	sentenceMenu(t_sentence	**sentence)
{
	int			flag;
	t_sentence	*cursor;
	t_sentence	*taked;

	if(!startWorkWithStruct("Sentence"))
		return;
	flag = 1;
	cursor = *sentence;
	taked = NULL;
	while (flag)
	{
		printSentence(sentence, cursor);
		printf("1. Cleaner\n2. Sentence clear?\n3. Cursor to start\n4. Cursor in start?\n5. Cursor to end\n6. Cursor in end?\n7. Skip el\n8. View Next el\n9. Delete next\n10. Take el\n11. Change next\n12. Add el\n13. Print\n0. Exit\n");
		scanf("%d", &flag);
		printf("\n");
		system("cls");
		
		switch (flag)
		{
		case 1:
			cleanerSentence(sentence, cursor);
			break;
		case 2:
			emptySentence(sentence);
			break;
		case 3:
			cursorToStart(sentence, &cursor);
			break;
		case 4:
			cursorInStart(sentence, cursor);
			break;
		case 5:
			cursorToEnd(sentence, &cursor);
			break;
		case 6:
			cursorInEnd(sentence, cursor);
			break;
		case 7:
			nextEl(sentence, &cursor);
			break;
		case 8:
			viewNextEl(sentence, cursor);
			break;
		case 9:
			deleteNextEl(sentence, cursor);
			break;
		case 10:
			takeEl(sentence, cursor, &taked);
			break;
		case 11:
			changeNextEl(sentence, cursor);
			break;
		case 12:
			addEl(sentence, &cursor);
			break;
		case 13:
			printSentence(sentence, cursor);
			break;
		case 0:
			break;
		default:
			break;
		}
	}
}