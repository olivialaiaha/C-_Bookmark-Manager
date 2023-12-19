#include "Database.h"

Database::Database()
{
	loadBookmarkFile();
}

Database::~Database()
{
	saveFile();
}

bool Database::existingName(string name){
	for (int i = 0; i < folders.size(); i++){
		if (folders[i].getName() == name){
			return true;
		}
	}
	return false;
}

int Database::getIndex(string topFo)
{
	int No = 0;
	for (int i = 0; i < bookmarks.size(); i++){
		if (bookmarks[i].getTopFo() == topFo){
			No++;
		}
	}
	for (int i = 0; i < folders.size(); i++){
		if (folders[i].getTopFo() == topFo){
			No++;
		}
	}
	return No;
}

string Database::findTopFo(int n, string folder)
{
	for (int i = 0; i < folders.size(); i++)
		if (folders[i].getName() == folder)
		{
			if (n == -1){
				return folders[i].getTopFo();
			}
			if (folders[i].getTopFo() != "top"){
				findTopFo(n, folders[i].getTopFo());
			}
			if (n != 0){
				cout << "   ";
			} else{
				cout << "[" << (folders[i].getIndex() + 1) << "]";
			}
			return"";
		}
	return"";
}

vector< Bookmark > Database::searchTags(string hashtag)
{
	vector< Bookmark > tmp;
	for (int i = 0, j = 1; i < bookmarks.size(); i++)
		if (bookmarks[i].getTags(hashtag))
		{
			tmp.push_back(bookmarks[i]);
			cout << "[" << j << "] ";
			bookmarks[i].output();
			j++;
		}
	return tmp;
}

vector<Bookmark>::iterator Database::bEnd(){
	return bookmarks.end();
}

vector< Folder >::iterator Database::fEnd(){
	return folders.end(); 
}

void Database::addBookmark(Bookmark newBookmark)
{
	bookmarks.push_back(newBookmark);
}

void Database::addFolder(Folder newFolder)
{
	folders.push_back(newFolder);
}

void Database::erase(int n, string folder)
{
	vector<Bookmark>::iterator itb = getBookmark(n, folder);
	vector<Folder>::iterator itf = getFolder(n, folder);
	if (itb != bEnd()){
		bookmarks.erase(itb);
	}
	if (itf != fEnd()){
		folders.erase(itf);
	}
}

vector<Bookmark>::iterator Database::getBookmark(int n, string folder)
{
	for (int i = 0; i < bookmarks.size(); i++){
		if (n == bookmarks[i].getIndex()){
			if (folder == bookmarks[i].getTopFo()){
				return(bookmarks.begin() + i);
			}
		}
	}
	return bookmarks.end();
}

string Database::moveFo(char i, string nowFolder){
	vector< Bookmark >::iterator itb = getBookmark((i - '1'), nowFolder);
	vector< Folder >::iterator itf = getFolder((i - '1'), nowFolder);
	if (itb != bEnd()){
		itb->openURL();
	}
	if (itf != fEnd()){
		return itf->getName();
	}
	return nowFolder;
}

vector<Folder>::iterator Database::getFolder(int n, string folder)
{
	for (vector<Folder>::iterator it = folders.begin(); it != folders.end(); ++it){
		if (n == it->getIndex()){
			if (folder == it->getTopFo()){
				return it;
			}
		}
	}
	return folders.end();
}

void Database::output(string nowFolder){
	cout << "+";
	for (int i = 0; i < 60; i++){
		cout << "-";
	}
	cout << "+\n";
	int num = getIndex(nowFolder);
	if (num == 0){
		findTopFo(0, nowFolder);
		cout << "[] None\n";
	}
	for (int i = 0; i < num; i++){
		findTopFo(i, nowFolder);
		cout << "[" << i + 1 << "] ";
		vector<Bookmark>::iterator itb = getBookmark(i, nowFolder);
		vector<Folder>::iterator itf = getFolder(i, nowFolder);
		if (itb != bEnd()){
			itb->output();
		}
		if (itf != fEnd()){
			itf->output();
		}
	}
	cout << "\n[a] add a folder or bookmark\n"
		<< "[d] delete a folder or bookmark\n"
		<< "[m] modify a folder or bookmark\n"
		<< "[s] use hash tag to search bookmarks\n"
		<< "[b] go back\n";
	if (num == 0){
		cout << "\nPlease a,d,m,s,b to do an action:\n";
	} else if (num == 1){
		cout << "Please select [1] to a open specific fold or bookmark or [a,d,m,s,b] to do an action:\n";
	} else{
		cout << "Please select [1-" << num << "] to a open specific fold or bookmark or [a,d,m,s,b] to do an action:\n";
	}
}

void Database::loadBookmarkFile()
{
	ifstream inBookMarkFile("BookMarks.txt", ios::in);
	if (!inBookMarkFile)
	{
		cout << "inBookMarkFile could not be opened.\n";
		system("pause");
		exit(1);
	}
	while (!inBookMarkFile.eof())
	{
		if (inBookMarkFile.eof())
			break;
		s_Bookmark buffer;
		inBookMarkFile.read(reinterpret_cast<char*>(&buffer), sizeof(s_Bookmark));
		if (!inBookMarkFile.eof())
			bookmarks.push_back(Bookmark(buffer.Comment, buffer.Name, buffer.URL, buffer.topFo, buffer.index, buffer.tag));
	}
	inBookMarkFile.close();
	ifstream inFolderFile("Folders.txt", ios::in);
	if (!inFolderFile)
	{
		cout << "inFolderFile could not be opened.\n";
		system("pause");
		exit(1);
	}
	while (!inFolderFile.eof())
	{
		if (inFolderFile.eof())
			break;
		s_Folder s_buffer;
		inFolderFile.read(reinterpret_cast<char*>(&s_buffer), sizeof(s_Folder));
		if (!inFolderFile.eof())
			folders.push_back(Folder(s_buffer.index, s_buffer.name, s_buffer.topFo));
	}
	inFolderFile.close();
}

void Database::saveFile()
{
	ofstream outBookmarkFile("Bookmarks.txt", ios::out);
	if (!outBookmarkFile)
	{
		cout << "outBookmarkFile could not be opened.\n";
		system("pause");
		exit(1);
	}
	
	for (int j = 0; j < bookmarks.size(); j++)
	{
		s_Bookmark buffer;
		buffer.index = bookmarks[j].getIndex();
		for (int i = 0; i < bookmarks[j].getTopFo().size(); i++){
			buffer.topFo[i] = bookmarks[j].getTopFo()[i];
		}
		for (int i = 0; i < bookmarks[j].getName().size(); i++){
			buffer.Name[i] = bookmarks[j].getName()[i];
		}
		for (int i = 0; i < bookmarks[j].getURL().size(); i++){
			buffer.URL[i] = bookmarks[j].getURL()[i];
		}
		for (int i = 0; i < bookmarks[j].getComment().size(); i++){
			buffer.Comment[i] = bookmarks[j].getComment()[i];
		}
		for (int i = 0; i < bookmarks[j].gettmpTags().size(); i++){
			buffer.tag[i] = bookmarks[j].gettmpTags()[i];
		}
		
		outBookmarkFile.write(reinterpret_cast<char*>(&buffer), sizeof(s_Bookmark));
	}
	outBookmarkFile.close();
	ofstream outFolderFile("Folders.txt", ios::out);
	if (!outFolderFile)
	{
		cout << "outFolderFile could not be opened.\n";
		system("pause");
		exit(1);
	}
	for (int i = 0; i < folders.size(); i++)
	{
		s_Folder buffer;
		buffer.index = folders[i].getIndex();
		for (int j = 0; j < folders[i].getTopFo().size(); j++){
			buffer.topFo[j] = folders[i].getTopFo()[j];
		}
		for (int j = 0; j < folders[i].getName().size(); j++){
			buffer.name[j] = folders[i].getName()[j];
		}
		outFolderFile.write(reinterpret_cast<char*>(&buffer), sizeof(s_Folder));
	}
	outFolderFile.close();
}
