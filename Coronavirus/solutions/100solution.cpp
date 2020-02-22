#include <bits/stdc++.h>             
using namespace std;

int n, x1, x2, z1, z2, a;

int main(){
	
  ios_base::sync_with_stdio(0);cin.tie(0); //optimizador

  cin >> n;
	
  for (int i = 0; i < n; i++){
		cin >> a;  
		
    if(i%2) //Si estamos en una posición impar
			if(a%2) x1++; //Si el número que esta en la posición es 1
			else z2++; //Si el número que esta en la posición es 0
		
    else  //Si estamos en una posción par
			if(a%2) x2++; //Si el número que esta en la posición es 1
			else z1++; //Si el número que esta en la posición es 0

	}

	cout << min( max(x1, z1), max(x2, z2) );
}