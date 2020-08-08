# Buscar divisores de un número en raíz de n

En varios problemas vamos a tener que buscar los divisores de ún número y muchas veces la forma bruta no es optima. 
La forma bruta es iterar sobre todos los números y ver si cada uno es un divisor o no. Entonces para esto tomemos un ejemplo, hagamos la
fuerza bruta e intentemos buscar un patrón. Tomemos el número 18 como ejemplo.

Algo que debemos tener encuenta es que si <img src="https://render.githubusercontent.com/render/math?math=a">
es un divisor de <img src="https://render.githubusercontent.com/render/math?math=n">, quiere decir que
<img src="https://render.githubusercontent.com/render/math?math=n/a = b"> para un entero 
<img src="https://render.githubusercontent.com/render/math?math=b">. Lo interesante es que <img src="https://render.githubusercontent.com/render/math?math=b">
igual es un divisor de <img src="https://render.githubusercontent.com/render/math?math=n">, porque 
<img src="https://render.githubusercontent.com/render/math?math=n/b = a">.

Entonces, cada que encontramos un divisor, en realidad tenemos 2. Tomando el ejemplo de 18 si hacemos la fuerza bruta obtenemos la lista

<img src="https://render.githubusercontent.com/render/math?math=[1, 2, 3, 6, 9, 18]">

Utilizando lo mencionado anteriormente, podemos hacer parejas cada que encontremos un divisor, y la lista queda como:

<img src="https://render.githubusercontent.com/render/math?math=[(1, 18), (2, 9), (3, 6), (6, 3), (9, 2), (18, 1)]">

**¿Notas algo en los problemas?**

En efecto, apartir de la mitad las parejas se estan repitiendo. Entonces no es necesario checar todos los números hasta 
<img src="https://render.githubusercontent.com/render/math?math=n">. Podrás ya darte una idea de una posible poda,
podemos checar los números hasta <img src="https://render.githubusercontent.com/render/math?math=n/2">, porque
el unico divisor después de allí es el número mismo.

Sin embargo, podemos hacer mejor que eso. Muchas veces cuando tenemos parejas repetidas de este estilo es conveniente darles ciertas
restricciones a las parejas para que no se repitan. Aquí sirve darle orden a las parejas. Esta es una tecnica bastante usada,
ahora si tenemos parejas de la forma <img src="https://render.githubusercontent.com/render/math?math=(a, b)"> vamos a decir que
solo queremos las parejas tal que <img src="https://render.githubusercontent.com/render/math?math=a \leq b">. Es decir, 
la primera entrada va a ser la menor.

Teniendo encuenta esto, y recordando que <img src="https://render.githubusercontent.com/render/math?math=b%20%3D%20n%2Fa">. Queremos
encontra los divsores <img src="https://render.githubusercontent.com/render/math?math=a"> tal que
<img src="https://render.githubusercontent.com/render/math?math=a \leq n/a"> lo cuál implica que 
<img src="https://render.githubusercontent.com/render/math?math=a^2 \leq n"> y entonces 
<img src="https://render.githubusercontent.com/render/math?math=a \leq \sqrt{n}">. Por tanto, solo debemos buscar hasta 
la raiz del números, los demás divisores aparecen como complemento de los ya encontrados.

``` cpp
std::vector<int64_t> encontrarDivisores(int64_t n) {

  std::vector<int64_t> divisores;
  
  for (int64_t i = 1; i <= std::sqrt(n); i++)
    if (n % i == 0) {
      divisores.push_back(i);
      devisores.push_back(n/i);
    }
   
  return divisores;
}
```

**Nota:** Si el número tiene raiz exacta, esa raíz es contada dos veces con esta implementación. i.e. 49 tiene el vector [1, 49, 7, 7]. 
