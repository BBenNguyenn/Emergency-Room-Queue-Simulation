CC=g++
CFLAGS=
#CFLAGS=-c -Wall -ggdb

all: t

main: clean
	$(CC) *.cpp -o Run

t: clean
	$(CC) Main.cpp Const.cpp Arrival.cpp Discharge.cpp CompleteAssessment.cpp CompleteBloodWork.cpp CompleteXRay.cpp EDSimulation.cpp Event.cpp FileHandler.cpp ListItem.cpp Node.cpp Patient.cpp PriorityQueue.cpp Queue.cpp Station.cpp StartAssessment.cpp StartBloodWork.cpp StartTreatment.cpp StartXRay.cpp -o Run
	
t2: clean
	$(CC) Main.cpp EDSimulation.cpp FileHandler.cpp Patient.cpp ListItem.cpp -o test
	
t3: clean
	$(CC) Arrival.cpp Event.cpp testmain.cpp ListItem.cpp Node.cpp Patient.cpp Queue.cpp PriorityQueue.cpp -o test


clean:
	rm -f Run test