all:
	g++ date.h date.cpp date_common.h date_common.cpp gregorian.h gregorian.cpp julian.h julian.cpp kattistime.h kattistime.cpp custom_test.cpp

run:
	./a.out
