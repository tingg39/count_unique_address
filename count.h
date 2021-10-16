#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct node
{
	long long val;
	struct node *next;
} Node;

typedef struct htable
{
	Node* arr[1000];
} Htable;

int hashNum(long long n)
{
	int num = (int)(n % 1000);
	return num;
}

int getCharVal(char c)
{
	if( c == 'a' || c == 'A')
	{
		return 10;
	}else if(c == 'b' || c == 'B')
	{
		return 11;
	}else if(c == 'c' || c == 'C')
	{
		return 12;
	}else if(c == 'd' || c == 'D')
	{
		return 13;
	}else if(c == 'e' || c == 'E')
	{
		return 14;
	}else if(c == 'f' || c == 'F')
	{
		return 15;
	}else if(c == '1')
	{
		return 1;
	}else if(c == '2')
	{
		return 2;
	}else if(c == '3')
	{
		return 3;
	}else if(c == '4')
	{
		return 4;
	}else if(c == '5')
	{
		return 5;
	}else if(c == '6')
	{
		return 6;
	}else if(c == '7')
	{
		return 7;
	}else if(c == '8')
	{
		return 8;
	}else if(c == '9')
	{
		return 9;
	}else if(c == '0')
	{
		return 0;
	}
}

long long getVal(char address[15])
{
	if(address[0] != '0' || address[1] != 'x')
	{
		printf("error\n");
	}
	int j = 2;
	while(address[j] != '\0')
	{
		j = j + 1;
	}
	int i = 0;
	long long result = 0;
	for(i; i < j; i++)
	{
		int num = getCharVal(address[i+2]);
		result = result + num * pow(16, j - 3 - i);
	}
	return result;
}

void insert(long long n, Htable* table)
{
	int index = hashNum(n);
	if(index >= 1000 || index < 0)
	{
		printf("error\n");
		return;
	}
	if(table->arr[index] == NULL)
	{
		Node* nnode = (Node*)malloc(sizeof(Node));
		nnode->val = n;
		nnode->next = NULL;
		table->arr[index] = nnode;
	}else
	{
		Node* temp = table->arr[index];
		if(temp->val == n)
		{
			return;
		}
		while(temp->next != NULL)
		{
			if(temp->val == n)
			{
				return;
			}
			temp = temp->next;
		}
		if(temp->val == n)
		{
			return;
		}
		Node* nnode = (Node*)malloc(sizeof(Node));
		nnode->val = n;
		nnode->next = NULL;
		temp->next = nnode;
	}
}

int countNum(Htable* table)
{
	int size = 0;
	int i = 0;
	for(i; i < 1000; i++)
	{
		Node* temp = table->arr[i];
		if(temp == NULL)
		{
			continue;
		}else{
			size = size + 1;
			while(temp->next != NULL)
			{
				size = size + 1;
				temp = temp->next;
			}
		}
	}
	return size;
}	
