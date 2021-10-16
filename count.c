#include "count.h"

int main(int argc, char** argv)
{
	if(argc < 2)
	{
		printf("error\n");
		return 0;
	}
	Htable* table = (Htable*)malloc(sizeof(Htable));
	FILE* f = fopen(argv[1], "r");
	if(f == NULL)
	{
		printf("error\n");
		return 0;
	}
	char address[15];
	while(fscanf(f, "%s", &address) == 1)
	{
		long long dec = getVal(address);
		insert(dec, table);
	}
	int res = countNum(table);
	printf("%d", res);
	printf("\n");
	return 1;
} 	
