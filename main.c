#include<stdio.h>
#include<stdlib.h>

/* */

struct _Node;
typedef struct _Node* Position;
typedef struct _Node {
    Position next;
} Node;

/* */

struct _IntegerNode;
typedef struct _IntegerNode* IntegerPosition;
typedef struct _IntegerNode {
    int data;
    struct _Node node;
} IntegerNode;

IntegerPosition create_integer_node(int data);
IntegerPosition create_integer_node(int data) {
    IntegerPosition new_integer_node = NULL;
    new_integer_node = (IntegerPosition)malloc(sizeof(IntegerNode));

    if(!new_integer_node) {
        return NULL;
    }

    new_integer_node->node.next = NULL;
    new_integer_node->data = data;

    return new_integer_node;
}

int add_after_integer_node(IntegerPosition target_node, IntegerPosition new_node);
int add_after_integer_node(IntegerPosition target_node, IntegerPosition new_node) {
    Position temp = target_node->node.next; // spremi trenutni target next

    target_node->node.next = new_node; // target ima novi new
    new_node->node.next = temp; // a new ima (stari) target next

    return 0;
}

int print_all_integer_nodes(IntegerPosition head);
int print_all_integer_nodes(IntegerPosition head) {
    IntegerPosition temp = head;

    printf("Print all node data: \n");

    while(temp) {
        printf(" | %i | ", temp->data);
        temp = temp->node.next;
    }

    printf("\n");

    return 0;
}

// implementiraj mene
int delete_node() {
    return 0;
}

int main() {

    /*
    * extend za brojeve
    */
    IntegerPosition integer_node_head = create_integer_node(0);

    if(!integer_node_head) {
        return -1;
    }

    for(int i = 1; i < 10; i++) {
        IntegerPosition new_integer_node = create_integer_node(i);

        if(!new_integer_node) {
            return -1;
        }

        new_integer_node->data = i;

        add_after_integer_node(integer_node_head, new_integer_node);
    }

    // znam da je ispis 0 9 8 ..., zato što za head šaljem "0" odnosno na njega kačim nove elemente
    print_all_integer_nodes(integer_node_head);


    // puni charovima

    // puno custom structom

    return 0;
}