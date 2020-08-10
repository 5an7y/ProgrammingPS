#include<bits/stdc++.h>
using namespace std;

int n, respuesta;
vector<int> ar;

int main(){
  ios_base::sync_with_stdio(0);cin.tie(0);

  cin >> n;

  for (int i = 0; i < n; i++) {
    int aux;
    cin >> aux;
    ar.push_back(aux);
  }

  sort(ar.begin(), ar.end());

  for (int i = 0; i < n; i++) {
    // Act es la cantidad de números que hay de ar[i]
    int act = 1;
    while (i + 1 < n && ar[i] == ar[i+1]) {
      i++;
      act++;
    }
    if (act % 2) {
      respuesta++;
    }
  }
  
  cout << respuesta;

  return 0;
}