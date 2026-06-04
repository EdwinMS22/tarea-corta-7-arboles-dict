// ##########################################################
// Tarea Corta 7 - Estructuras de Datos
// Edwin Andrey Muñoz Sandí 2025075200
// ############################################################

#include <iostream>
#include <string>
#include "BSTDictionary.h"

using std::cout;
using std::string;

int main() {
    Dictionary<int, string>* dict1 = new BSTDictionary<int, string>();
    Dictionary<int, string>* dict2 = new BSTDictionary<int, string>();

    delete dict1;
    delete dict2;
}