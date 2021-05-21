#include "list.h"

int main()
{
	cout << "|===========<Quartz_Origin_list>===========|" << endl;
	list watchList;
	quartzWatches watchOne(false, "One", 1995, manufacturerStruct("Zodiac", "Germany"), CLASSIC, GRAPHENE, 400);
	watchList.addLink(&watchOne);
	quartzWatches watchTwo(true, "Two", 1000, manufacturerStruct("G-Shock", "Japan"), SPORT, LI_ION, 445);
	watchList.addLink(&watchTwo);
	quartzWatches watchTree(false, "Tree", 2400, manufacturerStruct("Rocket", "USSR"), CLASSIC, SOLAR, 95);
	watchList.addLink(&watchTree);
	watchList.showAll();
	cout << "|-------------------------------------------|" << endl;
	cout << "|========<Quartz_Watches_Under_1500>========|" << endl;
	watchList.findByPrice(1500);
	cout << "|-------------------------------------------|" << endl;
	cout << "|==========<Quartz_Classic_Watches>=========|" << endl;
	watchList.findClassicWatches();
	cout << "|-------------------------------------------|" << endl;
	mechanicalWatches watch1(false, "One", 1995, manufacturerStruct("Zodiac", "Switzerland"), CLASSIC, false, true);
	watchList.addLink(&watch1);
	mechanicalWatches watch2(true, "Two", 1000, manufacturerStruct("G-Shock", "Japan"), SPORT, true, false);
	watchList.addLink(&watch2);
	mechanicalWatches watch3(false, "Tree", 2400, manufacturerStruct("Rocket", "USSR"), CLASSIC, true, false);
	watchList.addLink(&watch3);
	watchList.showAll();
	return 0;
}
