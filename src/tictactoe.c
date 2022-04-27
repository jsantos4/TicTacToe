#include <stdio.h>
#include <stdlib.h>

unsigned int xboard, oboard = 0;
const unsigned int spaceCodes[9] = { 2148008064, 1073774592, 536872968, 134479872, 67125316, 33555456, 8519682, 4202496, 2097686 };

int checkwin() {
	return (xboard & (xboard << 1) & (xboard >> 1) || oboard & (oboard << 1) & (oboard >> 1));
}

int checkspace(unsigned int space){
	if (space & (xboard | oboard) != 0 || space > 8){
		printf("Invalid space, choose again\n");
		return 1;
	} else
		return 0;
}

void turn(unsigned int space, unsigned int board) {

	if (board > 0)
		xboard = xboard | space;
	else
		oboard = oboard | space;

	printf("%u\n%u\n", xboard, oboard);
}

int main() {
	unsigned int space;
	int player = 1;
	
	while (checkwin() == 0) {
		printf("SPACES:\n0 | 1 | 2\n3 | 4 | 5\n6 | 7 | 8\n");

		scanf("%u", &space);
		while (checkspace(space) != 0){
			scanf("%d", &space);
		}

		turn(spaceCodes[space], player);
		player *= -1;
	}
	return 0;
}
