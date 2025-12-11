#  Proyecto 3: Sistema de Gestión Hospitalaria en C++

## Descripción
Este proyecto corresponde al **Proyecto 3 de Programación en C++**, donde se implementa un sistema hospitalario modular con persistencia en archivos binarios.  
El sistema permite administrar **Pacientes, Doctores, Citas e Historiales Médicos**, integrando un menú principal y operaciones específicas para cada entidad.

---

## Especificaciones del Proyecto 3

1. **Arquitectura modular**
   - Cada entidad (`Paciente`, `Doctor`, `Cita`, `HistorialMedico`, `Hospital`) está encapsulada en archivos `.hpp` y `.cpp`.
   - El proyecto compila desde la carpeta raíz con un **Makefile** o un único comando `g++`.
   - Separación clara entre **interfaz (headers)** y **implementación (source)**.

2. **Persistencia en archivos binarios**
   - Los datos se guardan en la carpeta `datos/` (`pacientes.bin`, `doctores.bin`, `citas.bin`, `historiales.bin`).
   - El módulo `persistencia/gestorArchivos.cpp` implementa:
     - Guardar registros (`write`)
     - Leer registros (`read`)
     - Listar registros
     - Buscar por ID
     - Modificar registros
     - Eliminar registros (marcado lógico)
     - Generar IDs únicos automáticamente

3. **Menú principal**
   - `main.cpp` muestra un menú con opciones para:
     - Gestionar pacientes
     - Gestionar doctores
     - Gestionar citas
     - Gestionar historiales médicos
     - Salir del sistema

4. **Operaciones**
   - Cada módulo en `operaciones/` solicita datos al usuario, crea objetos y usa el Gestor de Archivos.
   - Ejemplo: `operacionesPacientes.cpp`, `operacionesDoctores.cpp`, etc.

5. **Validaciones y utilidades**
   - Carpeta `utilidades/` contiene funciones auxiliares:
     - Validación de entradas (ej. fechas, IDs, strings).
     - Formatos de impresión (ej. tablas, alineación).

6. **Documentación**
   - Incluye este **README.md** con:
     - Descripción del sistema
     - Estructura de carpetas
     - Instrucciones de compilación
     - Especificaciones del Proyecto 3
   - Carpeta `docs/` opcional para diagramas UML y manuales.

7. **Requisitos de compilación**
   - El proyecto debe compilar sin errores desde la raíz.
   - Los `.o` y `.exe` se guardan en `output/`.
   - Los binarios de datos se guardan en `datos/`.

---

## Estructura de Carpetas
proyectodeprogramacion2/ 
│── citas/ # Entidad Cita 
│── doctores/ # Entidad Doctor
│── pacientes/ # Entidad Paciente 
│── historial/ # Entidad HistorialMedico 
│── hospital/ # Entidad Hospital 
│── operaciones/ # Funciones de menú 
│── persistencia/ # Gestor de Archivos y constantes 
│── utilidades/ # Validaciones y formatos 
│── datos/ # Archivos binarios persistentes
│── output/ # Binarios compilados 
│── main.cpp # Menú principal 
│── parte2dehospital.cpp# Extensión del sistema 
│── README.md # Documentación del proyecto
Usando g++
g++ main.cpp citas/Cita.cpp doctores/Doctor.cpp pacientes/Paciente.cpp \
    historial/HistorialMedico.cpp hospital/Hospital.cpp \
    operaciones/operacionesPacientes.cpp operaciones/operacionesDoctores.cpp \
    operaciones/operacionesCitas.cpp operaciones/operacionesHistorial.cpp \
    persistencia/gestorArchivos.cpp utilidades/Formatos.cpp utilidades/Validaciones.cpp \
    -o output/hospital.exe
## Compilación y ejecución
./output/hospital.exe
.gitignore recomendado
# Archivos compilados
*.o
*.exe

# Binarios de datos
*.bin

# Configuración local
.vscode/
output/


