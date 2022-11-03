/**
* Author : Irmak Akyeli
* ID: 21803690
* Section : 2
* Assignment : 2
*/


#include "DecisionTree.h"
#include <iostream>
#include <cmath>
#include <sstream>
#include <fstream>
#include <string>
using namespace std;


void DecisionTree::recursiveTrain(const bool** data, const int* labels, const int numSamples, const int numFeatures, DecisionTreeNode*& node, bool* usedSamples, bool* usedFeatures)
{
	int maxFeatureId = -1; //this is our variable to track the feature with maximum information gain
	double maxInfoGain = -1; //this is the max information gain we could obtain
	for (int i = 0; i < numFeatures; i++)
	{
		if (!usedFeatures[i]) //looks if the feature already used as we can only use it ones
		{
			double currentIG = calculateInformationGain(data, labels, numSamples, numFeatures, usedSamples, i);
			if (currentIG > maxInfoGain)
			{
				maxFeatureId = i;
				maxInfoGain = currentIG; //chooses the current feature if it is greater than the one we had before
			}
		}
	}

	if (maxInfoGain <= 0  || maxInfoGain == -1) //if we have information gain less than 0 it means the leafs are pure
	{
		double classLabel = 0.0;
		int count = 0;
		for (int i = 0; i < numSamples; i++)
		{
			if (usedSamples[i])
			{
				classLabel += (double)labels[i];
				count++;
			}
		}
		classLabel = classLabel / (double)count;
		int finalClass = (int)round(classLabel);
		node = new DecisionTreeNode(true, finalClass);
		return;
	}

	bool* usedSamplesLeft = new bool[numSamples];
	bool* usedSamplesRight = new bool[numSamples];
	bool* usedFeaturesChild = new bool[numFeatures];

	for (int i = 0; i < numSamples; i++)
	{
		usedSamplesLeft[i] = usedSamples[i];
		usedSamplesRight[i] = usedSamples[i];
	}

	for (int i = 0; i < numSamples; i++)
	{
		if (usedSamples[i])
		{
			if (!data[i][maxFeatureId])
			{
				usedSamplesRight[i] = false;
			}
			else
			{
				usedSamplesLeft[i] = false;
			}
		}
	}


	for (int i = 0; i < numFeatures; i++)
	{
		usedFeaturesChild[i] = usedFeatures[i]; //takes the used features from parent to not use the sames two times
	}
	if (maxFeatureId >= 0)
	{
		usedFeaturesChild[maxFeatureId] = true;
	}
	node = new DecisionTreeNode(false, maxFeatureId); //false means it is not a leaf node and its feature is maxFeatueId

	recursiveTrain(data, labels, numSamples, numFeatures, node->leftChild, usedSamplesLeft, usedFeaturesChild);
	recursiveTrain(data, labels, numSamples, numFeatures, node->rightChild, usedSamplesRight, usedFeaturesChild);

}

void DecisionTree::train(const bool** data, const int* labels, const int numSamples, const int numFeatures)
{
	int maxFeatureId = 0;
	bool* usedSamples = new bool[numSamples];
	bool* usedFeatures = new bool[numFeatures];
	for (int i = 0; i < numSamples; i++)
	{
		usedSamples[i] = true; //initializes the usedSamples as it is the first time we will use them
	}

	for (int i = 0; i < numFeatures; i++)
	{
		usedFeatures[i] = false;  //initializes the usedFeatures as it is the first time we will use them
	}
	recursiveTrain(data, labels, numSamples, numFeatures, root, usedSamples, usedFeatures);
}

void DecisionTree::train(const string fileName, const int numSamples, const int numFeatures)
{

	ifstream inFile;
	inFile.open(fileName.c_str());

	bool** data = new bool* [numSamples];
	int* labels = new int[numSamples];

	for (int i = 0; i < numSamples; i++)
	{
		data[i] = new bool[numFeatures]; //initializes the data
	}

	for (int y = 0; y < numSamples; y++)
	{
		for (int i = 0; i < numFeatures; i++)
		{
			int x;
			inFile >> x;
			data[y][i] = x; //fills it with the parsed information
		}
		int x;
		inFile >> x;
		labels[y] = x; // fils the labels
	}
	train( (const bool **) data,  (const int*) labels,  numSamples, numFeatures);

	for (int i = 0; i < numSamples; i++)
	{
		delete[] data[i];
	}
	delete[] data;

	delete[] labels;
}

int DecisionTree::predict(const bool* data)
{
	DecisionTreeNode* curr;
	curr = root;
	while (!curr->isLeaf) //traverses until it reaches a leaf
	{
		if (data[curr->feature])
		{
			curr = curr->rightChild;

		}
		else
		{
			curr = curr->leftChild;
		}
	}
	return curr->classLabel; //retrns the class of the leaf it reached
}

double DecisionTree::test(const bool** data, const int* labels, const int numSamples)
{
	int correct=0, incorrect=0; //numbers to calculate persentage
	for (int i = 0; i < numSamples; i++)
	{

		if (predict(data[i]) == labels[i]) //check if the prediction is correct
		{
			correct++;
		}
		else
		{
			incorrect++;
		}
	}
	double persentage = ((double)correct) / ((double)correct + (double)incorrect);
	return (persentage * 100);
}

double DecisionTree::test(const string fileName, const int numSamples)
{
	ifstream inFile;
	inFile.open(fileName.c_str());

	bool** data = new bool* [numSamples];
	int* labels = new int[numSamples];
	int numFeatures= -2;
	string line;
	getline(inFile, line);

	for (int i = 0; i < line.length(); i++)
	{
		if (line[i] != ' ')
		{
			numFeatures++;
		}
	}

	inFile.clear();
    	inFile.seekg(0, std::ios::beg); //rereads the first line as taking numFeatures we passed it

	for (int i = 0; i < numSamples; i++)
	{
		data[i] = new bool[numFeatures];
	}

	for (int y = 0; y < numSamples; y++)
	{
		for (int i = 0; i < numFeatures; i++)
		{
			int x;
			inFile >> x;
			data[y][i] = x;
		}
		int x;
		inFile >> x;
		labels[y] = x;
	}

	return test((const bool**)data, (const int*)labels, numSamples);
}

void DecisionTree::printRecursive(DecisionTreeNode* root, string gap)
{

	if (root->isLeafNode())
	{
		cout  << gap << "Class: " << root->getClass() << endl;
		gap = gap + "\t ";
		return;
	}
	else if (!root->isLeafNode())
	{
		cout  << gap << "Feature: " << root->getFeature() << endl;
		gap = gap + "\t "; //makes the gap as wanted
		printRecursive(root->leftChild, gap);
		printRecursive(root->rightChild, gap);
		cout << endl;
	}
}

void DecisionTree::print()
{
	string gap = " ";
	printRecursive(root, gap);
}

double DecisionTree::calculateEntropy(const int* classCounts, const int numClasses)
{
	int total = 0;
	double entropy = 0.0;
	double probability = 0.0;
	for (int i = 0; i < numClasses; i++)
	{
		total += classCounts[i];
	}

	for (int i = 0; i < numClasses; i++)
	{

		probability = (double)classCounts[i] / (double)total;
		if (classCounts[i] != 0)
		{
			entropy += probability * log2(probability);
		}
	}

	entropy *= (-1);
	return entropy;
}

double DecisionTree::calculateInformationGain(const bool** data, const int* labels,
	const int numSamples, const int numFeatures, const bool* usedSamples,
	const int featureId)
{
	double firstEntropy = 0.0, secondEntropy = 0.0, currentEntropy = 0.0, pottentialEntropy = 0.0;
	int left=0, right=0, allC=0;
	int max=0;
	for(int i=0; i < numSamples; i++)
    {
        int curr=labels[i];
        if(curr > max)
        {
            max = curr;
        }
    }
	int *leftChildClass = new int[max];
	int *rightChildClass = new int[max];
	int *totalClasses = new int[max];

	for (int i = 0; i < max; i++)
	{
		leftChildClass[i] = 0;
		rightChildClass[i] = 0;
		totalClasses[i] = 0;
	}

	for (int i = 0; i < numSamples; i++)
	{
		if (usedSamples[i])
		{
			totalClasses[labels[i] - 1]++;
			if (!data[i][featureId])
			{
				leftChildClass[(labels[i] - 1)]++;
				left++;
			}
			else if (data[i][featureId])
			{
				rightChildClass[(labels[i] - 1)]++;
				right++;
			}
			allC++;
		}
	}
	firstEntropy = calculateEntropy(leftChildClass, max);
	secondEntropy = calculateEntropy(rightChildClass, max);
	currentEntropy = calculateEntropy(totalClasses, max);
	pottentialEntropy = ((double) left / (double)allC) * firstEntropy + ((double)right / (double)allC) * secondEntropy;
	return currentEntropy - pottentialEntropy;
}
