#ifndef OPERACIONES_PACIENTES_HPP
#define OPERACIONES_PACIENTES_HPP

#include "../hospital/Hospital.hpp"

// Funciones de negocio para pacientes
void registrarPaciente(Hospital& hospital);
void listarPacientes();
void buscarPacientePorID();
void modificarPaciente();
void eliminarPaciente();
int obtenerNuevoIdPaciente();
#endif
