// C++ program to find number of rotations
// in a sorted and rotated array.
#include<bits/stdc++.h>
using namespace std;

typedef struct List {
    int val;
    List *next;
    List(int x) : val(x), next(NULL) {}
}ListNode;

ListNode* reorderList(ListNode* A) {
    if(A->next == NULL)
        return A;
    ListNode *head = A;
    int count = 0 , mid = 0;
    while(head) {
        count++;
        head = head->next;
    }
    mid = count/2;
    if(count%2 != 0)
        mid++;
    
    ListNode *start = A;
    ListNode *middle = A, *start2;
    mid--;
    while(mid){
        mid--;
        middle = middle->next;
    }
    start2 = middle->next;
    middle->next = NULL;
    
    
    // reverse the list
    ListNode *b = start2->next,*previous = NULL;
    while(start2) {
        start2->next = previous;
        previous = start2;
        start2 = b;
        if(b)
            b = b->next;
    }
    head = NULL;
    ListNode *ptr = NULL;
    while(previous && start){
        ListNode *temp = (ListNode *)malloc(sizeof(ListNode));
        ListNode *temp2 = (ListNode *)malloc(sizeof(ListNode));
        if(head == NULL) {
            temp->val = start->val;
            temp->next = NULL;
            head = temp;
            ptr = head;
        }
        if(head->next == NULL) {
            temp2->val = previous->val;
            temp2->next = NULL;
            ptr->next = temp2;
            ptr = temp2;
        }
        else{
            temp->val = start->val;
            temp2->val = previous->val;
            temp->next = temp2;
            temp2->next = NULL;
            ptr->next = temp;
            ptr = temp2;
        }
        previous = previous->next;
        start = start->next;
    }
    if(count%2 != 0)
        ptr->next = start;

    return head;
        
    
}

void push(ListNode** head_ref, int new_key)
{
    /* allocate node */
    ListNode* new_node =
            (ListNode*) malloc(sizeof(ListNode));
    /* put in the key  */
    new_node->val  = new_key;
    /* link the old list off the new node */
    new_node->next = (*head_ref);
    /* move the head to point to the new node */
    (*head_ref)    = new_node;
}

int main()
{
    //int arr[] = {23, 12, 96};
    int arr[] = {7, 6, 5, 4, 3, 2, 1};
    //41, 20, 66, 1, 96, 35, 51, 79, 61, 48, 99, 11, 32, 88, 60, 18, 42,
    //29, 13, 91, 85, 10, 33, 52, 84, 4, 94, 46, 23, 82, 59, 38, 97, 17,
    //14, 90, 54, 69, 57, 74, 73, 39};
    int n = sizeof(arr)/sizeof(arr[0]);
    /* Start with the empty list */
    ListNode* head = NULL;
    for(int i = 0 ; i < n ; i++) {
        push(&head, arr[i]);
    }
    ListNode* new_head = head;
    new_head = reorderList(head);
    while(new_head){
        printf("%d,\t", new_head->val);
        new_head = new_head->next;
    }
    return 0;
}


