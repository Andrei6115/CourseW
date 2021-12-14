#include "plenty.h"

void	cleanerPlenty(t_plenty **plenty)
{
	t_plenty	*tmp;
	t_plenty	*list;
	
	if (*plenty)
	{	
		list = *plenty;
		while (list)
		{
			tmp = list->next;
			cleanerText(&(list->text), &(list->text));
			list = tmp;
		}
		*plenty = NULL;
	}
	else
	{
		printf("Plenty clear\n");
	}
}

void isEmpty(t_plenty *plenty)
{
	if (!plenty)
		printf("List clear\n");
	else
		printf("List not clear\n");
}

int	equalPlenty(t_plenty *first, t_plenty *second)
{
	if(equalText(first->text, second->text))
	{
		return 1;
	}
	else
		return 0;

}

static t_plenty	*lastText(t_plenty *lst)
{
	while (lst)
	{
		if (!lst->next)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}

void addEl(t_plenty **plenty)
{
	t_plenty	*new;
	t_plenty	*last;
	t_plenty	*temp;

	new = malloc(sizeof(t_plenty));
	if (!new)
	{
		printf("MEM ERROR\n");
		exit(1);
	}
	new->next = NULL;
	new->prev = NULL;
	new->text = NULL;
	textMenu(&(new->text));
	temp = (*plenty);
	while (temp)
	{
		if (equalPlenty(temp, new))
		{
			printf("Equal el!\n");
			cleanerText(&(new->text), &(new->text));
			free (new);
			return;
		}
		temp = temp->next;
	}
	if (!*plenty)
	{
		*plenty = new;
	}
	else
	{
		last = lastText(*plenty);
		last->next = new;
		new->prev = last;
	}
}

void	deleteEl(t_plenty **plenty)
{
	t_plenty	*temp;
	t_plenty	*new;

	if (!*plenty)
	{
		printf("Plenty empty\n");
		return;
	}
	new = malloc(sizeof(t_plenty));
	if (!new)
	{
		printf("MEM ERROR\n");
		exit(1);
	}
	new->next = NULL;
	new->prev = NULL;
	new->text = NULL;
	textMenu(&(new->text));
	temp = (*plenty);
	while (temp)
	{
		if (equalPlenty(temp, new))
		{
			cleanerText(&(new->text), &(new->text));
			free (new);
			if (temp->next && temp->prev)
			{
				temp->prev->next = temp->next;
				temp->next->prev = temp->prev;
				cleanerText(&(temp->text), &(temp->text));
				free (temp);
			}
			else if (temp->next)
			{
				*plenty = temp->next;
				temp->next->prev = NULL;
				cleanerText(&(temp->text), &(temp->text));
				free (temp);
			}
			else if (temp->prev)
			{
				temp->prev->next = NULL;
				cleanerText(&(temp->text), &(temp->text));
				free (temp);
			}
			else
			{
				cleanerText(&(temp->text), &(temp->text));
				free (temp);
				*plenty = NULL;
			}
			return;
		}
		temp = temp->next;
	}
}

void	takeEl(t_plenty **plenty, t_plenty **taked)
{
	t_plenty	*temp;
	t_plenty	*new;

	if (!*plenty)
	{
		printf("Plenty empty\n");
		return;
	}
	new = malloc(sizeof(t_plenty));
	if (!new)
	{
		printf("MEM ERROR\n");
		exit(1);
	}
	new->next = NULL;
	new->prev = NULL;
	new->text = NULL;
	textMenu(&(new->text));
	temp = (*plenty);
	
	while (temp)
	{
		if (equalPlenty(temp, new))
		{
			if (*taked)
			{

				cleanerText(&((*taked)->text), &((*taked)->text));
				free (*taked);
				*taked = NULL;
			}
			cleanerText(&(new->text), &(new->text));
			free (new);
			if (temp->next && temp->prev)
			{
				temp->prev->next = temp->next;
				temp->next->prev = temp->prev;
				*taked = temp;
			}
			else if (temp->next)
			{
				*plenty = temp->next;
				temp->next->prev = NULL;
				*taked = temp;
			}
			else if (temp->prev)
			{
				temp->prev->next = NULL;
				*taked = temp;
			}
			else
			{
				*taked = temp;
				*plenty = NULL;
			}
			return;
		}
		temp = temp->next;
	}
}

void searchEl(t_plenty **plenty)
{
	t_plenty	*new;
	t_plenty	*temp;

	new = malloc(sizeof(t_plenty));
	if (!new)
	{
		printf("MEM ERROR\n");
		exit(1);
	}
	new->next = NULL;
	new->prev = NULL;
	new->text = NULL;
	textMenu(&(new->text));
	temp = (*plenty);
	while (temp)
	{
		if (equalPlenty(temp, new))
		{
			printf("Equal el\n");
			cleanerText(&(new->text), &(new->text));
			free (new);
			return;
		}
		temp = temp->next;
	}
	printf("Not equal el\n");
}		

void	printPlenty(t_plenty *plenty)
{
	if (plenty)
	{
		while (plenty)
		{
			printText(&(plenty->text), plenty->text);
			printf("===============================\n");
			plenty = plenty->next;
		}
	}
	else
	{
		printf("Empty plenty\n");
	}
}

void	plentyMenu()
{
	int			flag;
	t_plenty	*taked;
	t_plenty	*plenty;

	if(!startWorkWithStruct("Plenty"))
		return;
	flag = 1;
	plenty = NULL;
	taked = NULL;
	while (flag)
	{
		printPlenty(plenty);
		printf("1. Cleaner\n2. Plenty clear?\n3. Delete El\n4. Take el\n5. Add el\n6. Search el\n7. Print\n0. Exit\n");
		scanf("%d", &flag);
		printf("\n");
		system("cls");
		
		switch (flag)
		{
		case 1:
			cleanerPlenty(&plenty);
			break;
		case 2:
			isEmpty(plenty);
			break;
		case 3:
			deleteEl(&plenty);
			break;
		case 4:
			takeEl(&plenty, &taked);
			break;
		case 5:
			addEl(&plenty);
			break;
		case 6:
			searchEl(&plenty);
			break;
		case 7:
			printPlenty(plenty);
			break;
		case 0:
			return;
		default:
			printf("Input error\n");
			break;
		}
	}
}