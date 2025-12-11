#include "operacionesDoctores.hpp"
#include "../doctores/Doctor.hpp"
#include "../persistencia/GestorArchivos.hpp"
#include <iostream>
#include <limits>

using namespace std;

void registrarDoctor(Hospital& hospital) {
    Doctor d;
    char nombre[50], apellido[50], especialidad[50], telefono[15];
    int experiencia;
    float costo;

    cin.ignore();
    cout << "Nombre: "; cin.getline(nombre, 50);
    cout << "Apellido: "; cin.getline(apellido, 50);
    cout << "Especialidad: "; cin.getline(especialidad, 50);
    cout << "Telefono: "; cin.getline(telefono, 15);
    cout << "Años de experiencia: "; cin >> experiencia;
    cout << "Costo de consulta: "; cin >> costo;

    d.setId(hospital.obtenerNuevoIdDoctor());
    d.setNombre(nombre);
    d.setApellido(apellido);
    d.setEspecialidad(especialidad);
    d.setTelefono(telefono);
    d.setExperiencia(experiencia);
    d.setCostoConsulta(costo);

    if (GestorArchivos::guardarDoctor(d)) {
        hospital.incrementarDoctores();
        std::cout << " Doctor registrado.\n";
    } else {
        std::cout << " Error al guardar.\n";
    }
}

void listarDoctores() {
    GestorArchivos::listarTodosDoctores();
}

void buscarDoctorPorID() {
    int id; cout << "ID a buscar: "; cin >> id; cin.ignore();
    Doctor d;
    if (GestorArchivos::leerDoctorPorID(id, d)) d.mostrarInformacion();
    else cout << "No encontrado.\n";
}

void modificarDoctor() {
    int id; cout << "ID a modificar: "; cin >> id; cin.ignore();
    Doctor d;
    if (!GestorArchivos::leerDoctorPorID(id, d)) { cout << "No encontrado.\n"; return; }

    char nombre[50], especialidad[50];
    cout << "Nuevo nombre: "; cin.getline(nombre, 50);
    cout << "Nueva especialidad: "; cin.getline(especialidad, 50);

    d.setNombre(nombre);
    d.setEspecialidad(especialidad);

    if (GestorArchivos::actualizarDoctorPorID(d)) cout << "✓ Actualizado.\n";
    else cout << " Error al actualizar.\n";
}

void eliminarDoctor() {
    int id; cout << "ID a eliminar: "; cin >> id; cin.ignore();
    if (GestorArchivos::eliminarDoctorPorID(id)) cout << "✓ Eliminado.\n";
    else cout << " No se pudo eliminar.\n";
}
