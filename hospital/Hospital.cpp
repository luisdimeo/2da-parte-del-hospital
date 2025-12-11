#include "Hospital.hpp"

Hospital::Hospital() {
    strcpy(nombre, "");
    strcpy(direccion, "");
    strcpy(telefono, "");
    siguienteIDPaciente = 1;
    siguienteIDDoctor = 1;
    siguienteIDCita = 1;
    siguienteIDConsulta = 1;
    totalPacientesRegistrados = 0;
    totalDoctoresRegistrados = 0;
    totalCitasAgendadas = 0;
    totalConsultasRealizadas = 0;
}

Hospital::Hospital(const char* n, const char* d, const char* t) {
    strncpy(nombre, n, 99); nombre[99] = '\0';
    strncpy(direccion, d, 149); direccion[149] = '\0';
    strncpy(telefono, t, 14); telefono[14] = '\0';
    siguienteIDPaciente = 1;
    siguienteIDDoctor = 1;
    siguienteIDCita = 1;
    siguienteIDConsulta = 1;
    totalPacientesRegistrados = 0;
    totalDoctoresRegistrados = 0;
    totalCitasAgendadas = 0;
    totalConsultasRealizadas = 0;
}

// ===== Getters =====
const char* Hospital::getNombre() const { return nombre; }
const char* Hospital::getDireccion() const { return direccion; }
const char* Hospital::getTelefono() const { return telefono; }

int Hospital::getSiguienteIDPaciente() const { return siguienteIDPaciente; }
int Hospital::getSiguienteIDDoctor() const { return siguienteIDDoctor; }
int Hospital::getSiguienteIDCita() const { return siguienteIDCita; }
int Hospital::getSiguienteIDConsulta() const { return siguienteIDConsulta; }

int Hospital::getTotalPacientes() const { return totalPacientesRegistrados; }
int Hospital::getTotalDoctores() const { return totalDoctoresRegistrados; }
int Hospital::getTotalCitas() const { return totalCitasAgendadas; }
int Hospital::getTotalConsultas() const { return totalConsultasRealizadas; }

// ===== Setters =====
void Hospital::setNombre(const char* n) { strncpy(nombre, n, 99); nombre[99] = '\0'; }
void Hospital::setDireccion(const char* d) { strncpy(direccion, d, 149); direccion[149] = '\0'; }
void Hospital::setTelefono(const char* t) { strncpy(telefono, t, 14); telefono[14] = '\0'; }

// ===== Generadores de ID =====
int Hospital::generarNuevoIDPaciente() { return siguienteIDPaciente++; }
int Hospital::generarNuevoIDDoctor() { return siguienteIDDoctor++; }
int Hospital::generarNuevoIDCita() { return siguienteIDCita++; }
int Hospital::generarNuevoIDConsulta() { return siguienteIDConsulta++; }

// ===== Incrementadores =====
void Hospital::incrementarPacientes() { totalPacientesRegistrados++; }
void Hospital::incrementarDoctores() { totalDoctoresRegistrados++; }
void Hospital::incrementarCitas() { totalCitasAgendadas++; }
void Hospital::incrementarConsultas() { totalConsultasRealizadas++; }

// ===== Presentación =====
void Hospital::mostrarInformacion() const {
    std::cout << "Hospital: " << nombre
              << "\nDireccion: " << direccion
              << "\nTelefono: " << telefono
              << "\nPacientes registrados: " << totalPacientesRegistrados
              << "\nDoctores registrados: " << totalDoctoresRegistrados
              << "\nCitas agendadas: " << totalCitasAgendadas
              << "\nConsultas realizadas: " << totalConsultasRealizadas
              << std::endl;
}
