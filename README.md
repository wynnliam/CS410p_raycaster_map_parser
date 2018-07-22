# CS410p_raycaster_map_parser
In a continuation of my raycaster project, I've sought to write a parser that can read map files into memory.

## About the Project Structure
The project is organized into two folders: bin and src. bin has the executables and data needed to run the system.
src is the source code itself. There is also the Makefile, which contains scripts for various things (compiling, running,
tests, etc).

## The Overall System
In a nutshell, this system sets out to do the following: given a human readable file, we "translate" it to
some thing the raycaster can use.

My goal for the distant future is to make a level editor that can be used
to streamline the process of building levels for the system. However, before I can do that, I need a file
that I can load into memory. The reality is, I may not ever care enough to build a level editor. So what I
should do is construct a file type that is both human readable, and easy enough to parse. From this, I created
the Squanto Map.

## The Squanto Map
The Squanto Map, or as I abreviate it: sqm, is the file type of choice for the Raycaster. It isn't particularly
fancy by any means. Essentially, it is a list of what I call "recipes". Each recipe is just a set of what I call
"attributes". Here's an example below:

```
# This is a demo map.

# Metadata about the map.
properties {
	# String
	name = "demo world";
	# String - 0 will denote "NULL"
	sky_tex = "path/to/sky texture.bmp";
}

# Specifies a rectangular space in the world.
component {
	# Integers
	x = "0"; y = "0";
	w = "3"; h = "4";
	# Integer (boolean, but can be treated as integer)
	is_floor_ciel = "1";
	# Strings
	tex_0 = "path/to/tex0.bmp";
	tex_1 = "path/ to/tex1.bmp";
}

thing {
	type = "0";
	x = "69";
	y = "128";
}
```

In the example above, we would say the map has three recipes: properties, component, and thing. Before we
break these down, here's a little bit more terminology: the words "properties", "component", and "thing" for
each recipe is the recipe's header. So a more abstract representation of a single recipe would be something
like this:

```
RECIPE_HEADER {
	attribute_1 = "Some value";
	attribute_2 = "Some value";
	attribute_3 = "Some value";
	# And so on...
}
```

So hopefully this better intuition for how an sqm file is laid out. Now we shall describe what the properties,
component, and thing recipes are exactly.

We'll start with properties. The properties recipe describes metadata about the level. When I say "metadata", it would
help to explain what it is not. Metadata is basically everything that isn't a floor, cieling, wall, or thing in the level.
I imagine this definition will change in the event that I add other features to levels. So with everything given above,
metadata is basically the name of the level and the sky texture used.

Next we have the component recipe. Essentially, this describes a rectangular space in the level. That would be either a
wall, or a floor/cieling area. I got the idea for representing levels like this from the Hammer Editor. Before a file becomes
a bsp, it had a kind of human readable format to it that was not unlike the one given here. The idea is that when you build
a level, you specify a series of rectangular areas that represent the map in its entirety: walls, floors, ramps, cielings, etc.
In the case of the raycaster, it's basically walls and then pairs of floors and ceilings. Now, the raycaster sees the world
as a giant grid of tiles. I'll discuss in greater detail handling this difference in level representation in a bit.

Finally, we've the thing recipe. The thing recipe essentially specifies something in the world that isn't a wall, floor, or ceiling.
Since the raycaster doesn't do much at the moment, that will boil down to player spawns and props in the world. One thing of note
here is the attribute "type". Basically, we can't code in any level-specific logic in the game like timers and what not. So a simple
work around is to use this type value that can then be used for a game specific entity. However, those entities would have to be hard-coded
into the game, unfortunately.

## Translating from an sqm to a raycastable level.
Above, I had mentioned how the representation of a level implied by the sqm is very different than the raycaster representation.
For an sqm map, we say a level is more-or-less a list of components and things, and then some extra metadata. However, a level
used by the raycaster is basically a tile grid with an array of things, and then some metadata. Naturally, this problem requires
a translation of sorts between an sqm file and the raycaster representation of the world.

### Enter: The map_data structure
To mediate this process, the I define a strucutre called map_data. Basically, it's takes the sqm file, and puts it in a strucutre
thats very faithful to the representation in the file. So why have it? Well remember, an sqm file is a stream of characters. The map_data
represents the *same* information in a format that the program can use. Once we've created a valid map_data structure, it can
then be converted into a format the raycaster understands. This process, however, is beyond the scope of this program, and is thusly omitted.

## In sum
Hopefully, this document gives you an idea of what the program does. In a sentence, it runs the process of reading a stream of
characters that then get transformed into a map_data structure.
