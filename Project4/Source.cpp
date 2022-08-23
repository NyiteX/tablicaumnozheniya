#include <iostream>
#include <conio.h>
#include <string>
using namespace std;

bool Proverka(string A)
{
	for (int i = 0; i < A.size(); i++)
		if (isdigit(A[i]) == 0)
			return 0;
	return 1;
}

class Tab
{
	int x, y;
	int kolotvet, kolpop, maxkolpop;
public:
	Tab()
	{
		kolotvet = 0;
		kolpop = 0;
		maxkolpop = 10;
	}
	void Menu()
	{
		while (kolpop < maxkolpop)
		{
			++kolpop;
			x = rand() % 9 + 1;
			y = rand() % 9 + 1;
			string str = "adawek";
			while (Proverka(str) == 0)
			{
				cout << x << "*" << y << "\nEnter result: ";
				cin >> str;
				if (Proverka(str) == 0)
					cout << "Wrong input.\n\n";
			}
			if (stoi(str) == x * y)
				kolotvet++;
			cout << endl;
		}
		cout << endl;
		if (kolotvet == maxkolpop)
			cout << "Perfect.\n" << "Ur result = " << kolotvet << endl;
		if (kolotvet < 10 && kolotvet>7)
			cout << "Good.\n" << "Ur result = " << kolotvet << endl;
		if (kolotvet > 5 && kolotvet < 8)
			cout << "Not bad.\n"<<"Ur result = "<<kolotvet<<endl;
		if(kolotvet < 6)
			cout << "You suck.\n"<<"Ur result = "<<kolotvet<<endl;
		if(kolpop >= maxkolpop)
		{
			char vvod;
			cout << "\nWanna try to play again ?\n";
			cout << "1. Try again.\n2. Exit.\n";
			vvod = _getch();
			if (vvod == '1')
			{
				kolotvet = 0;
				kolpop = 0;
				system("cls");
				Menu();
			}
			else
				cout << "\n=(\n";
		}
	}
};

void main()
{
	srand(time(0));

	Tab A;
	A.Menu();
}