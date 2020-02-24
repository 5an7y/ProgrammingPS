#include <bits/stdc++.h>
using namespace std;
#define MAXN 1000000

int n, ar[MAXN], dp[MAXN], maxi = 0;

int main(){

  ios_base::sync_with_stdio(0);cin.tie(0);

  cin >> n;

  for (int i = 0; i < n; i++)
    cin >> ar[i];
  
  for (int i = 0; i < n; i++){
    
    dp[i] = 1;

    for (int j = 0; j < i; j++)
      if (ar[j] < ar[i])
        dp[i] = max(dp[i], dp[j] + 1);

    maxi = max(maxi, dp[i]);

  }

  cout << maxi ;

  return 0;
}