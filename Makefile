output:\
    libresourcemanager.a\
    libresourcemanager.so\
    ResourceManager.o\
    example.o 
	g++ ResourceManager.o example.o -o test


example.o: example.cpp
	g++ -c example.cpp

ResourceManager.o: ResourceManager.cpp ResourceManager.h
	g++ -c ResourceManager.cpp -fPIC

libresourcemanager.a: ResourceManager.o
	ar rcs $@ $^

libresourcemanager.so: ResourceManager.o
	$(LINK.c) -shared $< -o $@

.PHONY: clean
clean:
	rm *.o
	rm *.a
	rm *.so

.PHONY: install
install:
	make
	cp ResourceManager.h /usr/local/include/ResourceManager.h
	cp libresourcemanager.a /usr/local/lib/libresourcemanager.a
	cp libresourcemanager.so /usr/local/lib/libresourcemanager.so
