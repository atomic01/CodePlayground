#include <stdio.h>
#include <stdlib.h>
#include "qdbmp.h"

int main()
{
	UINT x = 0, y = 0;
	UCHAR r = 0, g = 0, b = 0;
	const char* filename = "picture.bmp";

	BMP* bmp = BMP_ReadFile(filename);
	UINT width = BMP_GetWidth(bmp);
	UINT height = BMP_GetHeight(bmp);

	
	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < height; j++)
		{
			BMP_GetPixelRGB(bmp, i, j, &r, &g, &b);
			BMP_SetPixelRGB(bmp, i, j, r, 0, g);
		}
	}

	BMP_WriteFile(bmp, "result.bmp");
	BMP_Free(bmp);

	return 0;
}