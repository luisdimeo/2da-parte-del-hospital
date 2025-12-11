#include "Doctor.hpp"
#include <iostream>
#include <cstring>

// ===== Constructores =====
Doctor::Doctor() : id(0), experiencia(0), costoConsulta(0.0f), disponible(true), eliminado(false) {
    strcpy(nombre, "");
    strcpy(apellido, "");
    strcpy(especialidad, "");
    strcpy(telefono, "");
}

Doctor::Doctor(int id, const char* nombre, const char* especialidad)
    : id(id), experiencia(0), costoConsulta(0.0f), disponible(true), eliminado(false) {
    strncpy(this->nombre, nombre, sizeof(this->nombre));
    strncpy(this->especialidad, especialidad, sizeof(this->especialidad));
    strcpy(this->apellido, "");
    strcpy(this->telefono, "");
}

// ===== Getters =====
int Doctor::getId() const { return id; }
const char* Doctor::getNombre() const { return nombre; }
const char* Doctor::getApellido() const { return apellido; }
const char* Doctor::getEspecialidad() const { return especialidad; }
const char* Doctor::getTelefono() const { return telefono; }
int Doctor::getExperiencia() const { return experiencia; }
float Doctor::getCostoConsulta() const { return costoConsulta; }
bool Doctor::estaDisponible() const { return disponible; }

// ===== Setters =====
void Doctor::setId(int nuevoId) { id = nuevoId; }
void Doctor::setNombre(const char* n) { strncpy(nombre, n, sizeof(nombre)); }
void Doctor::setApellido(const char* a) { strncpy(apellido, a, sizeof(apellido)); }
void Doctor::setEspecialidad(const char* e) { strncpy(especialidad, e, sizeof(especialidad)); }
void Doctor::setTelefono(const char* t) { strncpy(telefono, t, sizeof(telefono)); }
void Doctor::setExperiencia(int exp) { experiencia = exp; }
void Doctor::setCostoConsulta(float c) { costoConsulta = c; }
void Doctor::setDisponible(bool d) { disponible = d; }

// ===== Métodos =====
void Doctor::marcarEliminado() { eliminado = true; }

void Doctor::mostrarInformacion() const {
    std::cout << "ID: " << id
              << "\nNombre: " << nombre << " " << apellido
              << "\nEspecialidad: " << especialidad
              << "\nTelefono: " << telefono
              << "\nAños de experiencia: " << experiencia
              << "\nCosto de consulta: " << costoConsulta
              << (eliminado ? " (Eliminado)" : "")
              << (disponible ? " (Disponible)" : " (No disponible)")
              << "\n";
}

