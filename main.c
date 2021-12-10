#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/* Zadano: */

struct _Node;
typedef struct _Node* Position;
typedef struct _Node {
    Position next;
} Node;

/* * * * */

int add_to_list(Position head, Position node);
int add_to_list(Position head, Position node) {
    Position temp = head;

    while(temp->next) {
        temp = temp->next;
    }

    temp->next = node;

    return 0;
}

int print_node(Position node, int size_of_data_pointer, int more_info);
int print_node(Position node, int size_of_data_pointer, int more_info) {
    printf("Node:\n");
    printf("->address: %p \n", node);
    printf("->next: %p \n", node->next);
    if(more_info == 1) {
        printf("->data (address): %p \n", *(node+size_of_data_pointer));
        // printf("\t->data (value): %p \n", *(node+size_of_data_pointer));
    }

    return 0;
}

int print_list(Position head, int size_of_data_pointer, int more_info);
int print_list(Position head, int size_of_data_pointer, int more_info) {
    Position temp = head;

    printf("\nList:\n");
    while(temp) {
        print_node(temp, size_of_data_pointer, more_info);
        temp = temp->next;
    }

    return 0;
}

int remove_node(Position head, Position node);
int remove_node(Position head, Position node) {
    Position current = head;
    Position previous = current;

    while(current != node) {
        previous = current;
        current = current->next;
    }

    previous->next = current->next;
    free(current);

    return 0;
}

Position create_node(int size_of_data_pointer);
Position create_node(int size_of_data_pointer) {
    Position master = calloc(sizeof(Node) + sizeof(size_of_data_pointer), size_of_data_pointer);
    if(!master) {
        return NULL;
    }
    return master;
}

int set_node_value(Position node, int* value, int size_of_data_pointer);
int set_node_value(Position node, int* value, int size_of_data_pointer) {
    int* var = (int*)(node+size_of_data_pointer);
    *var = value;
    return 0;
}

int main() {
    int size_of_data_pointer = sizeof(void*);
    printf("sizeof(data_ptr): %i, sizeof(struct): %i \n\n", size_of_data_pointer, sizeof(Node));
    Position head = create_node(size_of_data_pointer);

    Position number_test = create_node(size_of_data_pointer);
    int value = 1950;
    set_node_value(number_test, value, size_of_data_pointer);
    print_node(number_test, size_of_data_pointer, 1);
    printf("(int) value: %p %i \n\n", value, value, 1);

    Position letter_test = create_node(size_of_data_pointer);
    char letter = 'a';
    set_node_value(letter_test, letter, size_of_data_pointer);

    print_node(letter_test, size_of_data_pointer, 1);
    printf("(char) letter: %p %c \n\n", letter, letter, 1);

    Position array_test = create_node(size_of_data_pointer);
    int arr[3] = {1,2,3};
    set_node_value(array_test, arr, size_of_data_pointer);

    print_node(array_test, size_of_data_pointer, 1);
    printf("(int[3] arr) %p %i \n\n", arr, *arr);

    struct _Custom;
    typedef struct _Custom* CustomPointer;
    typedef struct _Custom {
        int a;
        char b;
    } Custom;
    Position struct_node_test = create_node(size_of_data_pointer);
    CustomPointer struct_test = (CustomPointer)malloc(sizeof(Custom));
    struct_test->a = 1911;
    struct_test->b = 'b';
    set_node_value(struct_node_test, struct_test, size_of_data_pointer);

    print_node(struct_node_test, size_of_data_pointer, 1);
    printf("(struct_test) %p %c \n\n", struct_test, struct_test->b);

    add_to_list(head, number_test);
    add_to_list(head, letter_test);
    add_to_list(head, array_test);
    add_to_list(head, struct_node_test);

    remove_node(head, letter_test);

    print_list(head, size_of_data_pointer, 0);

    return 0;
}
