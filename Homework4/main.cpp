/**
* Author : Irmak Akyeli
* ID: 21803690
* Section : 2
* Assignment : 4
*/

#include "HashTable.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;




int main(int argc, char* argv[])
{
	
	int size = 101, probes =0;
	bool isSuc;
	double suc = 0, unsuc = 0;
	HashTable::CollisionStrategy a = HashTable::LINEAR;
	HashTable h(size, a);
	HashTable::CollisionStrategy b = HashTable::QUADRATIC;
	HashTable h2(size, b);
	HashTable::CollisionStrategy c = HashTable::DOUBLE;
	HashTable h3(size, c);

	
	string fileName;
	ifstream inFile;
	fileName = "text.txt";
	inFile.open(fileName.c_str());
	int item;
	string select, line;
	cout << "//////////////////////////" << endl;
	cout << "Linear Probing: " << endl;
	cout << "//////////////////////////" << endl;
	cout << endl;
	while (getline(inFile, line))
	{
		stringstream ss;
		ss << line;
		
		ss >> select;
		ss >> item;
		if (select == "I")
		{
			isSuc = h.insert(item);
			if (isSuc)
				cout << item << " inserted" << endl;
			else
				cout << item << " not inserted" << endl;
		}
		else if (select == "R")
		{
			isSuc = h.remove(item);
			if (isSuc)
				cout << item << " removed" << endl;
			else
				cout << item << " not removed" << endl;
		}
		else if (select == "S")
		{
			isSuc = h.search(item, probes);
			if (isSuc)
				cout << item << " found after " << probes <<" probes" << endl;
			else
				cout << item << " not found after " << probes << " probes" << endl;
		}
	}
	cout << endl;
	cout << "The table is like: " << endl;
	h.display();
	cout << endl;
	h.analyze(suc, unsuc);
	cout << "Successful probing: "<< suc << " Unsuccessful probing: " << unsuc << endl;
	cout << endl;

	cout << "//////////////////////////" << endl;
	cout << "Quadratic Probing: " << endl;
	cout << "//////////////////////////" << endl;
	cout << endl;
	inFile.clear();
	inFile.seekg(0, std::ios::beg);
	while (getline(inFile, line))
	{
		stringstream ss;
		ss << line;

		ss >> select;
		ss >> item;
		if (select == "I")
		{
			isSuc = h2.insert(item);
			if (isSuc)
				cout << item << " inserted" << endl;
			else
				cout << item << " not inserted" << endl;
		}
		else if (select == "R")
		{
			isSuc = h2.remove(item);
			if (isSuc)
				cout << item << " removed" << endl;
			else
				cout << item << " not removed" << endl;
		}
		else if (select == "S")
		{
			isSuc = h2.search(item, probes);
			if (isSuc)
				cout << item << " found after " << probes << " probes" << endl;
			else
				cout << item << " not found after " << probes << " probes" << endl;
		}
	}
	cout << endl;
	cout << "The table is like: " << endl;
	h2.display();
	cout << endl;
	h2.analyze(suc, unsuc);
	cout << "Successful probing: " << suc << " Unsuccessful probing: " << unsuc << endl;

	cout << endl;

	
	cout << "//////////////////////////" << endl;
	cout << "Double Probing: " << endl;
	cout << "//////////////////////////" << endl;
	cout << endl;
	inFile.clear();
	inFile.seekg(0, std::ios::beg);
	while (getline(inFile, line))
	{
		stringstream ss;
		ss << line;

		ss >> select;
		ss >> item;
		if (select == "I")
		{
			isSuc = h3.insert(item);
			if (isSuc)
				cout << item << " inserted" << endl;
			else
				cout << item << " not inserted" << endl;
		}
		else if (select == "R")
		{
			isSuc = h3.remove(item);
			if (isSuc)
				cout << item << " removed" << endl;
			else
				cout << item << " not removed" << endl;
		}
		else if (select == "S")
		{
			isSuc = h3.search(item, probes);
			if (isSuc)
				cout << item << " found after " << probes << " probes" << endl;
			else
				cout << item << " not found after " << probes << " probes" << endl;
		}
	}
	cout << endl;
	cout << "The table is like: " << endl;
	h3.display();
	cout << endl;
	h3.analyze(suc, unsuc);
	cout << "Successful probing: " << suc << " Unsuccessful probing: " << unsuc << endl;

	return 0;

}