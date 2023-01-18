#include <stdio.h>
#include <stdlib.h>

#define TABLESIZE 13
int table[8] = { 10, 20, 30, 40, 33, 46, 50, 60 };

typedef struct node {
	int data;
	struct node* next;
}Node;

Node* chainedArr[TABLESIZE];

void chainedHash(Node* node, int value);
void hashPrint();

int main()
{
	printf("Chain\n");

	for (int i = 0; i < (sizeof(table) / sizeof(table[0])); i++)
	{
		Node* node = (Node*)malloc(sizeof(Node));
		node->data = table[i];
		node->next = NULL;

		chainedHash(node, node->data);

		if (i > 3)
		{
			printf("\nAfter %d input, HashTable\n", table[i]);
			hashPrint();
		}
	}

	return 0;
}

void chainedHash(Node* node, int value)
{
	int key = value % 13;

	if (chainedArr[key] == NULL)
		chainedArr[key] = node;
	else
	{
		node->next = chainedArr[key];		//Link node if there exist data in the key of HashTable
		chainedArr[key] = node;
	}
}

void hashPrint()
{
	for (int i = 0; i < TABLESIZE; i++)
	{
		printf("HashTable[%d] : ", i);

		if (chainedArr[i] != NULL)
		{
			Node* node = chainedArr[i];

			while (node->next)
			{
				printf("%d ", node->data);
				node = node->next;
			}
			printf("%d\n", node->data);
		}
		else
			printf("empty\n");
	}
}