#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdint>
using namespace std;

struct Alumno {
    string nombre;
    string matricula;
    float calif[3];
    int grupo;
};

void escribirCadena(ofstream &out, const string &dato) {
    uint32_t longitud = dato.size();

    out.write(
        reinterpret_cast<const char*>(&longitud),
        sizeof(longitud)
    );

    out.write(dato.data(), longitud);
}

int main() {
    Alumno alumnos[100];
    int n = 0;
    string linea, c1, c2, c3, c4;

    ifstream entrada("alumnos.txt");

    if (!entrada) {
        cout << "Error: no existe alumnos.txt.";
        return 1;
    }

    while (getline(entrada, linea) && n < 100) {
        stringstream ss(linea);
        Alumno a;

        if (getline(ss, a.nombre, '|') &&
            getline(ss, a.matricula, '|') &&
            getline(ss, c1, '|') &&
            getline(ss, c2, '|') &&
            getline(ss, c3, '|') &&
            getline(ss, c4, '|')) {

            try {
                a.calif[0] = stof(c1);
                a.calif[1] = stof(c2);
                a.calif[2] = stof(c3);
                a.grupo = stoi(c4);

                alumnos[n++] = a;
            }
            catch (...) {}
        }
    }

    entrada.close();

    ofstream binario("alumnos.dat", ios::binary);

    if (!binario) {
        cout << "Error al crear archivo binario.";
        return 1;
    }

    binario.write(
        reinterpret_cast<const char*>(&n),
        sizeof(n)
    );

    for (int i = 0; i < n; i++) {
        escribirCadena(binario, alumnos[i].nombre);
        escribirCadena(binario, alumnos[i].matricula);

        binario.write(
            reinterpret_cast<const char*>(alumnos[i].calif),
            sizeof(alumnos[i].calif)
        );

        binario.write(
            reinterpret_cast<const char*>(&alumnos[i].grupo),
            sizeof(alumnos[i].grupo)
        );
    }

    binario.close();

    ifstream texto("alumnos.txt", ios::binary | ios::ate);
    ifstream datos("alumnos.dat", ios::binary | ios::ate);

    cout << "\nAlumnos guardados: " << n;
    cout << "\nTamano del archivo de texto: "
         << texto.tellg() << " bytes";

    cout << "\nTamano del archivo binario: "
         << datos.tellg() << " bytes";

    cout << "\nLos tamanos son diferentes porque "
         << "el texto usa caracteres y separadores, "
         << "mientras el binario guarda datos en "
         << "representacion interna.";

    return 0;
}
