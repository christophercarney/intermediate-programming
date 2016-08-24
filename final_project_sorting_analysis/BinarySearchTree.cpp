//Programmer:   Christopher Carney & Dylan Fetch
//Section:      2
//Lab:          Final
//Date:         April 27, 2014
//Description:  This is the implementation of the BinarySearchTree class

#include <iostream>
#include "BinarySearchTree.h"

using namespace std;


                            /*PUBLIC METHOD IMPLEMENTATIONS*/

BinarySearchTree::BinarySearchTree()
//POST: a default BinarySearchTree object has been constructed s.t. root = NULL
{
    root = NULL;
}

BinarySearchTree::BinarySearchTree(int inputs[], int logSize)
//PRE:  logSize is initialized, logSize > 0
//      inputs[0..logSize] have been initialized
//POST: a BinarySearchTree object has been constructed s.t. inputs[0..logSize] have been
//          sorted into a binary search tree 
{
    root = NULL;

    //determinate loop to insert keys from the input array into the binary search tree
    for (int i = 0; i < logSize; i++)
    {
        insertKey(inputs[i]);
    }
}

void BinarySearchTree::insertKey(int key)
//PRE:  key has been initialized, key is not currently in this binary search tree
//POST: key has been inserted into this binary search tree in the correct position
{
    privateInsert(root, key);
}

void BinarySearchTree::inorderCopy(int array[], int & logSize)
//PRE:  array[0..logsize-1] is initialized, logSize is initialized,logSize > 0
//POST: an Inorder traversal of the binary search tree starting at root has been saved into
//          array[0..logSize - 1] at the time of invocation in ascending order
{
    logSize = 0;                       //start inserting at the first subscript in the array
    privateInorder(root, array, logSize);
}

                            /*PRIVATE METHOD IMPLEMENTATIONS*/

void BinarySearchTree::privateInsert(TreeNodePtr & subTreeRoot, int key)
//PRE:  subTreeRoot is a pointer to the root of a subree in a binary search tree
//      key is initialized && key is not currently in this binary search tree
//POST: key has been inserted into the binary search tree;
{
    if (subTreeRoot == NULL)                    //BASE CASE: root is NULL and key must be inserted
    {                                           //  there
        subTreeRoot = new TreeNodeType;
        subTreeRoot->key = key;
        subTreeRoot->left = NULL;
        subTreeRoot->right = NULL;

        return;
    }
    else if (subTreeRoot->key >= key)               //RECURSIVE CASE: if key is less or equal 
        privateInsert(subTreeRoot->left, key);      //   than the root go left in the tree
    else                                            //RECURSIVE CASE: else to right in the tree
        privateInsert(subTreeRoot->right, key);
}

void BinarySearchTree::privateInorder(TreeNodePtr subTreeRoot, int array[], int & logSize)
//PRE:  subTreeRoot is a pointer to the root of a subree in a binary search tree with
//          unique keys.
//      array[0..logSize-1] is initialized, logSize is initialized, logSize > 0
//POST: an Inorder traversal of the binary search tree starting at subTreeRoot has been saved
//           into array[0..logSize - 1] at the time of invocation in ascending order
{   
    if (subTreeRoot != NULL)                       //BASE CASE: NULL root is reached
    {
        privateInorder(subTreeRoot->left, array, logSize);     //RECURSIVE CASE: go left 
        array[logSize] = subTreeRoot->key;
        logSize++;
        privateInorder(subTreeRoot->right, array, logSize);    //RECURSIVE CASE: go right
    }
}

