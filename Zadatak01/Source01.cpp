#include <iostream>
#include <chrono>
#include <thread>
#include <string>

using namespace std;

struct point
{
	int s = 0;
	int r = 0;
};

int main() {
	point start, current, end;
	bool done = false;
	string board[27][52];
	
	cout << "Upisite stupac tocke A (1-50): "; cin >> start.s;
	cout << "Upisite redak tocke A (1-25): "; cin >> start.r;
	cout << "Upisite stupac tocke B (1-50): "; cin >> end.s;
	cout << "Upisite redak tocke B (1-25): "; cin >> end.r;
	current = start;

	while (!done)
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
		if ((end.r - current.r) > 0 && board[current.r + 1][current.s] != "# ")
			current.r++;
		else if ((end.r - current.r) < 0 && board[current.r + 1][current.s] != "# ")
			current.r--;
		if ((end.s - current.s) > 0 && board[current.r][current.s + 1] != "# ")
			current.s++;
		else if ((end.s - current.s) < 0 && board[current.r][current.s + 1] != "# ")
			current.s--;

		system("cls");
		for (int i = 0; i < 27; i++)
		{
			for (int j = 0; j < 52; j++)
			{
				if (start.r == i && start.s == j)
					board[i][j] = "A ";
				else if (end.r == i && end.s == j)
					board[i][j] = "B ";
				else if (i == 0 || j == 0 || i == 26 || j == 51)
					board[i][j] = "# ";
				else if (current.r == end.r && current.s == end.s)
					done = true;
				else
				{
					if (board[i][j] != "A " && board[i][j] != "B " && board[i][j] != "# ")
						board[i][j] = "- ";
					board[current.r][current.s] = "X ";
				}
				cout << board[i][j];
			}
			cout << endl;
		}
	}

	cout << endl;
	return 0;
}