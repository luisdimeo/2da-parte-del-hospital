#include "GestorArchivos.hpp"
#include "Constantes.hpp"
#include "../pacientes/Pacientes.hpp"
#include "../doctores/Doctor.hpp"
#include "../citas/Cita.hpp"
#include "../historial/HistorialMedico.hpp"
#include <fstream>
#include <iostream>

// ===== Inicialización =====
bool GestorArchivos::inicializarSistemaArchivos() {
    std::ofstream f1(Rutas::PACIENTES, std::ios::binary | std::ios::app);
    std::ofstream f2(Rutas::DOCTORES, std::ios::binary | std::ios::app);
    std::ofstream f3(Rutas::CITAS, std::ios::binary | std::ios::app);
    std::ofstream f4(Rutas::HISTORIALES, std::ios::binary | std::ios::app);

    bool ok = f1 && f2 && f3 && f4;
    f1.close(); f2.close(); f3.close(); f4.close();
    return ok;
}

// ===== Pacientes =====
bool GestorArchivos::guardarPaciente(Paciente& p) {
    std::ofstream archivo(Rutas::PACIENTES, std::ios::binary | std::ios::app);
    if (!archivo) return false;
    archivo.write(reinterpret_cast<char*>(&p), sizeof(Paciente));
    return true;
}

bool GestorArchivos::leerPacientePorID(int id, Paciente& p) {
    std::ifstream archivo(Rutas::PACIENTES, std::ios::binary);
    if (!archivo) return false;
    while (archivo.read(reinterpret_cast<char*>(&p), sizeof(Paciente))) {
        if (p.getId() == id && !p.estaEliminado()) return true;
    }
    return false;
}

bool GestorArchivos::actualizarPacientePorID(const Paciente& nuevo) {
    std::fstream archivo(Rutas::PACIENTES, std::ios::binary | std::ios::in | std::ios::out);
    if (!archivo) return false;
    Paciente p;
    while (archivo.read(reinterpret_cast<char*>(&p), sizeof(Paciente))) {
        if (p.getId() == nuevo.getId()) {
            archivo.seekp(-static_cast<int>(sizeof(Paciente)), std::ios::cur);
            archivo.write(reinterpret_cast<const char*>(&nuevo), sizeof(Paciente));
            return true;
        }
    }
    return false;
}



void GestorArchivos::listarTodosPacientes() {
    std::ifstream archivo(Rutas::PACIENTES, std::ios::binary);
    if (!archivo) {
        std::cout << "No se pudo abrir el archivo de pacientes.\n";
        return;
    }

    Paciente p;
    bool encontrado = false;

    while (archivo.read(reinterpret_cast<char*>(&p), sizeof(Paciente))) {
        if (!p.estaEliminado()) {   // solo mostrar si no está eliminado
            p.mostrarInformacion();
            encontrado = true;
        }
    }

    if (!encontrado) {
        std::cout << "No hay pacientes registrados.\n";
    }

    archivo.close();
}
bool GestorArchivos::eliminarPacientePorID(int id) {
    std::fstream archivo(Rutas::PACIENTES, std::ios::binary | std::ios::in | std::ios::out);
    if (!archivo) return false;

    Paciente p;
    while (archivo.read(reinterpret_cast<char*>(&p), sizeof(Paciente))) {
        if (p.getId() == id && !p.estaEliminado()) {
            p.marcarEliminado();  // marcar eliminado
            archivo.seekp(-static_cast<int>(sizeof(Paciente)), std::ios::cur);
            archivo.write(reinterpret_cast<const char*>(&p), sizeof(Paciente));
            archivo.close();
            return true;
        }
    }
    archivo.close();
    return false;
}

// ===== Doctores =====
bool GestorArchivos::guardarDoctor(Doctor& d) {
    std::ofstream archivo(Rutas::DOCTORES, std::ios::binary | std::ios::app);
    if (!archivo) return false;
    archivo.write(reinterpret_cast<char*>(&d), sizeof(Doctor));
    return true;
}

bool GestorArchivos::leerDoctorPorID(int id, Doctor& d) {
    std::ifstream archivo(Rutas::DOCTORES, std::ios::binary);
    if (!archivo) return false;
    while (archivo.read(reinterpret_cast<char*>(&d), sizeof(Doctor))) {
        if (d.getId() == id && !d.estaDisponible()) return true;
    }
    return false;
}

bool GestorArchivos::actualizarDoctorPorID(const Doctor& nuevo) {
    std::fstream archivo(Rutas::DOCTORES, std::ios::binary | std::ios::in | std::ios::out);
    if (!archivo) return false;
    Doctor d;
    while (archivo.read(reinterpret_cast<char*>(&d), sizeof(Doctor))) {
        if (d.getId() == nuevo.getId()) {
            archivo.seekp(-static_cast<int>(sizeof(Doctor)), std::ios::cur);
            archivo.write(reinterpret_cast<const char*>(&nuevo), sizeof(Doctor));
            return true;
        }
    }
    return false;
}

bool GestorArchivos::eliminarDoctorPorID(int id) {
    std::fstream archivo(Rutas::DOCTORES, std::ios::binary | std::ios::in | std::ios::out);
    if (!archivo) return false;
    Doctor d;
    while (archivo.read(reinterpret_cast<char*>(&d), sizeof(Doctor))) {
        if (d.getId() == id) {
            d.marcarEliminado();
            archivo.seekp(-static_cast<int>(sizeof(Doctor)), std::ios::cur);
            archivo.write(reinterpret_cast<char*>(&d), sizeof(Doctor));
            return true;
        }
    }
    return false;
}

void GestorArchivos::listarTodosDoctores() {
    std::ifstream archivo(Rutas::DOCTORES, std::ios::binary);
    if (!archivo) {
        std::cout << "No hay doctores registrados.\n";
        return;
    }

    Doctor d;
    while (archivo.read(reinterpret_cast<char*>(&d), sizeof(Doctor))) {
            d.mostrarInformacion(); 
    }
    archivo.close();
}


// ===== Citas =====
bool GestorArchivos::guardarCita(Cita& c) {
    std::ofstream archivo(Rutas::CITAS, std::ios::binary | std::ios::app);
    if (!archivo) return false;
    archivo.write(reinterpret_cast<char*>(&c), sizeof(Cita));
    return true;
}

bool GestorArchivos::leerCitaPorID(int id, Cita& c) {
    std::ifstream archivo(Rutas::CITAS, std::ios::binary);
    if (!archivo) return false;
    while (archivo.read(reinterpret_cast<char*>(&c), sizeof(Cita))) {
        if (c.getId() == id && !c.estaEliminada()) return true;
    }
    return false;
}

bool GestorArchivos::actualizarCitaPorID(const Cita& nueva) {
    std::fstream archivo(Rutas::CITAS, std::ios::binary | std::ios::in | std::ios::out);
    if (!archivo) return false;
    Cita c;
    while (archivo.read(reinterpret_cast<char*>(&c), sizeof(Cita))) {
        if (c.getId() == nueva.getId()) {
            archivo.seekp(-static_cast<int>(sizeof(Cita)), std::ios::cur);
            archivo.write(reinterpret_cast<const char*>(&nueva), sizeof(Cita));
            return true;
        }
    }
    return false;
}

void GestorArchivos::listarTodasCitas() {
    std::ifstream archivo(Rutas::CITAS, std::ios::binary);
    Cita c;
    while (archivo.read(reinterpret_cast<char*>(&c), sizeof(Cita))) {
        if (!c.estaEliminada()) c.mostrarInformacion();
    }
}

// ===== Historial Médico =====
bool GestorArchivos::guardarHistorial(HistorialMedico& h) {
    std::ofstream archivo(Rutas::HISTORIALES, std::ios::binary | std::ios::app);
    if (!archivo) return false;
    archivo.write(reinterpret_cast<char*>(&h), sizeof(HistorialMedico));
    return true;
}

bool GestorArchivos::leerHistorialPorID(int id, HistorialMedico& h) {
    std::ifstream archivo(Rutas::HISTORIALES, std::ios::binary);
    if (!archivo) return false;
    while (archivo.read(reinterpret_cast<char*>(&h), sizeof(HistorialMedico))) {
        if (h.getId() == id && !h.estaEliminado()) return true;
    }
    return false;
}

bool GestorArchivos::eliminarHistorialPorID(int id) {
    std::fstream archivo(Rutas::HISTORIALES, std::ios::binary | std::ios::in | std::ios::out);
    if (!archivo) return false;
    HistorialMedico h;
    while (archivo.read(reinterpret_cast<char*>(&h), sizeof(HistorialMedico))) {
        if (h.getId() == id) {
            h.marcarEliminado();
            archivo.seekp(-static_cast<int>(sizeof(HistorialMedico)), std::ios::cur);
            archivo.write(reinterpret_cast<char*>(&h), sizeof(HistorialMedico));
            return true;
        }
    }
    return false;
}

void GestorArchivos::listarTodosHistoriales() {
    std::ifstream archivo(Rutas::HISTORIALES, std::ios::binary);
    HistorialMedico h;
    while (archivo.read(reinterpret_cast<char*>(&h), sizeof(HistorialMedico))) {
        if (!h.estaEliminado()) h.mostrarInformacion();
    }
} 

int GestorArchivos::obtenerNuevoIdDoctor() {
    std::ifstream archivo(Rutas::DOCTORES, std::ios::binary);
    if (!archivo) return 1; // primer doctor

    Doctor d;
    int ultimoId = 0;
    while (archivo.read(reinterpret_cast<char*>(&d), sizeof(Doctor))) {
        ultimoId = d.getId();
    }
    archivo.close();
    return ultimoId + 1;
}
