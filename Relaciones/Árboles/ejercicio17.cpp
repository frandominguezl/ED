/*
* @file ejercicio17.cpp
* @brief Diferencias de eficiencia entre insertar miles de datos aleatorios en un set,
* frente a hacerlo en un unordered set
* @author Francisco Domínguez Lorente
*/

/*
Según la página web cppreference.com y consultando los apartados correspondientes,
la eficiencia de ambas operaciones de inserción dependiendo del caso usado, son
las siguientes:

- Para std::set::insert -> O(log(size()))
- Para std::unordered_set::insert -> Average case: O(1), worst case O(size())

Por lo tanto podemos concluir que es bastante más eficiente insertar datos en una unordered_set
antes que en un set normal, puesto que podemos esperar que el mejor (y más habitual) caso sea
O(1). */