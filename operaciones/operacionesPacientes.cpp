#include "operacionesPacientes.hpp"
#include "../pacientes/pacientes.hpp"
#include "../persistencia/GestorArchivos.hpp"
#include <iostream>
#include <limits>

using namespace std;
int obtenerNuevoIdPaciente() {
    std::ifstream archivo(Rutas::PACIENTES, std::ios::binary);
    if (!archivo) return 1;

    Paciente p;
    int maxId = 0;
    while (archivo.read(reinterpret_cast<char*>(&p), sizeof(Paciente))) {
        if (p.getId() > maxId) {
            maxId = p.getId();
        }
    }
    archivo.close();
    return maxId + 1;
}
void registrarPaciente(Hospital& hospital) {
    Paciente p;
    char nombre[50], direccion[100], sintomas[100], telefono[15], gmail[50];
    int edad;

    cout << "Nombre: "; cin.getline(nombre, 50);
    cout << "Edad: "; cin >> edad; cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Direccion: "; cin.getline(direccion, 100);
     cout << "Telefono: "; cin.getline(telefono, 15);
     cout << "Gmail: "; cin.getline(gmail, 50);
    cout << "Sintomas: "; cin.getline(sintomas, 100);

    p.setId(hospital.generarNuevoIDPaciente());
    p.setNombre(nombre);
    p.setEdad(edad);
    p.setDireccion(direccion);
    p.setSintomas(sintomas);
    p.setTelefono(telefono);
    p.setGmail(gmail);
    p.setId(obtenerNuevoIdPaciente());

    if (GestorArchivos::guardarPaciente(p)) {
        hospital.incrementarPacientes();
        cout << " Paciente registrado.\n";
    } else {
        cout << " Error al guardar.\n";
    }
}

void listarPacientes() {
    GestorArchivos::listarTodosPacientes();
}

void buscarPacientePorID() {
    int id; cout << "ID a buscar: "; cin >> id; cin.ignore();
    Paciente p;
    if (GestorArchivos::leerPacientePorID(id, p)) p.mostrarInformacion();
    else cout << "No encontrado.\n";
}

void modificarPaciente() {
    int id; cout << "ID a modificar: "; cin >> id; cin.ignore();
    Paciente p;
    if (!GestorArchivos::leerPacientePorID(id, p)) { cout << "No encontrado.\n"; return; }

    char nombre[50], direccion[100], sintomas[100], telefono[15], gmail[50];
    int edad;
    cout << "Nuevo nombre: "; cin.getline(nombre, 50);
    cout << "Nueva edad: "; cin >> edad; cin.ignore();
    cout << "Nueva direccion: "; cin.getline(direccion, 100);
    cout << "Telefono: "; cin.getline(telefono, 15);
     cout << "Gmail: "; cin.getline(gmail, 50);
    cout << "Nuevos sintomas: "; cin.getline(sintomas, 100);

    p.setNombre(nombre); p.setEdad(edad); p.setDireccion(direccion); p.setSintomas(sintomas); p.setTelefono(telefono); p.setGmail(gmail);

    if (GestorArchivos::actualizarPacientePorID(p)) cout << "✓ Actualizado.\n";
    else cout << " Error al actualizar.\n";
}

void eliminarPaciente() {
    int id; cout << "ID a eliminar: "; cin >> id; cin.ignore();
    if (GestorArchivos::eliminarPacientePorID(id)) cout << "✓ Eliminado.\n";
    else cout << " No se pudo eliminar.\n";
}
