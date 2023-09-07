// Plantillas.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>

#include <fstream>
//clase plantillas para guardar datos
template <typename T>

class DataHelper
{
    T data;

public:
    DataHelper(T newdata) //constructor de una fucion
    {
        data = newdata;
    }

    void print()
    {
        std::cout << data << "\n";
    }
    //imprime al archivo dado por la ruta
    void printtoFile(const char* filename, bool binary = false)
    {
        if (!binary)
        {

            std::fstream myfile(filename, std::ios_base::out);
            if (myfile.is_open())
            {
                myfile << sizeof(T) << data;
                myfile.close();
                /*
                 myfile << "hola mundo \n";
                myfile << "Esta es otra linea \r\n";
                myfile.close();
                */
            }
            else
            {
                std::cout << " no se puede abrir el archivo" << "\n";
            }
        }
        else
        {
            std::fstream myfile(filename, std::ios_base::out | std::ios_base::binary);
            if (myfile.is_open())
            {
                myfile << sizeof(T) << data;
                myfile.close();
                /*
                myfile << "hola mundo \n";
                myfile << "esta es otra linea \r\n";
                myfile.close();
                */
            }
        }
    }

};

int main()
{
    std::cout << "tamaños \n";
    std::cout << "int : " << sizeof(int) << "\n";
    std::cout << "float : " << sizeof(float) << "\n";
    std::cout << "double : " << sizeof(double) << "\n";
    std::cout << "char : " << sizeof(char) << "\n";
    std::cout << "string : " << sizeof(std::string) << "\n";

    DataHelper<char>* mychar = new DataHelper<char>('w');
    DataHelper<float>* myfloat = new DataHelper<float>(3.141916);

    DataHelper<char* >* mychars = new DataHelper<char* >((char*)"hola mundo");

    mychar->print();
    myfloat->print();
    mychars->print();

    myfloat->printtoFile("float.txt");
    myfloat->printtoFile("float.bin", true);

    //abrir archivo
    std::fstream archivo("criper.bmp", std::ios_base::in | std::ios_base::out);
    if (archivo.is_open())
    {
        char* buffer = new char[8];
        while (!archivo.eof())
        {
            archivo.read((char*)buffer, 8);
            std::cout << std::hex << buffer << "/n";
        }

    }
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
