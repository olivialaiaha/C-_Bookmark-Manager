#ifndef DELDTE_H
#define DELETE_H

#include "Database.h"

class Delete
{
public:
	Delete(Database &theDatabase);
	void excute(char, string);
	void erase(int, string);
private:
	Database &database;
};

#endif // !DELDTE_H

