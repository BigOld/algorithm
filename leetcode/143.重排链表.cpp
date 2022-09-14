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
    void reorderList(ListNode* head) {
        ListNode* dir = new ListNode(0);
        dir -> next = head;
        ListNode* p = dir; // 慢指针
        ListNode* q = dir; // 快指针

        while(q && q-> next) {
            p = p -> next;
            q = q -> next -> next;
        }
        ListNode* h2 = p -> next;
        p -> next = NULL;

        // 将h2 倒序
        ListNode* pre = NULL;
        ListNode* cur = h2;
        h2 = pre;

        while(cur) {
            ListNode* temp = cur -> next;
            cur -> next = h2;
            h2 = cur;
            cur = temp;
        }

        ListNode* p1 = head;
        ListNode* p2 = h2;
        while(p2) {
            ListNode* temp = p2 -> next;
            p2 -> next = p1 -> next;
            p1 -> next = p2;
            p1 = p2 -> next;
            p2 = temp;
        }

    }
};