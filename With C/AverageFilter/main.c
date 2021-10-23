#include <stdio.h>
#include <stdlib.h>

int main() {
	FILE *PGM;
	int w = 0, h = 0, maxGray, i, j = 0, k, t, x, z = 0;
	char c1, c2;
	static int pixel[512][512];
	static int pixelCopy[512][512];
	
	PGM = fopen("C:\\Users\\Administrator\\Desktop\\BLM4540 Gor.Is\\Odev1\\averageFilter\\lena.ascii.pgm","rb");
	if (PGM == NULL)
		return -58;
	
	//READING
	printf("Image reading...\n");
	fscanf(PGM, "%c%c %d %d %d", &c1, &c2, &w, &h, &maxGray);
	printf("H: %d, W: %d, maxGray: %d\n", w, h, maxGray);
	while(!feof(PGM)) {
		for (i = 0; i < h; i++){
			fscanf(PGM, "%d", &pixel[j][i]);
			pixelCopy[j][i] = pixel[j][i];
		}
		j++;
	}
	fclose(PGM);
	printf("Image readed!\nWhats your (XnX) X: ");
	scanf("%d", &x);
	
	//AVERAGE FILTERING (flexible version)
	int padding = (x-1) / 2;
	for (i = padding; i < w - padding; i++)
		for (j = padding; j < h - padding; j++){
			int sum = 0; z = 0;
			for (k = i - padding; k < i + padding + 1; k++)
				for(t = j - padding; t < j + padding + 1; t++)
					sum += pixel[t][k];
			sum = sum - pixel[j][i];
			pixelCopy[j][i] = sum / (x*x);
		}
	
	//REWRITING
	PGM = fopen("C:\\Users\\Administrator\\Desktop\\BLM4540 Gor.Is\\Odev1\\averageFilter\\lena.ascii_filtered.pgm","w");
	fprintf(PGM, "%c%c %d %d %d\n", c1, c2, w, h, maxGray);
	for(i = 0; i < w; i++) {
		for(j = 0; j < h; j++)
			fprintf(PGM, "%d ", pixelCopy[i][j]);
		fprintf(PGM, "\n");
	}
	fclose(PGM);
	
	
	return 0;
}
