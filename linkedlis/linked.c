#include <stdio.h>
#include <stdlib.h>

struct node
{
	int val;
	struct node *next;
}node;

struct node *create_node(struct node *newnode, int num)/*create new node and assig value*/
{
	struct node *temp;

	temp = malloc(sizeof(node));
	newnode = malloc(sizeof(node));
	
	newnode->val = num;
	newnode->next = temp;
	temp->next = NULL;

	return (newnode);
}

int main(void)
{
	struct node *head;

	int i = 2;

	for (; i < 21; i += 2)
		printf("%d\n", create_node(head, i)->val);

	return (0);
}
