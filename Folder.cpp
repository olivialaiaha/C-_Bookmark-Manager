#include "Folder.h"

int Folder::getIndex(){ 
	return index; 
}

string Folder::getTopFo(){ 
	return topFo; 
}

string Folder::getName(){ 
	return Name; 
}

void Folder::setIndex(int i){ 
	index = i; 
}

void Folder::setTopFo(string f){ 
	topFo = f; 
}

void Folder::setName(string n){ 
	Name = n; 
}

void Folder::output(){ 
	cout << "+ " << Name << endl; 
}