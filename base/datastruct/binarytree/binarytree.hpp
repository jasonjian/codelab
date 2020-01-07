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
    bool insertNodeWithUserData( UserData& pData, TreeNode* pCurrNode)const;
    bool insertNodeWithUserDataRecursion( UserData& pData, TreeNode* pCurrNode);
    bool deleteNodeWithUserData(const UserData& pVal);
    bool preOrderTranversal(TreeNode* pNode)const;
    bool inOrderTranversal(TreeNode* pNode)const;
    bool postOrderTranversal(TreeNode* pNode)const;
    bool isFullBinaryTree()const;
    void generateTestData()const;
    void tranverse()const;

    friend std::ostream& operator<<(std::ostream& pStream, BinaryTree& ptree);

    BinaryTree();
    ~BinaryTree();
    
private:
    BinaryTree(BinaryTree& pVal) = delete;
    BinaryTree(const BinaryTree& pVal) = delete;
    BinaryTree(const BinaryTree&& pVal) = delete;
    BinaryTree operator=(const BinaryTree& pVal);

private:
    TreeNode* mRoot;
};
