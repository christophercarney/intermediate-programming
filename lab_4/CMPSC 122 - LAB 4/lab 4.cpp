//Programmer:   Christopher Carney
//Section:      2
//Lab:          4
//Date:         January 31, 2014
//Description:  This program is an exercise in using Linked Lists and pointers
//                  by hardcoding a linked list through various steps.

#include <iostream>
using namespace std;

struct NodeType;
typedef NodeType* NodePtr;

struct NodeType
{
    int data;                  //holds the value of the list node
    NodeType* next;            //points to the next node in the list
};

void walkList(NodePtr head)
//PRE:  head has been initialized
//POST: all values in the Linked List starting at the Node head and continuing until NULL 
//          have been printed (one from every node) with a space between each digit in the list
{
    NodePtr cur;                        //define a node to traverse each value

    cur = head;                         //start at the head

    //starting at the head of the list, print out each value then go to the next node and 
    //  prints that value out; until it reaches a NULL pointer
    while (cur != NULL)
    {
        cout << cur->data << " ";     //print the value of the current node
        cur = cur->next;              //pount cur to the next node in the list
    }

    return;

}

int main()
{
    NodePtr head;               //create head node of the list
    NodePtr temp;               //temp node to add values
    
    //STEP 1
    cout << "STEP 1: ";

    head = new NodeType;        //allocate pointee for the head
    
    head->data = 5;           //new node now has a 5
    head->next = NULL;        //it is the end of the list so a NULL pointer

    walkList(head);

    //STEP 2
    cout << "\nSTEP 2: ";

    temp = new NodeType;        //allocate a temp pointee

    temp->data = 8;           //store 8 in the temp pointee
    temp->next = head;        //point temp node to the 5 node
    head = temp;                //point head to where temp points (8 node) 8 is now the first element

    walkList(head);

    //STEP 3
    cout << "\nSTEP 3: ";

    temp = new NodeType;          //allocate new temp node

    temp->data = 12;              //set new node to 12 in data field
    temp->next = NULL;            //it will be the end of the list so points to nothing

    head->next->next = temp;      //from the list head, point 5 (end of list) to the 12 node
                                  //  (new end of list, stored in temp)

    walkList(head);

    //STEP 4
    cout << "\nSTEP 4: ";

    temp = new NodeType;                                //allocate new temp node

    temp->data = 7;                                     //store 7 in data field
    temp->next = head->next->next;                      //point temp node to the 12 node
    head->next->next = temp;                        //point node with 5 in it to the 7

    walkList(head);

    //STEP 5
    cout << "\nSTEP 5: ";

    temp = head->next;                                //point the temp to the 5 to "remember" where 
                                                        //   it is in the list

    head->next = temp->next;                        //point the 8 node to the 7 node (which is 1
                                                        //  after the new temp node
    delete temp;                                        //delte the 5 node which is contained in temp

    walkList(head);

    cout << endl;

}
