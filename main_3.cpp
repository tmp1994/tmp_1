// AUTHOR: VIT
#include <iostream>
#include <map>
using namespace std;

int main() {
	int n = 0;
	cin >> n;
	unsigned long *id = new unsigned long[n];
	map<unsigned long, unsigned long> res;
	for (unsigned long i = 0; i < n; i++) {
		cin >> id[i];
		auto entry = make_pair(id[i], 1);
		auto tt = res.insert(entry);
		if (!tt.second) {
			res[id[i]]++;
		}
	}
	int result = 0;
	for (auto iter = res.begin(); iter != res.end(); iter++) {
		if (iter->first != 0)
		{
			if (iter->second == 2) {
				result++;
			} else {
				if (iter->second > 2) {
					result = -1;
					break;
				}
			}
		}
	}
	cout << result << endl;
	system("pause");
}
5-6