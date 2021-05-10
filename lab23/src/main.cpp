#include "list.h"

int main()
{
	watch watchOne(false, "ZO9507", 1995, manufacturerStruct("Zodiac", "Germany"), CLASSIC);
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
	watchList->addLink(watchOne);
	watchList->addLink(watchTwo);

	cout << "|===============<Origin_list>===============|" << endl;
	watchList->showAll();
	cout << "|-------------------------------------------|" << endl;
	cout << "|=======<Watch_with_price_under_1500>=======|" << endl;
	watchList->findByPrice(1500);
	cout << "|-------------------------------------------|" << endl;
	cout << "|=========<Watch_on_first_position>=========|" << endl;
	watch tmp = watchList->getLink(0);
	tmp.show();
	cout << "|-------------------------------------------|" << endl;
	cout << "|=======<List_with_deleted_first_link>======|" << endl;
	watchList->removeLink(0);
	watchList->showAll();
	cout << "|-------------------------------------------|" << endl;
	delete watchList;
	delete manufacturer;
	delete watchTree;
	return 0;
}