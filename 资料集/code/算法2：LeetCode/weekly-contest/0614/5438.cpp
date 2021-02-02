#inclue <bits/stdc++.h>
using namespace std;

bool isok(vector<int>& handled, int m, int k, int v) {
    for (int i = 0; i < handled.size() && m > 0;) {
        if (handled[i] <= v) {
            i += k;
            m --;
        } else {
            i += 1;
        }
    }
    return m <= 0;
}
int minDays(vector<int>& bloomDay, int m, int k) {
    int n = bloomDay.size();
    if (n < k * m) {
        return -1;
    }
    vector<int> handled(n - k + 1);
    // why multiset ?
    multiset<int, greater<int>> minTree;
    int right = -1;
    for (int i = 0; i < k; ++ i) {
        right = max(right, bloomDay[i]);
        minTree.insert(bloomDay[i]);
    }
    for (int i = k - 1; i < n; ++ i) {
        right = max(right, bloomDay[i]);
        handled[i - k + 1] = *(minTree.begin());
        if (! minTree.empty()) {
            auto it = minTree.find(bloomDay[i - k + 1]);
            minTree.erase(it);
        }
        if (i < n - 1) {
            minTree.insert(bloomDay[i + 1]);
        }
    }
    int left = 1;
    while (left < right) {
        if (left + 1 == right) {
            if (isok(handled, m, k, left)) {
                return left;
            } else {
                return right;
            }
        }
        int mid = (left + right) / 2;
        if (isok(handled, m, k, mid)) {
            right = mid;
        } else {
            left = mid;
        }
    }
    return left;
}