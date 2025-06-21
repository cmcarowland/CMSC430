bin_dir=./bin
source_dir=./src
CXXFLAGS += -I/usr/src/googletest/googletest/include
LDFLAGS += -L/usr/src/googletest/lib
LINKFLAGS = -lgtest -lgtest_main -lpthread

all: $(bin_dir)/project1.elf $(bin_dir)/test.elf

OBJ_FILES = $(bin_dir)/scanner.o $(bin_dir)/listing.o
$(bin_dir)/project1.elf: $(OBJ_FILES)	
	g++ -o $@ $^
	
$(bin_dir)/scanner.o: $(source_dir)/scanner.c $(source_dir)/tokens.h $(source_dir)/listing.h
	g++ -c $(source_dir)/scanner.c -o $@

$(source_dir)/scanner.c: $(source_dir)/scanner.l $(source_dir)/utils.h
	flex -o $@ $(source_dir)/scanner.l

$(bin_dir)/listing.o: $(source_dir)/listing.cc $(source_dir)/listing.h
	g++ -c $(source_dir)/listing.cc -o $@

$(bin_dir)/test.elf: $(source_dir)/scanner.c $(bin_dir)/listing.o $(source_dir)/tokens.h $(source_dir)/tests.cpp
	g++ $(CXXFLAGS) $(LDFLAGS) -DTESTING=1 $(source_dir)/scanner.c $(bin_dir)/listing.o $(source_dir)/tests.cpp $(LINKFLAGS) -o $@

clean:
	rm -f $(bin_dir)/*
	rm -f $(source_dir)/scanner.c