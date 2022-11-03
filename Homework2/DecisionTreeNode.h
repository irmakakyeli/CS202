/**
* Author : Irmak Akyeli
* ID: 21803690
* Section : 2
* Assignment : 2
*/

#ifndef DECISION_TREE_NODE_H
#define DECISION_TREE_NODE_H

class DecisionTreeNode
{
public:
	DecisionTreeNode* leftChild;
	DecisionTreeNode* rightChild;
	

	//constructors
	DecisionTreeNode();
	DecisionTreeNode(bool isL, int noInfo);
	

	//methods
	bool isLeafNode();
	int getClass();
	void setClass( int classNo);
	int getFeature();
	void setFeature(int featureNo);
	DecisionTreeNode* getLeftChild();
	DecisionTreeNode* getRightChild();
	void setLeftChild(DecisionTreeNode* leftChild);
	void setRightChild(DecisionTreeNode* rightChild);
	
private:
	friend class DecisionTree;
	int classLabel;
	bool isLeaf;
	int feature;
};

#endif // !DECISION_TREE_NODE_H
