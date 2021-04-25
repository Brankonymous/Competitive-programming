#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
    int val;
    struct node *left, *right;
}Node;

Node *create_node(int data){
    Node *tmp = malloc(sizeof(Node));
    tmp->left = tmp->right = NULL;
    tmp->val = data;
    return tmp;
}

void ins(Node **root, int data){
    if (*root == NULL){
        *root = create_node(data);
    }
    else{
        if ((*root)->val <= data)
            ins(&(*root)->right, data);
        else
            ins(&(*root)->left, data);
    }
}

int check(Node **root, int data){
    if (*root == NULL){
        return 0;
    }
    else{
        if ((*root)->val == data)
            return 1;
        else if ((*root)->val < data)
            return check(&(*root)->right, data);
        else
            return check(&(*root)->left, data);
    }
}

int main(){
    Node *root = NULL;

    char t[10];
    int x;
    printf("Select operation ('ins' value, 'check' value, 'exit')\n");
    while(1){
        scanf("%s", t);
        if (strcmp(t, "exit") == 0)
            break;
        else if (strcmp(t, "ins") == 0){
            scanf("%d", &x);
            ins(&root, x);
        }
        else if (strcmp(t, "check") == 0){
            scanf("%d", &x);
            if (check(&root, x) == 0)
                printf("Number doesn't exist\n");
            else
                printf("Number exists\n");
        }
    }
    return 0;
}
