// ##########################################################
// Tarea Corta 7 - Estructuras de Datos
// Edwin Andrey Muñoz Sandí 2025075200
// ############################################################

#include <iostream>
#include <string>
#include <sstream>
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

static int readInt(const string& prompt) {
    while (true) {
        cout << prompt;
        string line;
        std::getline(std::cin, line);

        std::istringstream iss(line);
        int value{};
        if ((iss >> value) && (iss >> std::ws).eof())
            return value;
        cout << "Not a valid integer. Try again.\n";
    }
}

static int readIntInRange(const string& prompt, int min, int max) {
    while (true) {
        int value = readInt(prompt);

        if (value >= min && value <= max)
            return value;
        cout << "Integer must be between " << min << " and " << max << ". Try again.\n";
    }
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
        option = readIntInRange("Choose an option: ", 0, 10);
    }

    delete dict1;
    delete dict2;
    return 0;
}