
#include <curses.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void view(void);
void update(int t);
#define width  230
#define height  120
int board[height][width];
int x = 100;
int y = 60;
int l = 8;
int s = 20;
int main(int argc, char* argv[])


{
	
	if (initscr() == NULL) {
		return 1;
	}
	
	
	
	
	int k = 0;

	while (1) {
		// 画面をクリア
		//erase();
		update(k);
		view();
		refresh();
		k++;
	}
	return 0;
}
void update(int t) {
	int a;
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {

			a =(int)(14* sin (3.14*(t/s - sqrt((x-j)*(x-j)+(y-i)*(y-i))/l)) +1);
			if (a == 0) {
				a = 1;
			}
			board[i][j] = a;

		}
	}
}
void view() {
	start_color();	//色を設定するモードになる
	for (int i = 1; i < 16; i++) {
		init_color(i, (int)(i * 500 / 16 + 300), (int)(i * 500 / 16 + 300), (int)(i * 500 / 16 + 300));
		init_pair(i, i, i);
	}

	for (int i = 0; i < height ; i++) {
		for (int j = 0; j < width ; j++) {
			
			attrset(COLOR_PAIR(board[i][j]));			// 色1 を使う
			mvaddstr(i, j, " " );
			
		}
	}
}