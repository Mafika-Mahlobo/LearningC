#include <stdio.h>
#include <stdlib.h>
#include "main.h"

int main(void)
{
	struct node *temp = malloc(sizeof(struct node))
	struct node *current = malloc(sizeof(struct node));

	if (temp == NULL || current == NULL)
		return (1);

	temp = create_node(current, 5);

	while (temp != NULL)
	{
		printf("%d\n", temp->val);
		temp = temp->next;
	}

	while (current != NULL)
	}
		current->next;
		free(current);
	}
}

