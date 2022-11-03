/**
* Author : Irmak Akyeli
* ID: 21803690
* Section : 2
* Assignment : 3
*/
#ifndef PATIENT_NODE_H
#define PATIENT_NODE_H

class PatientNode
{
public:
	int id, priority, arrivalTime, examinationTime;
	PatientNode();
	PatientNode(int gid, int gpriority, int garrivalTime, int gexaminationTime);
	int getPriority();
};

#endif 
