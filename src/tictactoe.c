#include <stdio.h>
#include <stdlib.h>

unsigned int xboard, oboard = 0;
const unsigned int spaceCodes[9] = { 2148008064, 1073774592, 536872968, 134479872, 67125316, 33555456, 8519682, 4202496, 2097696 };

int checkwin() {
	return (xboard & (xboard << 1) & (xboard >> 1) || oboard & (oboard << 1) & (oboard >> 1));
}

int checkspace(unsigned int space){
	if ((spaceCodes[space] & (xboard | oboard)) != 0 || space > 8){
		printf("Invalid space, choose again\n");
		return 1;
	} else
		return 0;
}

void turn(unsigned int space, int player) {

	if (player > 0)
		xboard = xboard | space;
	else
		oboard = oboard | space;
}

int main() {
	unsigned int space;
	int player = -1;
	printf("SPACES:\n0 | 1 | 2\n3 | 4 | 5\n6 | 7 | 8\n");
	
	while (checkwin() == 0) {

		scanf("%u", &space);
		while (checkspace(space) != 0){
			scanf("%d", &space);
		}

		player *= -1;
		turn(spaceCodes[space], player);

		//Display board
		printf("\n");
		for (int i = 0; i < 9; i++) {
			if (spaceCodes[i] & xboard )
				printf("X | ");
			else if (spaceCodes[i] & oboard)
				printf("O | ");
			else
				printf("  | ");
			if ((i + 1) % 3 == 0)
				printf("\n");
		}
		printf("\n");
	}

	if (player > 0)
		printf("\nX wins\n");
	else
		printf("\nO wins \n");
	return 0;
}
