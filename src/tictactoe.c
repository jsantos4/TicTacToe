#include <stdio.h>

unsigned int xboard, oboard = 0;
const unsigned int spaceCodes[9] = { 2148008064, 1073774592, 536872968, 134479872, 67125316, 33555456, 8519682, 4202496, 2097686 };

int checkwin() {
	return (xboard & (xboard << 1) & (xboard >> 1));
}

int checkspace(unsigned int space){
	return space & (xboard | oboard);
}

void turn(unsigned int space, int board) {
	if (board > 0)
		xboard = xboard | space;
	else
		oboard = oboard | space;
}

int main() {
	int player = 1;
	int space;
	while (checkwin() == 0) {
		printf("SPACES:\n1 | 2 | 3\n4 | 5 | 6\n7 | 8 | 9\n");
		scanf("%d", &space);
		space = spaceCodes[space];
		turn(space, player);
		player *= -1;
	}
	return 0;
}
