//Programmer:   Christopher Carney
//Section:      2
//Lab:          15
//Date:         April 15, 2014
//Description:  This is the implementation file for the HashTable class

#include <iostream>
#include <iomanip>
#include "HashTable.h"

using namespace std;

HashTable::HashTable()
//POST: a default empty hash table object has been created s.t. logical size == 0 &&
//          table[0..HASH_CONSTANT] = NULL
{
    //NodePtr table[HASH_CONSTANT] called implicitly

    //determinate loop to set the heads of the has table to NULL
    for (int i = 0; i < HASH_CONSTANT; i++)
    {
        table[i] = NULL;
    }

    logSize = 0;
}

int HashTable::hashValue(int key)
//PRE:  key is initialized
//POST: FCTVAL = the hash value of the given key, key % HASH_CONSTANT
{
    return key % HASH_CONSTANT;
}

void HashTable::hashInsert(int key)
//PRE:  key is initialized, key is not currently a value in this hash table 
//POST: key has been inserted into this hash table 
{
    int hashVal;                              //the hash value of where to insert for the key
    NodePtr temp;                             //the temport node to hold the value

    hashVal = hashValue(key);
    
    if (table[hashVal] == NULL)               //case if the current head is NULL
    {
        table[hashVal] = new NodeType;
        table[hashVal]->key = key;            //set key
        table[hashVal]->next = NULL;          //next is NULL
        logSize++;
    }
    else                                      //otherwise insert at had
    {
        temp = new NodeType;                  //allocate new node
        temp->key = key;                      //set key

        temp->next = table[hashVal];          //temp's next is current head
        table[hashVal] = temp;                //new head is temp
        logSize++;  
    }
}

int HashTable::hashSearch(int key)
//PRE:  key is initialized
//POST: FCTVAL == the number of chains searched through before the value was found ||
//             == -1 if the value is not found in this hash table
{
    NodePtr cur;                              //the current node being searched
    int nodesTraversed;                       //the number of nodes traversed to find the value

    cur = table[hashValue(key)];
    nodesTraversed = 0;

    //indeterminate loop to traverse the list until a NULL pointer is reached or the key is found
    while (cur != NULL && cur->key != key)
    {
        cur = cur->next;
        nodesTraversed++;
    }

    if (cur == NULL)                    //if cur's key is NULL it is not in the hash table
        return -1;
    else                                //otherwise return nodes traversed to find
        return nodesTraversed;
}

double HashTable::getLoadFactor() const
//POST: FCTVAL = the load factor of this hash table, logSize / HASH_CONSTANT
{
    double dLogSize;                 //the double value of the logical sie
    double dConstant;                //the double value of the hash constant

   dLogSize = logSize;
   dConstant = HASH_CONSTANT;

    return dLogSize / dConstant;
}

void HashTable::drawTable() const
//POST: an ASCII art table of this hash table has been drawn s.t.
//      [array subscript] -> hash table value -> hash table value -> ... -> NULL
{
    NodePtr cur;                        //the current node being traversed

    //determinate loop to print out every subscript of the array hash table
    for (int i = 0; i < HASH_CONSTANT; i++)
    {
        cur = table[i];                 //set cur the the current table subscript's head

        cout << "[" << i << "]" << " -> ";
 
        //indeterminate loop to print out values in a linked list until NULL is reached
        while (cur != NULL)
        {
            cout << setw(3) << cur->key << " -> ";     //print the value of the current node
            cur = cur->next;                           //point cur to the next node in the list
        }

        cout << setw(3) << "NULL" << endl;
    }
}