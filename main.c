#include<stdio.h>
#include<stdlib.h>

/* Zadano: */

struct _Node;
typedef struct _Node* Position;
typedef struct _Node {
    Position next;
} Node;

/* * * * */
// ovo je zapravo create node

int delete(Position item);
int delete(Position item) {
  Position temp = item;
  temp = item->next;
  item->next = temp->next;
  free(temp);
  return 0;
}

int print_all(Position head);
int print_all(Position head) {
    Position temp = head;

    while(temp) {
        // print
        temp = temp->next;
    }

    return 0;
}

int add_to_list(Position head, Position Node);
int add_to_list(Position head, Position Node) {
    Position temp = head;
    while(temp) {
        temp = temp->next;
    }
    temp->next = Node;
}

Position extend_node(Position head, int value);
Position extend_node(Position head, int value) {
        Position new = head;

        // jer možemo skliznit izvan memorije
        if(!new) {
            return -1;
        }

        // printf("Previous: %p %i \n", new, new);
        int temp = value;
        int *ptr = &temp;
        new = ptr;
        // printf("Next: %p %i \n", new, new);

        printf("\n");
}

    /*
    printf("Trenutno: \nAdresa: %p \nVrijednost: %i \n")








        printf("adrese slobodne: \n\n");
    for(int i = 0; i < size_of_data_pointer; i++) {
        Position new = node_1_attack + i;
        printf("%p %i \n", new, new);
        int a = 5;
        int *ptr = &a;
        new = ptr;
         printf("%p %i \n", new, new);

    printf("\n");

    }









    Position temp = pointer;
    // ovdje nailazim na problem splittanja data-e, google.
    printf("\nset_pointer_in_memory [(any) data]\n\taddress(data): %p\n\taddress_integer(data): %i \n \n", value, value);
    // steps su nužni AKO želimo ograničnit gornju granicu
    // void* bi trebao biti kao i ostali, ali za svaki slučaj
    // može izazvat promjene na ostatku memorije i uzrokovati probleme
    if(sizeof(value) > bytes) {
        return -5;
    }*/

    // pointer = &value;

    //printf("\n value + address :%i %i %i %p \n", value, &value, *value, value);

    // pointer = *value;

    // var:-1366620464 1344939112 1344939164 0x559cae8b06d0
    /*
    Node-ovi:
0x559cae8b06b0 -1366620496
0x559cae8b06b8 -1366620488
0x559cae8b06c0 -1366620480
0x559cae8b06c8 -1366620472
0x559cae8b06d0 -1366620464
0x559cae8b06d8 -1366620456
0x559cae8b06e0 -1366620448
0x559cae8b06e8 -1366620440
*/


    // iden probat pobrisat i istovremeno se ušuljat
    /*
    for(int i = 0; i < bytes; i++) {
        int *var = (int*)pointer;
        *var = 1950;
        printf("\n var:%i %i %i %p \n", var, &var, *var, var);
                // free() i odma malloc()
        // idem ubacit sve jedinice
        // free(&pointer);
        //free()
        printf("\t\t i:%i %i %i %i %p \t\n", i, pointer+i, *(pointer+i), *(&pointer+i), pointer+i);
    }
    */
    // ostaviti mu backdoor?
    // ovdje treba realloc igra
    // start = data;

    // ciao

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
    Position node_1 = calloc(sizeof(Node) + sizeof(size_of_data_pointer), size_of_data_pointer);
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
        funkcija: set_node_data(void* address, int byte, int value)
    */
    // testiranje
    printf("sizeof(node_1): %i\naddress: %p \n \n", sizeof(node_1), node_1);
    // starting point je:
    // int* overflow_pointer = (node_1 + size_of_data_pointer);
    // printf("address(overflow_pointer): %p \n \n", sizeof(node_1), node_1);
    // bolje 'size_of_data_pointer' nego da dijelim
    // + uvik je paran broj (ako zatreba)
    Position node_1_attack = node_1 + (size_of_data_pointer);
    printf("address(node_1_attack): %p\naddress_integer(node_1_attack): %i\nvalue(node_1_attack): %i\n\n", node_1_attack, node_1_attack, &node_1_attack);

    // ajmo vidit što doista piše
    printf("number_pointer: %p \n", number_pointer);
    printf("node_1_attack: %p \n\n", node_1_attack);

    printf("(Node) Adresa: %p, %i, završetak: %p, %i \n", node_1, node_1, node_1+size_of_node);
    printf("(Attack) Adresa: %p, %i \n", node_1_attack, node_1_attack);


    // ajmo se vratit na funkciju 'set_node_data'
    // testiram s 'number_pointer'
    Position head = extend_node(node_1_attack, 0);
    Position a = extend_node(node_1_attack, 1);
    Position b = extend_node(node_1_attack, 2);
    Position c = extend_node(node_1_attack, 2);
    Position d = extend_node(node_1_attack, 3);
    Position e = extend_node(node_1_attack, 4);

    print_all(head);

    // da vidimo je li prošlo
    printf("address(node_1_attack): %p\naddress_integer(node_1_attack): %i\nvalue(node_1_attack): %i\n\n", node_1_attack, node_1_attack, &node_1_attack);
    // 💪 :)


    return 0;
}
