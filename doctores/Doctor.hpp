#ifndef DOCTOR_HPP
#define DOCTOR_HPP

#include <cstring>
#include <iostream>

class Doctor {
private:
       int id;
    char nombre[50];
    char apellido[50];        
    char especialidad[50];
    char telefono[15];
    int experiencia;          
    float costoConsulta;      
    bool eliminado;
    bool disponible;

public:
    // Constructores
    Doctor();
    Doctor(int id, const char* nombre, const char* especialidad);

    // Getters
    int getId() const;
    const char* getNombre() const;
     const char* getApellido() const; 
    const char* getEspecialidad() const;
    const char* getTelefono() const;
    
    int getExperiencia() const;             
    float getCostoConsulta() const;
    bool estaDisponible() const;

    // Setters
    void setId(int nuevoId);
    void setNombre(const char* n);
    void setApellido(const char* a); 
    void setTelefono(const char* t);        
    void setExperiencia(int exp);           
    void setCostoConsulta(float c);
    void setEspecialidad(const char* e);
    void setDisponible(bool d);

    void mostrarInformacion() const;

    void marcarEliminado();      
    // Métodos de presentación
    static bool guardar(const Doctor& d);          
    static bool leerPorID(int id, Doctor& d);      
    static bool eliminarPorID(int id);             
    static void listarTodos();
};

#endif
