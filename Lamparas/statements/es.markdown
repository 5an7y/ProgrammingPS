# Problema

Santy fue contratado para ser el encargado de luces y sonidos de una fiesta. Lamentablemente el es muy desordenado y deja multicontactos conectados a distintas luces (lamparas) numeradas del 1 al $n$. Cada que prende un multicontactos, distintas lamparas se prenden. Como Santy tiene todo una enredadera quiere saber, cuantas lamparás le harían falta conectar con tal de que todas queden prendidas. Es importante resaltar que una vez que una lampara se prende ya no puede apagarse aun así otro interuptor la prenda.

# Entrada

Se te da un número $n$ representando el número de lamparas que hay. Un número $q$ que representa la cantidad de multicontactos.
Después se te dan $q$ líneas de la forma: $m_i$ es el número de lamparás que prende el i-ésimo multicontacto, seguido se te daran $m_i$ números $y_{ij}$ que son las lamparás que prende el i-esimo multicontactos.

# Salida

Un único número representando cuantas lamparas me faltarían prender, si prendo el número máximo de lamparas.

# Ejemplo

||input
3 4
1 1
2 2 3
3 3 4 1
2 1 2
||output
0
||description
Prendiendo los ultimos 2 multicontactos podemos prender todas las lamparás y ya no haría falta ninguna lampara
||input
3 2
1 1
1 2
||output
1
||description
No hay forma de prender la última lampara
||end

# Limites

- $1 \leq n \leq 10^5$
- $1 \leq q \leq 10^3$
- $1 \leq m_i \leq 10^3$
- $1 \leq y_{ij} \leq n$