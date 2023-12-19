#ifndef ADD_H
#define ADD_H

#include "Database.h"
#include <sstream>

class Add
{
public:
	Add(Database &theDatabase);
	void excute(string);
private:
	Database &database;
};

#endif // !ADD_H

