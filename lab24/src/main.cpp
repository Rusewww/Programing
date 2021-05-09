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

	list *watchList = new list;
	watchList->setCount(0);

	watchList->addLink(*watchTree);
	watchList->addLink(watchTwo);
	//watchList->addLink(watchOne);

	cout << "|===============<Origin_list>===============|" << endl;
	watchList->showAll();
	cout << "|-------------------------------------------|" << endl;
	cout << "|=======<Watch_with_price_under_1500>=======|" << endl;
	watchList->findByPrice(1500);
	cout << "|-------------------------------------------|" << endl;
	cout << "|=========<Watch_on_first_position>=========|" << endl;
	watch *tmp = &watchList->getLink(0);
	tmp->show();
	cout << "|-------------------------------------------|" << endl;
	cout << "|=======<List_with_deleted_first_link>======|" << endl;
	string one = watchOne.toString();
	//watchList->removeLink(0);
	//auto *test = new watch;
	//*test = watch::toClass(one);
	//test->show();
	//watchList->addLink(*test);
	watchList->readFromFile("../assets/input.txt");
	watchList->showAll();
	cout << "|-------------------------------------------|" << endl;
	watchList->writeToFile("../dist/output.txt");
	delete watchList;
	delete manufacturer;
	delete watchTree;
	delete tmp;
	//delete test;
	return 0;
}