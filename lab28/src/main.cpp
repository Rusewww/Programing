#include "list.h"

int main() {
    list menu;
    while (true) {
        try {
            string fileName;
            cout << "Enter name of input file: ";
            cin >> fileName;
            if (fileName == "\\exit")
                return 0;
            menu.setFileName(fileName);
            cout << "Finally!" << endl;
            menu.readFromFile();
            int *result = menu.findAverageValue();
            menu.setResult(result);
            cout << endl << "Enter name of output file: ";
            cin >> fileName;
            if (fileName == "\\exit")
                return 0;
            menu.setFileName(fileName);
            cout << "Finally!" << endl;
            menu.writeToFile();
            break;
        }
        catch (out_of_range &e) {
            cout << e.what() << endl;
        }
        catch (ios_base::failure &e) {
            cout << e.what() << endl;
        }
        catch (invalid_argument &e) {
            cout << e.what() << endl;
        }
    }
}