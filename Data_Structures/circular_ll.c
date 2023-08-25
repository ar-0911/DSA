
#include <stdio.h> 
#include <stdlib.h> 
  
struct Node { 
    int data; 
    struct Node* next; 
}; 
  
void insert(struct Node** head_ref, int data) 
{ 
    struct Node* ptr1 = (struct Node*)malloc(sizeof(struct Node)); 
    struct Node* temp = *head_ref; 
    ptr1->data = data; 
    ptr1->next = *head_ref; 
  
    if (*head_ref != NULL) { 
        while (temp->next != *head_ref) 
            temp = temp->next; 
        temp->next = ptr1; 
    } else
        ptr1->next = ptr1; 
  
    *head_ref = ptr1; 
} 
  
int countNodes(struct Node* head) 
{ 
    struct Node* temp = head; 
    int result = 0; 
    if (head != NULL) { 
        do { 
            temp = temp->next; 
            result++; 
        } while (temp != head); 
    } 
  
    return result; 
} 
  
int main() 
{ 
    struct Node* head = NULL; 
    insert(&head, 12); 
    insert(&head, 56); 
    insert(&head, 2); 
    insert(&head, 11); 
    insert(&head,22);
  
    printf("total number of elements in circular linked list: %d", countNodes(head)); 
  
    return 0; 
} 