#include<stdio.h>
#include<stdlib.h>

/* Zadano: */

struct _Node;
typedef struct _Node* Position;
typedef struct _Node {
    Position next;
} Node;

/* * * * */

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
    int size_of_node = sizeof(Node); // (4)
    printf("sizeof(number_pointer): %i \n address: %p \n", sizeof(size_of_number_pointer), number_pointer);
    printf("sizeof(letter_pointer): %i \n address: %p \n", sizeof(size_of_letter_pointer), letter_pointer);
    printf("sizeof(Node): %i \n address: %p \n", sizeof(size_of_letter_pointer), letter_pointer);
    /*
     dovoljno dobra pretpostavka:
    */
    int size_of_data_pointer = size_of_number_pointer;

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
        ideja: imam 4 byte-ova na raspolaganju, zadnjih 4 (ukupno 8)

        kako "spojiti" pisanje u zadnja 4 (naš pointer) da bude koristiv?
        - imamo "početnu" addresu
        - znam točan broj byte-ova
        - mogu iterirat i postavljat kroz pointer adrese vrijednost u memoriju
    */

    return 0;
}
