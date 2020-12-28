/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
 */

// @lc code=start
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
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode *cur=head,*nex=nullptr,*las;
        if(cur){
            nex=cur->next;
        }
        if(nex){
            head=nex;
            cur->next=nex->next;
            nex->next=cur;
            las=cur;
            cur=cur->next;
            if(cur){
                nex=cur->next;
            }
        }
        while(cur&&nex){
            las->next=nex;
            cur->next=nex->next;
            nex->next=cur;
            las=cur;
            cur=cur->next;
            if(cur){
                nex=cur->next;
            }
        }
        return head;
    }
};
// @lc code=end

