#include "leet002.hpp"
#include <cstdlib>
#include <iostream>

namespace leet002 {

ListNode* Solution::addTwoNumbers()
{
    ListNode* lNode;
    return lNode;
}

Solution::Solution()
{
    L1 = new ListNode(0);
    L2 = new ListNode(0);
    ListNode* L1Curr = L1;
    ListNode* L2Curr = L2;

    for (int i = 0; i < 1000; i++)
    {
        int x = rand();
        int y = x % 10;

        L1Curr->next      = new ListNode(y);
        L1Curr            = L1->next;
    }

    for (int i = 0; i < 1000; i++)
    {
        int x = rand();
        int y          = x % 10;

        L2Curr->next      = new ListNode(y);
        L2Curr            = L2Curr->next;
    }

    return;
}

Solution::~Solution() {}


std::ostream& operator<<(std::ostream& os, ListNode* node)
{
    ListNode* tmpnode = node;
    while(tmpnode->next){
        os<<"val = "<< node->next->val<< std::endl;
        tmpnode = tmpnode->next;
    }

    return os;
}

void test()
{
    Solution solution;
    auto res = solution.addTwoNumbers();
    std::cout<<"result = "<< res;
}

} // namespace leet002
