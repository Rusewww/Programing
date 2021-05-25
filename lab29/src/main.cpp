#include "list.h"

int main()
{
	watch watchOne(true, "ZO9507", 1995, manufacturerStruct("Zodiac", "Germany"), CLASSIC);
	watch watchTwo(true, "MTG-B1000", 1000, manufacturerStruct("G-Shock", "Japan"), SPORT);

	auto *manufacturer = new manufacturerStruct;
	manufacturer->setFirm("Mazzucato");
	manufacturer->setCountry("Italy");

	auto *watchTree = new watch;
	watchTree->setWaterproof(true);
	watchTree->setModel("RIM");
	watchTree->setCost(2200);
	watchTree->setManufacturer(manufacturer);
	watchTree->setStyle(ARMOURED);

	delete manufacturer;

	list *watchList = new list;
	watchList->setCount(0);
	watchList->addLink(watchOne);
	watchList->addLink(watchTwo);
	watchList->addLink(*watchTree);
	delete watchTree;

	cout << "|===============<Origin_list>===============|" << endl;
	for (int i = 0; i < 3; i++) {
		string out = watchList->getLink(i).toString();
		cout << out << endl;
	}
	cout << "|-------------------------------------------|" << endl;
	cout << "|==========<List_redden_from_file>==========|" << endl;

	string fromFile[3];
	list::readFromFile("../assets/input.txt",fromFile);

	watchList->deleteList();

	watchList->addLink(watch::toClass(fromFile[0]));
	watchList->addLink(watch::toClass(fromFile[1]));
	watchList->addLink(watch::toClass(fromFile[2]));

	for (int i = 0; i < 3; i++) {
		string out = watchList->getLink(i).toString();
		cout << out << endl;
	}

	cout << "|-------------------------------------------|" << endl;
	watchList->writeToFile("../dist/output.txt");
	delete watchList;
	return 0;
}
/*
 * #include "list.hpp"
//#include "Backpack.h"


int main() {

    LeatherBackpack leatherBackpack(false, "Black", 33, Firm("Nike", "USA"), TOURIST, true, ANILINE);
    LeatherBackpack leatherBackpack1(true, "Red", 44, Firm("Puma", "USA"), TACTICAL, false, SUEDE);
    LeatherBackpack leatherBackpack2(false, "Blue", 24, Firm("Adidas", "Germany"), URBAN, true, VELOUR);

    List<LeatherBackpack> list;
    list.addElement(&leatherBackpack);
    list.addElement(&leatherBackpack1);
    list.addElement(&leatherBackpack2);

    //list.deleteElement(1);

    list.SortList();

    //Исходный список
    cout << "|-------------------------------------------------------LEATHER BACKPACK LIST-------------------------------------------------------|" << endl;
    PrintForm1();
    cout << endl;
    list.ShowList();
    cout << "|-----------------------------------------------------------------------------------------------------------------------------------|" << endl;
    cout << endl;

    List<int> listint;

    int a = 5;
    int b = 1;
    int c = 4;

    listint.addElement(&a);
    listint.addElement(&b);
    listint.addElement(&c);

    int res = listint.getElement(1);
    cout << res << endl << endl;

    listint.SortList();

    int min = listint.FindMinElement();
    cout << min << endl << endl;
    listint.ShowList();
    cout << endl;

    List<char> listchar;

    char sym1 = 'v';
    char sym2 = 'l';
    char sym3 = 'a';
    char sym4 = 'd';

    listchar.addElement(&sym1);
    listchar.addElement(&sym2);
    listchar.addElement(&sym3);
    listchar.addElement(&sym4);

    //listchar.deleteElement(2);
    listchar.ShowList();
    cout << endl;
//    listchar.SortList();
//    listchar.ShowList();


    List<string> liststring;
    string word1 = "Hello!";
    string word2 = "Have a nice day!";
    string word3 = "Good luck!";

    liststring.addElement(&word1);
    liststring.addElement(&word2);
    liststring.addElement(&word3);

    int resindex = liststring.FindIndexElement(word2);
    cout << resindex << endl << endl;


    liststring.ShowList();
    cout << endl;

    liststring.deleteElement(1);
//    liststring.SortList();
    liststring.ShowList();
    cout << endl;

    return 0;
}*/