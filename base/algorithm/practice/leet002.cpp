#include <cstdlib>
#include <iostream>
#pragma once

namespace leet002 {

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* L1;
ListNode* L2;

class Solution
{
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2);
};

ListNode* Solution::addTwoNumbers(ListNode* l1, ListNode* l2)
{
    (void)l1;
    (void)l2;

    ListNode* lNode;
    return lNode;
}

void generateTestData()
{
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

void print(ListNode* List)
{
    auto curr = List;
    while (curr)
    {
        std::cout << "val = " << curr->val << std::endl;
        curr = List->next;
    }
}

void test()
{
    std::cout<<"line = " << __LINE__;
    generateTestData();
    std::cout<<"line = " << __LINE__;
    Solution lSolution;
    std::cout<<"line = " << __LINE__;
    auto res = lSolution.addTwoNumbers(L1, L2);
    std::cout<<"line = " << __LINE__;
    print(res);
    std::cout<<"line = " << __LINE__;
}

} // namespace leet002
