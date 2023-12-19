#include "Delete.h"

Delete::Delete(Database & theDatabase):database(theDatabase)
{
}

void Delete::excute(char item, string nowFolder)
{
	vector<Bookmark>::iterator itb = database.getBookmark((item - '1'), nowFolder);
	vector<Folder>::iterator itf = database.getFolder((item - '1'), nowFolder);
	string input;
	if (itb != database.bEnd()){
		itb->output();
		cout << "Do you really want to delete this bookmark? [y for Yes, n for No]\n";
		cin >> input;
		if (input == "y"){
			erase((item - '1'), nowFolder);
		}
	}
	if (itf != database.fEnd()){
		if (database.getIndex(itf->getName()) != 0){
			cout << "The folder [" << itf->getName() << "] is no empty, can not remove it\n";
		} else{
			itf->output();
			cout << "Do you really want to delete this folder? [y for Yes, n for No]\n";
			cin >> input;
			if (input == "y"){
				erase((item - '1'), nowFolder);
			}
		}
	}
	cout << "\n";
}

void Delete::erase(int n, string folder)
{
	vector<Bookmark>::iterator itb;
	vector<Folder>::iterator itf;
	database.erase(n, folder);
	for (int i = n ; i <= database.getIndex(folder); i++){
		itb = database.getBookmark(i + 1, folder);
		itf = database.getFolder(i + 1, folder);
		if (itb != database.bEnd()){
			itb->setIndex(i);
		}
		if (itf != database.fEnd()){
			itf->setIndex(i);
		}
	}
}
