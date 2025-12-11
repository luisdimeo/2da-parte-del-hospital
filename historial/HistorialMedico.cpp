#include "HistorialMedico.hpp"

HistorialMedico::HistorialMedico() {
    id = -1; pacienteID = -1; doctorID = -1;
    costo = 0.0f; siguienteConsultaID = -1; eliminado = false;
    strcpy(fecha, ""); strcpy(hora, "");
    strcpy(diagnostico, ""); strcpy(tratamiento, "");
    strcpy(medicamentos, "");
}

HistorialMedico::HistorialMedico(int id, int pid, const char* f, const char* h,
                                 const char* d, const char* t,
                                 const char* m, int did, float c) {
    this->id = id; this->pacienteID = pid; this->doctorID = did;
    this->costo = c; this->siguienteConsultaID = -1; eliminado = false;
    strncpy(fecha, f, 10); fecha[10] = '\0';
    strncpy(hora, h, 5); hora[5] = '\0';
    strncpy(diagnostico, d, 199); diagnostico[199] = '\0';
    strncpy(tratamiento, t, 199); tratamiento[199] = '\0';
    strncpy(medicamentos, m, 149); medicamentos[149] = '\0';
}

// ===== Getters =====
int HistorialMedico::getId() const { return id; }
int HistorialMedico::getPacienteID() const { return pacienteID; }
const char* HistorialMedico::getFecha() const { return fecha; }
const char* HistorialMedico::getHora() const { return hora; }
const char* HistorialMedico::getDiagnostico() const { return diagnostico; }
const char* HistorialMedico::getTratamiento() const { return tratamiento; }
const char* HistorialMedico::getMedicamentos() const { return medicamentos; }
int HistorialMedico::getDoctorID() const { return doctorID; }
float HistorialMedico::getCosto() const { return costo; }
int HistorialMedico::getSiguienteConsultaID() const { return siguienteConsultaID; }
bool HistorialMedico::estaEliminado() const { return eliminado; }

// ===== Setters =====
void HistorialMedico::setId(int nuevoId) { id = nuevoId; }
void HistorialMedico::setPacienteID(int pid) { pacienteID = pid; }
void HistorialMedico::setFecha(const char* f) { strncpy(fecha, f, 10); fecha[10] = '\0'; }
void HistorialMedico::setHora(const char* h) { strncpy(hora, h, 5); hora[5] = '\0'; }
void HistorialMedico::setDiagnostico(const char* d) { strncpy(diagnostico, d, 199); diagnostico[199] = '\0'; }
void HistorialMedico::setTratamiento(const char* t) { strncpy(tratamiento, t, 199); tratamiento[199] = '\0'; }
void HistorialMedico::setMedicamentos(const char* m) { strncpy(medicamentos, m, 149); medicamentos[149] = '\0'; }
void HistorialMedico::setDoctorID(int did) { doctorID = did; }
void HistorialMedico::setCosto(float c) { if(c >= 0) costo = c; }
void HistorialMedico::setSiguienteConsultaID(int id) { siguienteConsultaID = id; }
void HistorialMedico::marcarEliminado() { eliminado = true; }

// ===== Presentación =====
void HistorialMedico::mostrarInformacion() const {
    std::cout << "ID: " << id
              << "\nPaciente ID: " << pacienteID
              << "\nDoctor ID: " << doctorID
              << "\nFecha: " << fecha
              << "\nDiagnostico: " << diagnostico
              << "\nTratamiento: " << tratamiento
              << (eliminado ? " (Eliminado)" : "")
              << "\n";
}

// ===== Persistencia =====
size_t HistorialMedico::tamanoRegistro() { return sizeof(HistorialMedico); }
