 #include <stdio.h>
 #include <sys/ioctl.h>
 #include <stdlib.h>
// #include <unistd.h>
 #include <time.h>
 struct Actor {
        unsigned char pos_x;
        unsigned char pos_y;
	unsigned char front_pos_x;
	unsigned char front_pos_y;
        unsigned char dir;
        char *name;
 };

 struct Map {
        unsigned char enemy_number;
        unsigned char treasure_number;
	unsigned char treasure_x;
	unsigned char treasure_y;
        unsigned char stair_x;
        unsigned char stair_y;
        unsigned char map_lvl;
};

 struct Weapon {
	unsigned char number;
	unsigned char atk;
	char name[10];
};
