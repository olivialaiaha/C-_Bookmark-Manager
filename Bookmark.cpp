#include "Bookmark.h"

int Bookmark::getIndex(){ 
	return index; 
}

int Bookmark::getTagsSize(){ 
	return Tags.size(); 
}

bool Bookmark::getTags(string hash){
	if (tmpTags.find(hash) != -1){
		return true;
	}
	return false;
}

string Bookmark::getTopFo(){ 
	return topFo; 
}

string Bookmark::getName(){ 
	return Name; 
}

string Bookmark::getURL(){ 
	return URL; 
}

string Bookmark::gettmpTags(){ 
	return tmpTags; 
}

string Bookmark::getTag(int index){ 
	return Tags[index]; 
}

string Bookmark::getComment(){ 
	return Comment; 
}

void Bookmark::setIndex(int I){ 
	index = I; 
}

void Bookmark::setTopFo(string F){ 
	topFo = F; 
}

void Bookmark::setName(string N){ 
	Name = N; 
}

void Bookmark::setURL(string U){ 
	URL = U; 
}

void Bookmark::setComment(string C){ 
	Comment = C; 
}

void Bookmark::setTags(string tag){
	tmpTags = tag;
	stringstream buffer;
	buffer << tmpTags;
	while (getline(buffer, tag, ',')){
		if (tag[0] == ' '){
			for (int i = 1; i < tag.size(); i++){
				tag[i - 1] = tag[i];
			}
			tag[tag.size() - 1] = '\0';
		}
		Tags.push_back(tag);
	}
}

void Bookmark::addTag(string tag){ 
	Tags.push_back(tag); 
}

void Bookmark::output(){
	cout << "- [" << Name << "] (" << URL << ")";
	outputTags();
	cout << " {" << Comment << "}\n";
}

void Bookmark::outputTags(){
	for (int i = 0; i < Tags.size(); i++){
		cout << " #" << Tags[i];
	}
}

void Bookmark::openURL(){
	cout << "open bookmark url(" << URL << ")\n";
	system(("start chrome \"" + URL + "\"").c_str());
}