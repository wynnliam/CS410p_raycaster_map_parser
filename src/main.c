// Liam Wynn, 7/10/2018, Raycaster: Map File Loader

/*
	In this, I attempt to devise a series of functions that manage
	parsing an sqm (squanto map) file to consturct a raw level.
*/

#include <assert.h>

#include "./parse/parser.h"

int main() {
	FILE* map_file;

	printf("%d\n", (int)('\n'));
	printf("Loading level map.sqm...\n");

	map_file = fopen("map.sqm", "r");
	assert(map_file != 0);

	printf("Opened map.sqm file!\n");
	printf("Reading file contents...\n");

	parse_to_map_data(map_file);

	fclose(map_file);

	printf("Done!\n");

	return 0;
}
