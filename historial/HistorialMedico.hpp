#ifndef HISTORIAL_MEDICO_HPP
#define HISTORIAL_MEDICO_HPP

#include <cstring>
#include <iostream>

class HistorialMedico {
private:
    int id;
    int pacienteID;
    char fecha[11];        // formato DD/MM/AAAA
    char hora[6];          // formato HH:MM
    char diagnostico[200];
    char tratamiento[200];
    char medicamentos[150];
    int doctorID;
    float costo;
    int siguienteConsultaID;   // -1 si es la última consulta
    bool eliminado;

public:
    // ===== Constructores =====
    HistorialMedico();
    HistorialMedico(int id, int pacienteID, const char* fecha, const char* hora,
                    const char* diagnostico, const char* tratamiento,
                    const char* medicamentos, int doctorID, float costo);

    // ===== Getters =====
    int getId() const;
    int getPacienteID() const;
    const char* getFecha() const;
    const char* getHora() const;
    const char* getDiagnostico() const;
    const char* getTratamiento() const;
    const char* getMedicamentos() const;
    int getDoctorID() const;
    float getCosto() const;
    int getSiguienteConsultaID() const;
    bool estaEliminado() const;

    // ===== Setters =====
    void setId(int nuevoId);
    void setPacienteID(int pid);
    void setFecha(const char* f);
    void setHora(const char* h);
    void setDiagnostico(const char* d);
    void setTratamiento(const char* t);
    void setMedicamentos(const char* m);
    void setDoctorID(int did);
    void setCosto(float c);
    void setSiguienteConsultaID(int id);
    void marcarEliminado();

    // ===== Presentación =====
    void mostrarInformacion() const;

    // ===== Persistencia =====
    static size_t tamanoRegistro();
    static bool guardar(const HistorialMedico& h);          // Guardar en archivo binario
    static bool leerPorID(int id, HistorialMedico& h);      // Leer por ID
    static bool eliminarPorID(int id);                      // Eliminar por ID
    static void listarTodos();    
};

#endif
