.PHONY: update-yosys build-yosys all

all: build-yosys-napi

update-yosys:
	git submodule update --init
	git submodule foreach git pull origin master

build-yosys: update-yosys
	cd yosys-src && echo "ENABLE_LIBYOSYS=1" > Makefile.conf && make

build-yosys-napi: build-yosys
	rm -rf build
	node-gyp configure
	node-gyp build
