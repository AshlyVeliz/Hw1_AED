# Lista Simplemente Enlazada (Hw1)

## 📌 Integrantes del grupo
- Abel Escobar (202310682)
- Darlene Escobar (202310296)
- Ashly Veliz (202210422)

------

## ⚙️ Funciones implementadas y su explicación

### `front()`
Esta función simplemente retorna el valor del primer nodo en la lista (es decir, el nodo apuntado por `head`). Obtenemos el elemento al frente sin modificar la lista. Si la lista está vacía, lanza una excepción para indicar que la lista está vacía.

### `push_front(T value)`
Inserta un nuevo nodo al principio de la lista. Creamos un nodo que contiene el valor proporcionado y que apunta al actual nodo `head`. Luego, actualiza `head` para que apunte al nuevo nodo, haciendo que el nuevo nodo se convierta en el primero de la lista.

### `back()`
Devuelve el valor del último nodo de la lista. Recorremos la lista desde `head` hasta que encontramos un nodo que no tenga siguiente (`next == nullptr`), que es el último nodo, y retornamos su valor.

### `push_back(T value)`
Añade un nuevo nodo con el valor dado al final de la lista. Si la lista está vacía, simplemente hacemos que `head` apunte a este nuevo nodo. Si ya hay elementos, recorremos desde `head` hasta el último nodo y enlazamos el nuevo nodo al final.

### `bool empty()`
Esta función verifica si la lista está vacía. Lo hace comprobando si el puntero `head` es igual a `nullptr`. Si lo es, significa que no hay elementos en la lista y retorna `true`; de lo contrario, retorna `false`. Es útil para evitar errores al intentar acceder o eliminar elementos de una lista vacía.

### `T pop_front()`
Esta función elimina el primer nodo de la lista y retorna su valor. Si la lista está vacía, lanza una excepción. Al eliminar el primer nodo, el puntero `head` se actualiza para que apunte al siguiente nodo. También se libera la memoria del nodo eliminado y se actualiza el tamaño de la lista.

### `T pop_back()`
Esta función elimina el último nodo de la lista y retorna su valor. Si solo hay un elemento, se elimina directamente el nodo `head`. Si hay más de uno, se recorre la lista hasta llegar al penúltimo nodo, se elimina el último, y se actualiza el puntero `next` del penúltimo nodo a `nullptr`. Se reduce el tamaño de la lista.

### `T operator[](int index)`
Permite acceder al valor de un nodo según su índice en la lista, como si fuera un arreglo. Se recorre la lista desde el nodo `head` hasta llegar al índice deseado. Si el índice está fuera de rango, lanza una excepción `out_of_range`.

---


## Observaciones
- Todas las funciones se implementaron de forma genérica usando templates (`template <typename T>`).
- Se hace uso correcto de punteros y gestión de memoria dinámica.
- Se incluye verificación de errores con excepciones (`runtime_error`, `out_of_range`).
