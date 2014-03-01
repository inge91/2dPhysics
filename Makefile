# SRC: read source files from dir
# HDR: read header files from dir
# OBJS: SRC, but .cpp replaced by .o
SRC = ${wildcard 2DPhysics/*.cpp}
HDR = ${wildcard 2DPhysics/*.h}
TMP = ${SRC:.cpp=.o}
OBJS = ${TMP:2DPhysics/%=%}
BIN = output

CFLAGS = -Wall -std=c++11 -g
# Alternative include path
INCFLAGS = -I /usr/include/SOIL/
# libraries to be linked
LDFLAGS = -lGL -lglut -lSOIL -lopencv_core -lopencv_imgproc -lopencv_highgui

# Compile binary
$(BIN): $(OBJS)
	$(CXX) $(OBJS) -o $(BIN) $(LDFLAGS)

# Compile source to oject files 
%.o: 2DPhysics/%.cpp 
	$(CXX) $(CFLAGS) $(INCFLAGS) -c $^

# Remove binary and object files
clean:
	rm -f $(BIN) $(OBJS)

build:
	mkdir -p build

print: 
	@echo $(OBJS)
