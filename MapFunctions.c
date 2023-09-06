void map_Init(unsigned char floors_cleared, struct Map *current_map_data,
              char current_map_layout[][11], struct Actor *mc)
{
        //srand(time(NULL));
        unsigned char r = (rand() /256);
        unsigned char r2 = (rand() / 256);
	unsigned char r3 = (rand() / 256);
	unsigned char r4 = (rand() / 256);
	unsigned char r5 = (rand() / 256);
        unsigned char i, j;
        current_map_data->map_lvl = floors_cleared;
        current_map_data->enemy_number = (current_map_data->map_lvl) / 25;
        current_map_data->treasure_number = (current_map_data->map_lvl) / 36;
	current_map_data->treasure_x = r3/27;
	current_map_data->treasure_y = r4/27;
        current_map_data->stair_x = r/27;
        current_map_data->stair_y = r2/27;


        for (i = 0; i <= 10; ++i) {
                for (j = 0; j <= 10; ++j) {
                        current_map_layout[j][i] = current_map_data->floor;
                }
        }
	current_map_layout[current_map_data->stair_y][current_map_data->stair_x] = '?';
	current_map_layout[mc->pos_y][mc->pos_x] = mc->dir;
	if ((r5/27) >= 7) {
		current_map_layout[current_map_data->treasure_y][current_map_data->treasure_x] = '&';
		current_map_data->treasure_x = r3/27;
        	current_map_data->treasure_y = r4/27;
	}
	else {
		current_map_data->treasure_x = 10;
        	current_map_data->treasure_y = 1;
	}
}
