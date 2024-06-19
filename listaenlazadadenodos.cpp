#include <iostream>
#include <cstdlib>
#include <cstring>

// Definimos la estructura Nodo que representará cada elemento de la lista enlazada.
struct Nodo
{
    char *Nombre; // Apuntador a una cadena de caracteres (nombre).
    Nodo *sig; // Apuntador al siguiente nodo de la lista.
};

// Declaramos un apuntador global para la lista.
Nodo *Lista = nullptr;

// Declaración de las funciones que se usarán.
bool ListaVacia();
char *SacaLista();
void MuestraListado();
void InsertarLista(const char *Nom);

// Función que verifica si la lista está vacía.
bool ListaVacia()
{
    return Lista == nullptr;
}

// Función que saca (elimina y retorna) el primer elemento de la lista.
char *SacaLista()
{
    if (ListaVacia())
    {
        printf("La lista está vacía.\n");
        return nullptr;
    }
    Nodo *temp = Lista; // Guardamos el nodo que se va a eliminar.
    char *nombre = strdup(Lista->Nombre); // Copiamos el nombre del nodo.
    Lista = Lista->sig; // Avanzamos el puntero de la lista al siguiente nodo.
    free(temp->Nombre); // Liberamos la memoria del nombre del nodo.
    free(temp); // Liberamos la memoria del nodo.
    return nombre; // Retornamos el nombre del nodo eliminado.
}

// Función que muestra todos los elementos de la lista.
void MuestraListado()
{
    if (ListaVacia())
    {
        printf("La lista está vacía.\n");
        return;
    }
    Nodo *temp = Lista; // Empezamos desde el primer nodo.
    while (temp != nullptr)
    {
        printf("%s\n\n", temp->Nombre); // Imprimimos el nombre del nodo actual.
        temp = temp->sig; // Avanzamos al siguiente nodo.
    }
}

// Función principal.
int main()
{
    system("cls"); // Limpiamos la consola (esta línea es específica de Windows).

    // Ejemplo de inserción de nombres en la lista.
    InsertarLista("Ana");
    InsertarLista("Juan");
    InsertarLista("Maria");

    // Mostramos la lista actual.
    MuestraListado();

    // Ejemplo de extracción de un elemento de la lista.
    char *nombre = SacaLista();
    if (nombre)
    {
        printf("Elemento extraido: %s\n", nombre);
        free(nombre); // Liberamos la memoria del nombre extraído.
    }

    // Mostramos la lista después de la extracción.
    MuestraListado();

    return 0;
}

// Función que inserta un nuevo nombre en la lista.
void InsertarLista(const char *Nom)
{
    Nodo *t = new Nodo; // Creamos un nuevo nodo.
    if (!t)
    {
        printf("No se pudo asignar memoria.\n");
        return;
    }
    t->Nombre = strdup(Nom); // Asignamos el nombre al nodo.
    t->sig = nullptr; // El nuevo nodo apunta a nullptr ya que será el último nodo.
    if (Lista == nullptr)
    {
        Lista = t; // Si la lista está vacía, el nuevo nodo será el primero.
    }
    else
    {
        Nodo *q = Lista;
        while (q->sig != nullptr)
        {
            q = q->sig; // Avanzamos hasta el último nodo de la lista.
        }
        q->sig = t; // El último nodo apunta al nuevo nodo.
    }
}

