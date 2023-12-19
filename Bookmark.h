#ifndef BOOKMARK_H
#define BOOKMARK_H
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

class Bookmark
{
public:
	Bookmark(string C = "", string N  = "", string U = "", string F = "top", int I = 0, string T = "") :index(I), topFo(F), Comment(C), Name(N), URL(U){ 
		setTags(T);
	}
	int getIndex();
	int getTagsSize();
	bool getTags(string hash);
	string getTopFo();
	string getName();
	string getURL();
	string gettmpTags();
	string getTag(int index);
	string getComment();
	void setIndex(int I);
	void setTopFo(string F);
	void setName(string N);
	void setURL(string U);
	void setComment(string C);
	void setTags(string tag);
	void addTag(string tag);
	void output();
	void outputTags();
	void openURL();
private:
	int index;
	string topFo;
	string Name;
	string URL;
	vector<string> Tags;
	string tmpTags;
	string Comment;
};

struct s_Bookmark
{
	int index;
	char topFo[20] = "";
	char Name[20] = "";
	char URL[100] = "";
	char tag[100] = "";
	char Comment[100] = "";
};

#endif // !BOOKMARK_H

