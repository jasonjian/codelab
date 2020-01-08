#include "binarytree.hpp"
#include <cstdlib>
#include <iomanip>

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
    lUserData.setId(1681692777);
    mRoot = new(TreeNode);
    mRoot->mData = lUserData;
}

BinaryTree::~BinaryTree()
{
    if(releaseTreeNode(mRoot)){
    }
}

bool BinaryTree::releaseTreeNode(TreeNode* pCurrNode)
{
    if(nullptr == pCurrNode){
        std::cout<<"this is a null treenode, no need delete";
        return true;
    }

    if(nullptr != pCurrNode->mLeft){
        releaseTreeNode(pCurrNode->mLeft);
    }

    if(nullptr != pCurrNode->mRight){
        releaseTreeNode(pCurrNode->mRight);
    }

    //    std::cout<<"Now I am going to release UserData : "<<pCurrNode->mData<<std::endl;
    delete(pCurrNode);
    return true;
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
        std::cout<<"The data to be inserted already exist, failed to insert"<< std::endl;
        return false;
    }

    //    std::cout<<"Now Try to insert = "<< pData<<std::endl;
 
    while (pCurrNode != nullptr){
        if(pData < pCurrNode->getData()){
            //       std::cout<<pData << "is smaller than "<< pCurrNode->getData() <<std::endl;
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
            // std::cout<<pData << "is bigger than "<< pCurrNode->getData() <<std::endl;
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
            std::cout<<pData << "is equal as "<< pCurrNode->getData() <<std::endl;
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
    static std::uint32_t lCount = 0;
    if(pNode == nullptr) return true;
    std::cout<<"PreOrder["<<std::setw(2)<< lCount++<<"] : " << pNode->getData()<< std::endl;
    preOrderTranversal(pNode->mLeft);
    preOrderTranversal(pNode->mRight);
    return true;
}

bool BinaryTree::inOrderTranversal(TreeNode* pNode)const
{
    static std::uint32_t lCount = 0;
    if(pNode == nullptr) return true;
    inOrderTranversal(pNode->mLeft);
    std::cout<<"inorder["<<std::setw(2)<< lCount++<<"] : " << pNode->getData()<< std::endl;
    inOrderTranversal(pNode->mRight);
    return true;
}

bool BinaryTree::postOrderTranversal(TreeNode* pNode)const
{
    static std::uint32_t lCount = 0;
    if(pNode == nullptr) return true;
    postOrderTranversal(pNode->mLeft);
    postOrderTranversal(pNode->mRight);
    std::cout<<"PostOrder["<<std::setw(2)<< lCount++<<"] : " << pNode->getData()<< std::endl;
    return true;
}

std::uint32_t BinaryTree::getDepth(TreeNode* pNode)const
{
    if(pNode == nullptr){
        return 0;
    }

    if((nullptr == pNode->mLeft) && (nullptr == pNode->mRight)){
        return 1;
    }

    auto lLeftDepth = getDepth(pNode->mLeft);
    auto lRightDepth = getDepth(pNode->mRight);
    auto lDepth = (lLeftDepth > lRightDepth) ? lLeftDepth : lRightDepth;
    return lDepth + 1;
}

bool BinaryTree::isFullBinaryTree()const
{
    return true;
}

bool BinaryTree::isBinarySearchTree()const
{

    return true;
}

bool BinaryTree::isBalancedTree(TreeNode* pNode)const
{
    if(pNode == nullptr){
        return true;
    }
    
    if((std::abs( (int)getDepth(pNode->mLeft) - (int)getDepth(pNode->mRight) )) <= 1){
        return true;
    }else{
        return false;
    }

    if( (false == isBalancedTree(pNode->mLeft)) || (false == isBalancedTree(pNode->mLeft))){
        return false;
    }

    return true;
}

// Why when this is not const after the member function, this project will failed to compile
void BinaryTree::generateTestData()const
{
    UserData lData;

    for (auto i = 0; i < 3; i++){
        auto lId = rand();
        lData.setId(lId);
        insertNodeWithUserData(lData, mRoot);
    }
}

void BinaryTree::tranverse()const
{
    inOrderTranversal(mRoot);
    std::cout<<"tree depth = "<<getDepth(mRoot)<<std::endl;
    std::cout<<"isBalanceTree =  "<<isBalancedTree(mRoot)<<std::endl;
}

std::ostream& operator<<(std::ostream& pStream, BinaryTree& pTree)
{
    pTree.preOrderTranversal(pTree.getRoot());
    return pStream;
}
