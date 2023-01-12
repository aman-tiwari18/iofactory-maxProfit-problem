#include<iostream>
#include<vector>
using namespace std;

const int theatreEarn = 1500;
const int pubEarn = 1000;
const int commEarn = 3000;

int32_t main()  
{  
  int n;
  cin>>n;

  vector<long long> profit(n+1);
  vector<vector<int> > build(n+1,vector<int>(3));

  for(int i = 1; i <= n; i++) {

    if(i-5 >= 0 && profit[i] < profit[i-5]+theatreEarn*(n-i)) {
      profit[i] = profit[i-5] + theatreEarn*(n-i);
      build[i][0] = build[i-5][0] + 1;
    }

    if(i-4 >= 0 && profit[i] < profit[i-4]+pubEarn*(n-i)) {
      profit[i] = profit[i-4] + pubEarn*(n-i);
      build[i][1] = build[i-4][1] + 1;
    }

    if(i-10 >= 0 && profit[i] < profit[i-10]+commEarn*(n-i)) {
      profit[i] = profit[i-10] + commEarn*(n-i);
      build[i][2] = build[i-10][2] + 1;
    }

    if(profit[i-1] > profit[i]) {
      profit[i] = profit[i-1];
      build[i] = build[i-1];
    }

  }

  cout<<"Earnings: $"<<profit[n]<<endl;
  cout<<"Solution\n"<<"T:"<<build[n][0]<<" P:"<<build[n][1]<<" C:"<<build[n][2];
  return 0;
  
}