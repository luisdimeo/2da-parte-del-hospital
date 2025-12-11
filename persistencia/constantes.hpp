#ifndef CONSTANTES_HPP
#define CONSTANTES_HPP

namespace Rutas {
    // Carpeta donde se guardan los archivos binarios
    static const char* HOSPITAL   = "datos/hospital.bin";
    static const char* PACIENTES = "datos/pacientes.bin";
    static const char* DOCTORES  = "datos/doctores.bin";
    static const char* CITAS     = "datos/citas.bin";
    static const char* HISTORIALES = "datos/historiales.bin";
}

namespace Limites {
    // Límites de arrays fijos en las clases
    const int MAX_PACIENTES   = 1000;
    const int MAX_DOCTORES    = 500;
    const int MAX_CITAS       = 2000;
    const int MAX_CONSULTAS   = 5000;
}

#endif
