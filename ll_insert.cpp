#include<stdlib.h>
#include "ll_ds.h"
#include<stdio.h>
/*typedef struct Node {
    int val;
    struct Node *next;
}node;*/
void insert_data(int value, node **list, node **head)
{
    node *temp;
    temp = (node *)malloc(sizeof(node));
    temp->val = value;
    temp->next = NULL;
    if((*list) == NULL) {
        *list = *head = temp;
    }
    else {
        (*head)->next = temp;
        *head = temp;
    }
    //free(temp);
}
void delete_data(int data, node **temp_node) {
    node *temp, *temp2;
    temp = *temp_node;
    if((temp)->next == NULL && (temp)->val == data)
        temp=NULL;
    if(temp->next != NULL && temp->val == data) {
        temp2 = temp;
        temp = temp->next;
        temp2->next = NULL;
        free(temp2);
        *temp_node = temp;
    }
    while((temp)->next) {
        if((temp)->next->val == data) {
            temp2 = (temp)->next;
            (temp)->next=temp2->next;
            free(temp2);
        }
        temp = (temp)->next;
    }
}
void display(node *head) {
    if(head ==NULL)
        printf("NULL\n");
    while(head) {
        printf("%d\t",(head)->val);
        head = (head)->next;
    }
    printf("\n");
}
int main() {
    node *list, *head;
    list = head = NULL;
    for(int i = 0 ; i < 10 ; i++) {
        insert_data(i+1 ,&list, &head);
    }
    display(list);
    //node *del_node = list;
    delete_data(3,&list);
    display(list);
    delete_data(1,&list);
    display(list);
    return 0;
}
