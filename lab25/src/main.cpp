#include "list.h"

int main()
{
	list *watchList = new list;
	cout << "|==========<List_redden_from_file>==========|" << endl;
	watchList->readFromFile("../assets/input.txt");
	cout << *watchList;
	cout << "|-------------------------------------------|" << endl;
	cout << "|==============<Overloaded '='>=============|" << endl;
	watch watchOne(true, "ZO9507", 1995, manufacturerStruct("Zodiac", "Germany"), CLASSIC);
	watch watchTree;
	watchTree = watchOne;
	cout << watchTree;
	cout << "|-------------------------------------------|" << endl;

	watchList->writeToFile("../dist/output.txt");
	delete watchList;
	return 0;
}
