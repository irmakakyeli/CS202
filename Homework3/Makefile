all: simulator_Q1 simulator_Q2

simulator_Q1:
	g++ -DFIRST simulation.cpp PatientNode.cpp PatientNode.h DoctorNode.cpp DoctorNode.h maxHeap1.cpp maxHeap1.h -o simulator_Q1

simulator_Q2:
	g++ simulation.cpp PatientNode.cpp PatientNode.h DoctorNode.cpp DoctorNode.h maxHeap2.cpp maxHeap2.h -o simulator_Q2

clean:
	rm simulator_Q1 simulator_Q2
