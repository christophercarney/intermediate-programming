//Programmer:   Christopher Carney
//Section:      2
//Lab:          5
//Date:         February 11, 2014
//Description:  This program is an exercise in many different functions manipulating
//                  linked lists and then testing them properly.

#include <iostream>
using namespace std;

struct NodeType;
typedef NodeType* NodePtr;

struct NodeType
{
    int data;                  //holds the value of the list node
    NodeType* next;            //points to the next node in the list
};


void insertAtHead(NodePtr & head, int k)
//PRE:	head has been initialized, head is a pointer to a linked list
//       k has been initialized
//POST:	k has been inserted as the data field in the first node in the linked list starting at head and                                                                    
//          continuing until NULL. k is in the data field of the head node
//          head's pointee points to the previous first node in the linked list starting at head
{
    NodePtr temp;                   //temp node to store a new value in

    temp = new NodeType;            //allocate a pointee for temp

    temp->data = k;                 //store k in the temp node

    
    if (head == NULL)
    {
        head->data = k;
        head->next = NULL;
    }
    else
    {
        temp->next = head;              //make temp's successor be head
        head = temp;                    //point head to temps pointee
    }
    
}

void insertAtTail(NodePtr & head, int k)
//PRE:	head has been initialized, head is a pointer to a linked list
//       k has been initialized
//POST:	k has been inserted in the last data field in the last node in the linked list starting at head and
//         continuing until NULL. 
//      the node with k as the data field points to NULL.
//      the previous final element in the linked list starting at head now points to the node with k
//          contained in the data field
{
    NodePtr temp;                   //temp node to store the value to be inserted
    NodePtr tail;                   //pointer to keep track of where the final node is

    tail  = head;
    while (tail->next != NULL)      //walk the list to find the last node, set pointer tail to it
    {
        tail = tail->next;
    }

    temp = new NodeType;            //allocate a new temp node

    temp->data = k;                 //store k in temp
    temp->next = NULL;              //make temp's successor be a NULL pointer

    tail->next = temp;              //point tail's next to temp

}

bool findKey(NodePtr head, int k)
//PRE:	head has been initialized, head is a pointer to a linked list
//       k has been initialized
//POST:	FCTVAL == true if k has been found in the data field of any node in the linked list starting at  				
//          head and continuing until NULL || false if k has not been found in the data field of any node
//          in the linked list starting at head and continuing until NULL
{
    NodePtr cur;                                    //the current node being examined

    cur = head;
    while (cur->data != k && cur->next != NULL)     //transverse the list if the key is not found or
    {                                               //  if at the end of the list
        cur = cur->next;
    }

    if (cur->data == k)                             //if the current data is k then the loop has stopped
        return true;                                //  on the correct key
    else                                            //otherwise the value was not found in the list
        return false;
}

void concatenateList(NodePtr & head, NodePtr & head2)
//PRE:	head has been initialized, head is a pointer to a linked list
//       head2 has been initialized, head2 is a pointer to a linked list
//POST:	the last node of the linked list starting at head and continuing until NULL now points to the
//          first element in the linked list starting at head2 and continuing until NULL.
//          the linked list starting at head and continuing until NULL now contains all nodes from the 
//          list starting at head and the linked list starting at head2.
{
    NodePtr cur;                    //a pointer to keep track of the current position in the list

    cur = head;
    while (cur->next != NULL)       //walk list until cur's next is NULL (the last node in head's list)
    {
        cur = cur->next;
    }

    cur->next = head2;              //cur's NULL pointer now points to the beginning of the second list
                                    //  to concatenate

}

void walkList(NodePtr head)
//PRE:  head has been initialized, head is a pointer to a linked list
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
        cur = cur->next;              //point cur to the next node in the list
    }

    cout << endl;
    return;

}


void deleteNode(NodePtr & head, int k)
//PRE:  head is initialized, head is a pointer to a linked list
//      k is initialized
//POST: the node with k in the data field has been deallocated from the linked list starting at head.
//      the predecessor to the node with k in the data field now points to the successor of the node
//        with k in the data field in the linked list starting at head
//      if k is not found in the list starting at head until NULL the list remains the same
{
    NodePtr pred;                           //pointer to a list node that will hold the predecessor of 
                                            //  the node to delete
    NodePtr cur;                            //pointer to a list node 

    pred =  new NodeType;                   //allocate new node to hold pred

    cur = head;
    while (cur != NULL && cur->data != k)   //walk through the list while not at the final node and the
    {                                       //  key has not been found
        pred = cur;                         //predecessor node becomes the current node when...
        cur = cur-> next;                   //...the current node becomes it's successor
    }

    if (cur == NULL)                        //if cur is a NULL pointer the key is not in the list
        return;                             //do nothing and return
    else if (head->data == k)               //special case if key is the first element in the list b/c
    {                                       //     pred has not been allocated yet
        head = cur-> next;
        delete cur;
    }
    else                                    //otherwise the key has been found
    {
        pred->next = cur->next;             //point the predecessor to current's successor (subvert it)
        delete cur;                         //delete the current node b/c the loop stopped at it b/c it
    }                                       //   contains the key

}

int main()
{
    NodePtr head;                   //a pointer to the head node of the list
    NodePtr head2;                  //a pointer the the head node of a second linked list
    
    head = new NodeType;            //create a head pointer in the main program

    head->data = 9;                 //codify it with data
    head->next = NULL;              //currently the first and only node

    //showing the linked list at the beginning before any function calls
    cout << "\nThe current linked list: ";
    walkList(head);
    
    //testing the insertAtHead function thoroughly
    cout << "\nINSERT-AT-HEAD function, inserting an 8 and outputting list...\n"; 
    insertAtHead(head, 8);
    walkList(head);
    cout << "Inserting a 16 and outputting current list\n";
    insertAtHead(head, 16);
    walkList(head);

    //testing the insertAtTail function thoroughly
    cout << "\nINSERT-AT-TAIL function, inserting an 11 and outputting list...\n";
    insertAtTail(head, 11);
    walkList(head);
    cout << "Inserting a 17 and outputting current list\n";
    insertAtTail(head, 17);
    walkList(head);

    //testing the findKey function thoroughly
    cout << "\nFIND-KEY function, testing if 8 is in current list...\n";
    cout << boolalpha << findKey(head, 8) << endl;
    cout << "Testing if 6 is in current list...\n";
    cout << boolalpha << findKey(head, 6) << endl;

    head2 = new NodeType;               //create a new head pointer to demonstrate concatenateList

    head2->data = 0;                    //set data to a value
    head2->next = NULL;                 //it is the only node so it has a NULL pointer

    for (int i = 1; i < 5; i++)         //populates the list with numbers [1..4] for demonstration
    {
        insertAtTail(head2, i);
    }

    //testing the concatenate list function and showing it works to the user
    cout << "\nCONCATENATE-LIST function:";
    cout << "\nList #1: ";
    walkList(head);
    cout << "\nList #2: ";
    walkList(head2);
    cout << "\nConcatenated List: ";
    concatenateList(head, head2);
    walkList(head);

    //testing the deleteNode function thoroughly
    cout << "\nDELETE-NODE function, deleting 4, 0, and 16 from the list...\n";
    deleteNode(head, 4);
    deleteNode(head, 16);
    deleteNode(head, 0);
    walkList(head);
    cout << "\nAttempting to delete 25 from the list...\n";
    deleteNode(head, 25);
    walkList(head);

}