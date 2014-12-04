#include <stdio.h>
#include <stdlib.h>

char grey2ascii[] = " .:,;'-~+=!?%$*#@";

int main(int argc, char **argv)
{
	FILE *rle;
	char c1, c2;
	int c, col, rle_count, rle_char;

	if (argc < 2)
	{
		fprintf(stderr, "Include file to convert on command line.\n");
		exit(1);
	}
	if (rle = fopen(argv[1], "r"))
	{
		col = 40;
		while (fscanf(rle, "\t.BYT\t$%c%c\n", &c1, &c2) == 2)
		{
			rle_count = c1 > '9' ? c1 - 'A' + 10 : c1 - '0';
			rle_char = grey2ascii[c2 > '9' ? c2 - 'A' + 10 : c2 - '0'];
			while (rle_count--)
			{
				putchar(rle_char);
				if (!--col)
				{
					putchar('\n');
					col = 40;
				}
			}
		}
		putchar('\n');
		fclose(rle);
	}
	return (0);
}
