#ifndef SEARCH_H
#define SEARCH_H

#include "Database.h"
#include <iostream>

class Search
{
public:
	Search(Database &theDatabase);
	void excute();
private:
	Database &database;
};

#endif // !SEARCH_H

