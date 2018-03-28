.PHONY : clean all run
all: unit.o main.o
	g++ unit.o main.o -o ./bin/test

run:
	./bin/test

unit.o: ./include/unit.h ./src/unit.cc ./include/*.h
	g++ -DTEXT_RUN  -c ./src/unit.cc -I./include

main.o: ./main.cpp ./include/*.h
	g++ -DTEXT_RUN -c main.cpp -I./include

clean:
	rm -rf ./bin/test *.o
