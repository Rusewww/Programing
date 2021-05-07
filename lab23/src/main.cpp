#include "list.h"

int main()
{
	watch watchOne(true, "RIM", 2200, manufacturerStruct("Mazzucato", "Italy"), ARMOURED);
	watch watchTwo(false, "ZO9507", 1995, manufacturerStruct("Zodiac", "Germany"), CLASSIC);
	watch watchTree(true, "MTG-B1000", 1000, manufacturerStruct("G-Shock", "Japan"), SPORT);
	list *watchList = new list;
	watchList->setCount(0);
	watchList->addLink(watchOne);
	watchList->addLink(watchTwo);
	watchList->addLink(watchTree);

	watchList->showAll();
	cout << "_______________________________________________" << endl;
	watchList->findByPrice(1500);
	cout << "_______________________________________________" << endl;
	watch tmp = watchList->getLink(1);
	tmp.show();
	cout << "_______________________________________________" << endl;
	watchList->removeLink(1);
	watchList->showAll();
	delete watchList;
	return 0;
}