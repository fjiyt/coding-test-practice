#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>
#include <string>
#include <cstring>
#include <limits>
#include <set>
int n, m, k, t;
int h;

int dx[] = { 0,0,1,-1 };
int dy[] = { -1,1,0,0 };

using namespace std;

vector<vector<int>> a(100, vector<int>(100));
int map[100][100];
int gcnt[1000];
int gnum[1000];
int injup[100][100];

int g;


void print(vector<vector<int>> a, int n) {

	cout << '\n';
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cout << a[i][j] << ' ';
		}
		cout << '\n';
	}


}

long long ans = 0;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	cin >> n;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> a[i][j];
		}
	}
	k = 4;
	while (k--) {
		memset(map, -1, sizeof(map));
		memset(gcnt, 0, sizeof(gcnt));
		memset(gnum, -1, sizeof(gnum));
		memset(injup, 0, sizeof(injup));

		g = 0;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if (map[i][j] == -1) {
					int num = a[i][j];
					queue<pair<int, int>> q;
					map[i][j] = g;
					gcnt[g] = 1;
					gnum[g] = num;
					q.emplace(i, j);
					while (!q.empty()) {
						int x, y;
						tie(x, y) = q.front();
						q.pop();
						for (int k = 0; k < 4; ++k) {
							int nx = x + dx[k];
							int ny = y + dy[k];

							if (0 <= nx && nx < n && 0 <= ny && ny < n && a[nx][ny] == num && map[nx][ny]==-1) {
								map[nx][ny] = g;
								gcnt[g] += 1;
								q.emplace(nx, ny);
							}
						}

					}

					g += 1;
				}
			}
		}

		for (int i = 0; i < n; ++i) {	///////////////////////////////오답 가능성 있는 부분
			for (int j = 0; j < n; ++j) {
				int gn = map[i][j];
				for (int k = 0; k < 4; ++k) {
					int nx = i + dx[k];
					int ny = j + dy[k];
					if (0 <= nx && nx < n && 0 <= ny && ny < n && map[nx][ny] != gn) {
						injup[gn][map[nx][ny]] += 1;
					}
				}
			}
		}
		long long sum = 0;
		vector<vector<bool>> check(1000, vector<bool>(1000, false));
		set<pair<int, int>> st;
		for (int i = 0; i < g; ++i) {
			for (int j = 0; j < g; ++j) {
				bool flag = false;
				if (i == j) continue;
				if (i < j) {
					flag = st.count({ i,j });
				}
				else {
					flag = st.count({ j,i });
				}
				if (flag == false) {
					if (i < j) st.emplace(i, j);
					else st.emplace(j, i);
					check[i][j] = true;
					check[j][i] = true;
					sum += (gcnt[i] + gcnt[j]) * gnum[i] * gnum[j] * injup[i][j];
				}
			}
		}
		ans += sum;

		///////////////////////////////회전


		vector<vector<int>> b(100, vector<int>(100));


		vector<int> tmp;
		int hf = n / 2;
		for (int i = 0; i < n; ++i) tmp.emplace_back(a[hf][i]);
		reverse(tmp.begin(), tmp.end());
		int cnt = 0;
		for (int i = 0; i < n; ++i) b[i][hf] = tmp[cnt++];

		tmp.clear();
		for (int i = 0; i < n; ++i) tmp.emplace_back(a[i][hf]);
		cnt = 0;

		for (int i = 0; i < n; ++i) b[hf][i] = tmp[cnt++];




		int subsize = (n - 1) / 2;
		vector<vector<int>> sub(subsize, vector<int>(subsize));
		vector<vector<int>> sub2(subsize, vector<int>(subsize));

		//for (int i = 0; i < subsize; ++i) {
		//	for (int j = 0; j <subsize; ++j) {
		//		b[i][j] = a[i][subsize-1-j];

		//	}
		//}


		for (int i = 0; i < subsize; ++i) {
			for (int j = 0; j < subsize; ++j) {
				sub[i][j] = a[i][j];

			}
		}

		for (int i = 0; i < subsize; ++i) {
			for (int j = 0; j < subsize; ++j) {
				sub2[i][j] = sub[subsize - 1 - j][ i];
			}
		}

		//print(sub, subsize);

		for (int i = 0; i < subsize; ++i) {
			for (int j = 0; j < subsize; ++j) {
				b[i][j] = sub2[i][j];

			}
		}


		//print(sub2, subsize);



		for (int i = 0; i < subsize; ++i) {
			for (int j = hf+1; j < hf+1+subsize; ++j) {
				sub[i][j-(hf+1)] = a[i][j];

			}
		}

		for (int i = 0; i < subsize; ++i) {
			for (int j = 0; j < subsize; ++j) {
				sub2[i][j] = sub[subsize - 1 - j][i];

			}
		}


		for (int i = 0; i < subsize; ++i) {
			for (int j = hf + 1; j < hf + 1 + subsize; ++j) {
				b[i][j] = sub2[i][j - (hf + 1)];

			}
		}


		//print(sub2, subsize);

		for (int i = hf+1; i < subsize+hf+1; ++i) {
			for (int j = 0; j < subsize; ++j) {
				sub[i-(hf+1)][j] = a[i][j];

			}
		}

		for (int i = 0; i < subsize; ++i) {
			for (int j = 0; j < subsize; ++j) {
				sub2[i][j] = sub[subsize - 1 - j][i];

			}
		}

		for (int i = hf + 1; i < subsize + hf + 1; ++i) {
			for (int j = 0; j < subsize; ++j) {
				b[i][j] = sub2[i - (hf + 1)][j];

			}
		}

		//print(sub2, subsize);

		for (int i = hf + 1; i < subsize + hf + 1; ++i) {
			for (int j = hf + 1; j < hf + 1 + subsize; ++j) {
				sub[i - (hf + 1)][j-(hf+1)] = a[i][j];

			}
		}

		for (int i = 0; i < subsize; ++i) {
			for (int j = 0; j < subsize; ++j) {
				sub2[i][j] = sub[subsize - 1 - j][i];

			}
		}

		for (int i = hf + 1; i < subsize + hf + 1; ++i) {
			for (int j = hf + 1; j < hf + 1 + subsize; ++j) {
				b[i][j] = sub2[i - (hf + 1)][j - (hf + 1)];

			}
		}


		//print(sub2, subsize);


		//print(b, n);


		a = b;
	}





	cout << ans << '\n';


	return 0;
}
테스트 케이스는 다 맞고 논리도 다 맞는것 같은데, 런타임 에러가 제출하면 나서 난항을 겪고 있습니다. 배열의 범위를 벗어나서 런타임 에러가 난 것 같은데, 어디서 배열의 인덱스를 벗어난지를 모르겠습니다.

넉살 좋은 머루

작성자
4 months ago


Like
1
Dislike
29 x 29 == 841인데 제가 배열 범위를 100으로 잡아서 생긴 문제였습니다.


익명으로 댓글달기
런타임 에러 질문
제목
익명으로 질문하기
```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>
#include <string>
#include <cstring>
#include <limits>
#include <set>
int n, m, k, t;
int h;

int dx[] = { 0,0,1,-1 };
int dy[] = { -1,1,0,0 };

using namespace std;

vector<vector<int>> a(100, vector<int>(100));
int map[100][100];
int gcnt[1000];
int gnum[1000];
int injup[100][100];

int g;


void print(vector<vector<int>> a, int n) {

	cout << '\n';
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cout << a[i][j] << ' ';
		}
		cout << '\n';
	}








}

long long ans = 0;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	cin >> n;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> a[i][j];
		}
	}
	k = 4;
	while (k--) {
		memset(map, -1, sizeof(map));
		memset(gcnt, 0, sizeof(gcnt));
		memset(gnum, -1, sizeof(gnum));
		memset(injup, 0, sizeof(injup));

		g = 0;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if (map[i][j] == -1) {
					int num = a[i][j];
					queue<pair<int, int>> q;
					map[i][j] = g;
					gcnt[g] = 1;
					gnum[g] = num;
					q.emplace(i, j);
					while (!q.empty()) {
						int x, y;
						tie(x, y) = q.front();
						q.pop();
						for (int k = 0; k < 4; ++k) {
							int nx = x + dx[k];
							int ny = y + dy[k];

							if (0 <= nx && nx < n && 0 <= ny && ny < n && a[nx][ny] == num && map[nx][ny]==-1) {
								map[nx][ny] = g;
								gcnt[g] += 1;
								q.emplace(nx, ny);
							}
						}

					}

					g += 1;
				}
			}
		}

		for (int i = 0; i < n; ++i) {	///////////////////////////////오답 가능성 있는 부분
			for (int j = 0; j < n; ++j) {
				int gn = map[i][j];
				for (int k = 0; k < 4; ++k) {
					int nx = i + dx[k];
					int ny = j + dy[k];
					if (0 <= nx && nx < n && 0 <= ny && ny < n && map[nx][ny] != gn) {
						injup[gn][map[nx][ny]] += 1;
					}
				}
			}
		}
		long long sum = 0;
		vector<vector<bool>> check(1000, vector<bool>(1000, false));
		set<pair<int, int>> st;
		for (int i = 0; i < g; ++i) {
			for (int j = 0; j < g; ++j) {
				bool flag = false;
				if (i == j) continue;
				if (i < j) {
					flag = st.count({ i,j });
				}
				else {
					flag = st.count({ j,i });
				}
				if (flag == false) {
					if (i < j) st.emplace(i, j);
					else st.emplace(j, i);
					check[i][j] = true;
					check[j][i] = true;
					sum += (gcnt[i] + gcnt[j]) * gnum[i] * gnum[j] * injup[i][j];
				}
			}
		}
		ans += sum;

		///////////////////////////////회전


		vector<vector<int>> b(100, vector<int>(100));


		vector<int> tmp;
		int hf = n / 2;
		for (int i = 0; i < n; ++i) tmp.emplace_back(a[hf][i]);
		reverse(tmp.begin(), tmp.end());
		int cnt = 0;
		for (int i = 0; i < n; ++i) b[i][hf] = tmp[cnt++];

		tmp.clear();
		for (int i = 0; i < n; ++i) tmp.emplace_back(a[i][hf]);
		cnt = 0;

		for (int i = 0; i < n; ++i) b[hf][i] = tmp[cnt++];




		int subsize = (n - 1) / 2;
		vector<vector<int>> sub(subsize, vector<int>(subsize));
		vector<vector<int>> sub2(subsize, vector<int>(subsize));

		//for (int i = 0; i < subsize; ++i) {
		//	for (int j = 0; j <subsize; ++j) {
		//		b[i][j] = a[i][subsize-1-j];

		//	}
		//}


		for (int i = 0; i < subsize; ++i) {
			for (int j = 0; j < subsize; ++j) {
				sub[i][j] = a[i][j];

			}
		}

		for (int i = 0; i < subsize; ++i) {
			for (int j = 0; j < subsize; ++j) {
				sub2[i][j] = sub[subsize - 1 - j][ i];
			}
		}

		//print(sub, subsize);

		for (int i = 0; i < subsize; ++i) {
			for (int j = 0; j < subsize; ++j) {
				b[i][j] = sub2[i][j];

			}
		}


		//print(sub2, subsize);



		for (int i = 0; i < subsize; ++i) {
			for (int j = hf+1; j < hf+1+subsize; ++j) {
				sub[i][j-(hf+1)] = a[i][j];

			}
		}

		for (int i = 0; i < subsize; ++i) {
			for (int j = 0; j < subsize; ++j) {
				sub2[i][j] = sub[subsize - 1 - j][i];

			}
		}


		for (int i = 0; i < subsize; ++i) {
			for (int j = hf + 1; j < hf + 1 + subsize; ++j) {
				b[i][j] = sub2[i][j - (hf + 1)];

			}
		}


		//print(sub2, subsize);

		for (int i = hf+1; i < subsize+hf+1; ++i) {
			for (int j = 0; j < subsize; ++j) {
				sub[i-(hf+1)][j] = a[i][j];

			}
		}

		for (int i = 0; i < subsize; ++i) {
			for (int j = 0; j < subsize; ++j) {
				sub2[i][j] = sub[subsize - 1 - j][i];

			}
		}

		for (int i = hf + 1; i < subsize + hf + 1; ++i) {
			for (int j = 0; j < subsize; ++j) {
				b[i][j] = sub2[i - (hf + 1)][j];

			}
		}

		//print(sub2, subsize);

		for (int i = hf + 1; i < subsize + hf + 1; ++i) {
			for (int j = hf + 1; j < hf + 1 + subsize; ++j) {
				sub[i - (hf + 1)][j-(hf+1)] = a[i][j];

			}
		}

		for (int i = 0; i < subsize; ++i) {
			for (int j = 0; j < subsize; ++j) {
				sub2[i][j] = sub[subsize - 1 - j][i];

			}
		}

		for (int i = hf + 1; i < subsize + hf + 1; ++i) {
			for (int j = hf + 1; j < hf + 1 + subsize; ++j) {
				b[i][j] = sub2[i - (hf + 1)][j - (hf + 1)];

			}
		}


		//print(sub2, subsize);


		//print(b, n);


		a = b;
	}





	cout << ans << '\n';


	return 0;
}
```
테스트 케이스는 다 맞고 논리도 다 맞는것 같은데, 런타임 에러가 제출하면 나서 난항을 겪고 있습니다.
배열의 범위를 벗어나서 런타임 에러가 난 것 같은데, 어디서 배열의 인덱스를 벗어난지를 모르겠습니다.
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>
#include <string>
#include <cstring>
#include <limits>
#include <set>
int n, m, k, t;
int h;

int dx[] = { 0,0,1,-1 };
int dy[] = { -1,1,0,0 };

using namespace std;

vector<vector<int>> a(100, vector<int>(100));
int map[100][100];
int gcnt[1000];
int gnum[1000];
int injup[100][100];

int g;


void print(vector<vector<int>> a, int n) {

	cout << '\n';
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cout << a[i][j] << ' ';
		}
		cout << '\n';
	}








}

long long ans = 0;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	cin >> n;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> a[i][j];
		}
	}
	k = 4;
	while (k--) {
		memset(map, -1, sizeof(map));
		memset(gcnt, 0, sizeof(gcnt));
		memset(gnum, -1, sizeof(gnum));
		memset(injup, 0, sizeof(injup));

		g = 0;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if (map[i][j] == -1) {
					int num = a[i][j];
					queue<pair<int, int>> q;
					map[i][j] = g;
					gcnt[g] = 1;
					gnum[g] = num;
					q.emplace(i, j);
					while (!q.empty()) {
						int x, y;
						tie(x, y) = q.front();
						q.pop();
						for (int k = 0; k < 4; ++k) {
							int nx = x + dx[k];
							int ny = y + dy[k];

							if (0 <= nx && nx < n && 0 <= ny && ny < n && a[nx][ny] == num && map[nx][ny]==-1) {
								map[nx][ny] = g;
								gcnt[g] += 1;
								q.emplace(nx, ny);
							}
						}

					}

					g += 1;
				}
			}
		}

		for (int i = 0; i < n; ++i) {	///////////////////////////////오답 가능성 있는 부분
			for (int j = 0; j < n; ++j) {
				int gn = map[i][j];
				for (int k = 0; k < 4; ++k) {
					int nx = i + dx[k];
					int ny = j + dy[k];
					if (0 <= nx && nx < n && 0 <= ny && ny < n && map[nx][ny] != gn) {
						injup[gn][map[nx][ny]] += 1;
					}
				}
			}
		}
		long long sum = 0;
		vector<vector<bool>> check(1000, vector<bool>(1000, false));
		set<pair<int, int>> st;
		for (int i = 0; i < g; ++i) {
			for (int j = 0; j < g; ++j) {
				bool flag = false;
				if (i == j) continue;
				if (i < j) {
					flag = st.count({ i,j });
				}
				else {
					flag = st.count({ j,i });
				}
				if (flag == false) {
					if (i < j) st.emplace(i, j);
					else st.emplace(j, i);
					check[i][j] = true;
					check[j][i] = true;
					sum += (gcnt[i] + gcnt[j]) * gnum[i] * gnum[j] * injup[i][j];
				}
			}
		}
		ans += sum;

		///////////////////////////////회전


		vector<vector<int>> b(100, vector<int>(100));


		vector<int> tmp;
		int hf = n / 2;
		for (int i = 0; i < n; ++i) tmp.emplace_back(a[hf][i]);
		reverse(tmp.begin(), tmp.end());
		int cnt = 0;
		for (int i = 0; i < n; ++i) b[i][hf] = tmp[cnt++];

		tmp.clear();
		for (int i = 0; i < n; ++i) tmp.emplace_back(a[i][hf]);
		cnt = 0;

		for (int i = 0; i < n; ++i) b[hf][i] = tmp[cnt++];




		int subsize = (n - 1) / 2;
		vector<vector<int>> sub(subsize, vector<int>(subsize));
		vector<vector<int>> sub2(subsize, vector<int>(subsize));

		//for (int i = 0; i < subsize; ++i) {
		//	for (int j = 0; j <subsize; ++j) {
		//		b[i][j] = a[i][subsize-1-j];

		//	}
		//}


		for (int i = 0; i < subsize; ++i) {
			for (int j = 0; j < subsize; ++j) {
				sub[i][j] = a[i][j];

			}
		}

		for (int i = 0; i < subsize; ++i) {
			for (int j = 0; j < subsize; ++j) {
				sub2[i][j] = sub[subsize - 1 - j][ i];
			}
		}

		//print(sub, subsize);

		for (int i = 0; i < subsize; ++i) {
			for (int j = 0; j < subsize; ++j) {
				b[i][j] = sub2[i][j];

			}
		}


		//print(sub2, subsize);



		for (int i = 0; i < subsize; ++i) {
			for (int j = hf+1; j < hf+1+subsize; ++j) {
				sub[i][j-(hf+1)] = a[i][j];

			}
		}

		for (int i = 0; i < subsize; ++i) {
			for (int j = 0; j < subsize; ++j) {
				sub2[i][j] = sub[subsize - 1 - j][i];

			}
		}


		for (int i = 0; i < subsize; ++i) {
			for (int j = hf + 1; j < hf + 1 + subsize; ++j) {
				b[i][j] = sub2[i][j - (hf + 1)];

			}
		}


		//print(sub2, subsize);

		for (int i = hf+1; i < subsize+hf+1; ++i) {
			for (int j = 0; j < subsize; ++j) {
				sub[i-(hf+1)][j] = a[i][j];

			}
		}

		for (int i = 0; i < subsize; ++i) {
			for (int j = 0; j < subsize; ++j) {
				sub2[i][j] = sub[subsize - 1 - j][i];

			}
		}

		for (int i = hf + 1; i < subsize + hf + 1; ++i) {
			for (int j = 0; j < subsize; ++j) {
				b[i][j] = sub2[i - (hf + 1)][j];

			}
		}

		//print(sub2, subsize);

		for (int i = hf + 1; i < subsize + hf + 1; ++i) {
			for (int j = hf + 1; j < hf + 1 + subsize; ++j) {
				sub[i - (hf + 1)][j-(hf+1)] = a[i][j];

			}
		}

		for (int i = 0; i < subsize; ++i) {
			for (int j = 0; j < subsize; ++j) {
				sub2[i][j] = sub[subsize - 1 - j][i];

			}
		}

		for (int i = hf + 1; i < subsize + hf + 1; ++i) {
			for (int j = hf + 1; j < hf + 1 + subsize; ++j) {
				b[i][j] = sub2[i - (hf + 1)][j - (hf + 1)];

			}
		}


		//print(sub2, subsize);


		//print(b, n);


		a = b;
	}





	cout << ans << '\n';


	return 0;
}