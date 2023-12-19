#include <iostream>
#include"Add.h"
#include"Delete.h"
#include"Modify.h"
#include"Search.h"

int main()
{
	Database database;
	Add add(database);
	Delete erase(database);
	Modify modify(database);
	Search search(database);
	string nowFolder = "top";
	while (true)
	{
		database.output(nowFolder);
		string input;
		cin >> input;
		switch (input[0])
		{
		case'a':
			add.excute(nowFolder);
			break;
		case'd':
			erase.excute(input[1], nowFolder);
			break;
		case'm':
			modify.excute(input[1], nowFolder);
			break;
		case's':
			search.excute();
			break;
		case'b':
			if (nowFolder == "top")
			{
				cout << "\nFinish...\n";
				system("pause");
				return 0;
			}
			nowFolder = database.findTopFo(-1, nowFolder);
			cout << "\n";
			break;
		default:
			nowFolder = database.moveFo(input[0], nowFolder);
			cout << "\n";
		}
	}
}