
#include "ManejoDeArchivo.h" 

// CONSTRUCTOR
ManejoDeArchivo::ManejoDeArchivo() {
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Funcion para crear el archivo .csv de informacion del laboratorio
void ManejoDeArchivo::CrearArchivoInformacionCSV(vector <Informacion> Informaciones) {
	ifstream Archivo ("Informacion-Laboratorio.csv") ;

	if (!Archivo.is_open()) {
		ofstream Archivo ;
		Archivo.open("Informacion-Laboratorio.csv", ios::app) ;

		for (int i=0 ; i<Informaciones.size() ; i++) {
			Archivo << Informaciones[i].getNombreDeInfo() << ';' << Informaciones[i].getContenidoDeInfo() << '\n' ;
		}
		Archivo.close() ;
	} else if (!Informaciones.empty()) {
		ofstream Archivo ;
		Archivo.open("Informacion-Laboratorio.csv", ios::out) ;

		for (int i=0 ; i<Informaciones.size() ; i++) {
			Archivo << Informaciones[i].getNombreDeInfo() << ';' << Informaciones[i].getContenidoDeInfo() << '\n' ; 
		}
	}
	Archivo.close() ;
}

void ManejoDeArchivo::CargarArchivoInformacionCSV(vector <Informacion>* Informaciones) {
	Informaciones->clear() ;

	ifstream Archivo ("Informacion-Laboratorio.csv") ;
	Informacion* InformacionAuxiliar = new Informacion ;
	string Nombre, Contenido ;

	if (Archivo.is_open()) {
		while (!Archivo.eof()) {
			// Copiar todo a variables temporales
			getline(Archivo, Nombre, ';') ;
			getline(Archivo, Contenido, '\n') ;

			// Guardar lo que hay en las variables en vectores
			InformacionAuxiliar->setNombreDeInfo(Nombre) ;
			InformacionAuxiliar->setContenidoDeInfo(Contenido) ;

			// Agregar  al vector
			Informaciones->push_back(*InformacionAuxiliar) ;
		}
		// Eliminar un ultimo elemento que me crea
		Informaciones->pop_back() ;
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Funcion para crear Archivo .csv  de informacion de estudiantes
void ManejoDeArchivo::CrearArchivoEstudianteCSV(vector <Estudiante> Estudiantes) {
	ifstream Archivo ("Estudiantes-Laboratorio.csv") ;

	if (!Archivo.is_open()) {
		ofstream Archivo ;
		Archivo.open("Estudiantes-Laboratorio.csv" , ios::app) ;

		for (int i=0 ; i<Estudiantes.size() ; i++) {
			Archivo << "Nombre" << ';' << "Apellido" << ';' << "Email" << ';'  ;
			Archivo << "Carrera" << ';' << "Edad" << ';' << "Cedula" << ';'   ;
			Archivo << "Telefono" << ';'<< "Codigo" << ';' << "Semestre" << ';' ;
			Archivo << "Valor de multa Acomulada" << ';' << "Estado de multa" << ';' << "Estado del estudiante" << '\n' ;
			Archivo << Estudiantes[i].getNombre() << ';' << Estudiantes[i].getApellido() << ';'  ;
			Archivo << Estudiantes[i].getEmail() << ';' << Estudiantes[i].getCarrera() << ';'       ;
			Archivo << Estudiantes[i].getEdad() << ';' << Estudiantes[i].getCedula() << ';'  ;
			Archivo << Estudiantes[i].getTelefono() << ';' << Estudiantes[i].getCodigo() << ';'   ;
			Archivo << Estudiantes[i].getSemestre() << ';' << Estudiantes[i].getValorMultaAcomulada() << ';'      ;
			Archivo << Estudiantes[i].getEstadoDeMulta() << ';' << Estudiantes[i].getEstadoDeEstudiante() << '\n'  ;
		}
		Archivo.close() ;
	}//else {
	// Agregar otro registro de persona
	//	ActualizarArchivoEstudianteCSV(Estudiantes) ;
	//}
	Archivo.close() ;
}

void ManejoDeArchivo::CargarArchivoEstudianteCSV(vector <Estudiante>& Estudiantes) {
	Estudiantes.clear() ; // Eliminar por si existe algo ya en el vector

	ifstream Archivo ("Estudiantes-Laboratorio.csv") ;
	Estudiante* EstudianteAuxiliar = new Estudiante ;
	string Nombre, Apellido, Email, Carrera, Edad, Cedula, Telefono, Codigo ;
	string Semestre, ValorMultaAcomulada, EstadoDeMulta, EstadoDeEstudiante ;


	if (Archivo.is_open()) {
		char texto[512]  ;
		Archivo.getline(texto,512, '\n') ; // Cabeceras
		while (!Archivo.eof()) {
			// Copiar todo a variables temporales
			getline(Archivo, Nombre, ';') ;
			getline(Archivo, Apellido, ';') ;
			getline(Archivo, Email, ';') ;
			getline(Archivo, Carrera, ';') ;
			getline(Archivo, Edad, ';') ;
			getline(Archivo, Cedula, ';') ;
			getline(Archivo, Telefono, ';') ;
			getline(Archivo, Codigo, ';') ;
			getline(Archivo, Semestre, ';') ;
			getline(Archivo, ValorMultaAcomulada, ';') ;
			getline(Archivo, EstadoDeMulta, ';') ;
			getline(Archivo, EstadoDeEstudiante, '\n') ;

			// Guardar lo que hay en las variables en vectores
			EstudianteAuxiliar->setNombre (Nombre) ;
			EstudianteAuxiliar->setApellido(Apellido) ;
			EstudianteAuxiliar->setEmail(Email) ;
			EstudianteAuxiliar->setCarrera(Carrera) ;
			// Variable con paso de strin a entero
			EstudianteAuxiliar->setEdad(CambioStringALong (Edad)) ;
			EstudianteAuxiliar->setCedula(CambioStringALong (Cedula)) ;
			EstudianteAuxiliar->setTelefono(CambioStringALong (Telefono)) ;
			EstudianteAuxiliar->setCodigo(CambioStringALong (Codigo)) ;
			EstudianteAuxiliar->setSemestre(CambioStringALong (Semestre)) ;
			EstudianteAuxiliar->CorrerValorMulta(CambioStringALong (ValorMultaAcomulada)) ;
			EstudianteAuxiliar->setEstadoDeMulta(CambioStringALong (EstadoDeMulta)) ;
			EstudianteAuxiliar->setEstadoDeEstudiante(CambioStringALong (EstadoDeEstudiante)) ;

			// Agregar  al vector
			Estudiantes.push_back(*EstudianteAuxiliar) ;
		}
		// Eliminar un ultimo elemento que me crea
		Estudiantes.pop_back() ;
	}

	delete EstudianteAuxiliar ;
}


// Actualizar Archivo de Estudiantes
void ManejoDeArchivo::ActualizarArchivoEstudianteCSV(vector <Estudiante> Estudiantes) {
	ofstream Archivo ("Estudiantes-Laboratorio.csv", ios::out) ;
	// Cabezeras
	Archivo << "Nombre" << ';' << "Apellido" << ';' << "Email" << ';'  ;
	Archivo << "Carrera" << ';' << "Edad" << ';' << "Cedula" << ';'   ;
	Archivo << "Telefono" << ';'<< "Codigo" << ';' << "Semestre" << ';' ;
	Archivo << "Valor de multa Acomulada" << ';' << "Estado de multa" << ';' << "Estado del estudiante" << '\n' ;

	for (int i=0 ; i<Estudiantes.size() ; i++) {
		Archivo << Estudiantes[i].getNombre() << ';' << Estudiantes[i].getApellido() << ';'  ;
		Archivo << Estudiantes[i].getEmail() << ';' << Estudiantes[i].getCarrera() << ';'       ;
		Archivo << Estudiantes[i].getEdad() << ';' << Estudiantes[i].getCedula() << ';'  ;
		Archivo << Estudiantes[i].getTelefono() << ';' << Estudiantes[i].getCodigo() << ';'   ;
		Archivo << Estudiantes[i].getSemestre() << ';' << Estudiantes[i].getValorMultaAcomulada() << ';'      ;
		Archivo << Estudiantes[i].getEstadoDeMulta() << ';' << Estudiantes[i].getEstadoDeEstudiante() << '\n'  ;
	}
	Archivo.close() ;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Funcion para crear Archivo .csv de informacion de profesores
void ManejoDeArchivo::CrearArchivoProfesorCSV(vector <Profesor> Profesores) {
	ofstream Archivo ;
	Archivo.open("Profesores-Laboratorio.csv", ios::app) ;

	Archivo << "Nombre" << ';' << "Apellido" << ';' << "Email" << ';'  ;
	Archivo << "Edad" << ';' << "Cedula" << ';' << "Telefono" << ';'   ;
	Archivo << "Codigo" << ';' << "Titulo Prfesional" << '\n' ;
	
	for (int i=0 ; i<Profesores.size() ; i++) {
		Archivo << Profesores[i].getNombre() << ';' << Profesores[i].getApellido() << ';'  ;
		Archivo << Profesores[i].getEmail() << ';' << Profesores[i].getEdad() << ';'       ;
		Archivo << Profesores[i].getCedula() << ';' << Profesores[i].getTelefono() << ';'  ;
		Archivo << Profesores[i].getCodigo() << ';' << Profesores[i].getTituloProfesional() << '\n'   ;
		
	}
	Archivo.close() ;
}

void ManejoDeArchivo::CargarArchivoProfesorCSV(vector <Profesor>* Profesores) {
	Profesores->clear() ; // Eliminar por si existe algo ya en el vector

	ifstream Archivo ("Profesores-Laboratorio.csv") ;
	Profesor* ProfesoreAuxiliar = new Profesor ;
	string Nombre, Apellido, Email, Carrera, Edad, Cedula, Telefono, Codigo, TituloProfesional ;

	if (Archivo.is_open()) {
		char texto[512]  ;
		// Copiar todo a variables temporales
		Archivo.getline(texto,512, '\n') ; // Cabeceras
		while (!Archivo.eof()) {
			getline(Archivo, Nombre, ';') ;
			getline(Archivo, Apellido, ';') ;
			getline(Archivo, Email, ';') ;
			getline(Archivo, Edad, ';') ;
			getline(Archivo, Cedula, ';') ;
			getline(Archivo, Telefono, ';') ;
			getline(Archivo, Codigo, ';') ;
			getline(Archivo, TituloProfesional, '\n') ;

			// Guardar lo que hay en las variables en vectores
			ProfesoreAuxiliar->setNombre (Nombre) ;
			ProfesoreAuxiliar->setApellido(Apellido) ;
			ProfesoreAuxiliar->setEmail(Email) ;
			ProfesoreAuxiliar->setTituloProfesional(TituloProfesional) ;

			// Variable con paso de strin a entero
			ProfesoreAuxiliar->setEdad(CambioStringALong (Edad)) ;
			ProfesoreAuxiliar->setCedula(CambioStringALong (Cedula)) ;
			ProfesoreAuxiliar->setTelefono(CambioStringALong (Telefono)) ;
			ProfesoreAuxiliar->setCodigo(CambioStringALong (Codigo)) ;

			// Agregar  al vector
			Profesores->push_back(*ProfesoreAuxiliar) ;
		}
		// Eliminar un ultimo elemento que me crea
		Profesores->pop_back() ;
	}

	delete ProfesoreAuxiliar ;
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void ManejoDeArchivo::ActualizarArchivoProfesorCSV(vector <Profesor> Profesores) {
	ofstream Archivo ;
	Archivo.open("Profesores-Laboratorio.csv", ios::in) ;

	Archivo << "Nombre" << ';' << "Apellido" << ';' << "Email" << ';'  ;
	Archivo << "Edad" << ';' << "Cedula" << ';' << "Telefono" << ';'   ;
	Archivo << "Codigo" << ';' << "Titulo Prfesional" << '\n' ;
	
	for (int i=0 ; i<Profesores.size() ; i++) {
		Archivo << Profesores[i].getNombre() << ';' << Profesores[i].getApellido() << ';'  ;
		Archivo << Profesores[i].getEmail() << ';' << Profesores[i].getEdad() << ';'       ;
		Archivo << Profesores[i].getCedula() << ';' << Profesores[i].getTelefono() << ';'  ;
		Archivo << Profesores[i].getCodigo() << ';' << Profesores[i].getTituloProfesional() << '\n' ;
	}
	Archivo.close() ;
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void ManejoDeArchivo::CrearArchivoAdminisCSV(vector <PersonalAdmi> PersonalAdm) {
	ofstream Archivo ;
	Archivo.open("PersonalAdmi-Laboratorio.csv", ios::app) ;

	Archivo << "Nombre" << ';' << "Apellido" << ';' << "Email" << ';'  ;
	Archivo << "Edad" << ';' << "Cedula" << ';' << "Telefono" << '\n'   ;
	
	for (int i=0 ; i<PersonalAdm.size() ; i++) {
		Archivo << PersonalAdm[i].getNombre() << ';' << PersonalAdm[i].getApellido() << ';'  ;
		Archivo << PersonalAdm[i].getEmail() << ';' << PersonalAdm[i].getEdad() << ';'       ;
		Archivo << PersonalAdm[i].getCedula() << ';' << PersonalAdm[i].getTelefono() << '\n'  ;
	}
	Archivo.close() ;
}

void ManejoDeArchivo::CargarArchivoAdminisCSV(vector <PersonalAdmi>* PersonalAdm) {
	PersonalAdm->clear() ; // Eliminar por si existe algo ya en el vector

	ifstream Archivo ("PersonalAdmi-Laboratorio.csv") ;
	PersonalAdmi* PersonalAuxiliar = new PersonalAdmi ;
	string Nombre, Apellido, Email, Carrera, Edad, Cedula, Telefono ;

	if (Archivo.is_open()) {
		char texto[512]  ;
		// Copiar todo a variables temporales
		Archivo.getline(texto,512, '\n') ; // Cabeceras
		while (!Archivo.eof()) {
			getline(Archivo, Nombre, ';') ;
			getline(Archivo, Apellido, ';') ;
			getline(Archivo, Email, ';') ;
			getline(Archivo, Edad, ';') ;
			getline(Archivo, Cedula, ';') ;
			getline(Archivo, Telefono, '\n') ;

			// Guardar lo que hay en las variables en vectores
			PersonalAuxiliar->setNombre (Nombre) ;
			PersonalAuxiliar->setApellido(Apellido) ;
			PersonalAuxiliar->setEmail(Email) ;

			// Variable con paso de strin a entero
			PersonalAuxiliar->setEdad(CambioStringALong (Edad)) ;
			PersonalAuxiliar->setCedula(CambioStringALong (Cedula)) ;
			PersonalAuxiliar->setTelefono(CambioStringALong (Telefono)) ;

			// Agregar  al vector
			PersonalAdm->push_back(*PersonalAuxiliar) ;
		}
		// Eliminar un ultimo elemento que me crea
		PersonalAdm->pop_back() ;
	}

	delete PersonalAuxiliar ;
}




/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


// Crear Archivo para articulos de prestamos
//void ManejoDeArchivo::CrearArchivoArticuloDePrestamoCSV(vector <ArticuloDePrestamo> ArticulosParaPrestar) {
//	ifstream Archivo ("Articulo-De-Prestamo-Laboratorio.csv") ;
//
//	if (!Archivo.is_open()) {
//		ofstream Archivo ;
//		Archivo.open("Articulo-De-Prestamo-Laboratorio.csv", ios::app) ;
//		Archivo << "Nombre" << ';' << "Marca" << ';' << "Cantidad De Articulos" << ';' << "Codigo" << ';' ;
//		Archivo << "Valor De Articulo" << ';' << "Estado Del Articulo" << ';' << "Estado De Disponibilidad" << ';' ;
//		Archivo << "Estado De Asignacion a Profesor" << ';' << "Asignado a" << '\n' ;
//		for (int i=0 ; i<ArticulosParaPrestar.size() ; i++) {
//			Archivo << ArticulosParaPrestar[i].getIDNombre() << ';' << ArticulosParaPrestar[i].getIDMarca() << ';' ;
//			Archivo << ArticulosParaPrestar[i].getCantidadDeTipoDeArticulo() << ';' << ArticulosParaPrestar[i].getCodigoArticulo() << ';' ;
//			Archivo << ArticulosParaPrestar[i].getValorArticuloInicial() << ';' << ArticulosParaPrestar[i].getEstadoArticuloDeActivo() << ';' ;
//			Archivo << ArticulosParaPrestar[i].getEstadoDeLimiteDeArticulos() << ';' << ArticulosParaPrestar[i].getEstadoDeAsignadoAProfesor() << '\n' ;
//		}
//		Archivo.close() ;
//	}
//	Archivo.close() ;
//
//}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void ManejoDeArchivo::CrearArchivoArticuloComputoCSV(vector <ArticuloComputo> ArticulosComputo) {
	ifstream Archivo ("Articulo-De-Computo-Laboratorio.csv") ;
	
	if (!Archivo.is_open()) {
		ofstream Archivo ;
		Archivo.open("Articulo-De-Computo-Laboratorio.csv", ios::app) ;
		Archivo << "Nombre" << ';' << "Marca" << ';' << "Cantidad De Articulos" << ';' << "Codigo" << ';' ;
		Archivo << "Valor De Articulo" << ';' << "Valor Actual Del Articulo" << ';' << "Estado Del Articulo" << ';' << "Estado De Disponibilidad" << ';' ;
		Archivo << "Estado De Asignacion a Profesor" << ';' << "Valor De Despreciacion" << ';' <<  "Asignado a" << ';' ;
		Archivo << "Anio" << ';' << "Mes" << ';' << "Dia" << '\n' ; 
			
		for (int i=0 ; i<ArticulosComputo.size() ; i++) {
			Archivo << ArticulosComputo[i].getIDNombre() << ';' << ArticulosComputo[i].getIDMarca() << ';' ;
			Archivo << ArticulosComputo[i].getCantidad() << ';' << ArticulosComputo[i].getCodigoArticulo() << ';' ;
			Archivo << ArticulosComputo[i].getValorArticuloInicial() << ';' << ArticulosComputo[i].getValorActualArticulo() << ';' << ArticulosComputo[i].getEstadoArticuloDeActivo() << ';' ;
			Archivo << ArticulosComputo[i].getEstadoDeLimiteDeArticulos() << ';' << ArticulosComputo[i].getEstadoDeAsignadoAProfesor() << ';' ; 
			Archivo << ArticulosComputo[i].getDespreciacion() << ';' << ArticulosComputo[i].getProfesor()->getCodigo() << ';' ;
			Archivo << ArticulosComputo[i].getFecha()->tm_year << ';' << ArticulosComputo[i].getFecha()->tm_mon << ';' << ArticulosComputo[i].getFecha()->tm_mday << '\n' ;
		}
		Archivo.close() ;
	}else {
		ActualizarComputoCSV (ArticulosComputo) ; 
	}
	Archivo.close() ;
}

///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////

vector <int> ManejoDeArchivo::CargarArchivoArticuloComputoCSV(vector <ArticuloComputo>* ArticulosComputo) {
	ArticuloComputo* ArticuloAux = new ArticuloComputo ;
	Laboratorio* Asignarle = new Laboratorio ;
	
	time_t FechaAux ;
	time(&FechaAux) ;
	ctime(&FechaAux) ;
	struct tm* FechaAsignar = localtime(&FechaAux) ;  
	
	ArticulosComputo->clear() ; 
	
	vector <int> Codigos ; 
		
	ifstream Archivo ("Articulo-De-Computo-Laboratorio.csv") ;
	
	string Datos, CodigoProfe, Codigo ;
	 
	if (Archivo.is_open()) {
		char Cabezeras[512] ; // Esto es Para cabezeras
		Archivo.getline(Cabezeras,512, '\n') ; // Para copiar cabezeras y desacerlas
		while(!Archivo.eof()) {
			getline(Archivo, Datos, ';') ;
			ArticuloAux->setIDNombre(Datos) ;

			getline(Archivo, Datos, ';') ;
			ArticuloAux->setIDMarca(Datos) ;
			
			getline(Archivo, Datos, ';') ;
			ArticuloAux->setCantidad (CambioStringALong (Datos)) ;
			
			getline(Archivo, Codigo, ';') ;
			ArticuloAux->setCodigoArticulo (CambioStringALong (Codigo)) ;
			
			getline(Archivo, Datos, ';') ;
			ArticuloAux->setValorArticuloInicial (CambioStringALong (Datos)) ; 
			
			getline(Archivo, Datos, ';') ;
			ArticuloAux->setValorActualArticulo (CambioStringALong (Datos)) ;
			
			getline(Archivo, Datos, ';') ;
			ArticuloAux->setEstadoArticuloDeActivo (CambioStringALong (Datos)) ;
			
			getline(Archivo, Datos, ';') ;
			ArticuloAux->setEstadoDeLimiteDeArticulos (CambioStringALong (Datos)) ;
			
			getline(Archivo, Datos, ';') ;
			ArticuloAux->setEstadoDeAsignadoAProfesor (CambioStringALong (Datos)) ;
			
			getline(Archivo, Datos, ';') ;
			ArticuloAux->setDespreciacion (CambioStringALong (Datos)) ; 
			
			getline(Archivo, CodigoProfe, ';') ;
			
			getline(Archivo, Datos, ';') ;
			getline(Archivo, Datos, ';') ;
			getline(Archivo, Datos, '\n') ;

			
			Codigos.push_back(CambioStringALong (CodigoProfe)) ; 
			Codigos.push_back(CambioStringALong (Codigo)) ;
			
			ArticulosComputo->push_back(*ArticuloAux) ;   			 
		}  
		ArticulosComputo->pop_back() ; 
		Codigos.pop_back() ;
		Codigos.pop_back() ;
	}
	delete ArticuloAux, Asignarle ;
	return Codigos ;
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void ManejoDeArchivo::ActualizarComputoCSV(vector <ArticuloComputo> ArticulosComputo) {
	ofstream Archivo ;
	Archivo.open("Articulo-De-Computo-Laboratorio.csv", ios::in) ;
	
	Archivo << "Nombre" << ';' << "Marca" << ';' << "Cantidad De Articulos" << ';' << "Codigo" << ';' ;
	Archivo << "Valor De Articulo" << ';' << "Valor Actual Del Articulo" << ';' << "Estado Del Articulo" << ';' << "Estado De Disponibilidad" << ';' ;
	Archivo << "Estado De Asignacion a Profesor" << ';' << "Valor De Despreciacion" << ';' <<  "Asignado a" << ';' ;
	Archivo << "Anio" << ';' << "Mes" << ';' << "Dia" << '\n' ; 
	
	for (int i=0 ; i<ArticulosComputo.size() ; i++) {
		Archivo << ArticulosComputo[i].getIDNombre() << ';' << ArticulosComputo[i].getIDMarca() << ';' ;
		Archivo << ArticulosComputo[i].getCantidad() << ';' << ArticulosComputo[i].getCodigoArticulo() << ';' ;
		Archivo << ArticulosComputo[i].getValorArticuloInicial() << ';' << ArticulosComputo[i].getValorActualArticulo() << ';' << ArticulosComputo[i].getEstadoArticuloDeActivo() << ';' ;
		Archivo << ArticulosComputo[i].getEstadoDeLimiteDeArticulos() << ';' << ArticulosComputo[i].getEstadoDeAsignadoAProfesor() << ';' ; 
		Archivo << ArticulosComputo[i].getDespreciacion() << ';' << ArticulosComputo[i].getProfesor()->getCodigo() << ';' ;
		Archivo << ArticulosComputo[i].getFecha()->tm_year << ';' << ArticulosComputo[i].getFecha()->tm_mon << ';' << ArticulosComputo[i].getFecha()->tm_mday << '\n' ;
	}
	Archivo.close() ;
}


///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////

void ManejoDeArchivo::CargarArticuloComputoCSV(vector <ArticuloComputo> ArticulosParaComputo) {
	ArticuloComputo* ArticuloAux = new ArticuloComputo ;
	
	time_t FechaAux ;
	time(&FechaAux) ;
	ctime(&FechaAux) ;
	struct tm* FechaAsignar = localtime(&FechaAux) ;  
	
	vector <int> Fechas ;
	
	ifstream Archivo ("Articulo-De-Computo-Laboratorio.csv") ;
	
	string Datos, CodigoProfe, Codigo ;
	 
	if (Archivo.is_open()) {
		char Cabezeras[512] ; // Esto es Para cabezeras
		Archivo.getline(Cabezeras,512, '\n') ; // Para copiar cabezeras y desacerlas
		while(!Archivo.eof()) {
			getline(Archivo, Datos, ';') ;
			getline(Archivo, Datos, ';') ;			
			getline(Archivo, Datos, ';') ;			
			getline(Archivo, Codigo, ';') ;			
			getline(Archivo, Datos, ';') ;			
			getline(Archivo, Datos, ';') ;
			getline(Archivo, Datos, ';') ;			
			getline(Archivo, Datos, ';') ;			
			getline(Archivo, Datos, ';') ;			
			getline(Archivo, Datos, ';') ;
			getline(Archivo, CodigoProfe, ';') ;
			
			getline(Archivo, Datos, ';') ;
			Fechas.push_back(CambioStringALong (Datos)) ; 
			
			getline(Archivo, Datos, ';') ;
			Fechas.push_back(CambioStringALong (Datos)) ; 
			
			getline(Archivo, Datos, '\n') ;
			Fechas.push_back(CambioStringALong (Datos)) ; 
		} 
		Fechas.pop_back() ;
		Fechas.pop_back() ;
		Fechas.pop_back() ;
		int itera = 0 ; 
		for (int i=0 ; i<Fechas.size() ; i+=3) {
			FechaAsignar->tm_year = Fechas[i] ; 
			FechaAsignar->tm_mon = Fechas [i+1] ;
			FechaAsignar->tm_mday = Fechas[i+2] ;  
			ArticulosParaComputo[itera].AsignarFecha(FechaAsignar) ;
			itera++ ;
		}
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Crear Archivo para articulos de prestamos
void ManejoDeArchivo::CrearArchivoArticuloDePrestamoCSV(vector <ArticuloDePrestamo> ArticulosParaPrestar) {
	ifstream Archivo ("Articulo-De-Prestamo-Laboratorio.csv") ;

	if (!Archivo.is_open()) {
		ofstream Archivo ;
		Archivo.open("Articulo-De-Prestamo-Laboratorio.csv", ios::app) ;
		Archivo << "Nombre" << ';' << "Marca" << ';' << "Cantidad De Articulos" << ';' << "Codigo" << ';' ;
		Archivo << "Valor De Articulo" << ';' << "Valor Actual Del Articulo" << ';' << "Estado Del Articulo" << ';' << "Estado De Disponibilidad" << ';' ;
		Archivo << "Estado De Asignacion a Profesor" << ';' << "Valor De Despreciacion" << ';' <<  "Asignado a" << '\n' ;
		
		for (int i=0 ; i<ArticulosParaPrestar.size() ; i++) {
			Archivo << ArticulosParaPrestar[i].getIDNombre() << ';' << ArticulosParaPrestar[i].getIDMarca() << ';' ;
			Archivo << ArticulosParaPrestar[i].getCantidadDeTipoDeArticulo() << ';' << ArticulosParaPrestar[i].getCodigoArticulo() << ';' ;
			Archivo << ArticulosParaPrestar[i].getValorArticuloInicial() << ';' << ArticulosParaPrestar[i].getValorActualArticulo() << ';' << ArticulosParaPrestar[i].getEstadoArticuloDeActivo() << ';' ;
			Archivo << ArticulosParaPrestar[i].getEstadoDeLimiteDeArticulos() << ';' << ArticulosParaPrestar[i].getEstadoDeAsignadoAProfesor() << ';' ; 
			Archivo << ArticulosParaPrestar[i].getDespreciacion() << ';' << ArticulosParaPrestar[i].getProfesor()->getCodigo() << '\n' ;
		}
		Archivo.close() ;
	}else {
		ActualizarArchivoArticuloDePrestamoCSV(ArticulosParaPrestar) ;
	}
	
	Archivo.close() ;

}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void ManejoDeArchivo::ActualizarArchivoArticuloDePrestamoCSV(vector <ArticuloDePrestamo> ArticulosParaPrestar) {
	
	ofstream Archivo ;
	
	Archivo.open("Articulo-De-Prestamo-Laboratorio.csv", ios::out) ;
	
	Archivo << "Nombre" << ';' << "Marca" << ';' << "Cantidad De Articulos" << ';' << "Codigo" << ';' ;
	Archivo << "Valor De Articulo" << ';' << "Valor Actual Del Articulo" << ';' << "Estado Del Articulo" << ';' << "Estado De Disponibilidad" << ';' ;
	Archivo << "Estado De Asignacion a Profesor" << ';' << "Valor De Despreciacion" << ';' <<  "Asignado a" << '\n' ;
	
	for (int i=0 ; i<ArticulosParaPrestar.size() ; i++) {
		Archivo << ArticulosParaPrestar[i].getIDNombre() << ';' << ArticulosParaPrestar[i].getIDMarca() << ';' ;
		Archivo << ArticulosParaPrestar[i].getCantidadDeTipoDeArticulo() << ';' << ArticulosParaPrestar[i].getCodigoArticulo() << ';' ;
		Archivo << ArticulosParaPrestar[i].getValorArticuloInicial() << ';' << ArticulosParaPrestar[i].getValorActualArticulo() << ';' << ArticulosParaPrestar[i].getEstadoArticuloDeActivo() << ';' ;
		Archivo << ArticulosParaPrestar[i].getEstadoDeLimiteDeArticulos() << ';' << ArticulosParaPrestar[i].getEstadoDeAsignadoAProfesor() << ';' ; 
		Archivo << ArticulosParaPrestar[i].getDespreciacion() << ';' << ArticulosParaPrestar[i].getProfesor()->getCodigo() << '\n' ;
	}
	Archivo.close() ;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

vector <int> ManejoDeArchivo::CargarArchivoArticuloDePrestamoCSV(vector <ArticuloDePrestamo>* ArticulosParaPrestar) {
	ArticuloDePrestamo* ArticuloAux = new ArticuloDePrestamo ;
	Laboratorio* Asignarle = new Laboratorio ;
	vector <int> Codigos ; 
	
	ArticulosParaPrestar->clear() ;

	ifstream Archivo ("Articulo-De-Prestamo-Laboratorio.csv") ;

	string Datos, CodigoProfe, Codigo ;
	 
	if (Archivo.is_open()) {
		char Cabezeras[512] ; // Esto es Para cabezeras
		Archivo.getline(Cabezeras,512, '\n') ; // Para copiar cabezeras y desacerlas
		while(!Archivo.eof()) {
			
			getline(Archivo, Datos, ';') ;
			ArticuloAux->setIDNombre(Datos) ;

			getline(Archivo, Datos, ';') ;
			ArticuloAux->setIDMarca(Datos) ;
			
			getline(Archivo, Datos, ';') ;
			ArticuloAux->setCantidadDeTipoDeArticulo (CambioStringALong (Datos)) ;
			
			getline(Archivo, Codigo, ';') ;
			ArticuloAux->setCodigoArticulo (CambioStringALong (Codigo)) ;
			
			getline(Archivo, Datos, ';') ;
			ArticuloAux->setValorArticuloInicial (CambioStringALong (Datos)) ; 
			
			getline(Archivo, Datos, ';') ;
			ArticuloAux->setValorActualArticulo (CambioStringALong (Datos)) ;
			
			getline(Archivo, Datos, ';') ;
			ArticuloAux->setEstadoArticuloDeActivo (CambioStringALong (Datos)) ;
			
			getline(Archivo, Datos, ';') ;
			ArticuloAux->setEstadoDeLimiteDeArticulos (CambioStringALong (Datos)) ;
			
			getline(Archivo, Datos, ';') ;
			ArticuloAux->setEstadoDeAsignadoAProfesor (CambioStringALong (Datos)) ;
			
			getline(Archivo, Datos, ';') ;
			ArticuloAux->setDespreciacion (CambioStringALong (Datos)) ; 
			
			getline(Archivo, CodigoProfe, '\n') ;
			
			Codigos.push_back(CambioStringALong (CodigoProfe)) ;
			Codigos.push_back(CambioStringALong (Codigo)) ;
			
			// Agregat al Vector
			ArticulosParaPrestar->push_back(*ArticuloAux) ;   			
			//return Codigos ;
		}
		ArticulosParaPrestar->pop_back() ;  
		Codigos.pop_back() ;
		Codigos.pop_back() ;
	}
	delete ArticuloAux, Asignarle ;
	return Codigos ;	
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void ManejoDeArchivo::CrearArchivoArticuloMuebleCSV(vector <ArticuloMueble> ArticulosParaMueble) {
	ifstream Archivo ("Articulo-De-Mueble-Laboratorio.csv") ;
	
	if (!Archivo.is_open()) {
		ofstream Archivo ;
		Archivo.open("Articulo-De-Mueble-Laboratorio.csv", ios::app) ;
		Archivo << "Nombre" << ';' << "Material" << ';' << "Cantidad De Articulos" << ';' << "Codigo" << ';' ;
		Archivo << "Valor De Articulo" << ';' << "Valor Actual Del Articulo" << ';' << "Estado Del Articulo" << ';' << "Estado De Disponibilidad" << ';' ;
		Archivo << "Estado De Asignacion a Profesor" << ';' << "Valor De Despreciacion" << ';' <<  "Asignado a" << '\n' ;
	
		for (int i=0 ; i<ArticulosParaMueble.size() ; i++) {
			Archivo << ArticulosParaMueble[i].getIDNombre() << ';' << ArticulosParaMueble[i].getMaterial() << ';' ;
			Archivo << ArticulosParaMueble[i].getCantidad() << ';' << ArticulosParaMueble[i].getCodigoArticulo() << ';' ;
			Archivo << ArticulosParaMueble[i].getValorArticuloInicial() << ';' << ArticulosParaMueble[i].getValorActualArticulo() << ';' << ArticulosParaMueble[i].getEstadoArticuloDeActivo() << ';' ;
			Archivo << ArticulosParaMueble[i].getEstadoDeLimiteDeArticulos() << ';' << ArticulosParaMueble[i].getEstadoDeAsignadoAProfesor() << ';' ; 
			Archivo << ArticulosParaMueble[i].getDespreciacion() << ';' << ArticulosParaMueble[i].getProfesorAsignado()->getCodigo() << '\n' ;
		}
		Archivo.close() ;
	}
	Archivo.close() ;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

vector <int> ManejoDeArchivo::CargarArchivoArticuloMuebleCSV(vector <ArticuloMueble>* ArticulosParaMueble) {
	ArticuloMueble* ArticuloAux = new ArticuloMueble ;
	Laboratorio* Asignarle = new Laboratorio ;
	vector <int> Codigos ; 
	
	ArticulosParaMueble->clear() ;

	ifstream Archivo ("Articulo-De-Mueble-Laboratorio.csv") ;

	string Datos, CodigoProfe, Codigo ;
	 
	if (Archivo.is_open()) {
		char Cabezeras[512] ; // Esto es Para cabezeras
		Archivo.getline(Cabezeras,512, '\n') ; // Para copiar cabezeras y desacerlas
		while(!Archivo.eof()) {
			
			getline(Archivo, Datos, ';') ;
			ArticuloAux->setIDNombre(Datos) ;

			getline(Archivo, Datos, ';') ;
			ArticuloAux->setMaterial(Datos) ;
			
			getline(Archivo, Datos, ';') ;
			ArticuloAux->setCantidad (CambioStringALong (Datos)) ;
			
			getline(Archivo, Codigo, ';') ;
			ArticuloAux->setCodigoArticulo (CambioStringALong (Codigo)) ;
			
			getline(Archivo, Datos, ';') ;
			ArticuloAux->setValorArticuloInicial (CambioStringALong (Datos)) ; 
			
			getline(Archivo, Datos, ';') ;
			ArticuloAux->setValorActualArticulo (CambioStringALong (Datos)) ;
			
			getline(Archivo, Datos, ';') ;
			ArticuloAux->setEstadoArticuloDeActivo (CambioStringALong (Datos)) ;
			
			getline(Archivo, Datos, ';') ;
			ArticuloAux->setEstadoDeLimiteDeArticulos (CambioStringALong (Datos)) ;
			
			getline(Archivo, Datos, ';') ;
			ArticuloAux->setEstadoDeAsignadoAProfesor (CambioStringALong (Datos)) ;
			
			getline(Archivo, Datos, ';') ;
			ArticuloAux->setDespreciacion (CambioStringALong (Datos)) ; 
			
			getline(Archivo, CodigoProfe, '\n') ;
			
			Codigos.push_back(CambioStringALong (CodigoProfe)) ;
			Codigos.push_back(CambioStringALong (Codigo)) ;
			
			// Agregat al Vector
			ArticulosParaMueble->push_back(*ArticuloAux) ;   			
		}
		
		ArticulosParaMueble->pop_back() ;  
		Codigos.pop_back() ;
		Codigos.pop_back() ;
	}
	delete ArticuloAux, Asignarle ;
	return Codigos ;
	
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void ManejoDeArchivo::ActualizarMuebleCSV(vector <ArticuloMueble> ArticulosParaMueble) {
	ofstream Archivo ;
	Archivo.open("Articulo-De-Mueble-Laboratorio.csv", ios::in) ;
	Archivo << "Nombre" << ';' << "Material" << ';' << "Cantidad De Articulos" << ';' << "Codigo" << ';' ;
	Archivo << "Valor De Articulo" << ';' << "Valor Actual Del Articulo" << ';' << "Estado Del Articulo" << ';' << "Estado De Disponibilidad" << ';' ;
	Archivo << "Estado De Asignacion a Profesor" << ';' << "Valor De Despreciacion" << ';' <<  "Asignado a" << '\n' ;
	
	for (int i=0 ; i<ArticulosParaMueble.size() ; i++) {
		Archivo << ArticulosParaMueble[i].getIDNombre() << ';' << ArticulosParaMueble[i].getMaterial() << ';' ;
		Archivo << ArticulosParaMueble[i].getCantidad() << ';' << ArticulosParaMueble[i].getCodigoArticulo() << ';' ;
		Archivo << ArticulosParaMueble[i].getValorArticuloInicial() << ';' << ArticulosParaMueble[i].getValorActualArticulo() << ';' << ArticulosParaMueble[i].getEstadoArticuloDeActivo() << ';' ;
		Archivo << ArticulosParaMueble[i].getEstadoDeLimiteDeArticulos() << ';' << ArticulosParaMueble[i].getEstadoDeAsignadoAProfesor() << ';' ; 
		Archivo << ArticulosParaMueble[i].getDespreciacion() << ';' << ArticulosParaMueble[i].getProfesorAsignado()->getCodigo() << '\n' ;
	}
	Archivo.close() ;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Funcion para Cambiar el dato de string -> long
long ManejoDeArchivo::CambioStringALong(string Temporal) {

	stringstream geek(Temporal);
	long CambioDeDato ;
	geek >> CambioDeDato ;

	return CambioDeDato ;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void ManejoDeArchivo::CrearArchivoFechas(vector <ArticuloComputo> ArticulosComp){
	ifstream Archivo ("Fechas-Articulos.csv") ;
	
	if(!Archivo.is_open()) {
		ofstream Archivo ;
		Archivo.open("Fechas-Articulos.csv" , ios::app) ;
	
		Archivo << "Posicion" << ';' << "Dia" << ';' << "Mes" << ';' << "Anio" << '\n' ;
		
		for(int i=0 ; i<ArticulosComp.size() ; i++){
			Archivo << i << ';' << ArticulosComp[i].getFecha()->tm_mday << ';' << ArticulosComp[i].getFecha()->tm_mon << ';' << ArticulosComp[i].getFecha()->tm_year+1900 << '\n' ;
		}
	}else {
		ActualizarArchivoFechas(ArticulosComp) ; 	
	}
	Archivo.close() ;	
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void ManejoDeArchivo::CargarArchivoFechasCSV(vector <ArticuloComputo>* FechasDeUso){
	
	FechasDeUso->clear() ; // Eliminar por si existe algo ya en el vector
	
	time_t FechaAux ;
	time(&FechaAux) ;
	ctime(&FechaAux) ;
	struct tm* FechaAsignar = localtime(&FechaAux) ;  
	
	ArticuloComputo* ArticuloAux = new ArticuloComputo ;
	string Dato, Dia, Mes, Anio ; 
	int AuxPaso ;
	char Cabeceras[512] ;
	
	ifstream Archivo ("Fechas-Articulos.csv") ;
	
	if(Archivo.is_open()){
		Archivo.getline(Cabeceras,512, '\n') ; 	// Para copiar cabezeras y desacerlas
		while(!Archivo.eof()){
			
			getline(Archivo , Dato , ';') ;  	// Posicion
			getline(Archivo , Dia , ';') ;
			getline(Archivo , Mes , ';') ;
			getline(Archivo , Anio , '\n') ;
			cout << "Posicion:" << Dato << endl ;  
			int AuxPaso = CambioStringALong(Dato) ;
			cout << "a:" << AuxPaso << endl ;
			cout << "Tamanio:" << FechasDeUso->size() << endl ; 
			//for (int i=0 ; i<FechasDeUso->size() ; i++) {
			//	if (AuxPaso == i) {
					//getline(Archivo , Dato , ';') ;  	// Dia
					FechaAsignar->tm_mday = CambioStringALong(Dia) ;
					//getline(Archivo , Dato , ';') ; 	// Mes
					FechaAsignar->tm_mon = CambioStringALong(Mes) ;
					//getline(Archivo , Dato , '\n') ;    // A�o
					FechaAsignar->tm_year = CambioStringALong(Anio) ;
					cout << FechaAsignar->tm_year << endl ;
					system("pause") ;  
					ArticuloAux->AsignarFecha(FechaAsignar) ;
					FechasDeUso->push_back(*ArticuloAux) ; 
			//	}else {
			//		cout << "\nNo se ha encontrado nada \n\n" ;
			//		system("pause") ;
			//	}
			//}	
		}
		FechasDeUso->pop_back() ;
		FechasDeUso->pop_back() ;
		 
	}
	Archivo.close() ;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void ManejoDeArchivo::ActualizarArchivoFechas(vector <ArticuloComputo> ArticulosComp) {
	ofstream Archivo ;
	Archivo.open("Fechas-Articulos.csv" , ios::in) ;
	
	Archivo << "Posicion" << ';' << "Dia" << ';' << "Mes" << ';' << "Anio" << '\n' ;
		
	for(int i=0 ; i<ArticulosComp.size() ; i++){
		Archivo << i << ';' << ArticulosComp[i].getFecha()->tm_mday << ';' << ArticulosComp[i].getFecha()->tm_mon << ';' << ArticulosComp[i].getFecha()->tm_year+1900 << '\n' ;
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// DESTRUCTOR
ManejoDeArchivo::~ManejoDeArchivo() {
}
