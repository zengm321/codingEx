#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(nullptr) {};
};
class partition_list
{
public:
    ListNode *partlist(ListNode *head, int x)
    {
        ListNode *p = new ListNode(0);
        p->next = head;
        head = p;
        ListNode *last =head;

        if(head == NULL)
        {
            return NULL;
        };
        if(head->next == NULL)
        {
            return head->next;
        };

        int n =0;
        while(last->next != NULL)
        {
            last = last->next;
            n++;
        }
        while(n>0)
        {
            if(p->next->val <x)
            {
                p = p->next;
                n--;
            }
            else
            {
                last->next = new ListNode(p->next->val);
                last = last->next;
                p->next = p->next->next;
                n--;
            }
        }
        return head->next;


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


    partition_list s1;
    ListNode *res;
    res = s1.partlist(head, 3);
    for(int i = 0; i<6 ; i++)
    {
        cout <<res->val<<endl;
        res = res->next;
    }
    return 0;
}
