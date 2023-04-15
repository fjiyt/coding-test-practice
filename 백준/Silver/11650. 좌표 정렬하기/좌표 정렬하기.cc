#include <cstdio>
#include <algorithm>
using namespace std;

int N;
struct abc {
	int x, y;
}a[1111111];
bool compare(const abc &i, const abc &j) {
	if (i.x == j.x)return i.y < j.y;
	return i.x < j.x;
}
int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%d %d", &a[i].x, &a[i].y);
	}
	sort(a + 1, a + N + 1, compare);
	for (int i = 1; i <= N; i++) {
		printf("%d %d\n", a[i].x, a[i].y);
	}
	return 0;
}