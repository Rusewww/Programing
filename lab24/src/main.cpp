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

	watchList->addLink(*watchTree);
	delete watchTree;
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
	//delete tmp;
	cout << "|-------------------------------------------|" << endl;
	cout << "|=======<List_with_deleted_first_link>======|" << endl;
	string one = watchOne.toString();


	string fromFile[3];
	*fromFile = list::readFromFile("../assets/input.txt",fromFile);

	watchList->deleteList();
	int i = 0;
	while(i < 3){
		auto *test = new watch;
		*test = watch::toClass(fromFile[i++]);
		watchList->addLink(*test);
		watch *tmp1 = &watchList->getLink(i);
		tmp1->show();
		delete test;
	}

	/**test2[1] = watch::toClass(fromFileOne[0]);
	*test[1] = watch::toClass(fromFileOne[1]);
	*test3 = watch::toClass(fromFileOne[2]);
	watchList->addLink(*test);
	watchList->addLink(*test2);
	watchList->addLink(*test3);*/
	//watchList->showAll();
	cout << "|-------------------------------------------|" << endl;
	watchList->writeToFile("../dist/output.txt");
	delete watchList;
	return 0;
}