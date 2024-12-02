// https://leetcode.com/problems/partition-list/description/
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

//  use two different pointers to store the partitions
// finally check the partitions and merge the partitions to get final list
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if(!head)return NULL;
        ListNode *first=NULL,*second=NULL;
        ListNode *firstHead=NULL,*secondHead=NULL;
        ListNode *temp = head;
        while(temp){
            if(temp->val<x){
                if(firstHead){
                    first->next = temp;
                    first = first->next;
                }
                else{
                    firstHead = temp;
                    first = temp;
                }
            }
            else{
                if(secondHead){
                    second->next = temp;
                    second = second->next;
                }
                else{
                    secondHead = temp;
                    second = temp;
                }
            }
            temp = temp->next;
        }
        if(!first)return secondHead;
        if(!second)return firstHead;
        second->next = NULL;
        first->next = secondHead;
        return firstHead;
    }
};
