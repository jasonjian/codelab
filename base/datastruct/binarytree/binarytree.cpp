#include "binarytree.hpp"

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
bool BinaryTree::insertNodeWithUserData( UserData& pData, TreeNode* pCurrNode)
{
    TreeNode* lNewTreeNodePtr = nullptr;

    if(pData.getId() == pCurrNode->getData().getId()){
        std::cout<< "Duplicate Node, failed to insert";
        return false;
    }

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
            insertNodeWithUserData(pData, pCurrNode->mLeft);
        }
    }

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
            insertNodeWithUserData(pData, pCurrNode->mRight);
        }
    }
    
    return true;
}

bool BinaryTree::deleteNodeWithUserData(const UserData& pVal)
{

    return true;
}

bool BinaryTree::preOrderTranversal(TreeNode* pNode)const
{
    if(pNode == nullptr) return true;
    std::cout<<pNode->getData().getId();
    preOrderTranversal(pNode->mLeft);
    preOrderTranversal(pNode->mRight);
    return true;
}

bool BinaryTree::inOrderTranversal(TreeNode* pNode)const
{
    if(pNode == nullptr) return true;
    inOrderTranversal(pNode->mLeft);
    std::cout<<pNode->getData().getId();
    inOrderTranversal(pNode->mRight);
    return true;
}

bool BinaryTree::postOrderTranversal(TreeNode* pNode)const
{
    if(pNode == nullptr) return true;
    postOrderTranversal(pNode->mLeft);
    postOrderTranversal(pNode->mRight);
    std::cout<<pNode->getData().getId();
    return true;
}

bool BinaryTree::isFullBinaryTree()const
{

    return true;
}

std::ostream& operator<<(std::ostream& pStream, BinaryTree& ptree)
{
    pStream<<"test ostream function";
    return pStream;
}
