#include <stdio.h>
#include <stdlib.h>

char mapascii[16] =	{' ', '.', ':', ';', '-', '"', '^', '~',
			 '+', '=', '*', 'X', '%', '#', '&', '@'};
int main(int argc, char **argv)
{
	FILE *pbm;
	unsigned char *c, *image;
	int width, height, depth, i, j;
	int rle_count, rle_char, rle_size;
	int newline;

	if (argc < 2)
	{
		fprintf(stderr, "Supply PBM filename\n");
		exit(1);
	}
	if (pbm = fopen(argv[1], "rb"))
	{
		if (fscanf(pbm, "P5\n%d\n%d\n%d\n", &width, &height, &depth) == 3)
		{
			rle_size = 0;
			rle_count = 0;
			rle_char = -1;
			image = malloc(width * depth);
			fread(image, width, height, pbm);
			c = image;
			for (j = 0; j < height; j++)
			{
				//printf("\n\t.BYT\t");
				newline = 1;
				for (i = 0; i < width; i++)
				{
					if ((*c >> 4) == rle_char)
					{
						if (rle_count < 15)
							rle_count++;
						else
						{
							//if (!newline)
							//	printf(",");
							//else
							//	newline=0;
							//printf("$%1X%1X", rle_count, rle_char);
							printf("\t.BYT\t$%1X%1X\n", rle_count, rle_char);
							rle_count = 1;
							rle_size++;
						}
					}
					else
					{
						if (rle_char >= 0)
						{
							//if (!newline)
							//	printf(",");
							//else
							//	newline=0;
							//printf("$%1X%1X", rle_count, rle_char);
							printf("\t.BYT\t$%1X%1X\n", rle_count, rle_char);
						}
						rle_char = (*c >> 4);
						rle_count = 1;
						rle_size++;
					}
					c++;
				}
				putc('\n', stderr);
			}
			//if (!newline)
			//	printf(",");
			//else
			//	newline=0;
			//printf("$%1X%1X", rle_count, rle_char);
			printf("\t.BYT\t$%1X%1X\n", rle_count, rle_char);
			printf("\t.BYT\t$00\n");
			rle_size++;
		}
		fclose(pbm);
		fprintf(stderr, "\nRLE image size = %d\n", rle_size);
	}
	return (0);
}
