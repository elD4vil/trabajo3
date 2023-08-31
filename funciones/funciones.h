#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <string>
#include <vector>
#include <map>

void sumatoriaVector(const char* valor);
void promedioVector(const char* valor);
void modaVector(const char* valor);
void contarElem(const char* valor);
void crearArchivo(const std::string &ubicacion);
void agregarTexto(const std::string &ubicacion, const std::string &texto);
bool textoExisteEnArchivo(const std::string &ubicacion, const std::string &texto);
std::vector<int> mostrarop(std::vector<int> user, const char* menu);
void seleccionarOpciones(const char* valor, std::string usuario, std::string ubicacion, std::string anadir, std::vector<int> user, std::vector<int> mapeo1, const std::string &cuento, const std::string &guardar, const char* menu);
void conteoPalabra(const std::string &cuento, const std::string &guardar);

#endif

