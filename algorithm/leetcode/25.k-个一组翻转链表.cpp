/*
 * @lc app=leetcode.cn id=25 lang=cpp
 *
 * [25] K 个一组翻转链表
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode pummy(0,head);
        ListNode *cur=head,*revcur=head,*temp,*revlast=&pummy,*revhead,*tempnex;
        while(cur){
            bool rev=true;
            for(int i=0;i<k;++i){
                if(!cur){
                    rev=false;
                    break;
                }
                cur=cur->next;
            }
            if(rev){
                temp=revcur->next;
                revhead=revcur;
                for(int i=1;i<k;++i){
                    tempnex=temp->next;
                    temp->next=revcur;
                    revcur=temp;
                    temp=tempnex;
                }
                revlast->next=revcur;
                revlast=revhead;
                revhead->next=temp;
                revcur=temp;
            }
        }
        return pummy.next;
    }
};
// @lc code=end

