#include<stdio.h>
#include<stdlib.h>

/* Zadano: */

struct _Node;
typedef struct _Node* Position;
typedef struct _Node {
    Position next;
} Node;

/* * * * */

int set_pointer_in_memory(Position node_1_attack, int size_of_data_pointer, void* number_pointer);
int set_pointer_in_memory(Position start, int bytes, void* data) {
    // ovdje nailazim na problem splittanja data-e, google.

}

int main() {
    // dummy data
    int number = 1950;
    char letter = 'h';
    // struct Node - predefined

    // pointers to types of data
    int* number_pointer = &number;
    char* letter_pointer = &letter;
    // struct Node* (Position)- predefined

    // allocate and print memory
    // pazi: ovisi je li 32bit ili 64bit CPU
    int size_of_number_pointer = sizeof(number_pointer); // (4)
    int size_of_letter_pointer = sizeof(letter_pointer); // (4)
    int size_of_void_pointer = sizeof(void*); // (4)
    int size_of_node = sizeof(Node); // (4)
    printf("sizeof(number_pointer): %i \naddress: %p \n \n", sizeof(size_of_number_pointer), number_pointer);
    printf("sizeof(letter_pointer): %i \naddress: %p \n \n", sizeof(size_of_letter_pointer), letter_pointer);
    printf("sizeof(void*): %i \n \n", sizeof(size_of_letter_pointer));
    printf("sizeof(Node): %i \naddress: %p \n \n", sizeof(size_of_letter_pointer), letter_pointer);
    /*
     dovoljno dobra pretpostavka:
    */
    int size_of_data_pointer = size_of_void_pointer;

    // ideja: rezervirat (i počistit) više byte-ova nego što treba
    // na tu poziciju stavljat pointer naprijed
    // je li ovo positive overflow? istraži!!
    Position node_1 = calloc(
        sizeof(Node) + sizeof(size_of_data_pointer),
        size_of_data_pointer
    );
    /*
    calloc:
    num - Number of elements to allocate.
    size - Size of each element.
    */

    /*
        ideja: imam N/2 byte-ova na raspolaganju (desno od sredine)

        kako "spojiti" pisanje u zadnje (naš pointer) da bude koristiv?
        - imamo "početnu" addresu
        - znam točan broj byte-ova
        - mogu iterirat i postavljat kroz pointer adrese vrijednost u memoriju

        olakšat će mi ako napravim helper funkciju
        funkcija: set_pointer_in_memory(void* start_address, int bytes, int value)
    */
    // testiranje
    printf("sizeof(node_1): %i\naddress: %p \n \n", sizeof(node_1), node_1);
    // starting point je:
    // int* overflow_pointer = *(*node_1 + size_of_data_pointer);
    // printf("address(overflow_pointer): %p \n \n", sizeof(node_1), node_1);
    /*
        eh, ovo znači da smo limitirani na samo linked listu?
        odnosno da će data bit takav tip podatka
    */
    // bolje 'size_of_data_pointer' nego da dijelim
    // + uvik je paran broj (ako zatreba)
    Position node_1_attack = node_1 + (size_of_data_pointer);
    printf("address(node_1_attack): %p \n \n", node_1_attack);
    // ajmo se vratit na funkciju 'set_pointer_in_memory'
    // testiram s 'number_pointer'
    set_pointer_in_memory(node_1_attack, size_of_data_pointer, number_pointer);


    return 0;
}
