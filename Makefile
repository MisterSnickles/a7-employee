employee.exe: main.o employee.o  # No list.o needed, templates are header-only
	g++ main.o employee.o -o employee.exe

main.o: main.cpp list.h node.h employee.h
	g++ -g -c main.cpp

employee.o: employee.cpp employee.h
	g++ -g -c employee.cpp

clean:
	rm -f *.o *.exe

r:
	./employee.exe

zip:
	zip A7_Mabery_Jonathan.zip *.h *.cpp *.pdf Makefile