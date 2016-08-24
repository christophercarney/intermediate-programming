// Programmer:     Dylan Fetch & Christopher Carney
// Section:        2
// Lab:            Project 1
// Date:           March 6, 2014
// Description:    Custom Queue Class implementation for use with TimeCard pointers

#include "Queue.h"

Queue::Queue()
//POST: a default Queue has been constructed with front and back point to NULL
{
    front = NULL;
    back = NULL;
}

int Queue::logSize() const
//POST: FCTVAL == the number of NodeType nodes contained in the queue starting at front &
//      ending at back
{
    NodePtr cur;                            //a pointer to a NodeType node to traverse the queue
    int logSize;                            //the logical size of the queue

    logSize = 0;                            //initialize the logical size to start at 0
    cur = front;                            //set pointer to start at the head

    while (cur != NULL)                     //starting at the front of the queue, increment the logical
    {                                       //    size then go to the next node until it reaches NULL  
        cur = cur->next;                    //point cur to the next node in the list
        logSize++;                          
    }

    return logSize;
}

bool Queue::isEmpty() const
//POST: FCTVAL == true (1) if the queue is empty || false (0) if the queue contains a timecard
{
    int logicalSize;                        //the logical size of current queue

    logicalSize = logSize();                //check the logical size of the current queue and set it to 
                                            //    the var logicalSize

    if (logicalSize == 0)                   //the queue is empty if the logical size is 0
        return true;                        
    else                                    //otherwise the logical size is > 0 so queue contains values
        return false;
}

void Queue::enqueue(TimeCard* & k)
//PRE:  k is a pointer to a TimeCard object to be enqueued
//POST: k is inserted into the back of the queue
{
    NodePtr temp;                   //a temporary node to store the value to be inserted

    if (front == NULL)              //if the front of the list points to nothing then it is an empty 
    {                               //     queue
        back = new NodeType;        //a new node for the back of the queue to hold new TimeCard

        back->timecard = k;         //TimeCard in queue is inserted at the back
        back->next = NULL;          //the back points to NULL pointer

        front = back;               //since the list is empty the back is the front       
    }
    else                            //otherwise the queue already has values in it
    {

        temp = new NodeType;        //a new temp node to hold the new TimeCard 

        temp->timecard = k;         //store new TimeCard to be queued in temp
        temp->next = NULL;          //temp's successor is a NULL pointer (the new back of queue)

        back->next = temp;          //point back's next (old back of queue) to temp (new back)
        back = temp;                //the new back is the temp node (so the back is always known)

        temp = NULL;                //temp pointer is no longer needed b/c back is what temp was
    }

    return;
}

TimeCard* Queue::dequeue()
//POST: FCTVAL == the pointer to the newly deallocated front node of this queue
//      the NodeType node which is pointed to by front has been deallocated, front now
//          points to the NodeType node which was the previous successor of the deallocated node
{
    NodePtr temp;                   //a pointer to the front of the queue to be deleted

    TimeCard* tempCard;             //a temporary pointer to a timecard object

    temp = front;                   //temp is whatever the front is
    front = temp->next;             //front now points to temp's successor (the new front)

    temp->next = NULL;              //set temp's next to NULL to avoid dangling pointer

    tempCard = temp->timecard;      //tempCard is a pointer to temp's TimeCard (what is to be returned)

    delete temp;

    return tempCard;   
}

TimeCard* Queue::viewFront() const
//POST: FCTVAL == the pointer to the timecard at the front of the queue
{
    return front->timecard;
}