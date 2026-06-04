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
        option = 0;
    }

    delete dict1;
    delete dict2;
    return 0;
}