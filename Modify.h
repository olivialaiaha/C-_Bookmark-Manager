#ifndef MODIFY_H
#define MODIFY_H

#include "Database.h"
#include <sstream>

class Modify
{
public:
	Modify(Database &theDatabase);
	void modify(vector<Bookmark>::iterator, string);
	void changeTopFo(string, string);
	void excute(char, string);
private:
	Database &database;
};
#endif // !MODIFY_H

