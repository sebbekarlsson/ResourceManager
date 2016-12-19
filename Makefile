output:\
    ResourceManager.o\
    libresourcemanager.a\
    libresourcemanager.so\
    main.o
	g++\
	    ResourceManager.o\
	    main.o\
	    -o test

main.o: main.cpp
	g++ -c main.cpp

ResourceManager.o: ResourceManager.cpp ResourceManager.h
	g++ -c ResourceManager.cpp

libresourcemanager.a: ResourceManager.o
	ar rcs $@ $^

libresourcemanager.so: ResourceManager.o
	ar rcs $@ $^

clean:
	rm *.o
	rm *.a
	rm *.so
	
install:
	make
	cp ResourceManager.h /usr/local/include/ResourceManager.h
	cp libresourcemanager.a /usr/local/lib/libresourcemanager.a
	cp libresourcemanager.so /usr/local/lib/libresourcemanager.so
