//Programmer:   Christopher Carney
//Section:      2
//Lab:          13
//Date:         April 1, 2014
//Description:  This program hardcodes binary trees and then calls a method to print
//                  out the key and both of its children.

#include <iostream>
#include <iomanip>
using namespace std;

struct TreeType;
typedef TreeType* TreePtr;

struct TreeType
{
    char key;               //the value of the node in the tree
    TreeType* left;         //the pointer to the left child node of the tree
    TreeType* right;        //the pointer to the right child node of the tree
};

void nodeString(TreePtr start)
//PRE:  start is initialized, start is a pointer to a TreeType node
//POST: the key in the start node && the key of both the left and right child have been printed
//          too the screen, or "NULL" if the child points to NULL
{
    cout << "Root: " << start->key;                 //prints the key of start

    cout << "   " << "Left: ";
    if (start->left != NULL)                        //if the left child of start is not NULL 
        cout << setw(6) << start->left->key;        //  its value will be displayed
    else                                            //if the left child is NULL display that
        cout << setw(6) << "NULL";

    cout << "   " << "Right: ";
    if (start->right != NULL)                       //if the right child of start is not NULL 
        cout << setw(6) << start->right->key;       //  its value will be displayed
    else                                            //if the right child is NULL display that
        cout << setw(6) << "NULL";

    cout << endl;
}

int main()
{
    TreePtr root;                   //the root of the tree from the problem in part II

    //the following hardcodes the problem from part II of the notes into code
    root = new TreeType;

    root->key = '+';

    root->right = new TreeType;
    root->right->key = 'b';
    root->right->left = NULL;
    root->right->right = NULL;

    root->left = new TreeType;
    root->left->key = '-';

    root->left->left = new TreeType;
    root->left->left->key = '*';

    root->left->right = NULL;

    root->left->left->left = new TreeType;
    root->left->left->left->key = 'a';

    root->left->left->left->left = NULL;
    root->left->left->left->right = NULL;

    root->left->left->right = new TreeType;
    root->left->left->right->key = 'c';

    root->left->left->right->left = NULL;
    root->left->left->right->right = NULL;

    //printing all the nodes to ensure everything is coded properly
    nodeString(root);
    nodeString(root->left);
    nodeString(root->right);
    nodeString(root->left->left);
    nodeString(root->left->left->left);
    nodeString(root->left->left->right);

    return 0;
}