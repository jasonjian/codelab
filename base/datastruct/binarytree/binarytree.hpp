// construct a binary tree from a plaintxt
//
#include <userdata.hpp>

#pragma once

class TreeNode{

public:
    UserData& getData(){return mData;}

public:
    TreeNode* mLeft;
    TreeNode* mRight;
    TreeNode* mParent;
    UserData mData;
};


class BinaryTree {

public:
    bool insertNodeWithUserData( const UserData& pVal);
    bool deleteNodeWithUserData(const UserData& pVal);
    bool preOrderTranversal(TreeNode* pNode)const;
    bool inOrderTranversal(TreeNode* pNode)const;
    bool postOrderTranversal(TreeNode* pNode)const;
    bool isFullBinaryTree()const;

    friend std::ostream& operator<<(std::ostream& pStream, BinaryTree& ptree);

private:
    BinaryTree() = default;
    BinaryTree(BinaryTree& pVal) = delete;
    BinaryTree(const BinaryTree& pVal) = delete;
    BinaryTree(const BinaryTree&& pVal) = delete;
    ~BinaryTree() = default;
    BinaryTree operator=(const BinaryTree& pVal);

private:
    TreeNode* mRoot;
};
