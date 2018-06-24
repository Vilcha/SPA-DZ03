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

void init_points(point& s, point& e) {
	cout << "Upisite stupac tocke A (1-50): "; cin >> s.s;
	cout << "Upisite redak tocke A (1-25): "; cin >> s.r;
	cout << "Upisite stupac tocke B (1-50): "; cin >> e.s;
	cout << "Upisite redak tocke B (1-25): "; cin >> e.r;
}

int main() {
	point start, current, end;
	bool done = false;
	string board[27][52];

	init_points(start, end);

	if (start.s < 1 || start.s > 50 || start.r < 1 || start.r > 25 || end.s < 1 || end.s > 50 || end.r < 1 || end.r > 25)
	{
		system("cls");
		cout << "Krivo unesena vrijednost. " << endl;
		return 1;
	}
	current = start;
	board[4][20] = "# "; board[5][20] = "# "; board[6][20] = "# "; board[7][20] = "# "; board[8][20] = "# "; board[9][20] = "# ";
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
		{
		if (board[current.r][current.s - 1] == "# " || board[current.r][current.s + 1] == "# ")
			if (board[current.r + 1][current.s] == "# ")
				current.r--;
			else if (board[current.r - 1][current.s] == "# ")
				current.r++;
		}

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