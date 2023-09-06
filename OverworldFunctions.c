
int kbhit()
{
        int i;
        ioctl(0, FIONREAD, &i);
        return i; /* return a count of chars available to read */
}

char item_Indexer(unsigned char treasure_number)
{
        return 0;
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
		printf("You found a %s!", item_Indexer(current_map_data->treasure_number));
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
