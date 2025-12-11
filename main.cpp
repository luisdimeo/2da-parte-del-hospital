#include <iostream>
#include "hospital/Hospital.hpp"
#include "persistencia/gestorArchivos.hpp"
#include "operaciones/operacionesPacientes.hpp"
#include "operaciones/operacionesDoctores.hpp"
#include "operaciones/operacionesCitas.hpp"
#include "operaciones/operacionesHistorial.hpp"

using namespace std;

void menuPacientes(Hospital& hospital) {
    int opcion;
    do {
        cout << "\n--- MENU PACIENTES ---\n";
        cout << "1. Registrar paciente\n";
        cout << "2. Listar pacientes\n";
        cout << "3. Buscar paciente por ID\n";
        cout << "4. Modificar paciente\n";
        cout << "5. Eliminar paciente\n";
        cout << "0. Volver\n";
        cout << "Opcion: "; cin >> opcion; cin.ignore();

        switch(opcion) {
            case 1: registrarPaciente(hospital); break;
            case 2: listarPacientes(); break;
            case 3: buscarPacientePorID(); break;
            case 4: modificarPaciente(); break;
            case 5: eliminarPaciente(); break;
        }
    } while(opcion != 0);
}

void menuDoctores(Hospital& hospital) {
    int opcion;
    do {
        cout << "\n--- MENU DOCTORES ---\n";
        cout << "1. Registrar doctor\n";
        cout << "2. Listar doctores\n";
        cout << "3. Buscar doctor por ID\n";
        cout << "4. Modificar doctor\n";
        cout << "5. Eliminar doctor\n";
        cout << "0. Volver\n";
        cout << "Opcion: "; cin >> opcion; cin.ignore();

        switch(opcion) {
            case 1: registrarDoctor(hospital); break;
            case 2: listarDoctores(); break;
            case 3: buscarDoctorPorID(); break;
            case 4: modificarDoctor(); break;
            case 5: eliminarDoctor(); break;
        }
    } while(opcion != 0);
}

void menuCitas(Hospital& hospital) {
    int opcion;
    do {
        cout << "\n--- MENU CITAS ---\n";
        cout << "1. Registrar cita\n";
        cout << "2. Listar citas\n";
        cout << "3. Buscar cita por ID\n";
        cout << "4. Cancelar cita\n";
        cout << "5. Marcar cita como atendida\n";
        cout << "0. Volver\n";
        cout << "Opcion: "; cin >> opcion; cin.ignore();

        switch(opcion) {
            case 1: registrarCita(hospital); break;
            case 2: listarCitas(); break;
            case 3: buscarCitaPorID(); break;
            case 4: cancelarCita(); break;
            case 5: marcarCitaAtendida(); break;
        }
    } while(opcion != 0);
}

void menuHistorial(Hospital& hospital) {
    int opcion;
    do {
        cout << "\n--- MENU HISTORIAL ---\n";
        cout << "1. Registrar consulta\n";
        cout << "2. Listar historial de paciente\n";
        cout << "0. Volver\n";
        cout << "Opcion: "; cin >> opcion; cin.ignore();

        switch(opcion) {
            case 1: registrarConsulta(hospital); break;
            case 2: {
                int pid; cout << "ID del paciente: "; cin >> pid; cin.ignore();
                listarHistorialPaciente(pid);
                break;
            }
        }
    } while(opcion != 0);
}

int main() {
    // Inicializar archivos binarios
    if (!GestorArchivos::inicializarSistemaArchivos()) {
        cout << " Error al inicializar archivos.\n";
        return 1;
    }

    Hospital hospital("Hospital Central", "Av. Principal", "0412-1234567");

    int opcion;
    do {
        cout << "\n=== SISTEMA DE GESTION HOSPITALARIA ===\n";
        cout << "1. Pacientes\n";
        cout << "2. Doctores\n";
        cout << "3. Citas\n";
        cout << "4. Historial medico\n";
        cout << "5. Mostrar informacion del hospital\n";
        cout << "0. Salir\n";
        cout << "Opcion: "; cin >> opcion; cin.ignore();

        switch(opcion) {
            case 1: menuPacientes(hospital); break;
            case 2: menuDoctores(hospital); break;
            case 3: menuCitas(hospital); break;
            case 4: menuHistorial(hospital); break;
            case 5: hospital.mostrarInformacion(); break;
        }
    } while(opcion != 0);

    cout << " Saliendo del sistema...\n";
    return 0;
}
