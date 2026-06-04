// ##########################################################
// Tarea Corta 7 - Estructuras de Datos
// Edwin Andrey Muñoz Sandí 2025075200
// ############################################################

#include <iostream>
#include <string>
#include "BSTDictionary.h"

using std::cout;
using std::string;

static void printDict(Dictionary<int, string>* dict) {
    cout << "{ ";
    dict->print();
    cout << "}\n";
}

static void showMenu() {
    cout << "\n\tOperations\n";
    cout << "1. Insert\n";
    cout << "2. Remove\n";
    cout << "3. Get value\n";
    cout << "4. Set value\n";
    cout << "5. Contains\n";
    cout << "6. Clear\n";
    cout << "7. Get keys\n";
    cout << "8. Get values\n";
    cout << "9. Update\n";
    cout << "10. Zip\n";
    cout << "0. Exit\n";
}

int main() {
    Dictionary<int, string>* dict1 = new BSTDictionary<int, string>();
    Dictionary<int, string>* dict2 = new BSTDictionary<int, string>();

    int option = -1;
    while (option != 0) {
        cout << "\tDictionaries\n";
        cout << "Dictionary 1:\n";
        printDict(dict1);
        cout << "Dictionary 2:\n";
        printDict(dict2);

        showMenu();

        option = 0;
    }

    delete dict1;
    delete dict2;
    return 0;
}