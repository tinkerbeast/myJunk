# Include directories
include_directories (".")

# Get all sources
# TODO (tinkerbeast) - make this static
file(GLOB_RECURSE SOURCES *.cpp)

foreach(filename ${SOURCES})
	list(APPEND OBJECTS ${filename})
endforeach(filename ${SOURCES})

add_library(cppds SHARED ${OBJECTS})