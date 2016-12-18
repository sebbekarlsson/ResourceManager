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
	
install:
	make
	ar rvs ResourceManager.a ResourceManager.o
	cp ResourceManager.h /usr/local/include/ResourceManager.h
	cp ResourceManager.a /usr/local/lib/ResourceManager.a
