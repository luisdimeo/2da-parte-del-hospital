#include "operacionesCitas.hpp"
#include "../citas/Cita.hpp"
#include "../persistencia/GestorArchivos.hpp"
#include <iostream>
#include <limits>

using namespace std;

void registrarCita(Hospital& hospital) {
    Cita c;
    int pacienteID, doctorID;
    char fecha[11], hora[6], motivo[150];

    cout << "ID del paciente: "; cin >> pacienteID; cin.ignore();
    cout << "ID del doctor: "; cin >> doctorID; cin.ignore();
    cout << "Fecha (DD/MM/AAAA): "; cin.getline(fecha, 11);
    cout << "Hora (HH:MM): "; cin.getline(hora, 6);
    cout << "Motivo: "; cin.getline(motivo, 150);

    c.setId(hospital.generarNuevoIDCita());
    c.setPacienteID(pacienteID);
    c.setDoctorID(doctorID);
    c.setFecha(fecha);
    c.setHora(hora);
    c.setMotivo(motivo);
    c.setEstado("Agendada");

    if (GestorArchivos::guardarCita(c)) {
        hospital.incrementarCitas();
        cout << "Cita registrada.\n";
    } else {
        cout << " Error al guardar.\n";
    }
}

void listarCitas() {
    GestorArchivos::listarTodasCitas();
}

void buscarCitaPorID() {
    int id; cout << "ID de la cita: "; cin >> id; cin.ignore();
    Cita c;
    if (GestorArchivos::leerCitaPorID(id, c)) c.mostrarInformacion();
    else cout << "No encontrada.\n";
}

void cancelarCita() {
    int id; cout << "ID de la cita a cancelar: "; cin >> id; cin.ignore();
    Cita c;
    if (!GestorArchivos::leerCitaPorID(id, c)) { cout << "No encontrada.\n"; return; }
    c.cancelar();
    if (GestorArchivos::actualizarCitaPorID(c)) cout << "✓ Cancelada.\n";
    else cout << " Error al cancelar.\n";
}

void marcarCitaAtendida() {
    int id; cout << "ID de la cita atendida: "; cin >> id; cin.ignore();
    Cita c;
    if (!GestorArchivos::leerCitaPorID(id, c)) { cout << "No encontrada.\n"; return; }
    c.marcarComoAtendida();
    if (GestorArchivos::actualizarCitaPorID(c)) cout << "✓ Marcada como atendida.\n";
    else cout << " Error al actualizar.\n";
}
