#include "Cita.hpp"

Cita::Cita() {
    id = -1; pacienteID = -1; doctorID = -1;
    atendida = false; consultaID = -1; eliminado = false;
    strcpy(fecha, ""); strcpy(hora, "");
    strcpy(motivo, ""); strcpy(estado, "Agendada");
    strcpy(observaciones, "");
}

Cita::Cita(int id, int pid, int did, const char* f, const char* h,
           const char* m, const char* e) {
    this->id = id; this->pacienteID = pid; this->doctorID = did;
    atendida = false; consultaID = -1; eliminado = false;
    strncpy(fecha, f, 10); fecha[10] = '\0';
    strncpy(hora, h, 5); hora[5] = '\0';
    strncpy(motivo, m, 149); motivo[149] = '\0';
    strncpy(estado, e, 19); estado[19] = '\0';
    strcpy(observaciones, "");
}

// ===== Getters =====
int Cita::getId() const { return id; }
int Cita::getPacienteID() const { return pacienteID; }
int Cita::getDoctorID() const { return doctorID; }
const char* Cita::getFecha() const { return fecha; }
const char* Cita::getHora() const { return hora; }
const char* Cita::getMotivo() const { return motivo; }
const char* Cita::getEstado() const { return estado; }
const char* Cita::getObservaciones() const { return observaciones; }
bool Cita::estaAtendida() const { return atendida; }
int Cita::getConsultaID() const { return consultaID; }
bool Cita::estaEliminada() const { return eliminado; }

// ===== Setters =====
void Cita::setId(int nuevoId) { id = nuevoId; }
void Cita::setPacienteID(int pid) { pacienteID = pid; }
void Cita::setDoctorID(int did) { doctorID = did; }
void Cita::setFecha(const char* f) { strncpy(fecha, f, 10); fecha[10] = '\0'; }
void Cita::setHora(const char* h) { strncpy(hora, h, 5); hora[5] = '\0'; }
void Cita::setMotivo(const char* m) { strncpy(motivo, m, 149); motivo[149] = '\0'; }
void Cita::setEstado(const char* e) { strncpy(estado, e, 19); estado[19] = '\0'; }
void Cita::setObservaciones(const char* o) { strncpy(observaciones, o, 199); observaciones[199] = '\0'; }
void Cita::setConsultaID(int cid) { consultaID = cid; }
void Cita::marcarEliminada() { eliminado = true; }

// ===== Métodos de gestión =====
void Cita::marcarComoAtendida() {
    atendida = true;
    strcpy(estado, "Atendida");
}

void Cita::cancelar() {
    eliminado = true;
    strcpy(estado, "Cancelada");
}

// ===== Presentación =====
void Cita::mostrarInformacion() const {
    std::cout << "Cita ID: " << id
              << " | Paciente: " << pacienteID
              << " | Doctor: " << doctorID
              << " | Fecha: " << fecha
              << " | Hora: " << hora
              << " | Estado: " << estado
              << "\nMotivo: " << motivo
              << "\nObservaciones: " << observaciones
              << "\nConsultaID: " << consultaID
              << "\nEliminada: " << (eliminado ? "Si" : "No") << "\n";
}

// ===== Persistencia =====
size_t Cita::tamanoRegistro() { return sizeof(Cita); }
