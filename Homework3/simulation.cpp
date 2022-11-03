/**
* Author : Irmak Akyeli
* ID: 21803690
* Section : 2
* Assignment : 3
*/

#include <climits>
#include "DoctorNode.h"
#ifdef FIRST
#   include "maxHeap1.h"
#else
#   include "maxHeap2.h"
#endif // FIRST
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;



double driver(PatientNode  *& patients, int patientsNo, int maxAverageTime)
{
	int noOfDoctors=1, time = 1, noOfDoneP=0;
	double theAverage, totalWait=0.0;
	theAverage = (double)INT_MAX;
	maxHeap heap;
	DoctorNode* doctors;
	string s;
	while (theAverage > maxAverageTime)
	{
		s = " ";
		time = 1;
		doctors = new DoctorNode[noOfDoctors];
		for (int i = 0; i < noOfDoctors; i++)
		{
			doctors[i] = DoctorNode(i);
		}
		while (noOfDoneP != patientsNo)
		{
			for (int i = 0; i < patientsNo; i++)
			{
				if (time == patients[i].arrivalTime)
				{
					heap.heapInsert(patients[i]);
				}
			}
			if (!heap.heapIsEmpty())
			{
				for (int i = 0; i < noOfDoctors; i++)
				{
					if (doctors[i].checkIfAvailable(time) && noOfDoneP !=patientsNo)
					{
						PatientNode patient;
						heap.heapDelete(patient);
						stringstream variables;
						variables << i << ' ' << patient.id << ' ' << time << ' ' << time - patient.arrivalTime;
						string a, b, c, d;
						variables >> a >> b >> c >> d;
						totalWait += time - (patient.arrivalTime);
						doctors[i].setTime(time + patient.examinationTime);
						noOfDoneP++;
						s +=  "\nDoctor " + a +  " takes patient " + b +  " at minute" + c +  " (wait: " + d + " mins)";
					}
				}
			}

			time++;
		}
		noOfDoctors++;
		delete[] doctors;
		doctors = NULL;
		theAverage = (double)totalWait / (double)patientsNo;
		totalWait = 0.0;
		noOfDoneP = 0;
	}
	cout << s << endl;
	cout << "Average waiting time: " << theAverage << endl;
	
	return theAverage;
}

int main(int argc, char* argv[])
{
	string fileName;
	ifstream inFile;
	int patientsNo, id, priority, arrivalTime, duration, maxAverageTime;
	if (argc < 2 || argc > 3)
	{
		cout << "Enter 2 arguments only eg.. / <executablename> <filename> <maxAverageTime>" << endl;
		return 0;
	}
	fileName = argv[1];
	inFile.open(fileName.c_str());
	stringstream stringMaxTime;
	stringMaxTime << argv[2];
	stringMaxTime >> maxAverageTime;

	inFile >> patientsNo;

	PatientNode* patients = new PatientNode[patientsNo];
	for (int i = 0; i < patientsNo; i++)
	{
		inFile >> id;
		inFile >> priority;
		inFile >> arrivalTime;
		inFile >> duration;

		patients[i] = PatientNode(id, priority, arrivalTime, duration);
	}

	driver(patients, patientsNo, maxAverageTime);

}