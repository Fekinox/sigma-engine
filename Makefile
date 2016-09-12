#
# 'make'        build executable file 'mycc'
# 'make clean'  removes all .o and executable files
# 'make depend' creates dependencies
#

#SRCS specify the source files to compile
SRCS = source/compcollision.cpp source/comprender.cpp source/compinput.cpp source/hitbox.cpp source/ring.cpp source/font.cpp source/spritebank.cpp source/events.cpp source/fmanage.cpp source/main.cpp source/maincleanup.cpp source/maininit.cpp source/mainevent.cpp source/mainprerender.cpp source/mainrender.cpp source/mainpostrender.cpp source/sprite.cpp source/stringify.cpp source/texture.cpp source/timer.cpp
#OBJS specify the resultant source files formed from compilation
OBJS = $(SRCS:.cpp=.o)
#CC specifies which compiler we're using
CC = g++
#INCLUDE_PATHS specifies the additional include paths we'll need
INCLUDES = -IC:/SDL/SDL2-2.0.4/x86_64-w64-mingw32/include
#LIBRARY_PATHS specifies the additional library paths we'll need
LIBRARIES = -LC:/SDL/SDL2-2.0.4/x86_64-w64-mingw32/lib
#COMPILER_FLAGS specifies the additional compilation options we're using
# -w suppresses all warnings
# -Wl,-subsystem,windows gets rid of the console window -Wl,-subsystem,windows
CFLAGS = -g -std=c++11 -Wall
#LINKER_FLAGS specifies the libraries we're linking against
LFLAGS = -static-libgcc -static-libstdc++ -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf
#MAIN specifies the name of our exectuable
MAIN = a
#This is the target that compiles our executable

.PHONY : depend clean cleanlog

all : $(MAIN)
	@echo Sigma Engine compiled!

$(MAIN) : $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) -o $(MAIN) $(OBJS) $(LFLAGS) $(LIBRARIES)

.cpp.o :
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean :
	$(RM) source/*.o *~ $(MAIN)

cleanlog :
	$(RM) log.txt

depend : $(SRCS)
	makedepend $(INCLUDES) $^

# DO NOT DELETE
