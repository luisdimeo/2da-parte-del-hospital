#ifndef PACIENTE_HPP
#define PACIENTE_HPP

#include <iostream>
#include <cstring>

class Paciente {
private:
    int id;
    char nombre[50];
    int edad;
    char telefono[15];
    char direccion[100];   
    char sintomas[100];    
    char gmail[50];
    bool eliminado;

public:
    Paciente();
    Paciente(int id, const char* nombre, int edad, const char* telefono,
             const char* direccion, const char* sintomas);

    int getId() const;
    const char* getNombre() const;
    int getEdad() const;
    const char* getTelefono() const;
    const char* getDireccion() const;   
    const char* getSintomas() const;    
    const char* getGmail() const;

    void setId(int nuevoId);
    void setNombre(const char* nuevoNombre);
    void setEdad(int nuevaEdad);
    void setTelefono(const char* nuevoTelefono);
    void setDireccion(const char* d); 
    void setSintomas(const char* s);  
    void setGmail(const char* g);

    bool estaEliminado() const;
    void marcarEliminado();

    void mostrarInformacion() const;
    static size_t tamanoRegistro();
};

#endif 
