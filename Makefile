.PHONY: update-yosys build-yosys build-yosys-napi clean all

all: build-yosys-napi

update-yosys:
	git submodule update --init
	git submodule foreach git pull origin master

build-yosys: update-yosys
	echo "ENABLE_LIBYOSYS=1" > yosys-src/Makefile.conf
	echo "ENABLE_TCL=0" >> yosys-src/Makefile.conf
	echo "ENABLE_ABC=0" >> yosys-src/Makefile.conf
	echo "ENABLE_READLINE=0" >> yosys-src/Makefile.conf
	cd yosys-src && make

build-yosys-napi: build-yosys
	rm -rf build
	node-gyp configure
	node-gyp build

clean:
	cd yosys-src && make clean
