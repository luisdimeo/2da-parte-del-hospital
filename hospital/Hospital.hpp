#ifndef HOSPITAL_HPP
#define HOSPITAL_HPP

#include <cstring>
#include <iostream>

class Hospital {
private:
    char nombre[100];
    char direccion[150];
    char telefono[15];
     int contadorDoctores;

    // Contadores de IDs
    int siguienteIDPaciente;
    int siguienteIDDoctor;
    int siguienteIDCita;
    int siguienteIDConsulta;

    // Estadísticas generales
    int totalPacientesRegistrados;
    int totalDoctoresRegistrados;
    int totalCitasAgendadas;
    int totalConsultasRealizadas;

public:
Hospital() : contadorDoctores(0) {}
    int obtenerNuevoIdDoctor() { return ++contadorDoctores; }
    // ===== Constructores =====
    Hospital();
    Hospital(const char* nombre, const char* direccion, const char* telefono);

    // ===== Getters =====
    const char* getNombre() const;
    const char* getDireccion() const;
    const char* getTelefono() const;

    int getSiguienteIDPaciente() const;
    int getSiguienteIDDoctor() const;
    int getSiguienteIDCita() const;
    int getSiguienteIDConsulta() const;

    int getTotalPacientes() const;
    int getTotalDoctores() const;
    int getTotalCitas() const;
    int getTotalConsultas() const;

    // ===== Setters =====
    void setNombre(const char* n);
    void setDireccion(const char* d);
    void setTelefono(const char* t);

    // ===== Generadores de ID =====
    int generarNuevoIDPaciente();
    int generarNuevoIDDoctor();
    int generarNuevoIDCita();
    int generarNuevoIDConsulta();

    // ===== Incrementadores de estadísticas =====
    void incrementarPacientes();
    void incrementarDoctores();
    void incrementarCitas();
    void incrementarConsultas();

    // ===== Presentación =====
    void mostrarInformacion() const;
};

#endif
