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

static string readString(string prompt) {
    cout << prompt;
    string line;
    std::getline(std::cin, line);
    return line;
}

static void showDictSelectionMenu() {
    cout << "\nChoose a dictionary for this operation:\n";
    cout << "1. Dictionary 1\n";
    cout << "2. Dictionary 2\n";
}

static void pressToContinue() {
    cout << "\nPress ENTER to continue...";
    string dummy;
    std::getline(std::cin, dummy);
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

        cout << '\n';
        int dictOption{};
        try {
            if (option == 1) {
                showDictSelectionMenu();
                dictOption = readIntInRange("Choose an option: ", 1, 2);
                int key = readInt("Key: ");
                string value = readString("Value: ");
                dictOption == 1 ? dict1->insert(key, value) : dict2->insert(key, value);
            }
            else if (option == 2) {
                showDictSelectionMenu();
                dictOption = readIntInRange("Choose an option: ", 1, 2);
                int key = readInt("Key: ");
                dictOption == 1 ? dict1->remove(key) : dict2->remove(key);
            }
            else if (option == 3) {
                showDictSelectionMenu();
                dictOption = readIntInRange("Choose an option: ", 1, 2);
                int key = readInt("Key: ");
                string value = dictOption == 1 ? dict1->getValue(key) : dict2->getValue(key);
                cout << "\nValue associated with the key: " << value << '\n';
            }
        }
        catch (const std::runtime_error& e) {
            cout << "\nOperation failed: " << e.what() << '\n';
        }
        if (option != 0) pressToContinue();
        cout << '\n';
    }

    delete dict1;
    delete dict2;
    return 0;
}