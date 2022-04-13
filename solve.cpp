#include <bits/stdc++.h>
using namespace std;
#define N 100000
 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	int n, m, q;
	bool flg = 0;
	pair<int, int> trial[N];
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		int first, second;
		cin >> first >> second;
		if (flg) {
			flg = 0;
			i--;
			n--;
		}
		if (first == second) {
			flg = 1;
			continue;
		}
		else {
			trial[i].first = first;
			trial[i].second = second;
		}
		
	}
	cerr << ' ' << n << endl;
	sort(trial, trial + n);
	cin >> q;
	while (q--) 
	{
		bool flag = 0;
		int start, end;
		cin >> start >> end;
		if (end < start)
			swap(start, end);
		if (start < trial[0].first)
			cout << "NO" << endl;
		else {
			for (int i = 0; i < n; i++)
			{
				if (start <= trial[i].second && start >= trial[i].first) {
					if (end <= trial[i].second) {
						flag = 1;
						break;
					}
					else {
						start = trial[i].second;
					}
				}
				else if (start < trial[i].first)
					break;
			}
			if (flag)
				cout << "YES" << endl;
			else
				cout << "NO" << endl;
		}
	}
	return 0;
}
