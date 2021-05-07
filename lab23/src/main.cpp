#include "list.h"

int main()
{
	auto *manufacturer = new manufacturerStruct;
	manufacturer->setFirm("Mazzucato");
	manufacturer->setCountry("Italy");

	auto *watchOne = new watch;
	watchOne->setWaterproof(true);
	watchOne->setModel("RIM");
	watchOne->setCost(2200);
	watchOne->setManufacturer(manufacturer);
	watchOne->setStyle(ARMOURED);

	watch watchTwo(false, "ZO9507", 1995, manufacturerStruct("Zodiac", "Germany"), CLASSIC);
	watch watchTree(true, "MTG-B1000", 1000, manufacturerStruct("G-Shock", "Japan"), SPORT);
	list *watchList = new list;
	watchList->setCount(0);
	watchList->addLink(watchTwo);
	watchList->addLink(*watchOne);
	watchList->addLink(watchTree);

	watchList->showAll();
	cout << "_______________________________________________" << endl;
	watchList->findByPrice(1500);
	cout << "_______________________________________________" << endl;
	watch tmp = watchList->getLink(2);
	tmp.show();
	cout << "_______________________________________________" << endl;
	watchList->removeLink(1);
	watchList->showAll();
	return 0;
}