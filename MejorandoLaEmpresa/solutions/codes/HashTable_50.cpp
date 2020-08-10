#include<bits/stdc++.h>
using namespace std;

int n, numero, tablaHash[1000000], respuesta;

int main(){
  ios_base::sync_with_stdio(0);cin.tie(0);

  cin >> n;

  for (int i = 0; i < n; ++i) {
    cin >> numero;
    tablaHash[numero]++;
    
    if (tablaHash[numero] % 2) {
      // Si la cantidad de números se vuelve impar
      respuesta++;
    } else {
      // Si la cantidad de números se vuelve par
      respuesta--;
    }
  }
  
  cout << respuesta;

  return 0;
}