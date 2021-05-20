#include "list.h"

int main()
{
	list *watchList = new list;
	watchList->readFromFile("./assets/input.txt");
	cout << "|===============<Origin_list>===============|" << endl;
	cout << *watchList;
	cout << "|-------------------------------------------|" << endl;
	cout << "|==========<List_redden_from_file>==========|" << endl;
	cout << "|-------------------------------------------|" << endl;
	watchList->writeToFile("./dist/output.txt");
	delete watchList;
	return 0;
}
