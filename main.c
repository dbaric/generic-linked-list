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

int print_node(Position node, int size_of_data_pointer);
int print_node(Position node, int size_of_data_pointer) {
    Position master = node;
    Position slave = master + size_of_data_pointer;

    printf("\n");
    printf("data (address): %p \n", slave);
    printf("next: %p \n", master->next);
    printf("\n");

    return 0;
}

int print_list(Position head, int size_of_data_pointer);
int print_list(Position head, int size_of_data_pointer) {
    Position temp = head;

    printf("\nList:");
    while(temp) {
        print_node(temp, size_of_data_pointer);
        temp = temp->next;
    }

    return 0;
}

int remove_node(Position node);
int remove_node(Position node) {
  Position temp = node;

  temp = node->next;
  node->next = temp->next;
  free(temp);

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


Position validate_slave(Position master, int size_of_data_pointer);
Position validate_slave(Position master, int size_of_data_pointer) {
    Position slave = master + (size_of_data_pointer);

    if(!slave) {
        return NULL;
    }

    return slave;
}

int main() {
    int size_of_data_pointer = sizeof(void*);
    int arr[3] = {1,2,3};

    // cjelokupna ideja: overflowati pointer (najoptimalnije)

    // može primiti int
    int a_data = 5;
    Position a = create_node(size_of_data_pointer);
    Position slave_a = validate_slave(a, size_of_data_pointer);
    memcpy(slave_a, &a_data, size_of_data_pointer);

    // može primiti char
    char b_data ='b';
    Position b = create_node(size_of_data_pointer);
    Position slave_b = validate_slave(b, size_of_data_pointer);
    memcpy(slave_b, b, size_of_data_pointer);

    // može primiti samog sebe
    Position c = create_node(size_of_data_pointer);
    Position slave_c = validate_slave(c, size_of_data_pointer);
    memcpy(slave_c, a, size_of_data_pointer);

    // polje..?
    Position d = create_node(size_of_data_pointer);
    Position slave_d = validate_slave(d, size_of_data_pointer);
    memcpy(slave_d, arr, size_of_data_pointer);

    // magija
    add_to_list(a, b);
    add_to_list(a, c);
    add_to_list(a, d);

    print_list(a, size_of_data_pointer);

    remove_node(b);

    print_list(a, size_of_data_pointer);
    // 💪 :)


    return 0;
}
