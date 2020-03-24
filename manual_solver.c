// Include libraries
#include <stdio.h>

// This is a manual solver for now

// Function to rotate cube
void alterArray(int s, int r, char d, char **array1, char **array2, char **array3, char **array4){
	// Create temp arrays to for placeholders
	// Alter arrays based on passed values (side, row, direction)
}

// Menu function
char menu(){
	char option;
	printf("Enter an option\n");
	printf("Enter 'o' to output the cube's current configuration\n");
	printf("Enter 'r' to rotate the cube\n");
	printf("Enter 'q' to quit\n");
	scanf(" %c",&option);
	return option;
}

int main(){
	// Create arrays for each side
	// Red, Yello, White, Green, Blue, Orange
	char s1[9] = {'R','R','R','R','R','R','R','R','R'};
	char s2[9] = {'Y','Y','Y','Y','Y','Y','Y','Y','Y'};
	char s3[9] = {'W','W','W','W','W','W','W','W','W'};
	char s4[9] = {'G','G','G','G','G','G','G','G','G'};
	char s5[9] = {'B','B','B','B','B','B','B','B','B'};
	char s6[9] = {'O','O','O','O','O','O','O','O','O'};


	// Declare variables
	char choice = menu();
	int row, side;
	char direction;
	
	while (choice != 'q'){
		// Exit
		if(choice == 'q'){
			printf("exiting");
		}

		// Alter Rubix Cube 
		else if(choice == 'r'){
			printf("There is currently no error checking, be careful!");
			printf("Select a side (1 -> 6) to rotate\n");
			scanf("%d", &side);
			printf("Select a row (1 -> 3) to rotate\n");
			scanf("%d", &row);
			printf("Select a direction (L, R, U, D) to rotate\n");
			scanf(" %c", &direction);

			// Choose array(s) based on input, and call alterArray function
			//alterArray(side,row,direction,,,,);
		}
		

		// Print out Rubix Cube
		// Show ascii rubix cube using this format
		/*   /Y/Y/Y/|    /W/W/W/|
		 *  /Y/Y/Y/B|   /W/W/W/O|
		 * /Y/Y/Y/BB|  /W/W/W/OO|
		 *|R|R|R|BBB/ |G|G|G|OOO/
		 *|R|R|R|BB/  |G|G|G|OO/
		 *|R|R|R|B/   |G|G|G|O/
		 * */
		else if(choice == 'o'){
			printf("   /%c/%c/%c/|       /%c/%c/%c/|\n",s2[0],s2[1],s2[2],s3[0],s3[1],s3[2]);
			printf("  /%c/%c/%c/%c|      /%c/%c/%c/%c|\n",s2[3],s2[4],s2[5],s5[2],s3[3],s3[4],s3[5],s6[2]);
			printf(" /%c/%c/%c/%c%c|     /%c/%c/%c/%c%c|\n",s2[6],s2[7],s2[8],s5[1],s5[5],s3[6],s3[7],s3[8],s6[1],s6[5]);
			printf("|%c|%c|%c|%c%c%c/    |%c|%c|%c|%c%c%c/\n",s1[0],s1[1],s1[2],s5[0],s5[4],s5[8],s4[0],s4[1],s4[2],s6[0],s6[4],s6[8]);
			printf("|%c|%c|%c|%c%c/     |%c|%c|%c|%c%c/\n",s1[3],s1[4],s1[5],s5[3],s5[7],s4[3],s4[4],s4[5],s6[3],s6[7]);
			printf("|%c|%c|%c|%c/      |%c|%c|%c|%c/\n",s1[6],s1[7],s1[8],s5[6],s4[6],s4[7],s4[8],s6[6]);
		}

		// Bad choice
		else {
			printf("Invalid command\n");
		}
		choice = menu();
	}
	return 0;
}