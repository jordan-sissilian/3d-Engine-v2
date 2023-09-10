all:
	cd build && cmake .
	$(MAKE) -C build

run: all
	./bin/3dEngine/3DEngine

clean:
	rm -rf build