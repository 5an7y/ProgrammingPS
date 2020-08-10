# Descripción

Molesto después de fallar su entrevista en FB. Felipe decide crear su propia empresa "malvados y asociados". Para que su empresa funcione de forma correcta, necesita que en cada área de la empresa halla una cantidad par de persona trabajando. La empresa tiene un total de $n$ empleados, tu tarea será decir cuantas personas faltaría poner para que la empresa funcione de forma correcta.

# Problema

Dado una lista de $n$ números que representan en que área trabaja cada empleado actual, decir cuantos empleados habría que contratar (los nuevos empleados puede trabajar en cualquier área) para que la empresa funcione de manera correcta. 

# Entrada

Se te dará un número $n$ que representa la cantidad de empleado. Luego, una lista de $n$ números que son las áreas en la que trabaja cada empleado.

# Salida

Un único entero que representa la minima cantidad de personas que faltan para que la empresa funcione de forma correcta.

# Ejemplo

||input
6
1 2 1 3 1 1
||output
2
||description
Los del area $1$ son $4$ entonces no hay problema. Pero como solo hay una persona del area $2$ y $3$, podemos contratar $2$ personas para que vayan a cada área.
||input
4
1 2 1 2
||output
0
||end

# Limites

**Para un 25% de los casos**

- $0 < n < 10^4$
- $0 < A_i < 10^4$

**Para un 25% de los casos**

- $0 < n < 10^4$
- $|A_i| < 10^8$

**Para un 25% de los casos**

- $0 < n < 10^6$
- $0 < A_i < 10^6$

**Para un 25% de los casos**

- $0 < n < 10^6$
- $|A_i| < 10^8$