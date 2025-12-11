#ifndef OPERACIONES_CITAS_HPP
#define OPERACIONES_CITAS_HPP

#include "../hospital/Hospital.hpp"

// Funciones de negocio para citas
void registrarCita(Hospital& hospital);
void listarCitas();
void buscarCitaPorID();
void cancelarCita();
void marcarCitaAtendida();

#endif
