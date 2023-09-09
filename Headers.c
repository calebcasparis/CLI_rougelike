/*
	Here, we need to define all weapons & armor, as well as enemies as structs.
	We also need to define the inventory such that items can be placed
	within.
	Treasures need to be handled. Use enum to "pick" from list.
*/
#include <stdio.h>
#include <sys/ioctl.h>
#include <stdlib.h>
#include <time.h>
struct Actor {
        unsigned char pos_x;
        unsigned char pos_y;
	unsigned char front_pos_x;
	unsigned char front_pos_y;
        unsigned char dir;
 };

struct Weapon {
        unsigned char number;
        unsigned char atk;
        unsigned char verb[10];
        char name[20];
};

struct Map {
        unsigned char enemy_number;
	unsigned char treasure_number;
	unsigned char treasure_x;
	unsigned char treasure_y;
        unsigned char stair_x;
        unsigned char stair_y;
	unsigned char floor;
        unsigned char map_lvl;
};

struct Weapon none = {
	0,
	0,
	"punched",
	"\0"
};

struct Weapon held_weapon = {			//PLAYER WEAPON INIT
	0,
	0,
	"punched"
	"\0"
};
struct Weapon inv[4] = {

	[0] = {
        	0,
        	0,
        	"punched",
        	"\0"
	},

	[1] = {
        	0,
        	0,
        	"punched",
        	"\0"
	},

	[2] = {
        	0,
        	0,
        	"punched",
        	"\0"
	},

	[3] = {
        	0,
        	0,
        	"punched",
        	"\0"
	}
};

struct Weapon swords[9] = {

	[0] = {
        	1,
        	1,
        	"slashed",
        	"Rusty Sword"
	},

	[1] = {
        	2,
        	3,
        	"slashed",
        	"Iron Sword"
	},

	[2] = {
        	3,
        	5,
        	"slashed",
        	"Bronze Sword"
	},

	[3] = {
        	4,
        	7,
        	"slashed",
        	"Gold Sword"
	},

	[4] = {
        	5,
        	10,
        	"slashed",
        	"Bone Sword"
	},

	[5] = {
        	6,
        	12,
        	"slashed",
        	"Laser Sword"
	},

	[6] = {
        	7,
        	20,
        	"slashed",
        	"Relic Sword"
	},

	[7] = {
        	9,
        	25,
        	"slashed",
        	"Legendary Sword"
	},

	[8] = {
        	10,
        	35,
        	"slashed",
        	"Cursed Sword"
	}
};


/*	PROTOTYPES	*/
