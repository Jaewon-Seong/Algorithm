#include <stdio.h>
#include <stdlib.h>

#define TABLESIZE 13

int table[8] = { 10, 20, 30, 40, 33, 46, 50, 60 };
int doubleArr[TABLESIZE]; 		//HashTable storing data in DoubleHash, if there are no data 0

void doubleHash();
void hashPrint();

int main()
{
	printf("DoubleHash\n");
	doubleHash();

	return 0;
}

void doubleHash()
{
	int key;		//Location of data stored in HashTable

	for (int i = 0; i < (sizeof(table) / sizeof(table[0])); i++)
	{
		key = (table[i] % 13);

		if (doubleArr[key] != 0)		//If key exists in HashTable	
		{
			int quadra = 1;		//Variable to increase key value, after storing value, return location to 1
			int key2 = 0;		//Increases key value, after storing value in table, return value to 0

			while (1)
			{
				key2 = key + quadra * quadra;

				if (key2 >= TABLESIZE)
					key2 = key + quadra * quadra - 13;		//To solve overflow, change key value

				{
					if (doubleArr[key2] == 0)
					{
						doubleArr[key2] = table[i];
						break;
					}
					else
					{
						quadra++;
					}
				}
			}
		}
		else
			doubleArr[key] = table[i];

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
		if (doubleArr[i] == 0)
			printf("HashTable[%d] : empty\n", i);		//No data in HashTable, print empty
		else
			printf("HashTable[%d] : %d\n", i, doubleArr[i]);		//Print data in HashTable
	}
}