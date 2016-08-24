//Programmer:   Christopher Carney
//Section:      2
//Lab:          6
//Date:         February 18, 2014
//Description:  LAB 6 - Queue implemented via linked list

#include <iostream>
using namespace std;

struct NodeType;
typedef NodeType* NodePtr;

struct NodeType
{
    int data;                  //holds the value of the list node
    NodeType* next;            //points to the next node in the list
};

int logSize(NodePtr front, NodePtr back)
//PRE:  front has been initialized, front is a pointer to a (NodeType node ||  NULL pointer)
//      back has been initialized, back is a pointer to a (NodeType node || NULL pointer)
//POST: FCTVAL == the number of NodeType nodes contained in the queue starting at 'front' & continuing
//          until NULL, the number of values in the queue
{
    NodePtr cur;                            //define a node to traverse the queue
    int logSize;                            //the logical size of the queue

    logSize = 0;                            //initialize the logical size to start at 0
    cur = front;                            //start at the head

    //starting at the front of the queue, increment the logicl size then go to the next node and 
    //  repeat until it reaches a NULL pointer
    while (cur != NULL)
    {
        cur = cur->next;                    //point cur to the next node in the list
        logSize++;                          //increment the logical size
    }

    return logSize;                         //returns the logical size after the queue is traversed

}

bool isEmpty(NodePtr front, NodePtr back)
//PRE:  front has been initialized, front is a pointer to a (NodeType node ||  NULL pointer)
//      back has been initialized, back is a pointer to a (NodeType node || NULL pointer)  
//POST: FCTVAL == true if the logical size of the queue starting at 'front' & continuing until NULL = 0,
//          there are no pointers to NodeType nodes in the queue starting at 'front'
//      || == false if the logical size of the queue starting at 'front' & continuing until NULL > 0,
//          there are pointers to NodeType nodes in the queue starting at 'front'
{
    int logicalSize;                        //variable to check the logical size of current queue

    logicalSize = logSize(front, back);     //check the logical size of the current queue and set it to 
                                            //  the var logicalSize

    if (logicalSize == 0)                   //the queue is empty if the logical size is 0
        return true;                        
    else                                    //otherwise the logical size is > 0 so queue contains values
        return false;
}

void enqueue(NodePtr & front, NodePtr & back, int k)
//PRE:  front has been initialized, front is a pointer to a (NodeType node ||  NULL pointer)
//      back has been initialized, back is a pointer to a (NodeType node || NULL pointer)
//      k has been initialized
//POST: k has been inserted in the data field in the 'back' NodeType node in the queue starting at 
//          'front' & continuing until NULL
//      the NodeType node with k as the data field points to NULL
//      if front != NULL at the time of the function call the previous 'back' in the queue 
//          starting at 'front' now points to the node with k in the data field
//      if front == NULL at the time of function call it now is equal to 'back' NodeType node
{
    NodePtr temp;                   //temp node to store the value to be inserted

    if (front == NULL)              //if the front of the list points to nothing then it is an empty 
    {                               //     queue
        back = new NodeType;        //define new nodes for the back of the queue
        front = new NodeType;       //define new nodes for the front of the queue

        back->data = k;             //all data in queue is inserted at the back
        back->next = NULL;          //the back points to NULL pointer

        front = back;               //since the list is empty the back is the front
        
    }
    else                            //otherwise the queue already has values in it
    {

        temp = new NodeType;        //allocate a new temp node

        temp->data = k;             //store new value to be queued in temp
        temp->next = NULL;          //temp's successor is a NULL pointer (the new back of queue)

        back->next = temp;          //point back's next (old back of queue) to temp (new back)
        back = temp;                //the new back is the temp node (so the back is always known)

    }

    return;

}

void dequeue(NodePtr & front, NodePtr & back)
//PRE:  front has been initialized, front is a pointer to a (NodeType node ||  NULL pointer)
//      back has been initialized, back is a pointer to a (NodeType node || NULL pointer)  
//POST: the NodeType node which is pointed to by 'front' has been deallocated
//      'front' now points to the NodeType node which was the previous successor of the deallocated node
{
    if (isEmpty(front, back) == true)       //cannot dequeue if the queue is empty so return
        return;
    else                                    //otherwise queue is not empty so dequeue as normal
    {
        NodePtr temp;           //a pointer to the front of the queue to be deleted

        temp = front;           //temp is whatever the front is
        front = temp->next;     //front now points to temp's successor (the new front)

        delete temp;            //delete the requested value to be dequeued
    }
    
    return;

}

int lookAtFront(NodePtr front, NodePtr back)
//PRE:  front has been initialized, front is a pointer to a NodeType node 
//      back has been initialized, back is a pointer to a NodeType node  
//POST: FCTVAL == the data field of the NodeType node pointed to by 'front' 
{
    return front->data;                     //front of the queue is always known, just return the 
                                            //    value of the front node of the queue 
}

void outputQueue(NodePtr front, NodePtr back)
//PRE:  front has been initialized, front is a pointer to a (NodeType node ||  NULL pointer)
//      back has been initialized, back is a pointer to a (NodeType node || NULL pointer)  
//POST: all values in the queue starting at the Node 'front' and continuing until NULL 
//          have been printed (one from every node) with a space between each digit in the list 
{
    NodePtr cur;                         //define a node to traverse the queue

    cur = front;                         //start at the front

    //starting at the front of the queue, print out each value then go to the next node and 
    //  prints that value out; until it reaches a NULL pointer (the back of the queue)
    while (cur != NULL)
    {
        cout << cur->data << " ";     //print the value of the current node
        cur = cur->next;              //point cur to the next node in the queue
    }

    cout << endl;
    return;

}

int main()
{
    NodePtr front;                  //define node for the front of the queue
    NodePtr back;                   //define node for the back of the queue
    
    front = NULL;                   //set the front pointer to NULL b/c nothing in the queue
    back = NULL;                    //set the back pointer to NULL b/c nothing in the queue

    cout << "Is the queue empty?: ";
    if (isEmpty(front, back) == true)   //if queue us empty output true
        cout << "True\n";
    else                                //otherwise queue not empty so it is false
        cout << "False\n";

    cout << "Attempting to dequeue from empty queue and output queue: ";
    dequeue(front, back);
    outputQueue(front, back);

    cout << "\nQueuing numbers 0-9 into queue and outputting...";
    //enqueuing numbers 0-9 into the queue
    for (int i = 0; i < 10; i++)
    {
        enqueue(front, back, i);
    }
    outputQueue(front, back);

    cout << "\nCurrent logical size of the queue is: " << logSize(front, back) << endl;

    cout << "Checking front number then dequeuing front number from the queue...\n";
    cout << "Front number is: " << lookAtFront(front, back) << endl;
    dequeue(front, back);
    cout << "\nCurrent queue: ";
    outputQueue(front, back);

    cout << "\nDequeuing first three numbers in queue and outputting: ";
    //dequeing first three numbers from queue
    for (int i = 0; i < 3; i++)
    {
        dequeue(front, back);
    }
    outputQueue(front, back);
    cout << "Front number is: " << lookAtFront(front, back) << endl;

    cout << "\nCurrent logical size of queue: " << logSize(front, back);
    
    cout << "\nIs the queue empty?: ";
    if (isEmpty(front, back) == true)   //if queue us empty output true
        cout << "True\n";
    else                                //otherwise queue not empty so it is false
        cout << "False\n";

   
}