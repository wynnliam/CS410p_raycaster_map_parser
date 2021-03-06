// Liam Wynn, 7/17/2018, Raycaster: Map File Loader

/*
	Stores a structure that is similar to a map, but
	basically stores a "raw" format of the level. That is,
	it stores the data loaded in from a file. We will
	have to transform this into a usable level.
*/

struct component {
	// Done in unit coordinates. That is, x = 1 is 64 pixels,
	// x = 2 is 128 pixels, etc.
	int x, y, w, h;
	// Does the component represent a series of walls, or floor/ceiling
	// pairs?
	int is_floor_ceil;
	char* tex_0;
	char* tex_1;

	struct component* next;
};

// Have to use thing_data in place of thing because thing is already
// defined.
struct thing_data {
	int type;
	// Done in global coordinates. That is, x = 64 is 64 pixels.
	int x, y;

	struct thing_data* next;
};

struct map_data {
	char* name;
	// Path to the sky texture.
	char* sky_tex;

	// List of components.
	struct component* component_head;

	// List of things
	struct thing_data* thing_head;
};

/*
	Adds a component to the map_data structure. An important note here:
	it adds it like a stack. This way, when we set a component's attributes,
	we know we are setting the top-most one of the map_data.

	PRECONDITIONS:
		Must give a non-null map_data.

	POSTCONDITIONS:
		Modifies the given map_data's component list.

	ARGUMENTS:
		map_data - the map_data to add a component to.

	RETURNS:
		1 - the map data has a new component added.
		0 - the map data was null.
*/
int add_component(struct map_data* add_to);

/*
	Adds a thing_data to the map_data structure. An important note here:
	it adds it like a stack. This way, when we set a thing_data's attributes,
	we know we are setting the top-most one of the map_data.

	PRECONDITIONS:
		Must give a non-null map_data.

	POSTCONDITIONS:
		Modifies the given map_data's thing_data list.

	ARGUMENTS:
		map_data - the map_data to add a thing_data to.

	RETURNS:
		1 - the map data has a new thing_data added.
		0 - the map data was null.
*/
int add_thing_data(struct map_data* add_to);
