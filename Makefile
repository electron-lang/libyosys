.PHONY: update-yosys build-yosys all

update-yosys:
	git submodule update --init
	git submodule foreach git pull origin master

build-yosys: update-yosys
	cd yosys-src && echo "ENABLE_LIBYOSYS=1" > Makefile.conf && make

all: build-yosys
