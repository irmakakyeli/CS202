#ifndef  DOCTOR_NODE_H
#define DOCTOR_NODE_H


class DoctorNode
{
public:
	DoctorNode();
	DoctorNode(int idGiven);
	void setTime(int time);
	bool checkIfAvailable(int time);
	bool isOccupied;
	int timeAt;
	int id;
};
#endif