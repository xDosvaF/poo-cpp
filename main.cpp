
#include <iostream>
#include <string>
#include <thread>
#include <chrono>

using namespace std;

string mensaje = "Soy una variable global jeje";

class Animal {
    protected:
        string nombre;
        double peso;
        string clasificacion;
        string especie;

    public:
        Animal(string _nombre, double _peso,
               string _clasificacion, string _especie) {
            nombre = _nombre;
            peso = _peso;
            clasificacion = _clasificacion;
            especie = _especie;
        }

        void Presentacion() {
            cout << "Hola soy un " << especie
                 << " y me llamo " << nombre << endl;
        }

        virtual void Sonido() = 0;

        virtual ~Animal() = default;
};

class Mamifero : public Animal {
    private:
        string colorPelo;
        int patas;

    public:
        Mamifero(string _nombre, double _peso,
                 string _clasificacion, string _especie,
                 string _colorPelo, int _patas)
            : Animal(_nombre, _peso, _clasificacion, _especie) {
            colorPelo = _colorPelo;
            patas = _patas;
        }

        void Presentacion() {
            Animal::Presentacion();
        }

        void Sonido() override {
            if (especie == "Gato")
                cout << "El gato " << nombre << " hace MAUUUU!" << endl;
        }

        void setNombre(string _nombre) {
            if (_nombre.empty()) {
                cout << "Debes escribir un nombre" << endl;
                return;
            }

            nombre = _nombre;
        }

        string getNombre() {
            return nombre;
        }

        string getColorPelo() {
            return colorPelo;
        }
};

int main() {
    cout << mensaje << endl;

    Mamifero gato("Gotitas", 12.5, "terrestre",
                  "Gato", "blanco", 4);

    string setNombre;

    while (true) {
        cout << "\n¿Cuál es el nombre de tu gato?" << endl;
        getline(cin, setNombre);

        /*
        // Forma incorrecta de modificar un atributo protegido
        gato.nombre = "Max";
        */

        // Forma correcta de modificar el nombre
        gato.setNombre(setNombre);

        this_thread::sleep_for(chrono::seconds(1));

        cout << "¡Qué lindo nombre!" << endl;
        cout << "Tu gato se llama " << gato.getNombre() << endl;

        this_thread::sleep_for(chrono::seconds(1));

        /*
        // Forma incorrecta de acceder a un atributo privado
        string color = gato.colorPelo;
        */

        // Forma correcta de acceder al color
        string color = gato.getColorPelo();

        cout << "Mira! El color del pelo de tu gato es "
             << color << endl;

        gato.Presentacion();
        gato.Sonido();

        this_thread::sleep_for(chrono::seconds(2));
    }

    return 0;
}
