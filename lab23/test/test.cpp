#include "list.h"

bool getLinkTest()
{
	bool result = true;

	list *List = new list;
	List->setCount(0);

	watch watchOne(false, "ZO9507", 1995, manufacturerStruct("Zodiac", "Germany"), CLASSIC);
	watch watchTwo(true, "MTG-B1000", 1000, manufacturerStruct("G-Shock", "Japan"), SPORT);
	watch watchTree(true, "RIM", 2200, manufacturerStruct("Mazzucato", "Italy"), ARMOURED);

	List->addLink(watchOne);
	List->addLink(watchTwo);
	List->addLink(watchTree);

	watch expect = List->getLink(1);

	if (List->getLink(1).getWaterproof() == expect.getWaterproof() && List->getLink(1).getModel() == expect.getModel() &&
	    List->getLink(1).getCost() == expect.getCost() && List->getLink(1).getStyle() == expect.getStyle()) {
		result = true;
	} else {
		result = false;
	}

	delete List;
	return result;
}

bool removeLinkTest()
{
	bool result = true;

	list *List = new list;
	List->setCount(0);
	list *expect = new list;
	expect->setCount(0);

	watch watchOne(false, "ZO9507", 1995, manufacturerStruct("Zodiac", "Germany"), CLASSIC);
	watch watchTwo(true, "MTG-B1000", 1000, manufacturerStruct("G-Shock", "Japan"), SPORT);
	watch watchTree(true, "RIM", 2200, manufacturerStruct("Mazzucato", "Italy"), ARMOURED);

	List->addLink(watchOne);
	List->addLink(watchTwo);
	List->addLink(watchTree);

	expect->addLink(watchOne);
	expect->addLink(watchTree);

	List->removeLink(1);

	for (int i = 0; i < 2; i++) {
		if (List->getLink(i).getWaterproof() == expect->getLink(i).getWaterproof() &&
		    List->getLink(i).getModel() == expect->getLink(i).getModel() && List->getLink(i).getCost() == expect->getLink(i).getCost() &&
		    List->getLink(i).getStyle() == expect->getLink(i).getStyle()) {
			result = true;
		} else {
			result = false;
		}
	}

	delete List;
	delete expect;
	return result;
}

bool findByPriceTest()
{
	bool result = true;

	list *List = new list;
	List->setCount(0);

	watch watchOne(false, "ZO9507", 1995, manufacturerStruct("Zodiac", "Germany"), CLASSIC);
	watch watchTwo(true, "MTG-B1000", 1000, manufacturerStruct("G-Shock", "Japan"), SPORT);
	watch watchTree(true, "RIM", 2200, manufacturerStruct("Mazzucato", "Italy"), ARMOURED);

	List->addLink(watchOne);
	List->addLink(watchTwo);
	List->addLink(watchTree);

	watch find = List->findByPrice(1500);

	if (List->getLink(1).getWaterproof() == find.getWaterproof() && List->getLink(1).getModel() == find.getModel() &&
	    List->getLink(1).getCost() == find.getCost() && List->getLink(1).getStyle() == find.getStyle()) {
		result = true;
	} else {
		result = false;
	}

	delete List;
	return result;
}

int main()
{
	bool result = true;
	cout << "Test getLnk: ";
	result = getLinkTest();
	if (result) {
		cout << "Finally!" << endl;
	} else {
		cout << "Error." << endl;
	}

	cout << "Test removeLink: ";
	result = removeLinkTest();
	if (result) {
		cout << "Finally!" << endl;
	} else {
		cout << "Error." << endl;
	}

	cout << "Test findByPrice: " << endl;
	result = findByPriceTest();
	if (result) {
		cout << "Finally!" << endl;
	} else {
		cout << "Error." << endl;
	}

	if (result) {
		cout << "All test finally passed!" << endl;
	} else {
		cout << "Something occurred error." << endl;
	}
	return 0;
}