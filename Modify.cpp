#include "Modify.h"

Modify::Modify(Database & theDatabase):database(theDatabase)
{
}

void Modify::modify(vector<Bookmark>::iterator itb, string nowFolder)
{
	Bookmark tmp;
	string input;
	cout << "= bookmark Name: " << itb->getName() << "\nPlease input new bookmark name:\n";
	cin.ignore();
	getline(cin, input);
	tmp.setIndex(itb->getIndex());
	tmp.setTopFo(nowFolder);
	tmp.setName(input);
	cout << "= bookmark url: " << itb->getURL() << "\nPlease input new url:\n";
	getline(cin, input);
	tmp.setURL(input);
	cout << "= Hash tag: ";
	itb->outputTags();
	cout << "\nPlease input new hash tag:\n";
	getline(cin, input);
	tmp.setTags(input);
	cout << "= bookmark comment: " << itb->getComment() << "\nPlease input new comment:\n";
	getline(cin, input);
	tmp.setComment(input);
	database.erase(itb->getIndex(), nowFolder);
	database.addBookmark(tmp);
}

void Modify::changeTopFo(string folder, string newFolder)
{
	vector<Bookmark>::iterator itb;
	vector<Folder>::iterator itf;
	for (int i = 0; i < database.getIndex(folder); i++)
	{
		itb = database.getBookmark(i, folder);
		itf = database.getFolder(i, folder);
		if (itb != database.bEnd()){
			itb->setTopFo(newFolder);
		}
		if (itf != database.fEnd()){
			itf->setTopFo(newFolder);
		}
	}
}

void Modify::excute(char item, string nowFolder){
	vector<Bookmark>::iterator itb = database.getBookmark((item - '1'), nowFolder);
	vector<Folder>::iterator itf = database.getFolder((item - '1'), nowFolder);
	if (itb != database.bEnd()){
		modify(itb, nowFolder);
	}
	if (itf != database.fEnd()){
		cout << "\n= Folder name: " << itf->getName() << "\nPlease input new folder name:\n";
		string input;
		cin.ignore();
		getline(cin, input);
		if (database.existingName(input)){
			cout << "The folder was existed!\n";
			return;
		}
		changeTopFo(itf->getName(), input);
		itf->setName(input);
	}
	cout << "\n";
}
