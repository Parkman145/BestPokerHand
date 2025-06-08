run : a.exe
	./a.exe

build : a.exe

a.exe : main.cpp cards.h
	g++ -g main.cpp --std=c++20
clean :
	del a.exe

