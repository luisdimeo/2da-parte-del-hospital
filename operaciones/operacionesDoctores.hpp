#ifndef OPERACIONES_DOCTORES_HPP
#define OPERACIONES_DOCTORES_HPP

#include "../hospital/Hospital.hpp"

// Funciones de negocio para doctores
void registrarDoctor(Hospital& hospital);
void listarDoctores();
void buscarDoctorPorID();
void modificarDoctor();
void eliminarDoctor();

#endif
