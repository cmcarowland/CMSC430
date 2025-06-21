bin_dir=./bin
source_dir=./src
CXXFLAGS += -I/usr/src/googletest/googletest/include
LDFLAGS += -L/usr/src/googletest/lib
LINKFLAGS = -lgtest -lgtest_main -lpthread

all: $(bin_dir)/project2.elf $(bin_dir)/test.elf

$(bin_dir)/project2.elf: $(bin_dir)/scanner.o $(bin_dir)/parser.o $(bin_dir)/listing.o $(source_dir)/utils.cpp
	g++ -o $@ $(source_dir)/utils.cpp $(bin_dir)/scanner.o $(bin_dir)/parser.o $(bin_dir)/listing.o
	
$(bin_dir)/scanner.o: $(source_dir)/scanner.c $(source_dir)/listing.h $(source_dir)/tokens.h
	g++ -c $(source_dir)/scanner.c -o $@

$(source_dir)/scanner.c: $(source_dir)/scanner.l
	flex -o $@ $(source_dir)/scanner.l 

$(bin_dir)/parser.o: $(source_dir)/parser.c $(source_dir)/listing.h 
	g++ -c $(source_dir)/parser.c -o $@

$(source_dir)/parser.c $(source_dir)/tokens.h: $(source_dir)/parser.y
	bison -d -v --file-prefix $(source_dir)/parser $(source_dir)/parser.y 
	mv $(source_dir)/parser.tab.c $(source_dir)/parser.c
	mv $(source_dir)/parser.tab.h $(source_dir)/tokens.h

$(bin_dir)/listing.o: $(source_dir)/listing.cc $(source_dir)/listing.h
	g++ -c $(source_dir)/listing.cc -o $@

clean:
	rm -f $(bin_dir)/*
	cd $(source_dir) && \
	rm -f scanner.c tokens.h parser.c parser.tab.* parser.output

$(bin_dir)/test.elf: $(source_dir)/tests.cpp $(source_dir)/parser.c $(source_dir)/scanner.c $(bin_dir)/listing.o $(source_dir)/utils.cpp
	g++ $(CXXFLAGS) $(LDFLAGS) -DTESTING=1 $(source_dir)/tests.cpp $(source_dir)/parser.c $(source_dir)/scanner.c $(bin_dir)/listing.o $(source_dir)/utils.cpp $(LINKFLAGS) -o $@
