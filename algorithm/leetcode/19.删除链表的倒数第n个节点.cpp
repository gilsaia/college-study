/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第N个节点
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *find=head,*oper=head;
        for(int i=0;i<n;++i){
            find=find->next;
        }
        if(find==nullptr){
            oper=head->next;
            return oper;
        }
        while(find->next!=nullptr){
            find=find->next;
            oper=oper->next;
        }
        find=oper->next;
        oper->next=find->next;
        return head;
    }
};
// @lc code=end

