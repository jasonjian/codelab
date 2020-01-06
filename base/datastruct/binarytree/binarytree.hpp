// construct a binary tree from a plaintxt
//
#include <userdata.hpp>

#pragra once

class node{
    UserData mData;
    node* mLeft;
    node* mRight;
};


class BinaryTree {

public:
    bool preOrderTranversal()const;
    bool inOrderTranversal()const;
    bool postOrderTranversal()const;
    bool isFullBinaryTree()const;

private:
    BinaryTree() = default;
    //    BinaryTree(BinaryTree pVal);
    //    BinaryTree(const BinaryTree& pVal);
    //    BinaryTree(const BinaryTree&& pVal);
    ~BinaryTree() = default;

    BinaryTree operator=(const BinaryTree& pVal);

private:

    node* mRoot;


};
