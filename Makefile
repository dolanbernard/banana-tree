CC=gcc
TPROG=testmh_bmath
CFLAGS=-Wall -std=c99 -O1
SOURCEDIRMATH=mh_bmath
SOURCEDIRSTRING=mh_bstring
SOURCE=$(SOURCEDIRMATH)/mh_bmath.c $(SOURCEDIRSTRING)/mh_bstring.c test.c
OBJ=${SOURCE:c=o}
OUTPUTFILE=banana-tree-build.log

.SILENT: all test clean
.PHONY: all test clean

all: ${OBJ}
	@echo "Building Banana Tree"

test: $(TPROG)
	echo "Testing"
	
$(TPROG): $(OBJ) 
	$(CC) $(CFLAGS) -o $(TPROG) $(OBJ)

.c.o:
	@echo "compile $<"
	$(CC) $(CFLAGS) -c $< -o $(patsubst %.c, %.o, $<)

clean:
	@echo "Cleaning Banana Tree"
	-rm -f $(OBJ)
	-rm -f $(TPROG)
	-rm -f $(OUTPUTFILE)
