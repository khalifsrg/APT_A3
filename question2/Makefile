.default: all

PROGRAMS=points

all: $(PROGRAMS)

clean:
	rm -rf $(PROGRAMS) *.o *.dSYM

points: main.o Point2D.o Point3D.o
	g++ -Wall -Werror -std=c++14 -g -O -o $@ $^

%.o: %.cpp
	g++ -Wall -Werror -std=c++14 -g -O -c $^
