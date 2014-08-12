#include <iostream>

using namespace std;
struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(nullptr){};

};
class rList{
public:
    /*ListNode* reverseList(ListNode* head, int m , int n){
        ListNode *dummy = new ListNode(-1);
        dummy.next = head;

        ListNode* prev = dummy;
        for(int i = 0; i<m; i++){
            prev = prev->next;
        }
        ListNode* head2 = prev;

        prev = head2->next;
        ListNode* cur = prev->next;
        for(int i = m+1; i<n; i++){
            prev->next = cur->next;
            cur->next = head2->next;
            head2->next = cur;
            cur = prev->next;
        }
    }
    */
    ListNode* reverseList(ListNode* head){
        if(head == NULL) return NULL;
        ListNode* prev = NULL;
        ListNode* cur = head;
        ListNode* forwardnode;
        while(cur!= NULL){
            forwardnode = cur->next;
            cur->next = prev;
            prev = cur;
            cur = forwardnode;
        }
        return prev;
    }

};
int main()
{
    int myarray[] = {1,4,3,2,5,2};
    ListNode *mylist = new ListNode(myarray[0]);
    ListNode *head;
    head = mylist;
    for(int i =0; i< 6; i++){
        mylist->next = new ListNode(myarray[i+1]);
        mylist = mylist->next;
    }
    mylist->next = NULL;
    rList s;
    ListNode *res;
    res = s.reverseList(head);

    for(int i = 0; i<6 ; i++)
    {
        cout <<res->val<<endl;
        res = res->next;
    }

    return 0;
}
