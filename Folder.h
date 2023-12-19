#ifndef FOLDER_H
#define FOLDER_H

#include <iostream>
#include <string>
using namespace std;

class Folder
{
public:
	Folder(int n = 0, string name = "", string f = "top"): index(n), topFo(f), Name(name){};
	int getIndex();
	string getTopFo();
	string getName();
	void setIndex(int i);
	void setTopFo(string f);
	void setName(string n);
	void output();
private:
	int index;
	string topFo;
	string Name;
};

struct s_Folder
{
	int index;
	char topFo[20] = "";
	char name[20] = "";
};

#endif // !FOLDER_H

