#ifndef CITA_HPP
#define CITA_HPP

#include <cstring>
#include <iostream>
#include "../doctores/Doctor.hpp"

class Cita {
private:
    int id;
    int pacienteID;
    int doctorID;
    char fecha[11];        // formato DD/MM/AAAA
    char hora[6];          // formato HH:MM
    char motivo[150];
    char estado[20];       // "Agendada", "Atendida", "Cancelada"
    char observaciones[200];
    bool atendida;
    int consultaID;        // ID de consulta creada al atender (-1 si no existe)
    bool eliminado;

public:
    // ===== Constructores =====
    Cita();
    Cita(int id, int pacienteID, int doctorID,
         const char* fecha, const char* hora,
         const char* motivo, const char* estado);

    // ===== Getters =====
    int getId() const;
    int getPacienteID() const;
    int getDoctorID() const;
    const char* getFecha() const;
    const char* getHora() const;
    const char* getMotivo() const;
    const char* getEstado() const;
    const char* getObservaciones() const;
    bool estaAtendida() const;
    int getConsultaID() const;
    bool estaEliminada() const;

    // ===== Setters =====
    void setId(int nuevoId);
    void setPacienteID(int pid);
    void setDoctorID(int did);
    void setFecha(const char* f);
    void setHora(const char* h);
    void setMotivo(const char* m);
    void setEstado(const char* e);
    void setObservaciones(const char* o);
    void setConsultaID(int cid);
    void marcarEliminada();

    // ===== Métodos de gestión =====
    static size_t tamanoRegistro();
    void marcarComoAtendida();
    void cancelar();

    // ===== Presentación =====
    void mostrarInformacion() const;

    // ===== Persistencia =====
    static bool guardar(const Doctor& d);          // Guardar en archivo binario
    static bool leerPorID(int id, Doctor& d);      // Leer por ID
    static bool eliminarPorID(int id);             // Eliminar por ID
    static void listarTodos();
};

#endif
