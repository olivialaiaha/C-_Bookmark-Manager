#ifndef DATABASE_H
#define DATABASE_H

#include <fstream>
#include "Bookmark.h"
#include "Folder.h"
using namespace std;

class Database
{
public:
	Database();
	~Database();
	int getIndex(string topFo);
	string moveFo(char, string);
	void output(string);
	bool existingName(string);
	string findTopFo(int, string);
	void addBookmark(Bookmark newBookmark);
	void addFolder(Folder newFolder);
	void erase(int, string);
	vector< Bookmark > searchTags(string);
	vector<Bookmark>::iterator bEnd();
	vector< Folder >::iterator fEnd();
	vector< Bookmark >::iterator getBookmark(int, string folder);
	vector< Folder >::iterator getFolder(int, string folder);
private:
	vector< Bookmark > bookmarks;
	vector< Folder > folders;
	void loadBookmarkFile();
	void saveFile();
};

#endif // DATABASE_H

