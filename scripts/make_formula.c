#include <stdio.h>

#define M 729
int main()
{
	//Squares
	for (int i = 1; i <= 721; i+=9)
	{
		for (int n = i; n < (i+9); n++)
		{
			printf("%i ", n);
		}
		printf("0\n");
		
		for (int j = i; j < i+9; j++)
		{
			for (int k = j+1; k < i+9; k++)
			{
				printf("-%i -%i 0\n", j, k);
			}
		}
	}
	
	
	//Columns
	for (int x = 1; x <= 73; x+=9)
	{
		for (int y = x; y < (x+9) ; y++)
		{
			for (int n = y; n <= (y+648); n+=81)
			{
				printf("%i ", n);
			}
			printf("0\n");
	
			
			for (int z = y; z <= (x+648);z+=81)
			{
				for (int k = z+81; k <= (y+648); k+=81)
				{
					printf("-%i -%i 0\n", z, k);
				}
			}
			
		}
	}
	
	//Rows
	for (int y = 1; y <= 649; y+=81)
	{
		for (int x = y; x < (y+9); x++)
		{
			for (int n = x; n <= (x+72); n+= 9)
			{
				printf("%i ", n);
			}
			printf("0\n");
			
			for (int z = x; z <= (y+72); z+=9)
			{
				for (int k = z+9; k <= (x+72); k+=9)
				{
					printf("-%i -%i 0\n", z, k);
				}
			}
		}
	}
	
	//Cells
	int c1[9] = {1, 10, 19, 82, 91, 100, 163, 172, 181};
	for (int k = 0; k < 9; k++)
	{
		for (int n = 0; n < 9; n++)
		{
			printf("%i ", c1[n]+k);
		}
		printf("0\n");
	
		for (int i = 0; i < 9; i++)
		{
			for (int j = i+1; j < 9; j++)
			{
				printf("-%i -%i 0\n", c1[i]+k, c1[j]+k);
			}
		}	
	}
	
	int c2[9] = {28, 37, 46, 109, 118, 127, 190, 199, 208};
	for (int k = 0; k < 9; k++)
	{
		for (int n = 0; n < 9; n++)
		{
			printf("%i ", c2[n]+k);
		}
		printf("0\n");
	
		for (int i = 0; i < 9; i++)
		{
			for (int j = i+1; j < 9; j++)
			{
				printf("-%i -%i 0\n", c2[i]+k, c2[j]+k);
			}
		}	
	}
	
	int c3[9] = {55, 64, 73, 136, 145, 154, 217, 226, 235};
	for (int k = 0; k < 9; k++)
	{
		for (int n = 0; n < 9; n++)
		{
			printf("%i ", c3[n]+k);
		}
		printf("0\n");
	
		for (int i = 0; i < 9; i++)
		{
			for (int j = i+1; j < 9; j++)
			{
				printf("-%i -%i 0\n", c3[i]+k, c3[j]+k);
			}
		}	
	}
	
	int c4[9] = {244, 253, 262, 325, 334, 343, 406, 415, 424};
	for (int k = 0; k < 9; k++)
	{
		for (int n = 0; n < 9; n++)
		{
			printf("%i ", c4[n]+k);
		}
		printf("0\n");
	
		for (int i = 0; i < 9; i++)
		{
			for (int j = i+1; j < 9; j++)
			{
				printf("-%i -%i 0\n", c4[i]+k, c4[j]+k);
			}
		}	
	}
	
	int c5[9] = {271, 280, 289, 352, 361, 370, 433, 442, 451};
	for (int k = 0; k < 9; k++)
	{
		for (int n = 0; n < 9; n++)
		{
			printf("%i ", c5[n]+k);
		}
		printf("0\n");
	
		for (int i = 0; i < 9; i++)
		{
			for (int j = i+1; j < 9; j++)
			{
				printf("-%i -%i 0\n", c5[i]+k, c5[j]+k);
			}
		}	
	}
	
	int c6[9] = {298, 307, 316, 379, 388, 397, 460, 469, 478};
	for (int k = 0; k < 9; k++)
	{
		for (int n = 0; n < 9; n++)
		{
			printf("%i ", c6[n]+k);
		}
		printf("0\n");
	
		for (int i = 0; i < 9; i++)
		{
			for (int j = i+1; j < 9; j++)
			{
				printf("-%i -%i 0\n", c6[i]+k, c6[j]+k);
			}
		}	
	}
	
	int c7[9] = {487, 496, 505, 568, 577, 586, 649, 658, 667};
	for (int k = 0; k < 9; k++)
	{
		for (int n = 0; n < 9; n++)
		{
			printf("%i ", c7[n]+k);
		}
		printf("0\n");
	
		for (int i = 0; i < 9; i++)
		{
			for (int j = i+1; j < 9; j++)
			{
				printf("-%i -%i 0\n", c7[i]+k, c7[j]+k);
			}
		}	
	}
	
	int c8[9] = {514, 523, 532, 595, 604, 613, 676, 685, 694};
	for (int k = 0; k < 9; k++)
	{
		for (int n = 0; n < 9; n++)
		{
			printf("%i ", c8[n]+k);
		}
		printf("0\n");
	
		for (int i = 0; i < 9; i++)
		{
			for (int j = i+1; j < 9; j++)
			{
				printf("-%i -%i 0\n", c8[i]+k, c8[j]+k);
			}
		}	
	}
	
	int c9[9] = {541, 550, 559, 622, 631, 640, 703, 712, 721};
	for (int k = 0; k < 9; k++)
	{
		for (int n = 0; n < 9; n++)
		{
			printf("%i ", c9[n]+k);
		}
		printf("0\n");
	
		for (int i = 0; i < 9; i++)
		{
			for (int j = i+1; j < 9; j++)
			{
				printf("-%i -%i 0\n", c9[i]+k, c9[j]+k);
			}
		}	
	}
}
