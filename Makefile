output:\
    ResourceManager.o\
    main.o
	g++\
	    ResourceManager.o\
	    main.o\
	    -o test

main.o: main.cpp
	g++ -c main.cpp

ResourceManager.o: ResourceManager.cpp ResourceManager.h
	g++ -c ResourceManager.cpp

clean:
	rm *.o
