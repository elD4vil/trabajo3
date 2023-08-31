#include "../funciones/funciones.h"
#include <iostream> 
#include <unistd.h>
#include <fstream>
#include <string>
#include <cstring>
#include <map>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cstdlib> 

using namespace std;

int main(int argc, char *argv[]){
    system("clear");
    int opcion;
    string usuario,ubicacion,anadir,texto,funcion;
    const char* valor;
    while ((opcion = getopt(argc, argv, "u:v:f:t:i:o:")) != -1) {
        switch (opcion) {
            case 'u':
                usuario = optarg;
                break;
            case 'v':
                valor = optarg;
                break;
             case 'f':
                ubicacion = optarg;
                break;
            case 't':
                anadir = optarg;
                break;
            case 'i':
                texto = optarg;
                break;
            case 'o':
                funcion = optarg;
                break;
            default:
                cerr << "Uso: " << argv[0] << " -u usuario -v valor -f ubicacion -t añadir -i texto -o funcion" << endl;
                return 1;
        }
        
    }

    ifstream envFile(".env");
    if (!envFile.is_open()) {
        cerr << "No se pudo abrir el archivo .env" << endl;
        return 1;
    }

    string line;
    while (getline(envFile, line)) {
        size_t separator = line.find('=');
        if (separator != string::npos) {
            string variable = line.substr(0, separator);
            string value = line.substr(separator + 1);

            setenv(variable.c_str(), value.c_str(), 1); 
        }
    }

    envFile.close();

    const char* retrievedDatabasePath = getenv("DATABASE_PATH");
    const char* retrievedMenuPath = getenv("MENU_PATH");
    const char* retrievedProfilePath = getenv("PROFILE_PATH");

    if (!retrievedDatabasePath || !retrievedMenuPath || !retrievedProfilePath) {
        cerr << "Las variables de entorno no están configuradas correctamente." << endl;
        return 1;
    }

    

    ifstream databaseFile(retrievedDatabasePath);
    if (!databaseFile.is_open()) {
        cerr << "Error al abrir el archivo de la base de datos." << endl;
        return 1;
    }

    bool encontrarUsuario = false;
    string line2,permission;

    while (getline(databaseFile, line2)) {
    size_t pos = line2.find(usuario);
    if (pos != string::npos) {
        permission = line2.substr(pos + usuario.length() + 1);
        encontrarUsuario = true;
        break;
    }
}      

    databaseFile.close();

    if (encontrarUsuario) {
        cout << "Usuario encontrado en el archivo." << endl;
    } else {
        cout << "Usuario no registrado en la base de datos." << endl;
        return 1;
    }

    if(permission.empty()){
        cout << "El usuario no tiene perfil" << endl;
        exit(0);
    }

    cout << "Usuario: " << usuario << endl;
    cout << "Perfil asociado: " << permission << endl;

    /////////////////////////////////////////////////////////////////////

    ifstream file1(retrievedProfilePath);
    if (!file1.is_open()) {
        cout << "Error al abrir el archivo." << endl;
        return 1;
    }

    string line1;
    vector<int> numeros;
    while (getline(file1, line1)) {
        size_t pos = line1.find(permission);
        if (pos != string::npos) {
                string numerosStr = line1.substr(pos + permission.length() + 1); 
                istringstream numerosStream(numerosStr);
                int numero;

                while (numerosStream >> numero) {
                    numeros.push_back(numero);
                    char coma;
                    numerosStream >> coma; 
                }
                break; 
            }
        }

    file1.close();

////////////////////////////////////////////////////////////////////////
    cout << "========== Menu de Opciones ===========" << endl;

    vector<int> vector = mostrarop(numeros, retrievedMenuPath);

    cout << "=======================================" << endl;

    seleccionarOpciones(valor,usuario,ubicacion,anadir,numeros,vector,texto,funcion, retrievedMenuPath);

    return 0;
    }
