#include <bits/stdc++.h>
#define int long long
using namespace std;

//ifstream fin("C:/Users/abhin/CLionProjects/silver/mooyomooyo.in");
//ofstream fout("C:/Users/abhin/CLionProjects/silver/mooyomooyo.out");
ifstream fin("convention.in");
ofstream fout("convention2.out");

int n,m,c;
vector<int> a;

bool works(int wait) {
    int curWait=a[0]+wait, cow=0, bus=0;
    for (int i=0 ; i < n ; i++) {
        if (a[i]<=curWait && cow < c) {
            cow++;
            if (i==0) {
                bus++;
            }
        } else {
            bus++;
            cow=1;
            curWait=a[i]+wait;
        }
    }
    return bus<=m;
}

signed main() {
     fin >> n >> m >> c;
    for (int i=0 ; i < n ; i++) {
        int x; fin >> x ; a.push_back(x);
    }
    sort(begin(a),end(a));
    int low=0, high=INT_MAX,ans=low;
    while (low<=high) {
        int mid = low+(high-low)/2;
        if (works(mid)) {
            ans=mid;
            high=mid-1;
        } else {
            low=mid+1;
        }
    }
    //fout << works(4) << endl;
    fout << ans << endl;
}