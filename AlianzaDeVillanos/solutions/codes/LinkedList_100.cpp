#include <bits/stdc++.h>
using namespace std;

// Estructura del nodo
struct nodo {
  nodo *next, *ant;
  int val;
};

nodo *conexiones[1001]; // Arreglo donde se guardan los nodos
int n, q, x, y;
char tipo;

// Función para que X pase a ser jefe de Y
void unir(int x, int y) {
  
  if (conexiones[y] -> ant) {
    /* Si Y tiene un anterior entonces el
    siguiente de ese anterior pasa a ser el
    siguiente de Y */
    conexiones[y] -> ant -> next = conexiones[y] -> next;
  }
  if (conexiones[y] -> next) {
    /* Si Y tiene un siguiente entonces el
    anterior de ese siguiente pasa a ser el
    anterior de Y */
    conexiones[y] -> next -> ant = conexiones[y] -> ant;
  }

  // Hacemos que Y no apunte a nada
  conexiones[y] -> next = NULL;
  
  if (conexiones[x] -> next) {
    /* Si X tiene siguiente, hacemos ahora que
    Y apunte a ese siguiente */
    conexiones[y] -> next = conexiones[x] -> next;
    conexiones[y] -> next -> ant = conexiones[y];
  }

  // El siguiente de X pasa a ser Y
  conexiones[x] -> next = conexiones[y];
  // El anterior de Y pasa a ser X
  conexiones[y] -> ant = conexiones[x];
  return;
}

// Funcion para ver quien es el jefe maximo de X
int buscarElJefe (int x) {
  /* Llevamos una variable act, que es el nodo
  en el cual vamos actualmente */
  nodo* act = conexiones[x];
  /* Movemos la variable por los anteriores
  hasta que ya no exista un anterior */
  while (act -> ant) {
    act = act -> ant;
  }
  return act->val;
}

int main(){
  ios_base::sync_with_stdio(0);cin.tie(0); 

  // Leer la entrada
  cin >> n >> q;

  // Inicializamos cada nodo
  for (int i = 0; i <= n; ++i) {
    conexiones[i] = new nodo;
    conexiones[i] -> val = i;
  }

  for (int i = 0; i < q; i++) {
      
    cin >> tipo;
    if (tipo == 'U') { // Operacion unir
      cin >> x >> y;
      unir(x, y);
    } else { // Decir quien es el jefe
      cin >> x;
      cout << buscarElJefe(x) << '\n';
    }
    
  }

  for(int i = 0; i <= n; i++)
    delete conexiones[i]; // Borrar todos los nodos

  return 0;
}