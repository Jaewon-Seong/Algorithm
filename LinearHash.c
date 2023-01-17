#include <stdio.h>
#include <stdlib.h>

#define TABLESIZE 13

int table[8] = { 10, 20, 30, 40, 33, 46, 50, 60 };
int linearArr[TABLESIZE];		//HashTable storing data in linearHash, if there are no data 0

void linearHash();
void hashPrint();

int main()
{
	printf("Linear Hash\n");
	linearHash();

	return 0;
}

void linearHash()
{
	int key;		//Location of data stored in HashTable

	for (int i = 0; i < (sizeof(table) / sizeof(table[0])); i++)
	{
		key = (table[i] % 13);

		if (linearArr[key] != 0)		//If key exists in HashTable
		{
			while (1)
			{
				if (key == TABLESIZE - 1)		//If key value is same with the number of data, overflow happens. Then change key value to 0
					key = 0;
				else
				{
					if (linearArr[key + 1] == 0)		//Check next HashTable of key is empty
					{
						linearArr[key + 1] = table[i];		//If HashTable is empty, store data
						break;
					}
					else
						key++;		//If data exist in the next HashTable, increase key
				}

			}
		}
		else
			linearArr[key] = table[i];		//Store data if there are no data in key of HashTable

		if (i > 3)		
		{
			printf("\nAfter %d input, HashTable\n", table[i]);
			hashPrint();
		}
	}
}

void hashPrint()
{
	for (int i = 0; i < TABLESIZE; i++)
	{
		if (linearArr[i] == 0)
			printf("HashTable[%d] : empty\n", i);		//No data in HashTable, print empty
		else
			printf("HashTable[%d] : %d\n", i, linearArr[i]);		//Print data in HashTable
	}
}