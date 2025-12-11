#include "Pacientes.hpp"
#include <cstring>
#include <iostream>

Paciente::Paciente() {
    id = 0;
    edad = 0;
    eliminado = false;
    strcpy(nombre, "");
    strcpy(telefono, "");
    strcpy(direccion, "");
    strcpy(sintomas, "");
    strcpy(gmail, "");
}

// ===== Getters =====
int Paciente::getId() const { return id; }
bool Paciente::estaEliminado() const { return eliminado; }

// ===== Setters =====
void Paciente::setId(int nuevoId) { id = nuevoId; }

void Paciente::setNombre(const char* nuevoNombre) {
    strncpy(nombre, nuevoNombre, sizeof(nombre) - 1);
    nombre[sizeof(nombre) - 1] = '\0';
}

void Paciente::setEdad(int nuevaEdad) { edad = nuevaEdad; }
void Paciente::setDireccion(const char* d) {
    strncpy(direccion, d, 99);
    direccion[99] = '\0';
}

void Paciente::setSintomas(const char* s) {
    strncpy(sintomas, s, 99);
    sintomas[99] = '\0';
}

const char* Paciente::getTelefono() const { 
    return telefono; 
}

const char* Paciente::getDireccion() const {
    return direccion;
}

const char* Paciente::getSintomas() const {
    return sintomas;
}

const char* Paciente::getGmail() const {
    return gmail;
}
void Paciente::setTelefono(const char* nuevoTelefono) {
    strncpy(telefono, nuevoTelefono, sizeof(telefono) - 1);
    telefono[sizeof(telefono) - 1] = '\0';
}
void Paciente::setGmail(const char* g) {
    strncpy(gmail, g, sizeof(gmail) - 1);
    gmail[sizeof(gmail) - 1] = '\0';
}

void Paciente::mostrarInformacion() const {
    std::cout << "ID: " << id
              << " | Nombre: " << nombre
              << " | Edad: " << edad
              << " | Telefono: " << telefono
              << " | Direccion: " << direccion
              << " | Sintomas: " << sintomas
              << " | Gmail: " << gmail
              << (eliminado ? " (Eliminado)" : "")
              << "\n";
}
void Paciente::marcarEliminado() { eliminado = true; }