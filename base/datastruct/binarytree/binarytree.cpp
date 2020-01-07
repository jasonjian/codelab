#include "binarytree.hpp"
#include <cstdlib>

// this is a function of binary search tree
/*
  1) the left children node is always smaller than current node
  2) the right children node is always bigger than current node

  if (new node == cuurent node) return error;

  if(newnode < current node) && (left node is empty)
  insert the node in left tree;
  else
  recussive call the function to insert the data into its leftnode
  
  if(newnode < currnode)
  recussive call the function to insert the data into its leftnode

 */

BinaryTree::BinaryTree()
{
    UserData lUserData;
    lUserData.setId(8888);
    mRoot = new(TreeNode);
    mRoot->mData = lUserData;
}

BinaryTree::~BinaryTree()
{
    delete mRoot;
}

bool BinaryTree::insertNodeWithUserDataRecursion( UserData& pData, TreeNode* pCurrNode)
{
    TreeNode* lNewTreeNodePtr = nullptr;

    // parameter check
    {
        if(pData == pCurrNode->getData()){
            std::cout<< "Duplicate Node, failed to insert";
            return false;
        }
    }

    // to handle the left tree node
    // and a recursion end condition in this branch
    {
        if(pData.getId() < pCurrNode->getData().getId()){
            if(nullptr == pCurrNode->mLeft){
                try {
                    lNewTreeNodePtr  = new(TreeNode);
                }catch(...){
                    std::cout<< "Failed to create new TreeNode for insert data, insert failed";
                    return false;
                }
                pCurrNode->mLeft = lNewTreeNodePtr;
                return true;
            }else{
                insertNodeWithUserDataRecursion(pData, pCurrNode->mLeft);
            }
        }
    }

    // To handle the right tree node
    // A recursion end condition exist in this branch
    {
        if(pData.getId() > pCurrNode->getData().getId()){
            if(nullptr == pCurrNode->mRight){
                try {
                    lNewTreeNodePtr  = new(TreeNode);
                }catch(...){
                    std::cout<< "Failed to create new TreeNode for insert data, insert failed";
                    return false;
                }
                pCurrNode->mRight = lNewTreeNodePtr;
                return true;

            }else{
                insertNodeWithUserDataRecursion(pData, pCurrNode->mRight);
            }
        }
    }
    
    return true;
}

bool BinaryTree::insertNodeWithUserData( UserData& pData, TreeNode* pCurrNode)const
{
    TreeNode* lNewTreeNodePtr = nullptr;
    if(pCurrNode->getData() == pData){
        std::cout<<"The data to be inserted already exist, failed to insert";
        return false;
    }

    std::cout<<"pData = "<< pData<<std::endl;
    
    while (pCurrNode != nullptr){
        if(pData < pCurrNode->getData()){
            if(nullptr == pCurrNode->mLeft){
                try{
                    lNewTreeNodePtr = new(TreeNode);
                    lNewTreeNodePtr->mData = pData;
                }catch(...){
                    std::cout<< "exception happen when try to create the new node.";
                    return false;
                }
                pCurrNode->mLeft = lNewTreeNodePtr;
                return true;
            }else{
                pCurrNode = pCurrNode->mLeft;
                continue;
            }
        } else if(pData > pCurrNode->getData()){
            if(nullptr == pCurrNode->mRight){
                try{
                    lNewTreeNodePtr = new(TreeNode);
                    lNewTreeNodePtr->mData = pData;
                }catch(...){
                    std::cout<< "exception happen when try to create the new node.";
                    return false;
                }
                pCurrNode->mRight = lNewTreeNodePtr;
                return true;
            }
            pCurrNode = pCurrNode->mRight;
            continue;
        }

        else{
            std::cout<< "should not come here. UserData = "<< pData<<", pCurrNode->data = "<< pCurrNode->getData() << std::endl;
            return false;
        }
    }

    return false;
}

bool BinaryTree::deleteNodeWithUserData(const UserData& pVal)
{

    return true;
}

bool BinaryTree::preOrderTranversal(TreeNode* pNode)const
{
    if(pNode == nullptr) return true;
    std::cout<<pNode->getData()<<std::endl;
    preOrderTranversal(pNode->mLeft);
    preOrderTranversal(pNode->mRight);
    return true;
}

bool BinaryTree::inOrderTranversal(TreeNode* pNode)const
{
    if(pNode == nullptr) return true;
    inOrderTranversal(pNode->mLeft);
    std::cout<<pNode->getData();
    inOrderTranversal(pNode->mRight);
    return true;
}

bool BinaryTree::postOrderTranversal(TreeNode* pNode)const
{
    if(pNode == nullptr) return true;
    postOrderTranversal(pNode->mLeft);
    postOrderTranversal(pNode->mRight);
    std::cout<<pNode->getData();
    return true;
}

bool BinaryTree::isFullBinaryTree()const
{

    return true;
}

// why when this is not const after the member function, this project will not compile
void BinaryTree::generateTestData()const
{
    UserData lData;

    for (auto i = 0; i < 10; i++){
        auto lId = rand();
        lData.setId(lId);
        insertNodeWithUserData(lData, mRoot);
    }
}

void BinaryTree::tranverse()const
{
    preOrderTranversal(mRoot);
}


std::ostream& operator<<(std::ostream& pStream, BinaryTree& ptree)
{
    pStream<<"test ostream function";
    return pStream;
}
