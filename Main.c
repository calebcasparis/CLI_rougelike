#include <stdio.h>
#include <sys/ioctl.h>
#include <stdlib.h>
#include <unistd.h>	//for sleep only
#include "Headers.c"
#include "OverworldFunctions.c"
#include "MapFunctions.c"

int main()
{
	unsigned char floors_cleared = 0;
	struct Map current_map_data;
	char current_map_layout[10][10];
	map_Init(floors_cleared, &current_map_data, current_map_layout);

	struct Actor mc;

	mc.name = (char *) malloc(5);
	mc.pos_x =  5;
	mc.pos_y = 5;
	mc.dir = 'v';

 	int i, j;				//For loop iterations
	int c, previouschar, lastpreviouschar;	//For reading arrow keys


	current_map_layout[mc.pos_y][mc.pos_x] = mc.dir;		//Initial actor placement
	mc.front_pos_x = mc.pos_x;
	mc.front_pos_y = mc.pos_y + 1;


	system("stty raw -echo");			//Puts terminal in raw mode
							// printf("enter 'q' to quit\n");
	while (c != 'q') {
		system("clear");
                for (j = 0; j < 10; ++j) {		//
                        for (i = 0; i < 10; ++i) {	//Draws map
                                printf("%c", current_map_layout[j][i]);	//
                        }
                        printf("\n\b\b\b\b\b\b\b\b\b\b");	//Need 5 backspaces to display array correctly
                }
		printf("\nFLOOR: %d\b\b\b\b\b\b\b\b\b\b", floors_cleared);
		//printf("\nStairs: %d, %d\b\b\b\b\b\b\b\b\b\b\b\n\b",current_map_data.stair_x, current_map_data.stair_y);	//DEBUG LINE

		kbhit();				//Gets keyboard press
		lastpreviouschar = previouschar;	//Shuffles key presses
		previouschar = c;			//
		c = getchar();		//Gets last char on buffer (last keyboard press!)

/*UP*/		if (c == 'A' && previouschar == '[' && lastpreviouschar == '\033') {
			move_MC(1, &mc, &current_map_data, current_map_layout);
		}
/*DOWN*/	else if (c == 'B' && previouschar == '[' && lastpreviouschar == '\033') {
			move_MC(2, &mc, &current_map_data, current_map_layout);
	        }
/*RIGHT*/       else if (c == 'C' && previouschar == '[' && lastpreviouschar == '\033') {
			move_MC(3, &mc, &current_map_data, current_map_layout);
                }
/*LEFT*/        else if (c == 'D'&& previouschar == '[' && lastpreviouschar == '\033') {
			move_MC(4, &mc, &current_map_data, current_map_layout);
                }
		else if (c == '/') {
			interact(&mc, &current_map_data, current_map_layout);
		}
		else {
			;
		}
		if (mc.pos_x == current_map_data.stair_x && mc.pos_y == current_map_data.stair_y) {
			floors_cleared += 1;
			map_Init(floors_cleared, &current_map_data, current_map_layout);
		}

	}
	system("clear");
	system("stty cooked echo");	//Sets terminal back to cooked for user convenience
	return 0;
}
