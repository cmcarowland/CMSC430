bin_dir=./bin
source_dir=./src
CXXFLAGS += -I/usr/src/googletest/googletest/include
LDFLAGS += -L/usr/src/googletest/lib

all: $(bin_dir)/project2.elf $(bin_dir)/test.elf

$(bin_dir)/project2.elf: $(bin_dir)/scanner.o $(bin_dir)/parser.o $(bin_dir)/listing.o
	g++ -o $(bin_dir)/project2.elf $(bin_dir)/scanner.o $(bin_dir)/parser.o $(bin_dir)/listing.o
	
$(bin_dir)/scanner.o: $(source_dir)/scanner.c $(source_dir)/listing.h $(source_dir)/tokens.h
	g++ -c $(source_dir)/scanner.c -o $(bin_dir)/scanner.o

$(source_dir)/scanner.c: $(source_dir)/scanner.l
	flex -o $(source_dir)/scanner.c $(source_dir)/scanner.l 

$(bin_dir)/parser.o: $(source_dir)/parser.c $(source_dir)/listing.h 
	g++ -c $(source_dir)/parser.c -o $(bin_dir)/parser.o

$(source_dir)/parser.c $(source_dir)/tokens.h: $(source_dir)/parser.y
	bison -d -v --file-prefix $(source_dir)/parser $(source_dir)/parser.y 
	mv $(source_dir)/parser.tab.c $(source_dir)/parser.c
	cp $(source_dir)/parser.tab.h $(source_dir)/tokens.h

$(bin_dir)/listing.o: $(source_dir)/listing.cc $(source_dir)/listing.h
	g++ -c $(source_dir)/listing.cc -o $(bin_dir)/listing.o

clean:
	rm -f $(bin_dir)/*
	cd $(source_dir) && \
	rm -f scanner.c tokens.h parser.c parser.tab.* parser.output

$(bin_dir)/test.elf: $(bin_dir)/project2.elf $(source_dir)/tests.cpp
	g++ $(CXXFLAGS) $(LDFLAGS) $(source_dir)/tests.cpp -lgtest -lgtest_main -lpthread -o $(bin_dir)/test.elf
