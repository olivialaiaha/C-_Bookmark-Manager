#include "Add.h"

Add::Add(Database & theDatabase):database(theDatabase)
{
}

void Add::excute(string nowFolder)
{
	cout << "[f] add a folder\n"
		<< "[b] add a bookmark\n"
		<< "Please choose one:\n";
	string input;
	cin >> input;
	if (input == "f")
	{
		cout << "Please input folder name:\n";
		cin.ignore();
		getline(cin, input);
		if (database.existingName(input))
		{
			cout << "The folder was existed!\n";
			return;
		}
		Folder tmp(database.getIndex(nowFolder), input, nowFolder);
		database.addFolder(tmp);
	}
	else if (input == "b")
	{
		Bookmark tmp;
		tmp.setIndex(database.getIndex(nowFolder));
		tmp.setTopFo(nowFolder);
		cout << "Please input bookmark name:\n";
		cin.ignore();
		getline(cin, input);
		tmp.setName(input);
		cout << "Please input bookmark url:\n";
		getline(cin, input);
		tmp.setURL(input);
		cout << "Please input hash tags:\n";
		getline(cin, input);
		tmp.setTags(input);
		cout << "Pleace input comments:\n";
		getline(cin, input);
		tmp.setComment(input);
		database.addBookmark(tmp);
	}
	cout << "\n";
}
