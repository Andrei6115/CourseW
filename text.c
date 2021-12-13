#include "text.h"
int	equalText(t_text *first, t_text *second)
{
}

void	cleanerText(t_text **text, t_text *cursor)
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
		cursor = *text;
	}
	else
	{
		printf("List clear\n");
	}
}

void	emptytext(t_text **text)
{
	if (*text == NULL)
		printf("List clear\n");
	else
		printf("List not clear\n");
}

void	cursorToStart(t_text **text, t_text **cursor)
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

void	cursorInStart(t_text **text, t_text *cursor)
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

t_text	*lastWord(t_text *lst)
{
	while (lst)
	{
		if (!lst->next)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}

void cursorToEnd(t_text **text, t_text **cursor)
{
	
	if (*text)
	{
		*cursor = lastWord(*text);
	}
	else
	{
		printf("List clear\n");
	}
}

void cursorInEnd(t_text **text, t_text *cursor)
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

void	nextEl(t_text **text, t_text **cursor)
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

void	viewNextEl(t_text **text, t_text *cursor)
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

void	deleteNextEl(t_text **text, t_text *cursor)
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
	}
	else
	{
		printf("List clear\n");
	}
}

void	takeEl(t_text **text, t_text *cursor, t_text **taked)
{
	if ((*taked))
	{
		cleanerSentence(&((*taked)->sentence), &((*taked)->sentence));
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

void	changeNextEl(t_text **text, t_text *cursor)
{
	if (*text)
	{
		if (cursor->next)
		{
			sentenceMenu(&((*text)->sentence));
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


void	addEl(t_text **text, t_text **cursor)
{
	t_text	*temp;

	temp = malloc(sizeof(t_text));
	if (!temp)
	{
		printf("MEM ERROR\n");
		exit(1);
	}
	temp->next = NULL;
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
			(*cursor)->next = temp;
		}
		else
		{
			(*cursor)->next = temp;
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
	{
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
	int			flag;
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
		printf("1. Cleaner\n2. Text clear?\n3. Cursor to start\n4. Cursor in start?\n5. Cursor to end\n6. Cursor in end?\n7. Skip el\n8. View Next el\n9. Delete next\n10. Take el\n11. Change next\n12. Add el\n13. Print\n0. Exit\n");
		scanf("%d", &flag);
		printf("\n");
		system("cls");
		
		switch (flag)
		{
		case 1:
			cleanerText(text, cursor);
			break;
		case 2:
			
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
			viewNextEl(text, cursor);
			break;
		case 9:
			deleteNextEl(text, cursor);
			break;
		case 10:
			takeEl(text, cursor, &taked);
			break;
		case 11:
			changeNextEl(text, cursor);
			break;
		case 12:
			addEl(text, &cursor);
			break;
		case 13:
		printText(text, cursor);
			break;
		case 0:
			break;
		default:
			break;
		}
	}
}