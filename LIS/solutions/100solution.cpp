#include <bits/stdc++.h>
using namespace std;
#define MAXN 1000000
#define mit(a, b) (a + b)/2

int n, ar[MAXN], dp[MAXN], maxi = 0;

int binSearch(int *arr, int l, int r, int k){
  if (l == r) return l;
  if (k <= arr[mit(l, r)]) return binSearch(arr, l, mit(l, r), k);
  return binSearch(arr, mit(l, r) + 1, r, k);
}

int main(){

  ios_base::sync_with_stdio(0); cin.tie(0);

  cin >> n;

  for (int i = 0; i < n; i++)
    cin >> ar[i];
  
  int t = 0;
  dp[0] = ar[0];

  for (int j = 1; j < n; j++){
    int p = binSearch(dp, 0, t + 1, ar[j]);
    if (p > t) t++;
    dp[p] = ar[j];
  }
  
  cout << t + 1 << '\n';

  return 0;
}