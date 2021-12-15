#include "text.h"
int	equalText(t_text *first, t_text *second)
{
	while (first && second)
	{
		if (!equalSentence(first->sentence, second->sentence))
		{
			return (0);
		}
		first = first->next;
		second = second->next;
	}
	if (first != second)
		return (0);
	return (1);
}

void	cleanerText(t_text **text, t_text **cursor)
{
	t_text	*tmp;
	t_text	*list;

	if (*text)
	{	
		list = *text;
		while (list)
		{
			tmp = list->next;
			cleanerSentence(&(list->sentence), &(list->sentence));
			list = tmp;
		}
		*text = NULL;
		*cursor = *text;
	}
	else
	{
		printf("List clear\n");
	}
}

static void	emptytext(t_text **text)
{
	if (*text == NULL)
		printf("List clear\n");
	else
		printf("List not clear\n");
}

static void	cursorToStart(t_text **text, t_text **cursor)
{
	if(*text)
	{
		*cursor = *text;
	}
	else
	{
		printf("List clear\n");
	}
}

static void	cursorInStart(t_text **text, t_text *cursor)
{
	if(*text)
	{
		if (cursor == *text)
			printf("Cursor in start\n");
		else
			printf("Cursor not in start\n");
	}
	else
	{
		printf("List clear\n");
	}
}

static t_text	*lastSentence(t_text *lst)
{
	while (lst)
	{
		if (!lst->next)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}

static void cursorToEnd(t_text **text, t_text **cursor)
{
	
	if (*text)
	{
		*cursor = lastSentence(*text);
	}
	else
	{
		printf("List clear\n");
	}
}

static void cursorInEnd(t_text **text, t_text *cursor)
{
	if (*text)
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

static void	nextEl(t_text **text, t_text **cursor)
{
	if (*text)
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

static void	prevEl(t_text **text, t_text **cursor)
{
	if (*text)
	{
		if ((*cursor)->prev)
			*cursor = (*cursor)->prev;
		else
			printf("No el\n");
	}
	else
	{
		printf("List clear\n");
	}
}

static void	viewNextEl(t_text **text, t_text *cursor)
{
	if (*text)
	{
		if (cursor->next)
		{
			printSentence(&((*text)->sentence), (*text)->sentence);
		}
		else
			printf("No el\n");
	}
	else
	{
		printf("List clear\n");
	}
}

static void	viewPrevEl(t_text **text, t_text *cursor)
{
	if (*text)
	{
		if (cursor->prev)
		{
			printSentence(&((*text)->prev->sentence), (*text)->prev->sentence);
		}
		else
			printf("No el\n");
	}
	else
	{
		printf("List clear\n");
	}
}

static void	deleteNextEl(t_text **text, t_text *cursor)
{
	t_text	*temp;

	if (*text)
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
		cleanerSentence(&(temp->sentence), &(temp->sentence));
		free(temp);
	}
	else
	{
		printf("List clear\n");
	}
}

static void	deletePrevEl(t_text **text, t_text *cursor)
{
	t_text	*temp;

	if (*text)
	{
		if (!cursor->prev)
		{
			printf("No el\n");
			return ;
		}
		temp = cursor->prev;
		if (temp->prev)
		{
			cursor->prev = temp->prev;
		}
		else
		{
			cursor->prev = NULL;
			*text = cursor;
		}
		cleanerSentence(&(temp->sentence), &(temp->sentence));
		free(temp);
	}
	else
	{
		printf("List clear\n");
	}
}

static void	takeNextEl(t_text **text, t_text *cursor, t_text **taked)
{
	if ((*taked))
	{
		cleanerSentence(&((*taked)->sentence), &((*taked)->sentence));
		free(*taked);
		(*taked) = NULL;
	}
	if (*text)
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
			printf("Taked el: ");
			printSentence(&((*taked)->sentence), (*taked)->sentence);
			printf("\n");
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

static void	takePrevEl(t_text **text, t_text *cursor, t_text **taked)
{
	if ((*taked))
	{
		cleanerSentence(&((*taked)->sentence), &((*taked)->sentence));
		free(*taked);
		(*taked) = NULL;
	}
	if (*text)
	{
		if (cursor->prev)
		{
			(*taked) = cursor->prev;
			if ((*taked)->prev)
			{
				cursor->prev = (*taked)->prev;
			}
			else
			{
				cursor->prev = NULL;
				*text = cursor;
			}
			printf("Taked el: ");
			printSentence(&((*taked)->sentence), (*taked)->sentence);
			printf("\n");
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

static void	changeNextEl(t_text **text, t_text *cursor)
{
	if (*text)
	{
		if (cursor->next)
		{
			sentenceMenu(&(cursor->next->sentence));
		}
		else
		{
			printf("no elem\n");
		}text
	}
	else
	{
		printf("list clear\n");
	}
}

static void	changePrevEl(t_text **text, t_text *cursor)
{
	if (*text)
	{
		if (cursor->prev)
		{
			sentenceMenu(&(cursor->prev->sentence));
		}
		else
		{
			printf("notext elem\n");
		}
	}
	else
	{
		printf("list clear\n");
	}
}

static void	addAfterCursor(t_text **text, t_text **cursor)
{
	t_text	*temp;

	temp = malloc(sizeof(t_text));
	if (!temp)
	{
		printf("MEM ERROR\n");
		exit(1);
	}
	temp->next = NULL;text
	temp->prev = NULL;
	temp->sentence = NULL;
	sentenceMenu(&(temp->sentence));
	if (!*text)
	{
		*text = temp;
		*cursor = *text;
	}
	else
	{
		if ((*cursor)->next)
		{
			temp->next = (*cursor)->next;
			temp->next->prev = temp;
			(*cursor)->next = temp;
			temp->prev = (*cursor);
		}
		else
		{
			(*cursor)->next = temp;
			temp->prev = (*cursor);
		}

	}
}

static void	addBeforeCursor(t_text **text, t_text **cursor)
{
	t_text	*temp;

	temp = malloc(sizeof(t_text));
	if (!temp)
	{
		printf("MEM ERROR\n");
		exit(1);
	}
	temp->next = NULL;
	temp->prev = NULL;
	temp->sentence = NULL;
	sentenceMenu(&(temp->sentence));
	if (!*text)
	{
		*text = temp;
		*cursor = *text;
	}
	else
	{
		if ((*cursor)->prev)
		{
			temp->prev = (*cursor)->prev;
			temp->prev->next = temp;
			(*cursor)->prev = temp;
			temp->next = (*cursor);
		}
		else
		{
			(*cursor)->prev = temp;
			temp->next = (*cursor);
			*text = temp;
		}
	}
}

void	printText(t_text **text, t_text *cursor)
{
	t_text *list;

	list = *text;
	if (!list)
	{
		printf("List clear\n");
		return;
	}
	while (list)
	{text
		if (list == cursor)
			printf("=>\t");
		else
			printf("\t");
		printSentence(&list->sentence, list->sentence);
		list = list->next;
	}
	printf("\n");
}

void	textMenu(t_text	**text)
{
	int		flag;
	t_text	*cursor;
	t_text	*taked;

	if(!startWorkWithStruct("Text"))
		return;
	flag = 1;
	cursor = *text;
	taked = NULL;
	while (flag)
	{
		printText(text, cursor);
		printf("1. Cleaner\n2. Text clear?\n3. Cursor to start\n4. Cursor in start?\n5. Cursor to end\n6. Cursor in end?\n7. Next el\n8. Prev el\n9. View next el\n10. View prev el\n11. Delete next el\n12. Delete prev el\n13. Take next el\n14. Take prev el\n15. Change next\n16. Change prev\n17. Add after cursor\n18. Add before cursor\n19. Print\n0. Exit\n");
		scanf("%d", &flag);
		printf("\n");
		system("cls");
		switch (flag)
		{
		case 1:
			cleanerText(text, &cursor);
			break;
		case 2:
			emptytext(text);
			break;
		case 3:
			cursorToStart(text, &cursor);
			break;
		case 4:
			cursorInStart(text, cursor);
			break;
		case 5:
			cursorToEnd(text, &cursor);
			break;
		case 6:
			cursorInEnd(text, cursor);
			break;
		case 7:
			nextEl(text, &cursor);
			break;
		case 8:
			prevEl(text, &cursor);
			break;
		case 9:
			viewNextEl(text, cursor);
			break;
		case 10:
			viewPrevEl(text, cursor);
			break;
		case 11:
			deleteNextEl(text, cursor);
			break;
		case 12:
			deletePrevEl(text, cursor);
			break;
		case 13:
			takeNextEl(text, cursor, &taked);
			break;
		case 14:
			takePrevEl(text, cursor, &taked);
			break;
		case 15:
			changeNextEl(text, cursor);
			break;
		case 16:
			changePrevEl(text, cursor);
			break;
		case 17:
			addAfterCursor(text, &cursor);
			break;
		case 18:
			addBeforeCursor(text, &cursor);
			break;
		case 19:
			printText(text, cursor);
			break;
		case 0:
			break;
		default:
			printf("Input error\n");
			break;
		}
	}
}