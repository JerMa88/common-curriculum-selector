clean:
	rm -rf *.o test_list

test_list: test_list.o list.o
    clang++ -Wall -std=c++11 -o test_list test_list.o list.o

test_list.o: test_list.cpp
	clang++ -Wall -std=c++11 -c test_list.cpp

list.o: datastructure/list.cpp datastructure/list.h
	clang++ -Wall -std=c++11 -c ./datastructure/list.cpp