//Programmer:   Christopher Carney
//Section:      2
//Lab:          15
//Date:         April 15, 2014
//Description:  This is the header file for documentation of the Hash Table class

const int HASH_CONSTANT = 7;               //the constant for the size of the hash table & value

struct NodeType;
typedef NodeType* NodePtr;

struct NodeType
{
    int key;                        //the value of the node in the linked list
    NodeType* next;                 //the pointer to the next node in the linked list
};


class HashTable
{
    public:

        HashTable();
        //POST: a default empty hash table object has been created s.t. logical size == 0 &&
        //          table[0..HASH_CONSTANT] = NULL

        int hashValue(int key);
        //PRE:  key is initialized
        //POST: FCTVAL = the hash value of the given key, key % HASH_CONSTANT

        void hashInsert(int key);
        //PRE:  key is initialized, key is not currently a value in this hash table 
        //POST: key has been inserted into this hash table 

        int hashSearch(int key);
        //PRE:  key is initialized
        //POST: FCTVAL == the number of chains searched through before key was found ||
        //             == -1 if the key is not found in this hash table

        double getLoadFactor() const;
        //POST: FCTVAL = the load factor of this hash table, logSize / HASH_CONSTANT

        void drawTable() const;
        //POST: an ASCII art table of this hash table has been drawn s.t.
        //      [array subscript] -> hash table value -> hash table value -> ... -> NULL

    private:

        int logSize;                             //the logical size of the hash table array
        NodeType* table[HASH_CONSTANT];          //the array of pointers to heads of linked lists

};