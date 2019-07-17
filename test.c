#include <stdio.h>

#include "myJpeg.h"

int main(int argc, char* argv[]) {

	RAWDATA_t raw;
	int x, y;
	unsigned char r, g, b;
	char outname[256];

	if (argc != 2) {
		printf("�t�@�C�����w�肵�Ă�������\n");
		return -1;
	}

	if (jpegFileReadDecode(&raw, argv[1]) == -1) {
		printf("jpegFileReadDecode error\n");
		return -1;
	}

	printf("�擾��������f��X���W�́H");
	scanf("%d", &x);
	if (x < 0 || x >= raw.width - 1) {
		printf("���W�����������ł�\n");
		return -1;
	}
	printf("�擾��������f��Y���W�́H");
	scanf("%d", &y);
	if (y < 0 || y >= raw.height - 1) {
		printf("���W�����������ł�\n");
		return -1;
	}

	/* ��f�l�擾 */
	r = raw.data[y * raw.width * raw.ch + x * raw.ch];
	g = raw.data[y * raw.width * raw.ch + x * raw.ch + 1];
	b = raw.data[y * raw.width * raw.ch + x * raw.ch + 2];

	printf("��f�l��R=%d, G=%d, B=%d�ł�\n", r, g, b);


	freeRawData(&raw);

	return 0;
}