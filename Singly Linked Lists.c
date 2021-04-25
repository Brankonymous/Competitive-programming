#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
    int val;
    struct node *next;
}Node;

Node* create_node(){
    Node *tmp = malloc(sizeof(Node));
    tmp->next = NULL;
    return tmp;
}

void add_back(Node **head, int data){
    Node *p, *next_node = create_node();
    next_node->val = data;

    if (*head == NULL){
        *head = next_node;
    }
    else{
        p = *head;
        while(p->next != NULL){
            p = p->next;
        }
        p->next = next_node;
    }
}

void add_front(Node **head, int data){
    Node *tmp = create_node();
    tmp->val = data;
    if (*head == NULL){
        *head = tmp;
    }
    else{
        tmp->next = *head;
        *head = tmp;
    }
}

void display_list(Node *head){
    printf("List values: ");
    Node *p = head;
    while(p != NULL){
        printf("%d ", p->val);
        p = p->next;
    }
    printf("\n");
}

void delete_back(Node **head){
    if (*head == NULL){
        printf("No nodes for deletion\n");
        return;
    }
    Node *p = *head;
    if (p->next == NULL){
        free(*head);
        *head = NULL;
        return;
    }
    Node *tmp = *head;
    while(p->next != NULL){
        tmp = p;
        p = p->next;
    }
    free(p);
    tmp->next = NULL;
}

void delete_front(Node **head){
    if (*head == NULL){
        printf("No nodes for deletion\n");
    }
    else if ((*head)->next == NULL){
        free(*head);
        *head = NULL;
    }
    else{
        Node *p = (*head)->next;
        free(*head);
        *head = p;
    }
}

int main(){
    Node *head = NULL;
    for (int i = 0; ; i++){
        int x;
        char *t = malloc(10 * sizeof(char));
        printf("Select operation ('ins_back' value, 'ins_front' value, 'del_back', del_front', 'exit')\n");
        scanf("%s", t);
        if (strcmp(t, "ins_back") == 0){
            scanf("%d", &x);
            add_back(&head, x);
        }
        else if (strcmp(t, "ins_front") == 0){
            scanf("%d", &x);
            add_front(&head, x);
        }
        else if (strcmp(t, "del_back") == 0){
            delete_back(&head);
        }
        else if (strcmp(t, "del_front") == 0){
            delete_front(&head);
        }
        else
            break;
        display_list(head);
    }
}
/*
ins_back 3
ins_back 4
del_back
*/
