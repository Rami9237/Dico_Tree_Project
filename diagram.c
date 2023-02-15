#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

void print_tree_helper(struct node *node, int space) {
    if (node == NULL) {
        return;
    }

    space += 10;

    print_tree_helper(node->right, space);

    printf("\n");
    for (int i = 10; i < space; i++) {
        printf(" ");
    }
    printf("%d\n", node->data);

    print_tree_helper(node->left, space);
}

void print_tree(struct node *node) {
    print_tree_helper(node, 0);
}

struct node* new_node(int data) {
    struct node* node = (struct node*) malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return node;
}

int main() {
    struct node *root = new_node(1);
    root->left = new_node(2);
    root->right = new_node(3);
    root->left->left = new_node(4);
    root->left->right = new_node(5);
    root->right->left = new_node(6);
    root->right->right = new_node(7);

    print_tree(root);

    return 0;
}
