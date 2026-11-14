#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Alumno {
    string nombre;
    string matricula;
    float calif[3];
    int grupo;
};

int main() {
    ifstream existe("alumnos.txt");

    if (!existe) {
        cout << "Error: alumnos.txt no existe.";
        return 1;
    }

    existe.close();

    Alumno nuevo;

    cout << "Nombre: ";
    getline(cin >> ws, nuevo.nombre);

    cout << "Matricula: ";
    cin >> nuevo.matricula;

    for (int i = 0; i < 3; i++) {
        cout << "Calificacion " << i + 1 << ": ";
        cin >> nuevo.calif[i];
    }

    cout << "Grupo: ";
    cin >> nuevo.grupo;

    ofstream archivo("alumnos.txt", ios::app);

    if (!archivo) {
        cout << "Error al abrir el archivo.";
        return 1;
    }

    archivo << nuevo.nombre << "|"
            << nuevo.matricula << "|"
            << nuevo.calif[0] << "|"
            << nuevo.calif[1] << "|"
            << nuevo.calif[2] << "|"
            << nuevo.grupo << endl;

    archivo.close();

    cout << "\nAlumno agregado correctamente.";

    return 0;
}
