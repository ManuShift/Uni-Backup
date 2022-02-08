all: naughtyOrNice
	make clean;

naughtyOrNice: NaughtyOrNice.o InterpolationSearch.o  
	g++ -o naughtyOrNice NaughtyOrNice.o InterpolationSearch.o

NaughtyOrNice.o:
	g++ -c NaughtyOrNice.cpp

InterpolationSearch.o:
	g++ -c InterpolationSearch.cpp
	
clean:
	rm *.o;
