// Programmer:     Dylan Fetch & Christopher Carney
// Section:        2
// Lab:            Project 1
// Date:           March 6, 2014
// Description:    Custom Queue Class to be used by TimeCard class documentation

#ifndef Queue_H
#define Queue_H
#include "TimeCard.h"

class Queue
{
    public:
        Queue();
        //POST: a default Queue has been constructed with front and back point to NULL

        int logSize() const;
        //POST: FCTVAL == the number of NodeType nodes contained in the queue starting at front &
        //      ending at back

        bool isEmpty() const;
        //POST: FCTVAL == true (1) if the queue is empty || false (0) if the queue contains a timecard

        void enqueue(TimeCard* & k);
        //PRE:  k is a pointer to a TimeCard object to be enqueued
        //POST: k is inserted into the back of the queue

        TimeCard* dequeue();
        //POST: FCTVAL == the pointer to the newly deallocated front node of this queue
        //      the NodeType node which is pointed to by front has been deallocated, front now
        //          points to the NodeType node which was the previous successor of the deallocated node

        TimeCard* viewFront() const;
        //PRE:  front is a pointer to a NodeType node, back is a pointer to a NodeType node
        //POST: FCTVAL == the timecard at the front of the queue

    private:
        struct NodeType;
        typedef NodeType* NodePtr;
        struct NodeType
        {
            TimeCard* timecard;          //a pointer to hold the timecard of the list node
            NodePtr next;                //a pointer to the next node in the queue
        };

        NodePtr front;                    //a pointer to the first node in the queue
        NodePtr back;                     //a pointer to the last node in the queue
};

#endif