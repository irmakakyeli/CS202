/**
* Author : Irmak Akyeli
* ID: 21803690
* Section : 2
* Assignment : 2
*/
#include "DecisionTreeNode.h"
#include <iostream>
#include <fstream>
#include <cmath>
#include <sstream>
#include <string>
using namespace std;
#ifndef DECISION_TREE_H
#define DECISION_TREE_H

class DecisionTree
{
public:
	double calculateEntropy(const int* classCounts, const int numClasses);
	double calculateInformationGain(const bool** data, const int* labels,
		const int numSamples, const int numFeatures, const bool* usedSamples,
		const int featureId);
	void recursiveTrain(const bool** data, const int* labels, const int numSamples, const int numFeatures, DecisionTreeNode*& node, bool* usedSamples, bool* usedFeatures);
	void train(const bool** data, const int* labels, const int numSamples, const int numFeatures);
	void train(const string fileName, const int numSamples, const int numFeatures);
	int predict(const bool* data);
	double test(const bool** data, const int* labels, const int numSamples);
	double test(const string fileName, const int numSamples);
	void printRecursive(DecisionTreeNode* root, string gap);
	void print();
private:
	DecisionTreeNode* root;

};
#endif