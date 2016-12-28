output:\
    libresourcemanager.a\
    libresourcemanager.so\

ResourceManager.o: ResourceManager.cpp ResourceManager.h
	g++ -c ResourceManager.cpp

libresourcemanager.a: ResourceManager.o
	ar rcs $@ $^

libresourcemanager.so: ResourceManager.o
	ar rcs $@ $^

.PHONY: clean
clean:
	rm *.o
	rm *.a
	rm *.so

.PHONY: install
install:
	make clean
	make
	cp ResourceManager.h /usr/local/include/ResourceManager.h
	cp libresourcemanager.a /usr/local/lib/libresourcemanager.a
	cp libresourcemanager.so /usr/local/lib/libresourcemanager.so
