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
	g++ -fPIC -shared ResourceManager.cpp -o libresourcemanager.so
	cp ResourceManager.h /usr/local/include/ResourceManager.h
	cp ResourceManager.a /usr/local/lib/ResourceManager.a
	cp libresourcemanager.so /usr/local/lib/libresourcemanager.so
