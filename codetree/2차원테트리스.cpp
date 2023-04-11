#include <iostream>

#define MAX 5

using namespace std;

int k;
int Red[4][6];
int Yellow[6][4];
pair <int, int> tile[3][2] = { {{0,0}}, {{0,0}, {0,1}}, {{0,0},{1,0}} };
int score = 0;
void PrintRed()
{
	cout << "Red\n";
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			cout << Red[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}

void PrintYellow()
{
	cout << "Yellow\n";
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			cout << Yellow[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}
void deleteColumn(int num)
{
	for (int j = num-1; j >= 0; j--)
	{
		for (int i = 0; i < 4; i++)
		{
			Red[i][j + 1] = Red[i][j];
		}
	}
	for (int i = 0; i < 4; i++)
	{
		Red[i][0] = 0;
	}
}
void deleteColumns(int cnt)
{
	for (int j = 5 - cnt; j >= 0; j--)
	{
		for (int i = 0; i < 4; i++)
		{
			Red[i][j+cnt] = Red[i][j];
		}
	}

	for (int j = 0; j < cnt; j++)
	{
		for (int i = 0; i < 4; i++)
		{
			Red[i][1-j] = 0;
		}
	}
}
void checkColumn()
{
	for (int i = 2; i < 6; i++)
	{
		bool isFull = true;
		for (int j = 0; j < 4; j++)
		{
			if (!Red[j][i]) isFull = false;
		}

		if (isFull) {
			score++;
			deleteColumn(i);
		}
	}
}
void deleteWhiteRed()
{
	int max_cnt = 0;
	for (int i = 0; i < 4; i++)
	{
		int cnt = 0;
		for (int j = 0; j < 2; j++)
		{
			if (Red[i][j]) cnt++;
		}
		if (max_cnt < cnt) {
			max_cnt = cnt;
		}
		if (max_cnt == 2) break;
	}
	if(max_cnt > 0) deleteColumns(max_cnt);
}
void moveRed(int t, int x, int y)
{
	pair <int, int> p1 = make_pair(-1,-1); 
	pair <int, int> p2 = make_pair(-1,-1);
	if (t == 0)
	{
		p1.first = x + tile[t][0].first;
		p1.second = y + tile[t][0].second;
		for (int i = 0; i <= 5; i++)
		{
			if (Red[p1.first][p1.second])
			{
				p1.second--;
				break;
			}
			if (p1.second == 5) break;
			p1.second++;
		}
		//cout << t << " : " << p1.first << " " << p1.second << "\n";
		Red[p1.first][p1.second] = 1;
	}
	else {
		p1.first = x + tile[t][0].first;
		p1.second = y + tile[t][0].second;
		p2.first = x + tile[t][1].first;
		p2.second = y + tile[t][1].second;

		for (int i = 0; i <= 5; i++)
		{
			if (Red[p1.first][p1.second] || Red[p2.first][p2.second])
			{
				p1.second--;
				p2.second--;
				break;
			}
			if (p2.second == 5) break;
			p1.second++;
			p2.second++;
		}
		//cout << t << " : " << p1.first << " " << p1.second << "\n";
		Red[p1.first][p1.second] = 1;
		Red[p2.first][p2.second] = 1;
	}
	/*cout << "New\n";
	PrintRed();*/
	// 열삭제
	checkColumn();
	/*cout << "checkColumn\n";
	PrintRed();*/
	// 연한칸 삭제
	deleteWhiteRed();
	/*cout << "deleteWhiteRed\n";
	PrintRed();*/

}
void deleteRow(int num)
{
	for (int i = num - 1; i >= 0; i--)
	{
		for (int j = 0; j < 4; j++)
		{
			Yellow[i+1][j] = Yellow[i][j];
		}
	}
	for (int i = 0; i < 4; i++)
	{
		Yellow[0][i] = 0;
	}
}
void deleteRows(int cnt)
{
	for (int i = 5 - cnt; i >= 0; i--)
	{
		for (int j = 0; j < 4; j++)
		{
			Yellow[i+cnt][j] = Yellow[i][j];
		}
	}

	for (int i = 0; i < cnt; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			Yellow[1-i][j] = 0;
		}
	}
}
void checkRow()
{
	for (int i = 2; i < 6; i++)
	{
		bool isFull = true;
		for (int j = 0; j < 4; j++)
		{
			if (!Yellow[i][j]) isFull = false;
		}

		if (isFull) {
			score++;
			deleteRow(i);
		}
	}
}
void deleteWhiteYellow()
{
	int max_cnt = 0;
	for (int j = 0; j < 4; j++)
	{
		int cnt = 0;
		for (int i = 0; i < 2; i++)
		{
			if (Yellow[i][j]) cnt++;
		}
		if (max_cnt < cnt) {
			max_cnt = cnt;
		}
		if (max_cnt == 2) break;
	}
	if (max_cnt > 0) deleteRows(max_cnt);
}
void moveYellow(int t, int x, int y)
{
	pair <int, int> p1 = make_pair(-1, -1);
	pair <int, int> p2 = make_pair(-1, -1);

	if (t == 0)
	{
		p1.first = x + tile[t][0].first;
		p1.second = y + tile[t][0].second;
		for (int i = 0; i <= 5; i++)
		{
			if (Yellow[p1.first][p1.second])
			{
				p1.first--;
				break;
			}
			if (p1.first == 5) break;
			p1.first++;
		}
		//cout << t << " : " << p1.first << " " << p1.second << "\n";
		Yellow[p1.first][p1.second] = 1;
	}
	else {
		p1.first = x + tile[t][0].first;
		p1.second = y + tile[t][0].second;
		p2.first = x + tile[t][1].first;
		p2.second = y + tile[t][1].second;

		for (int i = 0; i <= 5; i++)
		{
			if (Yellow[p1.first][p1.second] || Yellow[p2.first][p2.second])
			{
				p1.first--;
				p2.first--;
				break;
			}
			if (p2.first == 5) break;
			p1.first++;
			p2.first++;
		}
		//cout << t << " : " << p1.first << " " << p1.second << "\n";
		Yellow[p1.first][p1.second] = 1;
		Yellow[p2.first][p2.second] = 1;
	}

	/*cout << "New\n";
	PrintYellow();*/
	// 열삭제
	checkRow();
	/*cout << "checkRow\n";
	PrintYellow();*/
	// 연한칸 삭제
	deleteWhiteYellow();
	/*cout << "deleteWhiteYellow\n";
	PrintYellow();*/

}
int calc()
{
	int blank = 0;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			if (Red[i][j]) blank++;
		}
	}

	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (Yellow[i][j]) blank++;
		}
	}
	return blank;
}
int main()
{
	cin >> k;
	while (k--)
	{
		int t, x, y;
		cin >> t >> x >> y;
		t--;

		//cout << "start: " << t << " " << x << " " << y << "\n";
		moveRed(t,x,0);
		moveYellow(t,0,y);
	}

	cout << score << "\n";
	cout << calc() << "\n";
}