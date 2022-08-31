#include <iostream>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:

    ListNode* get_tail(ListNode* head) {
        while(head -> next) head = head -> next;
        return head;
    }
    ListNode* quickSortList(ListNode* head) {
        if(!head || !head -> next) return head;
        // 设置虚拟头结点
        auto left = new ListNode(-1), mid = new ListNode(-1), right = new ListNode(-1);
        // 设置尾结点，因为要用尾插法
        auto ltail = left, mtail = mid, rtail = right;
        int val = head -> val;
        // 小于的放入left 等于的放入mid 大于的放入right
        for(auto p = head; p ; p = p -> next){
            if(p -> val < val){
                ltail -> next = p;
                ltail = p;
            }else if(p -> val > val){
                rtail -> next = p;
                rtail = p;
            }else{
                mtail -> next = p;
                mtail = p;
            }
        }
        ltail -> next = NULL, mtail -> next = NULL, rtail -> next = NULL;
        // 递归左右链表
        left -> next = quickSortList(left -> next); 
        right -> next = quickSortList(right -> next);

        // 将left - mid - right 串起来
        get_tail(left) -> next = mid -> next;
        // 防止 mid 为空 所以依然寻找 left 的尾结点
        get_tail(left) -> next = right -> next;
        return left -> next;
    }
};