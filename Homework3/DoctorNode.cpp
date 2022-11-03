#include "DoctorNode.h"


DoctorNode::DoctorNode()
{
	id = 0;
	isOccupied = false;
	timeAt = -1;
}

DoctorNode::DoctorNode(int idGiven)
{
	id = idGiven;
	isOccupied = false;
	timeAt = -1;
}

void DoctorNode::setTime(int time)
{
	isOccupied = true;
	timeAt = time;
}

bool DoctorNode::checkIfAvailable(int time)
{
	if (!isOccupied)
	{
		return true;
	}
	else if (time >= timeAt)
	{
		isOccupied = false;
		return true;
	}
	else
		return false;
}