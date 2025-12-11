#ifndef OPERACIONES_HISTORIAL_HPP
#define OPERACIONES_HISTORIAL_HPP

#include "../hospital/Hospital.hpp"

// Funciones de negocio para historial médico
void registrarConsulta(Hospital& hospital);
void listarHistorialPaciente(int pacienteID);

#endif
