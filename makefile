all:
	g++ custom_test.cpp date.h date.cpp date_common.h date_common.cpp gregorian.h gregorian.cpp julian.h julian.cpp kattistime.h kattistime.cpp

run:
	./a.out
