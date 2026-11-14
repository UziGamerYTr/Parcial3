#include <iostream>
#include <fstream>
#include <sstream>
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
    int n = 0;
    string linea;

    ifstream archivo("alumnos.txt");

    if (!archivo) {
        cout << "Error: no se encontro alumnos.txt.";
        return 1;
    }

    while (getline(archivo, linea) && n < 100) {
        stringstream ss(linea);
        string c1, c2, c3, c4;

        if (getline(ss, alumnos[n].nombre, '|') &&
            getline(ss, alumnos[n].matricula, '|') &&
            getline(ss, c1, '|') &&
            getline(ss, c2, '|') &&
            getline(ss, c3, '|') &&
            getline(ss, c4, '|')) {

            try {
                alumnos[n].calif[0] = stof(c1);
                alumnos[n].calif[1] = stof(c2);
                alumnos[n].calif[2] = stof(c3);
                alumnos[n].grupo = stoi(c4);
                n++;
            }
            catch (...) {
                cout << "Linea incorrecta ignorada.\n";
            }
        }
    }

    archivo.close();

    cout << "\nALUMNOS LEIDOS: " << n << endl;

    for (int i = 0; i < n; i++) {
        float promedio = (
            alumnos[i].calif[0] +
            alumnos[i].calif[1] +
            alumnos[i].calif[2]) / 3.0f;

        cout << "\nNombre: " << alumnos[i].nombre;
        cout << "\nMatricula: " << alumnos[i].matricula;
        cout << "\nGrupo: " << alumnos[i].grupo;
        cout << "\nPromedio: " << promedio << endl;
    }

    return 0;
}
