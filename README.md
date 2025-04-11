# Linked List (Hw1)

## 📌 Integrantes del grupo
- Abel Escobar (202310682)
- Darlene Escobar (202310296)
- Ashly Veliz (202210422)

------

## Explicación en detalle

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

### `int size()`

Se recorre la linked list nodo a nodo mediante un bucle hasta que se llegue al que el nodo siguiente en en la iteración sea nulo (nullptr). Se abordan casos especiales como “ if (!temp) return 0;” o “   if(temp->next) return 1;

### `void clear()`
Algoritmo visto en clase para el cual se recorre de inicio a fin la lista, guardando el nodo head en un nodo auxiliar (que se va a eliminar) y procedemos a mover el head un paso adelante. 

## void sort().
Implementamos el algoritmo de ordenamiento merge sort en el método sort() para una lista enlazada, adoptando un enfoque de "divide y conquista". Comenzamos verificando si la lista está vacía o tiene un solo nodo; en estos casos, no realizamos ordenamiento y retornamos de inmediato. Si la lista tiene más de un nodo, empleamos la función auxiliar findMiddle() para dividirla en dos mitades: asignamos la primera mitad desde el inicio (head) y la segunda mitad desde el nodo siguiente al punto medio, independizando ambas mitades middle->next = nullptr. Luego, creamos dos objetos temporales de tipo ForwardList para representar estas mitades para aplicar la recursión. 
Proseguimos aplicando recursión: invocamos sort() sobre cada objeto temporal (leftList y rightList), ordenando así ambas mitades de forma independiente. Una vez ordenadas, utilizamos la función auxiliar merge() para combinarlas en una lista ordenada, comparando los valores de los nodos y uniendo las mitades en orden ascendente mediante la ajuste de los punteros next. Finalmente, actualizamos el puntero head de la lista original con el resultado de la fusión, completando el ordenamiento. Implementamos este proceso para garantizar un ordenamiento eficiente con una complejidad temporal de O(n log n), optimizado para listas enlazadas.
### Void reverse()

Se implementó un enfoque iterativo donde se cambian los punteros next de cada uno de los nodos de la lista, de modo que ahora apuntan al nodo previo a ellos. Para ello nos valemos de 2 nodos auxiliares next y prev. Se guarda next = curr->next para no perder la el orden de la lista, curr->next = prev , invierte el next del nodo actual y finalmente se mueve el nodo actual y el auxiliar prev un paso adelante. 

---