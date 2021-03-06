COMPILER=gcc
DEBUG_FLAGS=-g -Wall
DEBUG_BIN=./bin/parser_d.out
PROD_BIN=./bin/parser.out

# Individual source files
SRC_MAIN=./src/main.c
SRC_PARSER=./src/parse/parser.c
SRC_MAP_DATA=./src/parse/map_data.c

.PHONY: clean run run_debug

all: $(SRC_MAIN) $(SRC_PARSER) $(SRC_MAP_DATA)
	$(COMPILER) $(SRC_MAIN) $(SRC_PARSER) $(SRC_MAP_DATA) -o $(PROD_BIN)

all_debug: $(SRC_MAIN) $(SRC_PARSER) $(SRC_MAP_DATA)
	$(COMPILER) $(DEBUG_FLAGS) $(SRC_MAIN) $(SRC_PARSER) $(SRC_MAP_DATA) -o $(DEBUG_BIN)

# TODO: Dont hardcode the executable names
run:
	cd ./bin/; ./parser.out

run_debug:
	cd ./bin/; gdb ./parser_d.out

clean:
	rm ./bin/*.out
