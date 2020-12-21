#include <cstdio>

char passbuf[256];
int main()
{
	FILE *fin = fopen("input.txt", "r");

	if (!fin) {
		fprintf(stderr, "Unable to open input file\n");
		return 1;
	}

	int res = 0;

	int lo, hi;
	char c;
	while (fscanf(fin, "%d-%d %c: %s", &lo, &hi, &c, passbuf) == 4) {
		int count = 0;
		for (char *pc = passbuf;count <= hi && *pc; pc++) {
			if (*pc == c)
				count++;
		}

		if (lo <= count && count <= hi)
			res++;
	}

	fclose(fin);

	printf("%d\n", res);

	return 0;
}