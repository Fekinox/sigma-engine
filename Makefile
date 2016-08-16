#
# 'make'        build executable file 'mycc'
# 'make clean'  removes all .o and executable files
#

#SRCS specify the source files to compile
SRCS = source/entity.cpp source/spritebank.cpp source/events.cpp source/fmanage.cpp source/main.cpp source/maincleanup.cpp source/maininit.cpp source/mainevent.cpp source/mainloop.cpp source/mainrender.cpp source/sprite.cpp source/stringify.cpp source/texture.cpp source/timer.cpp
#OBJS specify the resultant source files formed from compilation
OBJS = $(SRCS:.cpp=.o)
#CC specifies which compiler we're using
CC = g++
#INCLUDE_PATHS specifies the additional include paths we'll need
INCLUDES = -IC:/SDL/SDL2-2.0.4/i686-w64-mingw32/include/SDL2
#LIBRARY_PATHS specifies the additional library paths we'll need
LIBRARIES = -LC:/SDL/SDL2-2.0.4/i686-w64-mingw32/lib
#COMPILER_FLAGS specifies the additional compilation options we're using
# -w suppresses all warnings
# -Wl,-subsystem,windows gets rid of the console window -Wl,-subsystem,windows
CFLAGS = -g -std=c++0x -Wl,-subsystem,windows -Wall
#LINKER_FLAGS specifies the libraries we're linking against
LFLAGS = -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf
#MAIN specifies the name of our exectuable
MAIN = a
#This is the target that compiles our executable

.PHONY : depend clean

all : $(MAIN)
	@echo Delta Engine compiled!

$(MAIN) : $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) -o $(MAIN) $(OBJS) $(LFLAGS) $(LIBRARIES)

.cpp.o :
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean :
	$(RM) source/*.o *~ $(MAIN)

depend : $(SRCS)
	makedepend $(INCLUDES) $^

# DO NOT DELETE
