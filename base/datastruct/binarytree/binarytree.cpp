#include "binarytree.hpp"

bool BinaryTree::insertNodeWithUserData( const UserData& pVal)
{
    
    return true;
}

bool BinaryTree::deleteNodeWithUserData(const UserData& pVal)
{

    return true;
}

bool BinaryTree::preOrderTranversal(TreeNode* pNode)const
{
    std::cout<<pNode->getData().getId();

    if(nullptr != pNode->mLeft){
        preOrderTranversal(pNode->mLeft);
    }

    if(nullptr != pNode->mRight){
        preOrderTranversal(pNode->mRight);
    }
    return true;
}

bool BinaryTree::inOrderTranversal(TreeNode* pNode)const
{
    if(pNode->mLeft){
        inOrderTranversal(pNode->mLeft);
    }

    std::cout<<pNode->getData().getId();

    if(pNode->mRight){
        inOrderTranversal(pNode->mRight);
    }

    return true;
}

bool BinaryTree::postOrderTranversal(TreeNode* pNode)const
{
    if( pNode->mLeft ){
        postOrderTranversal(pNode->mLeft);
    }

    if(pNode->mRight){
        postOrderTranversal(pNode->mRight);
    }

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
