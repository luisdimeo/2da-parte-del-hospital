#ifndef GESTOR_ARCHIVOS_HPP
#define GESTOR_ARCHIVOS_HPP

#include "../Pacientes/Pacientes.hpp"
#include "../Doctores/Doctor.hpp"
#include "../citas/Cita.hpp"
#include "../historial/HistorialMedico.hpp"
#include "../hospital/Hospital.hpp"
#include "Constantes.hpp"
#include <fstream>

// ===== Header de cada archivo binario =====
struct ArchivoHeader {
    int cantidadRegistros;   // total de registros escritos
    int proximoID;           // ID que se asignará al siguiente registro
    int registrosActivos;    // registros no eliminados
    int version;             // versión del archivo
};

class GestorArchivos {
public:
    static bool inicializarSistemaArchivos();
    static bool guardarPaciente(Paciente&);
    static bool actualizarPacientePorID(const Paciente&);
    static bool eliminarPacientePorID(int);
    static void listarTodosPacientes();
    static bool leerPacientePorID(int, Paciente&);

    static bool guardarDoctor(Doctor&);
    static bool actualizarDoctorPorID(const Doctor&);
    static bool eliminarDoctorPorID(int);
    static void listarTodosDoctores();
    static bool leerDoctorPorID(int, Doctor&);

    static bool guardarCita(Cita&);
    static bool actualizarCitaPorID(const Cita&);
    static void listarTodasCitas();
    static bool leerCitaPorID(int, Cita&);

    static bool guardarHistorial(HistorialMedico&);
    static void listarTodosHistoriales();
    static bool leerHistorialPorID(int id, HistorialMedico& h);   
    static bool eliminarHistorialPorID(int id); 
    static int obtenerNuevoIdDoctor();
    
};
#endif
