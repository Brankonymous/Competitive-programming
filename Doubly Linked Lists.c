#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
    int val;
    struct node *next;
    struct node *prev;
}Node;

void display_list_norm(Node *head){
    printf("List values: ");
    Node *p = head;
    while(p != NULL){
        printf("%d ", p->val);
        p = p->next;
    }
    printf("\n");
}

void display_list_rev(Node *tail){
    printf("List values reversed: ");
    Node *p = tail;
    while(p != NULL){
        printf("%d ", p->val);
        p = p->prev;
    }
    printf("\n");
}

Node* create_node(int data){
    Node *tmp = malloc(sizeof(Node));
    tmp->val = data;
    tmp->next = tmp->prev = NULL;
    return tmp;
}

void insert_back(Node **head, Node **tail, int data){
    if (*tail == NULL){
        *tail = create_node(data);
        *head = *tail;
    }
    else{
        Node *tmp = create_node(data);
        (*tail)->next = tmp;
        ((*tail)->next)->prev = *tail;
        *tail = (*tail)->next;
    }
}

void insert_front(Node **head, Node **tail, int data){
    if (*head == NULL){
        *head = create_node(data);
        *tail = *head;
    }
    else{
        Node *tmp = create_node(data);
        (*head)->prev = tmp;
        ((*head)->prev)->next = *head;
        *head = (*head)->prev;
    }
}

void delete_back(Node **head, Node **tail){
    if (*tail == NULL){
        printf("No node to delete\n");
    }
    else if ((*tail)->prev == NULL){
        free(*head);
        *head = *tail = NULL;
    }
    else{
        Node *tmp = (*tail)->prev;
        free(*tail);
        *tail = tmp;
        (*tail)->next = NULL;
    }
}

void delete_front(Node **head, Node **tail){
    if (*head == NULL){
        printf("No node to delete\n");
    }
    else if ((*head)->next == NULL){
        free(*head);
        *head = NULL;
    }
    else{
        Node *tmp = (*head)->next;
        free(*head);
        *head = tmp;
    }
}

int main(){
    Node *head = NULL;
    Node *tail = NULL;

    char t[10];
    int x;
    printf("Select operation ('ins_back' value, 'ins_front' value, 'dis_rev', 'del_back', del_front', 'exit')\n");
    while(1){
        scanf("%s", t);
        if (strcmp(t, "exit") == 0){
            break;
        }
        else if (strcmp(t, "ins_back") == 0){
            scanf("%d", &x);
            insert_back(&head, &tail, x);
        }
        else if (strcmp(t, "ins_front") == 0){
            scanf("%d", &x);
            insert_front(&head, &tail, x);
        }
        else if (strcmp(t, "dis_rev") == 0){
            display_list_rev(tail);
            continue;
        }
        else if (strcmp(t, "del_back") == 0){
            delete_back(&head, &tail);
        }
        else if (strcmp(t, "del_front") == 0){
            delete_front(&head, &tail);
        }
        display_list_norm(head);
    }
    return 0;
}
