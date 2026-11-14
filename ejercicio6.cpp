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
    Alumno alumnos[100];
    int n;

    cout << "Cuantos alumnos desea guardar? ";
    cin >> n;

    if (n < 1 || n > 100) {
        cout << "Cantidad no valida.";
        return 1;
    }

    for (int i = 0; i < n; i++) {
        cout << "\nAlumno " << i + 1 << endl;
        cout << "Nombre: ";
        getline(cin >> ws, alumnos[i].nombre);

        cout << "Matricula: ";
        cin >> alumnos[i].matricula;

        for (int j = 0; j < 3; j++) {
            cout << "Calificacion " << j + 1 << ": ";
            cin >> alumnos[i].calif[j];
        }

        cout << "Grupo: ";
        cin >> alumnos[i].grupo;
    }

    ofstream archivo("alumnos.txt");

    if (!archivo) {
        cout << "Error al crear el archivo.";
        return 1;
    }

    for (int i = 0; i < n; i++) {
        archivo << alumnos[i].nombre << "|"
                << alumnos[i].matricula << "|"
                << alumnos[i].calif[0] << "|"
                << alumnos[i].calif[1] << "|"
                << alumnos[i].calif[2] << "|"
                << alumnos[i].grupo << endl;
    }

    archivo.close();

    cout << "\nAlumnos guardados correctamente.";

    return 0;
}
