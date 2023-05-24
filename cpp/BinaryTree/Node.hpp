/// @brief The node class, contains the basics for a node
class Node
{
    /// @brief The data of the node
    int data;

public:
    /// @brief The left child
    Node *left;

    /// @brief The right child
    Node *right;

    /// @brief The parent
    Node *parent;

    /// @brief The root of the tree
    Node *root;

    /// @brief Zero-arg constructor
    Node();

    /// @brief One-arg constructor, takes in a value to instantiate the node with
    /// @param val value to instantiate the `data` field with
    Node(int val);

    /// @brief Inserts a value into the tree
    /// @param val - The value to insert
    /// @param node - The node we are using as our iterative pointer while traversing through the tree
    void insertRec(int val, Node *node);
};