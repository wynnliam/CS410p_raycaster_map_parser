// Liam Wynn, 7/17/2018, Raycaster: Map File Loader

/*
	Stores a structure that is similar to a map, but
	basically stores a "raw" format of the level. That is,
	it stores the data loaded in from a file. We will
	have to transform this into a usable level.
*/

struct map_data {
	char* name;
	// Path to the sky texture.
	char* sky_tex;
};
