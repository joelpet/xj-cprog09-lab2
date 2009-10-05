CC = g++              # kompilator
FLAGS = -g -Wall      # flaggor
OBJS = main.o julian.o gregorian.o

date: $(OBJS)
	$(CC) $(FLAGS) -o date $(OBJS)
%.o: %.cpp
	$(CC) $(FLAGS) -c $*.cpp
depend:
	makedepend -- $(FLAGS) -- *.cpp

