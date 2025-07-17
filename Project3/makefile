bin_dir=./bin
source_dir=./src
CXXFLAGS += -I/usr/src/googletest/googletest/include
LDFLAGS += -L/usr/src/googletest/lib

all: mkdirs $(bin_dir)/project3.elf $(bin_dir)/test.elf

mkdirs:
	mkdir -p $(bin_dir)

$(bin_dir)/project3.elf: $(bin_dir)/scanner.o $(bin_dir)/parser.o $(bin_dir)/listing.o $(bin_dir)/values.o $(source_dir)/utils.cpp
	g++ -o $@ $^

$(bin_dir)/scanner.o: $(source_dir)/scanner.c $(source_dir)/values.h $(source_dir)/listing.h $(source_dir)/tokens.h
	g++ -c $(source_dir)/scanner.c -o $@

$(source_dir)/scanner.c: $(source_dir)/scanner.l
	flex $(source_dir)/scanner.l
	mv lex.yy.c $@

$(bin_dir)/parser.o: $(source_dir)/parser.c $(source_dir)/values.h $(source_dir)/listing.h $(source_dir)/symbols.h
	g++ -c $(source_dir)/parser.c -o $@

$(source_dir)/parser.c $(source_dir)/tokens.h: $(source_dir)/parser.y
	bison -d -v --file-prefix $(source_dir)/parser $(source_dir)/parser.y
	mv $(source_dir)/parser.tab.c $(source_dir)/parser.c
	mv $(source_dir)/parser.tab.h $(source_dir)/tokens.h

$(bin_dir)/listing.o: $(source_dir)/listing.cc $(source_dir)/listing.h
	g++ -c $(source_dir)/listing.cc -o $(bin_dir)/listing.o

$(bin_dir)/values.o: $(source_dir)/values.cc $(source_dir)/values.h
	g++ -c $(source_dir)/values.cc -o $@

clean:
	rm -f $(bin_dir)/*
	cd $(source_dir) && \
	rm -f scanner.c parser.tab.* parser.output tokens.h parser.c

$(bin_dir)/test.elf: $(source_dir)/tests.cpp $(source_dir)/parser.c $(bin_dir)/scanner.o $(bin_dir)/listing.o $(bin_dir)/values.o $(source_dir)/utils.cpp
	g++ $(CXXFLAGS) -DTESTING=1 $(LDFLAGS) $(source_dir)/tests.cpp $(source_dir)/parser.c $(bin_dir)/scanner.o $(bin_dir)/listing.o $(bin_dir)/values.o $(source_dir)/utils.cpp -lgtest -lgtest_main -lpthread -o $@