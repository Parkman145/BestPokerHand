source_files = main.cpp cards.cpp hand.cpp hand_algo.cpp
header_files = cards.h hand.h

build : a.exe

run : a.exe
	./a.exe


a.exe : $(source_files) $(header_files)
	g++ -g $(source_files) --std=c++20
clean :
	del a.exe

