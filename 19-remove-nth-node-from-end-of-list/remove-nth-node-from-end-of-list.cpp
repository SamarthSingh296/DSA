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
        
        ListNode* temp=head,*curr=head,*prev=NULL;
        int cnt=0;
        while(temp){
            cnt++;
            temp=temp->next;
        }
        cnt-=n;
        if(cnt==0){
            temp=head;
            head=head->next;
            delete temp;
            return head;

        }
        while(cnt--){
            prev=curr;
            curr=curr->next;
        }
        prev->next=curr->next;
        curr->next=NULL;
        delete curr;
        return head;

    }
};