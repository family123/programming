#include<stdio.h>
#include<stdlib.h>
using namespace std;
typedef struct DLL {
    int data;
    struct DLL *next;
    struct DLL *prev;
}dll;
//typedef struct DLL dll;


void insert(dll **head, dll **tail, int data) {
    dll *temp;

    temp = (dll *)malloc(sizeof(dll));
    temp->data = data;
    temp->next = temp->prev = NULL;
    if(*head == NULL) {
        *head = *tail = temp;
    }
    else {
        (*tail)->next = temp;
        temp->prev = *tail;
        *tail = temp ;
    }
}

void delete_num(dll **head, dll **tail, int num) {
    dll *ptr = *head, *temp;
    if(ptr->data == num) {
        temp = ptr;
        *head = (*head)->next;
        (*head)->prev = NULL;
        temp->next = NULL;
        free(temp);
        return;
    }
    if(ptr->next == NULL && ptr->data == num) {
        free(ptr);
        *head = NULL;
    }
    else {
        while(ptr->next->data !=num)
            ptr = ptr->next;
        temp = ptr->next;
        if(temp->next != NULL) {
            ptr->next = temp->next;
            temp->next->prev = ptr;
        }
        else {
            *tail = ptr;
            ptr->next = NULL;
        }
        temp->next = temp->prev = NULL;
        free(temp);
    }
}

void forward_display(dll **head) {
    dll *ptr = *head;
    printf("\nForward display:\t");
    while(ptr) {
        printf("%d\t",ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

void backward_display(dll **tail) {
    dll *ptr = *tail;
    printf("\nBackward display:\t");
    while(ptr) {
        printf("%d\t",ptr->data);
        ptr = ptr->prev;
    }
    printf("\n");
}
int main() {
    int i;
    dll *head = NULL, *tail = NULL;
    for( i = 1 ; i < 10 ; i++) {
        insert(&head, &tail, i);
    }
    forward_display(&head);
    backward_display(&tail);
    delete_num(&head, &tail, 4);
    forward_display(&head);
    backward_display(&tail);
    delete_num(&head, &tail, 9);
    forward_display(&head);
    backward_display(&tail);
    delete_num(&head, &tail, 1);
    forward_display(&head);
    backward_display(&tail);
    return 0;
}
