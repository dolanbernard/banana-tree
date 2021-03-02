CC=gcc
CFLAGS=-Wall -std=c99 -O1
SOURCEDIR=math
SOURCE:=$(SOURCEDIR)/mh_bmath.c
OBJ:=${SOURCE:c=o}
OUTPUTFILE=banana-tree-build.log

.SILENT: all clean
.PHONY: all clean

all: ${OBJ}
	@echo "Building Banana Tree"

.c.o:
	@echo "compile $<"
	$(CC) $(CFLAGS) -c $< -o $(patsubst %.c, %.o, $<)

clean:
	@echo "Cleaning Banana Tree"
	-rm -f $(SOURCEDIR)/*.o
