# Reducción del problema

El problema se puede reducir a contar cuantos números aparecen una cantidad impar de veces. Aquellos que aparecen una cantidad par de veces no es necesario modificarlos, mientras los que aparecen una cantidad impar basta con añadir una persona.

# Tabla hash (50 puntos)

Una idea para resolver este problema es usando una tabla hash. Llevamos un arreglos de la cantidad de números que hay, cuando esa cantidad se vuelva impar aumentamos uno a nuestra respuesta. Cuando la cantidad regresa a par restamos uno a nuestra respuesta.

```cpp
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
```

Sin embargo, un arreglo no puede almacenar números de muy grandes. La complejidad en este caso es de $O(n)$ porque poner un número en un arreglo ya acceder a el, es constante.

**Nota**: esta solución pasa a ser 100 si usas un `map` en vez de un arreglo. Esa solución es $O(n \log n)$, porque acceder a un elemento en un map es $\log n$

# Ordenamiento

Otra solución a este problema es ordenar el arreglo. De esta manera los números que son iguales quedan juntos. Para contar la cantidad de números solo se le debe dar una pasada al arreglo.

```cpp
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
```
La implementación anterior es con un vector.

La complejidad del algoritmo es $O(n \log n)$ por el ordenamiento.