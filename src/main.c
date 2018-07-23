// Liam Wynn, 7/10/2018, Raycaster: Map File Loader

/*
	In this, I attempt to devise a series of functions that manage
	parsing an sqm (squanto map) file to consturct a raw level.
*/

#include <assert.h>

#include "./parse/parser.h"

void print_map(struct map_data* map_data);

int main() {
	FILE* map_file;
	struct map_data* map_data;

	printf("%d\n", (int)('\n'));
	printf("Loading level map.sqm...\n");

	map_file = fopen("map.sqm", "r");
	assert(map_file != 0);

	printf("Opened map.sqm file!\n");
	printf("Reading file contents...\n");

	map_data = parse_to_map_data(map_file);

	fclose(map_file);

	printf("Done!\n");

	printf("Map Contents:\n");
	print_map(map_data);

	return 0;
}

void print_map(struct map_data* map_data) {
	printf("Map Name: %s\n", map_data->name);
	printf("Sky Texture: %s\n", map_data->sky_tex);
}
