#include <stdio.h>
#include <stdlib.h>


typedef struct _TreeNode {		//Define Node
	char value;
	struct _TreeNode* left;
	struct _TreeNode* right;
} TreeNode;

typedef TreeNode* Tree;

Tree makeNode(char value);		//Make Node
void addData(Tree node, char parent, char leftChild, char rightChild);		//Add Data to Node
Tree searchNode(Tree root, char value);		//Search Parent Node
void treeInOrder(Tree root);				//Print Node InOrder wirh Recursion

int main()
{
	int n;		//The Number of Binary Tree Node
	Tree root = makeNode('\0');			// Make Root Node, Initialize '\0'
	Tree now;		//Node Pinter to find Data

	scanf("%d", &n);
	getchar();		//Buffer flush

	for (int i = 0; i < n; i++)
	{
		char parent, leftChild, rightChild;
		scanf("%c %c %c", &parent, &leftChild, &rightChild);
		getchar();		//Buffer flush
		now = searchNode(root, parent);
		if (now != NULL)
			addData(now, parent, leftChild, rightChild);
		else
			addData(root, parent, leftChild, rightChild);		//When Root Node
	}

	treeInOrder(root);		//Print Tree InOrder

	return 0;
}

Tree makeNode(char value)
{
	Tree newNode = (Tree)malloc(sizeof(TreeNode));		//Allocate the size of TreeNode making a new Node

	newNode->value = value;		//Store value in data on a Node
	newNode->left = NULL;		//Initialize left Node
	newNode->right = NULL;		//Initialize right Node

	return newNode;		//Return the address of new Node, Link other's child
}

void addData(Tree node, char parent, char leftChild, char rightChild)
{
	node->value = parent;

	if (leftChild != '.')		//if there is a left child data
		node->left = makeNode(leftChild);			//Make left child Node and store data

	if (rightChild != '.')		//if there is a right child data
		node->right = makeNode(rightChild);		//Make right right child Node and store data
}

Tree searchNode(Tree root, char value)		//Send data and the address of parent Node
{
	if (root != NULL)
	{
		if (root->value == value)
			return root;
		else
		{
			Tree now = searchNode(root->left, value);		//Make new Node to Search

			if (now != NULL)
				return now;
			else
				return searchNode(root->right, value);
		}
	}
	return root;
}

void treeInOrder(Tree root)
{
	if (root != NULL)
	{
		treeInOrder(root->left);		//Recursive Call to left child Node
		printf("%c", root->value);		//Print parent data
		treeInOrder(root->right);		//Recursive Call to right child Node
	}
}