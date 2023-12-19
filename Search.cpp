#include "Search.h"

Search::Search(Database & theDatabase):database(theDatabase)
{
}

void Search::excute()
{
	cout << "Please input hash tag:\n";
	string input;
	cin >> input;
	vector< Bookmark > tmp = database.searchTags(input);
	if (tmp.size() == 0)
	{
		cout << "Can't find the tag!\n";
		return;
	}
	if (tmp.size() == 1){
		cout << "Please select [1] to open specific bookmark:\n";
	} else{
		cout << "Please select [1-" << tmp.size() << "] to open specific bookmark:\n";
	}
	cin >> input;
	tmp[(input[0] - '1')].openURL();
	cout << "\n";
}
