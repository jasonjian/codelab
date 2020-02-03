#include <iostream>
#pragma once

namespace leet002 {

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};
std::ostream& operator<<(std::ostream& os, ListNode& node);

class Solution
{
public:
    ListNode* addTwoNumbers();
    Solution();
    ~Solution();

private:
    ListNode* L1;
    ListNode* L2;
};

void test();
} // namespace leet002
