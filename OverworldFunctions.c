int kbhit()
{
        int i;
        ioctl(0, FIONREAD, &i);
        return i; /* return a count of chars available to read */
}

void item_Indexer(unsigned char treasure_number)
{
	unsigned char a = 0;

	while(a < 4) {
		switch (inv[a].number) {
			case 0:
				inv[a] = swords[treasure_number];
				return;
			break;
			case !0:
				++a;
			break;
		}
	}
}


void move_MC(int mv_dir, struct Actor *mc,
             struct Map *current_map_data,
             char current_map_layout[][11])
{
        switch(mv_dir) {
/*UP*/		case 1:
                        if (mc->pos_y == 0 || current_map_data->treasure_x == mc->pos_x &&
			    current_map_data->treasure_y == (mc->pos_y - 1)){
                                        ;
                        }
                        else {
                                current_map_layout[mc->pos_y][mc->pos_x] =
				current_map_data->floor;
                                mc->pos_y -= 1;
                        }
                        mc->dir = '^';
			mc->front_pos_x = mc->pos_x;
			mc->front_pos_y = mc->pos_y - 1;
                        current_map_layout[mc->pos_y][mc->pos_x] = mc->dir;
                break;
/*DOWN*/	case 2:
                        if (mc->pos_y == 10 - 1 ||
			    current_map_data->treasure_x ==
			    mc->pos_x && current_map_data->treasure_y == (mc->pos_y + 1)) {
                                ;
                        }
                        else {
                                current_map_layout[mc->pos_y][mc->pos_x] =
				current_map_data->floor;
                                mc->pos_y += 1;
                        }
                        mc->dir = 'v';
			mc->front_pos_x = mc->pos_x;
			mc->front_pos_y = mc->pos_y + 1;
                        current_map_layout[mc->pos_y][mc->pos_x] = mc->dir;
                break;
/*RIGHT*/	case 3:
                        if (mc->pos_x == 10 - 1 || mc->pos_y ==
			    current_map_data->treasure_y &&
			    current_map_data->treasure_x == (mc->pos_x + 1)) {
                                ;
                        }
                        else {
                                current_map_layout[mc->pos_y][mc->pos_x] =
				current_map_data->floor;
                                mc->pos_x += 1;
                        }
                        mc->dir = '>';
			mc->front_pos_x = mc->pos_x + 1;
                        mc->front_pos_y = mc->pos_y;
                        current_map_layout[mc->pos_y][mc->pos_x] = mc->dir;
                break;
/*LEFT*/	case 4:
                        if (mc->pos_x == 0 || mc->pos_y == current_map_data->treasure_y &&
			    current_map_data->treasure_x == (mc->pos_x - 1)) {
                                ;
                        }
                        else {
                                current_map_layout[mc->pos_y][mc->pos_x] =
				current_map_data->floor;
                                mc->pos_x -= 1;
                        }
                        mc->dir = '<';
			mc->front_pos_x = mc->pos_x - 1;
                        mc->front_pos_y = mc->pos_y;
                        current_map_layout[mc->pos_y][mc->pos_x] = mc->dir;
                break;
	}
}

void interact(struct Actor * mc, struct Map * current_map_data, char current_map_layout[][11])
{
	if (mc->front_pos_x == current_map_data->treasure_x &&
	    mc->front_pos_y == current_map_data->treasure_y) {
		printf("You found a %s!", swords[current_map_data->treasure_number].name);
		item_Indexer(current_map_data->treasure_number);
		getchar();
		system("clear");
		current_map_layout[current_map_data->treasure_y][current_map_data->treasure_x] =
		current_map_data->floor;
		current_map_data->treasure_x = 11;
		current_map_data->treasure_y = 2;
	}
	if (mc->front_pos_x == current_map_data->stair_x &&
            mc->front_pos_y == current_map_data->stair_y) {
		printf("It's a staircase.");
		getchar();
		system("clear");
	}
	else {
		printf("There's nothing there.");
		getchar();
		system("clear");
	}
}

void inventory()
{
	struct Weapon holder;
	while (1) {
		int dec = 0;
		system("clear");
		printf("INVENTORY\n\n");
		printf("\b\b\b\b\b\b\b\b\bWEAPONS\n");
		printf("1. %15s\n", inv[0].name);
		printf("\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b2. %15s\n", inv[1].name);
		printf("\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b3. %15s\n", inv[2].name);
		printf("\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b4. %15s\n\n", inv[3].name);
		printf("\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\bCONSUMABLES\n\n");
		printf("\b\b\b\b1. \n");
		printf("\b\b\b2. \n");
		printf("\b\b\b3. \n");
		printf("\b\b\b4. \n\b\b\b\b\b\b\b\b\b\b>");
		printf("\n\n\n\n\n\n\n\n\bEQUIPPED: %15s", held_weapon.name);
		dec = getchar();
		printf("\n");
		if (dec == '1') {
				holder = held_weapon;
				held_weapon = inv[0];
				inv[0] = holder;
		}
		else if (dec == '2') {
				holder = held_weapon;
				held_weapon = inv[1];
				inv[1] = holder;
		}
		else if (dec == '3') {
				holder = held_weapon;
				held_weapon = inv[2];
				inv[2] = holder;
		}
		else if (dec == '4') {
				holder = held_weapon;
				held_weapon = inv[3];
				inv[3] = holder;
		}
		else if (dec == 'q') {
				return;
		}
		else {
			;
		}
	}
}
