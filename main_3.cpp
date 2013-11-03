// AUTHOR: VIT
#include <iostream>
#include <map>

using namespace std;

typedef unsigned long uLong;

int main() {
	int n = 0;
	cin >> n;
	uLong *id = new uLong[n];
	map<uLong, uLong> res;
	for (uLong i = 0; i < n; i++) {
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
}