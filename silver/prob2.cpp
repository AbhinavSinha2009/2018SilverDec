#include <bits/stdc++.h>
#define int long long
using namespace std;

ifstream fin("mooyomooyo.in");
ofstream fout("convention2.out");

struct Cow{
    int priority;
    int arrival;
    int duration;
};

struct byTime{
  bool operator()(const Cow& a, const Cow& b) const {
      if (a.arrival!=b.arrival) {
          return a.arrival < b.arrival;
      }
      return a.priority < b.priority;
  }
};

struct byPriority{
    bool operator()(const Cow& a, const Cow& b) const {
        if (a.priority!=b.priority) {
            return a.priority < b.priority; // this is sorting greatest to least priority cuz 1 has the greatest then 2, etc.
        }
        return a.arrival < b.arrival;
    }
};

int maxWaitTime(vector<Cow> &order) {
    int currTime=0;
    int maxWait=0;
    for (const auto c : order) {
        if (c.arrival>=currTime) {
            currTime=c.arrival+c.duration;
        } else {
            maxWait=max(maxWait,currTime-c.arrival);
            currTime+=c.duration;
        }
    }
    return maxWait;
}

signed main() {
    int n; fin >> n;
    set<Cow, byTime> arrive;
    set<Cow, byPriority> pri;
    vector<Cow> order;
    for(int i=0 ; i < n ; i++){
        Cow curr;
        curr.priority=i+1;
        fin >> curr.arrival >> curr.duration;
        arrive.insert(curr);
    }
    vector<Cow> a;
    vector<set<Cow, byPriority>> v;
    for(auto it : arrive){a.push_back(it);}
    int currTime=0, sum=0;
    for(int i=0 ; i < a.size() ; i++){
        if (!pri.empty()) {
            v.push_back(pri);
            pri.clear();
        }
        Cow curr=a[i];
        int currPri=curr.priority, currAri=curr.arrival, curDur=curr.duration;
        //currTime+=sum;
        //sum=0;
        if(currAri >= currTime){ //or is it > instead of >=
            currTime=currAri+curDur;
            if (!pri.empty()) {
                v.push_back(pri);
                pri.clear();
            }
            pri.insert(curr);
            v.push_back(pri);
            pri.clear();
            //order.push_back(curr);
        } else {
            while(i<n){
                if(a[i].arrival<currTime){
                    sum+=a[i].duration;
                    currTime+=a[i].duration;
                    pri.insert(a[i]);
                    i++;
                    if (i==n) { // was the last element
                        if (!pri.empty()) {
                            v.push_back(pri);
                            pri.clear();
                        }
                        //i--;
                        //break;
                    }
                } else {
                    if (!pri.empty()) {
                        v.push_back(pri);
                        pri.clear();
                    }
                    i--;
                    break;
                }
            }
            sum=0;
        }

   }
   for(int i=0 ; i < v.size() ; i++){
     for(auto it : v[i]){
       order.push_back(it);
     }
   }
   // for(auto i : order){
   //   fout << i.priority << " ";
   // }
   // fout << endl;
    fout << maxWaitTime(order) << endl;
}