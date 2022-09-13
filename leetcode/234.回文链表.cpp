/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
#include <iostream>
using namespace std;

 struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode* dir = new ListNode(0);
        dir -> next = head;
        ListNode* pre = dir;
        ListNode* p = head;
        ListNode* q = head;
        while(q && q -> next) {
            pre = p;
            p = p -> next;
            q = q -> next -> next;
        }

        ListNode* head2 = pre -> next;
        pre -> next = NULL;
        ListNode* cur = head2;
        ListNode* p2 = NULL;
        while(cur) { // 翻转后半部分链表
            ListNode* temp = cur -> next;
            cur -> next = p2;
            p2 = cur;
            cur = temp;
        }
        ListNode* p1 = head;
        while(p1) { // 以p1的长度为准，因为可能有奇数的情况
            if(p1 -> val != p2 -> val) return false;

            p1 = p1 -> next;
            p2 = p2 -> next;
        }

        return true;
    }
};