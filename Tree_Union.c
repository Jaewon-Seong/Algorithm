#include <stdio.h>

char UnionTree[10] = "abcdefghi";		//Set to be a string
int index[9];		//Array that stores parent node values
int size[9];		//Array containing size including child nodes directly below

void MakeSize();		//Initialize the size of a set to 1
int GetRoot(int x);		//Get Root of a set
void Union(int x, int y);		//Merge two sets into one

int main()
{
	for (int i = 0; i < 9; i++)
		index[i] = i;

	MakeSize();
	
	//Initial state
	Union(0, 1);
	Union(3, 4);
	Union(5, 6);
	Union(5, 7);
	Union(5, 8);
	
	printf("Initial State\n");

	for (int i = 0; i < 9; i++)
		printf("%c's parent : %c // root : %c\n", UnionTree[i], UnionTree[index[i]], UnionTree[GetRoot(i)]);		

	//Combined sets of a
	Union(0, 2);
	
	printf("\nCombined sets of a\n");

	for (int i = 0; i < 3; i++)
		printf("%c's parent : %c // root : %c\n", UnionTree[i], UnionTree[index[i]], UnionTree[GetRoot(i)]);

//Combined sets of b
	Union(3, 5);
	
	printf("\nCombined sets of b\n");

	for (int i = 3; i < 9; i++)
		printf("%c's parent : %c // root : %c\n", UnionTree[i], UnionTree[index[i]], UnionTree[GetRoot(i)]);

	//Total set combined state
	Union(3, 0);

	printf("\nTotal set combined state\n");

	for (int i = 0; i < 9; i++)
		printf("%c's parent : %c // root : %c\n", UnionTree[i], UnionTree[index[i]], UnionTree[GetRoot(i)]);

	return 0;
}

void MakeSize()
{
	for (int i = 0; i < 9; i++)		//Initialize the size of every node to 1
		size[i] = 1;
}


int GetRoot(int x)
{
	if (index[x] == x)
		return x;
	return GetRoot(index[x]);		//Get Root using recursion
}

void Union(int x, int y)
{
	x = GetRoot(x);		//Store the root node of x
	y = GetRoot(y);		//Store the root node of x

	if (x == y)		//If they have same root node, the process of merging does not need
		return;
	
	if (size[x] >= size[y])			//Conditions for combining a set of x and a set of y based on a larger set
	{
		index[y] = index[x];		//Save and merge parent nodes of smaller nodes as parent nodes of larger nodes
		size[x]++;		//Increase the size of the set after they are combined
	}
	else
	{
		index[x] = index[y];
		size[y]++;
	}
}