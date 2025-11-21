Descripción General
Este proyecto implementa un sistema hospitalario en C++ que gestiona pacientes, doctores, citas y historiales médicos. A diferencia del Proyecto 1, los datos no se mantienen en memoria: 
se utiliza persistencia con archivos binarios y acceso aleatorio (seekg, seekp) para leer y escribir únicamente los registros necesarios.

 Objetivos de Aprendizaje
Implementar persistencia de datos mediante archivos binarios.

Dominar operaciones de lectura/escritura binaria con fstream.

Aplicar acceso aleatorio usando seekg() y seekp().

Comprender el mapeo entre estructuras en memoria y archivos.

Gestionar índices y posiciones en archivos binarios.

Garantizar integridad y escalabilidad en el manejo de registros.

 Arquitectura de Archivos
El sistema organiza la información en archivos binarios separados:

hospital.bin → Datos básicos del hospital (nombre, dirección, contadores).

pacientes.bin → Registros de pacientes.

doctores.bin → Registros de doctores.

citas.bin → Registros de citas.

historiales.bin → Consultas médicas atendidas.

Cada archivo contiene:

Header (encabezado) con metadatos: cantidad de registros, próximo ID, registros activos, versión.

Registros fijos de cada entidad.

 Estructuras Principales
Hospital: datos básicos y contadores de IDs.

Paciente: información personal, citas e historial referenciados por ID.

Doctor: datos profesionales y relación con pacientes/citas.

Cita: vínculo entre paciente y doctor, estado y referencia a historial.

Historial Médico: consultas realizadas, enlazadas mediante IDs.

 Ciclo de Operaciones
Cada operación sigue este patrón:

Abrir archivo binario.

Posicionarse en el registro exacto con seekg/seekp.
Funcionalidades del Menú
Registrar paciente

Registrar doctor

Agendar cita

Atender cita (crea historial médico)

Mostrar historial de pacientes

Listar doctores

Listar pacientes

Buscar paciente

Buscar doctor

Buscar paciente por coincidencia parcial

Eliminar paciente (borrado lógico)

Eliminar doctor (borrado lógico)

Salir

 Ventajas del Acceso Aleatorio
Escalabilidad: Maneja miles de registros sin cargar todo en RAM.

Persistencia inmediata: Cada operación se guarda en disco al instante.

Integridad: Los archivos siempre están actualizados.

Eficiencia: Solo se accede al registro necesario.

 Casos de Prueba
Crear pacientes y verificar persistencia tras cerrar/reabrir el programa.

Atender citas y confirmar que el historial se guarda en historiales.bin.

Eliminar registros y comprobar que se marcan como eliminado.

Listar registros y validar que solo se muestran los activos.
Leer o escribir solo ese registro.

Cerrar archivo inmediatamente.
