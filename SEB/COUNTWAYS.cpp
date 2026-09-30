#include <iostream>
#include <unordered_set>
using namespace std;

unordered_set<int> value;

int count(int x) {
    if (x < 0) return 0;
    if (x == 0) return 1;
    if (value.find(x) != value.end()) return 0;

    return count(x-1) + count(x-2) + count(x-3);
}

int main() {
    int x; cin >> x; // target
    int t; cin >> t; // number of skipp vallues

    for (int i = 0; i < t; i++) {
        int val; cin >> val;
        value.insert(val);
    }
    if(count(x)==0) cout<<"-1";
    else
     cout << count(x) << "\n";
    return 0;
}
