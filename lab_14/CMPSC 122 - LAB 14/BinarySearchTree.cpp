//Programmer:   Christopher Carney
//Section:      2
//Lab:          14
//Date:         April 8, 2014
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
//      inputs[0..logSize] have been initialized, each value in inputs is unique
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

bool BinarySearchTree::search(int key)
//PRE:  key has been initialized
//POST: FCTVAL == true if key is in this BinarySearchTree starting at root ||
//          false if key is not contained in this BinarySearchTree starting at root
{
    return privateSearch(root, key);
}

void BinarySearchTree::traceSearch(int key)
//PRE:  key has been initialized
//POST: the search for key in this BinarySearchTree starting at root has been outputted
//          to the user showing the decisions to go to the right or left node and also
//          if the key is contained in this BinarySearchTree
{
    privateTraceSearch(root, key);
}

void BinarySearchTree::inorderCopy(int array[], int & logSize)
//POST: an Inorder traversal of the binary search tree starting at root has been printed
//          to the screen in the order left, root, right
{
    logSize = 0;                       //start inserting at the first subscript in the array
    privateInorder(root, array, logSize);
}

void BinarySearchTree::printPreorder()
//POST: a Preeorder traversal of the binary search tree starting at root has been printed
//          to the screen in the order root, left, right
{
    privatePreorder(root);
}

                            /*PRIVATE METHOD IMPLEMENTATIONS*/

void BinarySearchTree::privateInsert(TreeNodePtr & subTreeRoot, int key)
//PRE:  subTreeRoot is a pointer to the root of a subree in a binary search tree with
//          unique keys.
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
    else if (subTreeRoot->key >= key)                //RECURSIVE CASE: if key is less than the root
        privateInsert(subTreeRoot->left, key);      //   go left in the tree
    else                                            //RECURSIVE CASE: else to right in the tree
        privateInsert(subTreeRoot->right, key);
}

bool BinarySearchTree::privateSearch(TreeNodePtr subTreeRoot, int key)
//PRE:  subTreeRoot is a pointer to the root of a subree in a binary search tree with
//          unique keys.
//      key is initialized.
//POST: FCTVAL == true if key is in this BinarySearchTree starting at root ||
//          false if key is not contained in this BinarySearchTree starting at root
{
    if (subTreeRoot == NULL)                                //BASE CASE: if a NULL subtree root is 
        return false;                                       //  reached the key is not in BST

    else if (subTreeRoot->key == key)                       //BASE CASE: if the key of the root 
        return true;                                        //  == key

    else if (subTreeRoot->key > key)                        //RECURSIVE CASE: key is less than the
        return privateSearch(subTreeRoot->left, key);       //  key of the root

    else                                                    //RECURSIVE CASE: key is greater than
        return privateSearch(subTreeRoot->right, key);      //  the key of the root
}

void BinarySearchTree::privateTraceSearch(TreeNodePtr subTreeRoot, int key)
//PRE:  subTreeRoot is a pointer to the root of a subree in a binary search tree with
//          unique keys.
//      key is initialized
//POST: the search for key in this BinarySearchTree starting at root has been outputted
//          to the user showing the decisions to go to the right or left node and also
//          if the key is contained in this BinarySearchTree
{
    if (subTreeRoot == NULL)                                //BASE CASE: if a NULL subtree root is 
    {                                                       //  reached
        cout << "Reached NULL node, " << key << " is not in tree, so return\n\n"; 
        return;                                       
    }
    else if (subTreeRoot->key == key)                       //BASE CASE: if the key of the root 
    {                                                       //  is the key being searched for
        cout << "Checking " << subTreeRoot->key << " node. Matches " << key << ". ";
        cout << key << " = " << subTreeRoot->key << ", so return\n\n";
        return;                                       
    }
    else if (subTreeRoot->key > key)                        //RECURSIVE CASE: key is less than the
    {                                                       //  root's key
        cout << "Checking " << subTreeRoot->key << " node. Does not match " << key << ". ";
        cout << key << " < " << subTreeRoot->key << ", so go left\n";
        privateTraceSearch(subTreeRoot->left, key);       
    }
    else                                                    //RECURSIVE CASE: key is greater than
    {                                                       //  root's key
        cout << "Checking " << subTreeRoot->key << " node. Does not match " << key << ". ";
        cout << key << " > " << subTreeRoot->key << ", so go right\n";
        privateTraceSearch(subTreeRoot->right, key);    
    }
}

void BinarySearchTree::privateInorder(TreeNodePtr subTreeRoot, int array[], int & logSize)
//PRE:  subTreeRoot is a pointer to the root of a subree in a binary search tree with
//          unique keys.
//POST: an Inorder traversal of the binary search tree starting at root has been printed
//          to the screen in the order left, root, right
{   
    if (subTreeRoot != NULL)                       //BASE CASE: NULL root is reached
    {
        privateInorder(subTreeRoot->left, array, logSize);     //RECURSIVE CASE: go left 
        array[logSize] = subTreeRoot->key;
        logSize++;
        privateInorder(subTreeRoot->right, array, logSize);    //RECURSIVE CASE: go right
    }
}

void BinarySearchTree::privatePreorder(TreeNodePtr subTreeRoot)
//PRE:  subTreeRoot is a pointer to the root of a subree in a binary search tree with
//          unique keys.
//POST: a Preeorder traversal of the binary search tree starting at root has been printed
//          to the screen in the order root, left, right
{
    if (subTreeRoot != NULL)                       //BASE CASE: NULL root is reached
    {
        cout << subTreeRoot->key << " ";           //print the root value
        privatePreorder(subTreeRoot->left);         //RECURSIVE CASE: go left as far as possible
        privatePreorder(subTreeRoot->right);        //RECURSIVE CASE: go right as far as possible
    }
}
