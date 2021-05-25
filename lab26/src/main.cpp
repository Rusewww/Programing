/**
 * @file main.cpp
 * @brief OOP. Inheritance.
 * @author Zozulia Igor.
 * @date 20-may-2021
 * @version 1.0
 */

/**
 * function main - main program function.
 * @return 0 - successful return code
 */

#include "list.h"

int main()
{
	cout << "|===========<Quartz_Origin_list>===========|" << endl;
	auto *quartzWatch = new quartzWatchesList;
	quartzWatches watchOne(false, "One", 1995, manufacturerStruct("Zodiac", "Germany"), CLASSIC, GRAPHENE, 400);
	quartzWatch->addLink(watchOne);
	quartzWatches watchTwo(true, "Two", 1000, manufacturerStruct("G-Shock", "Japan"), SPORT, LI_ION, 445);
	quartzWatch->addLink(watchTwo);
	quartzWatches watchTree(false, "Tree", 2400, manufacturerStruct("Rocket", "USSR"), CLASSIC, SOLAR, 95);
	quartzWatch->addLink(watchTree);
	quartzWatch->showAll();
	cout << "|-------------------------------------------|" << endl;
	cout << "|========<Quartz_Watches_Under_1500>========|" << endl;
	quartzWatch->findByPrice(1500);
	cout << "|-------------------------------------------|" << endl;
	cout << "|==========<Quartz_Classic_Watches>=========|" << endl;
	quartzWatch->findClassicWatches();
	cout << "|-------------------------------------------|" << endl;
	delete quartzWatch;
	cout << "|=========<Mechanical_Origin_list>==========|" << endl;
	auto *mechanicalWatch = new mechanicalWatchList;
	mechanicalWatches watch1(false, "One", 1995, manufacturerStruct("Zodiac", "Switzerland"), CLASSIC, false, true);
	mechanicalWatch->addLink(watch1);
	mechanicalWatches watch2(true, "Two", 1000, manufacturerStruct("G-Shock", "Japan"), SPORT, true, false);
	mechanicalWatch->addLink(watch2);
	mechanicalWatches watch3(false, "Tree", 2400, manufacturerStruct("Rocket", "USSR"), CLASSIC, true, false);
	mechanicalWatch->addLink(watch3);
	mechanicalWatch->showAll();
	cout << "|----------------------------------------------|" << endl;
	cout << "|=======<Mechanical_Watches_Under_1500>========|" << endl;
	mechanicalWatch->findByPrice(1500);
	cout << "|----------------------------------------------|" << endl;
	cout << "|=========<Mechanical_Classic_Watches>=========|" << endl;
	mechanicalWatch->findClassicWatches();
	cout << "|----------------------------------------------|" << endl;
	cout << "|<Mechanical_Switzerland_Watches_With_Skeleton>|" << endl;
	mechanicalWatch->findSwitzerlandWithSkeleton();
	cout << "|----------------------------------------------|" << endl;
	delete mechanicalWatch;
	return 0;
}
