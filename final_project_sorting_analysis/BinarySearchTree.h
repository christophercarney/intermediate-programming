//Programmer:   Christopher Carney & Dylan Fetch
//Section:      2
//Lab:          Final
//Date:         April 27, 2014
//Description:  This is the header file and documentation for the implementation of a 
//                  Binary Search Tree class.

struct TreeNodeType;
typedef TreeNodeType* TreeNodePtr;

struct TreeNodeType
{
    int key;                            //the value of the node in the tree
    TreeNodeType* left;                 //the pointer to the left child node of the tree
    TreeNodeType* right;                //the pointer to the right child node of the tree
};

class BinarySearchTree
{
    
    public:
                                    /*PUBLIC METHOD DEFINITIONS*/

        BinarySearchTree();
        //POST: a default BinarySearchTree object has been constructed s.t. root = NULL

        BinarySearchTree(int inputs[], int logSize);
        //PRE:  logSize is initialized, logSize > 0
        //      inputs[0..logSize]-1 have been initialized
        //POST: a BinarySearchTree object has been constructed s.t. inputs[0..logSize-1] have been
        //          sorted into a binary search tree 

        void insertKey(int key);
        //PRE:  key has been initialized
        //POST: key has been inserted into this binary search tree in the correct position

        void inorderCopy(int array[], int & logSize);
        //PRE:  array[0..logsize-1] is initialized, logSize is initialized,logSize > 0
        //POST: an Inorder traversal of the binary search tree starting at root has been printed
        //          to the screen in the order left, root, right

    private:

                                /*PRIVATE METHOD DEFINITIONS*/

        void privateInsert(TreeNodePtr & subTreeRoot, int key);
        //PRE:  subTreeRoot is a pointer to the root of a subree in a binary search tree
        //      key is initialized && key is not currently in this binary search tree
        //POST: key has been inserted into the binary search tree;

        void privateInorder(TreeNodePtr subTreeRoot, int array[], int & logSize);
        //PRE:  subTreeRoot is a pointer to the root of a subree in a binary search tree with
        //          unique keys.
        //      array[0..logSize-1] is initialized, logSize is initialized, logSize > 0
        //POST: an Inorder traversal of the binary search tree starting at root has been printed
        //          to the screen in the order left, root, right


                                /*PRIVATE DATA DEFINITIONS*/

        TreeNodePtr root;                   //the root of this BinarySearchTree object
};