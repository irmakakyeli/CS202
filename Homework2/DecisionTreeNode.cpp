/**
* Author : Irmak Akyeli
* ID: 21803690
* Section : 2
* Assignment : 2
*/
#include "DecisionTreeNode.h"
#include <string>
using namespace std;

DecisionTreeNode::DecisionTreeNode()
{
	isLeaf = false;
	classLabel = -1;
	feature = -1;
	leftChild =NULL;
	rightChild = NULL;
}

DecisionTreeNode::DecisionTreeNode(bool isL,  int noInfo)
{
	isLeaf = isL;
	classLabel = -1;
	feature = -1;
	if(isLeaf)
	{
		classLabel = noInfo;
		leftChild = NULL;
		rightChild = NULL;
	}
	else
	{
		feature = noInfo;
		leftChild = new DecisionTreeNode();
		rightChild = new DecisionTreeNode();
	}
	
}

//methods
bool DecisionTreeNode::isLeafNode()
{
	return isLeaf;
}

int DecisionTreeNode::getClass()
{
	return classLabel;
}


void DecisionTreeNode::setClass(int classNo)
{
	classLabel = classNo;
}


int DecisionTreeNode::getFeature()
{
	return feature;
}


void DecisionTreeNode::setFeature(int featureNo)
{
	feature = featureNo;
}


DecisionTreeNode* DecisionTreeNode::getLeftChild()
{
	return leftChild;
}


DecisionTreeNode* DecisionTreeNode::getRightChild()
{
	return rightChild;
}


void DecisionTreeNode::setLeftChild(DecisionTreeNode* leftC)
{
	leftChild = leftC;
}


void DecisionTreeNode::setRightChild(DecisionTreeNode* rightC)
{
	rightChild = rightC;
}