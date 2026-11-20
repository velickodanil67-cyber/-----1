#include "loc_max_func.h"

int main(void)
{
	FILE *f = fopen("input_data.txt", "r");
	if (f == NULL)
	{
		printf("File error\n");
		return -1;
	}
	else
	{
		int result = max_local_maximum_len(f);
		printf("Answer (max length of local maximum): %d\n", result);
		fclose(f);
		return 0;
	}
}