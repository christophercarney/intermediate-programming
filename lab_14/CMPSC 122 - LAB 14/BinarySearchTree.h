//Programmer:   Christopher Carney
//Section:      2
//Lab:          14
//Date:         April 8, 2014
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
        //      inputs[0..logSize]-1 have been initialized, each value in inputs is unique
        //POST: a BinarySearchTree object has been constructed s.t. inputs[0..logSize-1] have been
        //          sorted into a binary search tree 

        void insertKey(int key);
        //PRE:  key has been initialized, key is not currently in this binary search tree
        //POST: key has been inserted into this binary search tree in the correct position

        bool search(int key);
        //PRE:  key has been initialized
        //POST: FCTVAL == true if key is in this BinarySearchTree starting at root ||
        //          false if key is not contained in this BinarySearchTree starting at root

        void traceSearch(int key);
        //PRE:  key has been initialized
        //POST: the search for key in this BinarySearchTree starting at root has been outputted
        //          to the user showing the decisions to go to the right or left node and also
        //          if the key is contained in this BinarySearchTree

        void inorderCopy(int array[], int & logSize);
        //PRE:  array[0..logsize-1] is initialized, logSize is initialized,logSize > 0
        //POST: an Inorder traversal of the binary search tree starting at root has been printed
        //          to the screen in the order left, root, right

        void printPreorder();
        //POST: a Preeorder traversal of the binary search tree starting at root has been printed
        //          to the screen in the order root, left, right


    private:

                                /*PRIVATE METHOD DEFINITIONS*/

        void privateInsert(TreeNodePtr & subTreeRoot, int key);
        //PRE:  subTreeRoot is a pointer to the root of a subree in a binary search tree with
        //          unique keys.
        //      key is initialized && key is not currently in this binary search tree
        //POST: key has been inserted into the binary search tree;

        bool privateSearch(TreeNodePtr subTreeRoot, int key);
        //PRE:  subTreeRoot is a pointer to the root of a subree in a binary search tree with
        //          unique keys.
        //      key is initialized.
        //POST: FCTVAL == true if key is in this BinarySearchTree starting at root ||
        //          false if key is not contained in this BinarySearchTree starting at root

        void privateTraceSearch(TreeNodePtr subTreeRoot, int key);
        //PRE:  subTreeRoot is a pointer to the root of a subree in a binary search tree with
        //          unique keys.
        //      key is initialized
        //POST: the search for key in this BinarySearchTree starting at root has been outputted
        //          to the user showing the decisions to go to the right or left node and also
        //          if the key is contained in this BinarySearchTree

        void privateInorder(TreeNodePtr subTreeRoot, int array[], int & logSize);
        //PRE:  subTreeRoot is a pointer to the root of a subree in a binary search tree with
        //          unique keys.
        //      array[0..logSize-1] is initialized, logSize is initialized, logSize > 0
        //POST: an Inorder traversal of the binary search tree starting at root has been printed
        //          to the screen in the order left, root, right

        void privatePreorder(TreeNodePtr subTreeRoot);
        //PRE:  subTreeRoot is a pointer to the root of a subree in a binary search tree with
        //          unique keys.
        //POST: a Preorder traversal of the binary search tree starting at root has been printed
        //          to the screen in the order root, left, right


                                /*PRIVATE DATA DEFINITIONS*/

        TreeNodePtr root;                   //the root of this BinarySearchTree object
};