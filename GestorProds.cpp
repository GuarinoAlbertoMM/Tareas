#include <iostream>
#include <list>
#include <string>

using namespace std;

// Estructura del producto
struct Producto {
    int id;
    string nombre;
    int cantidad;
    float precio;
};

// Lista de productos, inventario
list<Producto> inventario = {
    {1, "Manzana", 50, 20.0},
    {2, "Banana", 100, 10.0},
    {3, "Leche", 20, 145.0},
    {4, "Pan", 30, 5.0},
    {5, "Huevos", 60, 6.0}
};

// Función para agregar un nuevo producto al inventario
void agregarProducto(int id, string nombre, int cantidad, float precio) {
    Producto nuevoProducto = {id, nombre, cantidad, precio};
    inventario.push_back(nuevoProducto);
    cout << "Producto agregado exitosamente.\n";
}

// Función para eliminar un producto del inventario buscado por ID
void eliminarProducto(int id) {
    for (auto it = inventario.begin(); it != inventario.end(); ++it) {
        if (it->id == id) {
            inventario.erase(it);
            cout << "Producto eliminado exitosamente.\n";
            return;
        }
    }
    cout << "Producto no encontrado.\n";
}

// Función para actualizar la cantidad en stock de un producto
void actualizarCantidad(int id, int nuevaCantidad) {
    for (auto& producto : inventario) {
        if (producto.id == id) {
            producto.cantidad = nuevaCantidad;
            cout << "Cantidad actualizada exitosamente.\n";
            return;
        }
    }
    cout << "Producto no encontrado.\n";
}

// Función para mostrar todos los productos del inventario
void mostrarInventario() {
    cout << "Inventario actual:\n";
    for (const auto& producto : inventario) {
        cout << "ID: " << producto.id
             << ", Nombre: " << producto.nombre
             << ", Cantidad: " << producto.cantidad
             << ", Precio: $" << producto.precio << "\n";
    }
}

// Función para buscar un producto por su nombre
void buscarProducto(string nombre) {
    for (const auto& producto : inventario) {
        if (producto.nombre == nombre) {
            cout << "Producto encontrado:\n";
            cout << "ID: " << producto.id
                 << ", Nombre: " << producto.nombre
                 << ", Cantidad: " << producto.cantidad
                 << ", Precio: $" << producto.precio << "\n";
            return;
        }
    }
    cout << "Producto no encontrado.\n";
}

// Función para calcular el valor total del inventario
void calcularValorTotal() {
    float valorTotal = 0;
    for (const auto& producto : inventario) {
        valorTotal += producto.cantidad * producto.precio;
    }
    cout << "El valor total del inventario es: $" << valorTotal << "\n";
}

int main() {
    int opcion, id, cantidad;
    float precio;
    string nombre;

    do {
        cout << "\n---- Gestión de Inventario ----\n";
        cout << "1. Mostrar inventario\n";
        cout << "2. Agregar producto\n";
        cout << "3. Eliminar producto\n";
        cout << "4. Actualizar cantidad\n";
        cout << "5. Buscar producto\n";
        cout << "6. Calcular valor total\n";
        cout << "0. Salir\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                mostrarInventario();
                break;
            case 2:
                cout << "Ingrese ID del producto: ";
                cin >> id;
                cout << "Ingrese nombre del producto: ";
                cin.ignore(); // Para ignorar el newline
                getline(cin, nombre);
                cout << "Ingrese cantidad en stock: ";
                cin >> cantidad;
                cout << "Ingrese precio: ";
                cin >> precio;
                agregarProducto(id, nombre, cantidad, precio);
                break;
            case 3:
                cout << "Ingrese ID del producto a eliminar: ";
                cin >> id;
                eliminarProducto(id);
                break;
            case 4:
                cout << "Ingrese ID del producto: ";
                cin >> id;
                cout << "Ingrese nueva cantidad en stock: ";
                cin >> cantidad;
                actualizarCantidad(id, cantidad);
                break;
            case 5:
                cout << "Ingrese el nombre del producto: ";
                cin.ignore();
                getline(cin, nombre);
                buscarProducto(nombre);
                break;
            case 6:
                calcularValorTotal();
                break;
            case 0:
                cout << "Saliendo...\n";
                break;
            default:
                cout << "Opción no válida.\n";
                break;
        }
    } while (opcion != 0);

    return 0;
}
