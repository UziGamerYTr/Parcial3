#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    string nombreArchivo;

    cout << "Nombre del archivo que desea abrir: ";
    cin >> nombreArchivo;

    ifstream archivo(nombreArchivo);

    if (!archivo.is_open()) {
        cout << "\nNo se pudo abrir el archivo: "
             << nombreArchivo;

        cout << "\nVerifique que el archivo exista.";

        cout << "\nEl programa termino correctamente.";

        return 0;
    }

    cout << "\nArchivo abierto correctamente.";
    cout << "\nContenido:\n";

    string linea;

    while (getline(archivo, linea)) {
        cout << linea << endl;
    }

    archivo.close();

    return 0;
}
