all: clean custom_calendar

clean:
	clear
	rm -f *.h.gch a.out

datetest:
	g++ date.h date.cpp date_common.h date_common.cpp gregorian.h gregorian.cpp julian.h julian.cpp kattistime.h kattistime.cpp datetest.cpp

custom: custom_calendar

custom_date:
	g++ -g date.h date.cpp date_common.h date_common.cpp gregorian.h gregorian.cpp julian.h julian.cpp kattistime.h kattistime.cpp custom_date_test.cpp 

custom_calendar:
	g++ -g date.h date.cpp date_common.h date_common.cpp gregorian.h gregorian.cpp julian.h julian.cpp kattistime.h kattistime.cpp custom_calendar_test.cpp 

lab22a:
	g++ -g -Wall cprog09lab22a.cpp date.h date.cpp date_common.h date_common.cpp gregorian.h gregorian.cpp julian.h julian.cpp kattistime.h kattistime.cpp 

lab22b:
	g++ -g -Wall cprog09lab22b.cpp date.h date.cpp date_common.h date_common.cpp gregorian.h gregorian.cpp julian.h julian.cpp kattistime.h kattistime.cpp

lab22c:
	g++ -g -Wall cprog09lab22c.cpp date.h date.cpp date_common.h date_common.cpp gregorian.h gregorian.cpp julian.h julian.cpp kattistime.h kattistime.cpp 
lab23:
	g++ cprog09lab23.cpp date.h date.cpp date_common.h date_common.cpp gregorian.h gregorian.cpp julian.h julian.cpp kattistime.h kattistime.cpp calendar.h 

run: all
	./a.out

submit22a: clean lab22a
	./submit.py -f -p cprog09lab22a julian.cpp julian.h kattistime.cpp kattistime.h date.cpp date.h date_common.h date_common.cpp cprog09lab22a.cpp

submit22b: clean lab22b
	./submit.py -f -p cprog09lab22b gregorian.cpp gregorian.h kattistime.cpp kattistime.h date.cpp date.h date_common.h date_common.cpp cprog09lab22b.cpp

submit22c: clean lab22c
	./submit.py -f -p cprog09lab22c gregorian.cpp gregorian.h julian.cpp julian.h kattistime.cpp kattistime.h date.cpp date.h date_common.h date_common.cpp cprog09lab22c.cpp

submit23: clean lab23
	./submit.py -f -p cprog09lab23 cprog09lab23.cpp date.h date.cpp date_common.h date_common.cpp gregorian.h gregorian.cpp julian.h julian.cpp kattistime.h kattistime.cpp calendar.h 
