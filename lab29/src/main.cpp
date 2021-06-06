#include "list.hpp"


int main() {

    mechanicalWatches watchOne(false, "One", 1995, manufacturerStruct("Zodiac", "Germany"), CLASSIC, false, false);
    mechanicalWatches watchTwo(true, "Two", 1000, manufacturerStruct("G-Shock", "Japan"), SPORT, true, false);
    mechanicalWatches watchTree(false, "Tree", 2400, manufacturerStruct("Rocket", "USSR"), CLASSIC, true, false);

    list<mechanicalWatches> listWatch;
    listWatch.addLink(&watchOne);
    listWatch.addLink(&watchTwo);
    listWatch.addLink(&watchTree);

    listWatch.sortList();

    cout << "Original watch list: " << endl;
    listWatch.showList();
    cout << endl;


    list<int> listInt;

    int numbOne = 117;
    int numbTwo = 2;
    int numbTree = 17;

    listInt.addLink(&numbOne);
    listInt.addLink(&numbTwo);
    listInt.addLink(&numbTree);

    cout << "Element from list of integer with index 1: " << endl;
    int res = listInt.getLink(1);
    cout << res << endl << endl;

    listInt.sortList();

    cout << "Minimal element from int list: " << endl;
    int min = listInt.findMinLink();
    cout << min << endl << endl;

    cout << "Int list: " << endl;
    listInt.showList();
    cout << endl;

    list<char> listChar;

    char sym1 = 'i';
    char sym2 = 'g';
    char sym3 = 'o';
    char sym4 = 'r';

    listChar.addLink(&sym1);
    listChar.addLink(&sym2);
    listChar.addLink(&sym3);
    listChar.addLink(&sym4);

    cout << "Char list: " << endl;
    listChar.showList();
    cout << endl;


    list<string> listString;
    string wordOne = "Welcome!";
    string wordTwo = "Hi!";
    string wordTree = "Hello!";

    listString.addLink(&wordOne);
    listString.addLink(&wordTwo);
    listString.addLink(&wordTree);

    cout << "Index of element wordTwo from list: ";
    int resIndex = listString.findIndexLink(wordTwo);
    cout << resIndex << endl << endl;

    cout << "String list: " << endl;
    listString.showList();
    cout << endl;

    cout << "Deleting element with index 1 from string list: " << endl;
    listString.deleteLink(1);
    listString.showList();
    cout << endl;

    return 0;
}