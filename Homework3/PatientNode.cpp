/**
* Author : Irmak Akyeli
* ID: 21803690
* Section : 2
* Assignment : 3
*/
#include "PatientNode.h"

PatientNode::PatientNode()
{
	id = 0;
	priority = 0;
	arrivalTime = 0;
	examinationTime = 0;
}

PatientNode::PatientNode(int gid, int gpriority, int garrivalTime, int gexaminationTime)
{
	id = gid;
	priority = gpriority;
	arrivalTime = garrivalTime;
	examinationTime = gexaminationTime;
}

int PatientNode::getPriority()
{
	return priority;
}
