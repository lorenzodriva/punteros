#include <iostream>
#include <cstdlib>
#include <cstring>

// Definimos la estructura Nodo que representar� cada elemento de la lista enlazada.
struct Nodo
{
    char *Nombre; // Apuntador a una cadena de caracteres (nombre).
    Nodo *sig; // Apuntador al siguiente nodo de la lista.
};

// Declaramos un apuntador global para la lista.
Nodo *Lista = nullptr;

// Declaraci�n de las funciones que se usar�n.
bool ListaVacia();
char *SacaLista();
void MuestraListado();
void InsertarLista(const char *Nom);

// Funci�n que verifica si la lista est� vac�a.
bool ListaVacia()
{
    return Lista == nullptr;
}

// Funci�n que saca (elimina y retorna) el primer elemento de la lista.
char *SacaLista()
{
    if (ListaVacia())
    {
        printf("La lista est� vac�a.\n");
        return nullptr;
    }
    Nodo *temp = Lista; // Guardamos el nodo que se va a eliminar.
    char *nombre = strdup(Lista->Nombre); // Copiamos el nombre del nodo.
    Lista = Lista->sig; // Avanzamos el puntero de la lista al siguiente nodo.
    free(temp->Nombre); // Liberamos la memoria del nombre del nodo.
    free(temp); // Liberamos la memoria del nodo.
    return nombre; // Retornamos el nombre del nodo eliminado.
}

// Funci�n que muestra todos los elementos de la lista.
void MuestraListado()
{
    if (ListaVacia())
    {
        printf("La lista est� vac�a.\n");
        return;
    }
    Nodo *temp = Lista; // Empezamos desde el primer nodo.
    while (temp != nullptr)
    {
        printf("%s\n\n", temp->Nombre); // Imprimimos el nombre del nodo actual.
        temp = temp->sig; // Avanzamos al siguiente nodo.
    }
}

// Funci�n principal.
int main()
{
    system("cls"); // Limpiamos la consola (esta l�nea es espec�fica de Windows).

    // Ejemplo de inserci�n de nombres en la lista.
    InsertarLista("Ana");
    InsertarLista("Juan");
    InsertarLista("Maria");

    // Mostramos la lista actual.
    MuestraListado();

    // Ejemplo de extracci�n de un elemento de la lista.
    char *nombre = SacaLista();
    if (nombre)
    {
        printf("Elemento extraido: %s\n", nombre);
        free(nombre); // Liberamos la memoria del nombre extra�do.
    }

    // Mostramos la lista despu�s de la extracci�n.
    MuestraListado();

    return 0;
}

// Funci�n que inserta un nuevo nombre en la lista.
void InsertarLista(const char *Nom)
{
    Nodo *t = new Nodo; // Creamos un nuevo nodo.
    if (!t)
    {
        printf("No se pudo asignar memoria.\n");
        return;
    }
    t->Nombre = strdup(Nom); // Asignamos el nombre al nodo.
    t->sig = nullptr; // El nuevo nodo apunta a nullptr ya que ser� el �ltimo nodo.
    if (Lista == nullptr)
    {
        Lista = t; // Si la lista est� vac�a, el nuevo nodo ser� el primero.
    }
    else
    {
        Nodo *q = Lista;
        while (q->sig != nullptr)
        {
            q = q->sig; // Avanzamos hasta el �ltimo nodo de la lista.
        }
        q->sig = t; // El �ltimo nodo apunta al nuevo nodo.
    }
}

