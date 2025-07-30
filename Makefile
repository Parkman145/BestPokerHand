source_files = main.cpp cards.cpp hand.cpp
header_files = cards.h hand.h

run : a.exe
	./a.exe

build : a.exe

a.exe : $(source_files) $(header_files)
	g++ -g $(source_files) --std=c++20
clean :
	del a.exe

