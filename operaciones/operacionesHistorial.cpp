#include "operacionesHistorial.hpp"
#include "../historial/HistorialMedico.hpp"
#include "../persistencia/GestorArchivos.hpp"
#include <iostream>
#include <limits>

using namespace std;

void registrarConsulta(Hospital& hospital) {
    HistorialMedico h;
    int pacienteID, doctorID;
    char fecha[11], hora[6], diagnostico[200], tratamiento[200], medicamentos[150];
    float costo;

    cout << "ID del paciente: "; cin >> pacienteID; cin.ignore();
    cout << "ID del doctor: "; cin >> doctorID; cin.ignore();
    cout << "Fecha (DD/MM/AAAA): "; cin.getline(fecha, 11);
    cout << "Hora (HH:MM): "; cin.getline(hora, 6);
    cout << "Diagnostico: "; cin.getline(diagnostico, 200);
    cout << "Tratamiento: "; cin.getline(tratamiento, 200);
    cout << "Medicamentos: "; cin.getline(medicamentos, 150);
    cout << "Costo: "; cin >> costo; cin.ignore();

    h.setId(hospital.generarNuevoIDConsulta());
    h.setPacienteID(pacienteID);
    h.setDoctorID(doctorID);
    h.setFecha(fecha);
    h.setHora(hora);
    h.setDiagnostico(diagnostico);
    h.setTratamiento(tratamiento);
    h.setMedicamentos(medicamentos);
    h.setCosto(costo);

    if (GestorArchivos::guardarHistorial(h)) {
        hospital.incrementarConsultas();
        cout << " Consulta registrada.\n";
    } else {
        cout << " Error al guardar.\n";
    }
}

void listarHistorialPaciente(int pacienteID) {
    cout << "Historial del paciente ID: " << pacienteID << "\n";
    GestorArchivos::listarTodasCitas();
    // Nota: aquí podrías filtrar por pacienteID si implementas esa lógica en GestorArchivos
}
