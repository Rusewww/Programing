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
	watchList->addLink(*watchOne);
	watchList->addLink(watchTwo);
	watchList->addLink(watchTree);

	cout << "|===============<Origin_list>===============|" << endl;
	watchList->showAll();
	cout << "|-------------------------------------------|" << endl;
	cout << "|========<Watch_with_price_under_400>=======|" << endl;
	watchList->findByPrice(1500);
	cout << "|-------------------------------------------|" << endl;
	cout << "|=========<Watch_on_first_position>=========|" << endl;
	watch tmp = watchList->getLink(1);
	tmp.show();
	cout << "|-------------------------------------------|" << endl;
	cout << "|=======<List_with_deleted_first_link>======|" << endl;
	watchList->removeLink(1);
	watchList->showAll();
	cout << "|-------------------------------------------|" << endl;
	return 0;
}