#include "list.h"

bool toStringTest()
{
	watch watchTestOne = watch(true, "ZO9507", 1995, manufacturerStruct("Zodiac", "Germany"), CLASSIC);
	watch watchTestTwo(true, "MTG-B1000", 1000, manufacturerStruct("G-Shock", "Japan"), SPORT);
	string expectOne = "1 ZO9507 1995 1 Zodiac Germany\n";
	string expectTwo = "1 MTG-B1000 1000 2 G-Shock Japan\n";

	string findOne = watchTestOne.toString();
	string findTwo = watchTestTwo.toString();

	if (expectOne == findOne && expectTwo == findTwo) {
		return true;
	} else {
		return false;
	}
}

bool toClassTest()
{
	watch expectOne = watch(true, "ZO9507", 1995, manufacturerStruct("Zodiac", "Germany"), CLASSIC);
	watch expectTwo(true, "MTG-B1000", 1000, manufacturerStruct("G-Shock", "Japan"), SPORT);
	string watchTestOne = "1 ZO9507 1995 1 Zodiac Germany\n";
	string watchTestTwo = "1 MTG-B1000 1000 2 G-Shock Japan\n";

	watch testOne = watch::toClass(watchTestOne);
	watch testTwo = watch::toClass(watchTestTwo);

	if (expectOne.getWaterproof() == testOne.getWaterproof() && expectOne.getModel() == testOne.getModel() &&
	    expectOne.getCost() == testOne.getCost() && expectOne.getStyle() == testOne.getStyle() &&
	    expectTwo.getWaterproof() == testTwo.getWaterproof() && expectTwo.getModel() == testTwo.getModel() &&
	    expectTwo.getCost() == testTwo.getCost() && expectTwo.getStyle() == testTwo.getStyle()) {
		return true;
	} else {
		return false;
	}
}

int main()
{
	bool result = true;

	cout << "Test toString: ";
	result = toStringTest();
	if (result) {
		cout << "Finally!" << endl;
	} else {
		cout << "Error." << endl;
	}

	cout << "Test toClass: ";
	result = toClassTest();
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