bin_dir=./bin
source_dir=./src

compile: $(bin_dir)/scanner.o $(bin_dir)/listing.o
	g++ -o $(bin_dir)/compile $(bin_dir)/scanner.o $(bin_dir)/listing.o
	
$(bin_dir)/scanner.o: $(source_dir)/scanner.c $(source_dir)/listing.h $(source_dir)/tokens.h
	g++ -c $(source_dir)/scanner.c -o $(bin_dir)/scanner.o

$(source_dir)/scanner.c: $(source_dir)/scanner.l
	flex -o $(source_dir)/scanner.c $(source_dir)/scanner.l

$(bin_dir)/listing.o: $(source_dir)/listing.cc $(source_dir)/listing.h
	g++ -c $(source_dir)/listing.cc -o $(bin_dir)/listing.o


clean:
	rm -f $(bin_dir)/*
	rm -f $(source_dir)/scanner.c