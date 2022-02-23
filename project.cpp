#include <iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;
#define ll long long
#define mod 1000000007
#define pb push_back
void fast() {
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
}
int l[3], k;
double get(double a, double b, double c) {
    double s = (a + b + c) / 2;
    if (s < a || s < b || s < c)
        return 0;
    //law of triangle's area
    return sqrt(s * (s - a) * (s - b) * (s - c));
}
int main() {
    fast();
    freopen("sticks.in", "r", stdin);
    int t;
    cin >> t;
    while (t--) {
        double ans = 0;
        for (int i = 0; i < 3; i++)
            cin >> l[i];
        cin >> k;
        sort(l, l + 3);
        ans = max(ans, get(l[0], l[1], l[2]));
        do {
            ans = max(ans, get(l[0], l[1], l[2] + k));
            double tmp = sqrt(l[0] * l[0] + l[1] * l[1]);
            if (l[2] <= tmp && tmp <= l[2] + k)
                ans = max(ans, get(l[0], l[1], tmp));
        } while (next_permutation(l, l + 3));
        cout << ans << '\n';
    }
}