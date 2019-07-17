#include <stdio.h>

#include "myJpeg.h"

int main(int argc, char* argv[]) {

	RAWDATA_t raw;
	int x, y;
	unsigned char r, g, b;
	char outname[256];

	if (argc != 2) {
		printf("ファイル名指定してください\n");
		return -1;
	}

	if (jpegFileReadDecode(&raw, argv[1]) == -1) {
		printf("jpegFileReadDecode error\n");
		return -1;
	}

	printf("取得したい画素のX座標は？");
	scanf("%d", &x);
	if (x < 0 || x >= raw.width - 1) {
		printf("座標がおかしいです\n");
		return -1;
	}
	printf("取得したい画素のY座標は？");
	scanf("%d", &y);
	if (y < 0 || y >= raw.height - 1) {
		printf("座標がおかしいです\n");
		return -1;
	}

	/* 画素値取得 */
	r = raw.data[y * raw.width * raw.ch + x * raw.ch];
	g = raw.data[y * raw.width * raw.ch + x * raw.ch + 1];
	b = raw.data[y * raw.width * raw.ch + x * raw.ch + 2];

	printf("画素値はR=%d, G=%d, B=%dです\n", r, g, b);


	freeRawData(&raw);

	return 0;
}