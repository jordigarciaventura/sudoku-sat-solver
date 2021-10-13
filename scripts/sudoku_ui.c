#include <stdio.h>
#include <ctype.h>

int main()
{
	int sol[81] = {0};
	int n = 0, i = 0, k = 0;
	
	char c1, c2, c3;
	
	scanf("%c", &c1);
	
	while(i < 81)
	{	
		if(isdigit(c1))
		{
			scanf("%c", &c2);
			if (isdigit(c2))
			{
				scanf("%c", &c3);
				if (isdigit(c3))
				{
					sol[i] = (int)(c1 - '0')*100 + (int)(c2 - '0')*10 + (int)(c3 - '0');
				}
				else
				{
					sol[i] = (int)(c1 - '0')*10 + (int)(c2 - '0');
				}
			}
			else
			{
				sol[i] = (int)(c1 - '0');
			}
			i++;
		}
		else if (c1 == '-')
		{
			scanf("%i", &k);
		} else if (c1 == 'U') {
			printf("UNSATISFIABLE\n");
			return 0;
		}
		
		scanf("%c", &c1);
	}
	
	printf("SOLUTION:\n");
	for(i = 0; i < 81; i++)
	{
		if (i % 27 == 0 && i != 0)
		{
			printf("\n -----   -----   -----\n");
		}
		else if (i % 9 == 0)
		{
			printf("\n");
		}
		else if (i % 3 == 0)
		{
			printf(" |");
		}
	
		sol[i] -= i*9;
		printf(" %i", sol[i]);
	}
	printf("\n\n");
}
