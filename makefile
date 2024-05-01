SOURCES_DIR := src
INCLUDE_DIR := include

SOURCES := $(wildcard $(SOURCES_DIR)/*.cpp)
OBJS := $(patsubst %.cpp, %.o, $(wildcard $(SOURCES_DIR)/*.cpp))

# CC specifies which compiler we're using
CC := g++

# COMPILER_FLAGS specifies the additional compilation options we're using
COMPILER_FLAGS := -O2 -g -Wall $(addprefix -I, $(INCLUDE_DIR) ) 

# LINKER_FLAGS specifies the libraries we're linking against
#LINKER_FLAGS := -lGL -lglfw -lGLEW

# OBJ_NAME specifies the name of our exectuable
RESULT := jage.a

all: $(RESULT)

# This is the target that compiles our executable
$(RESULT) : $(OBJS) $(BUILD_DIR_NAME)
	ar rcs $(RESULT) $(OBJS)

%.o: %.cpp
	$(CC) $(COMPILER_FLAGS) -c -o $@ $<

.PHONY: clean
clean:
	rm -f $(RESULT) $(OBJS)
