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
 * #include "Task.h"



int main() {

    Task task;
    task.Run();

    return 0;
}*/