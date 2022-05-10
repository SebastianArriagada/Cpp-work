/*
Requirements:

To solve the following tasks, more classes have to be used which are inherited from a common base class and
override the virtual methods of the base class.
The objects of these classes have to be put in a collection, then
the collection has to be traversed and the proper methods of the items have to be called.
Prepare automatic unit
tests. Divide your program to modules (compilation units).
Apply exception handling. The solution has to be
given based on the tools shown on the lectures.
Use design patterns and write which one is used.

Assignament:

Layers of gases are given, with certain type (ozone, oxygen, carbon dioxide) and thickness, affected by
atmospheric variables (thunderstorm, sunshine, other effects). When a part of one layer changes into another layer
due to an athmospheric variable, the newly transformed layer ascends and engrosses the first identical type of layer
of gases over it. In case there is no identical layer above, it creates a new layer on the top of the atmosphere.
In the following we declare, how the different types of layers react to the different variables by changing their type
and thickness.
No layer can have a thickness less than 0.5 km, unless it ascends to the identical-type upper layer. In case there is
no identical one, the layer perishes.

                        thunderstorm                    sunshine                    other
ozone                       -                               -                5% turns to oxygen
oxygen                 50% turns to ozone           5% turns to ozone       10% turns to carbon dioxide
carbon dioxide              -                       5% turns to oxygen              -


The program reads data from a text file. The first line of the file contains a single integer N indicating the number
of layers. Each of the following N lines contains the attributes of a layer separated by spaces: type and thickness.
The type is identified by a character:
Z – ozone,
X – oxygen,
C – carbon dioxide.
The last line of the file represents the atmospheric variables in the form of a sequence of characters:
T – thunderstorm,
S – sunshine,
O – others.
In case the simulation is over, it continues from the beginning.
The program should continue the simulation until one gas component totally perishes from the atmosphere.
The program should print all attributes of the layers by simulation rounds!

The program should ask for a filename, then print the content of the input file. You can assume that the input file
is correct. Sample input:

4
Z 5
X 0.8
C 3
X 4
OOOOSSTSSOO

This file will contain all the code togheter, splitted by a head commentary to specify which part is


Create the concept of layer.
Layer will be a mother class of type, Ozone, Oxygen or Carbondioxide
The main class will contain a function to transorm the layer according the Weather.
The weather could be Thunderstorm, Sunshine or Others.
The main function will recive a file name to read. Layers classes will be created and stored into a vector
A check of the tickness will be made every layer transformation

*/


// Class Layer
//
// This class is the base class of the layers.
// It has a type and a thickness.
// It has a method to get the type and the thickness.
// It has a virtual method to transform the layer according the weather.
// It has a method to update the thickness.
// It has a destructor.


#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>


using namespace std;

// Layer.h

class Layer {
    protected:
        char _type;
        double _thickness;
        Layer(char type, double thickness): _type(type), _thickness(thickness) {}
    public:
        virtual Layer* transformLayer(char weather) = 0;
        double getThickness() { return _thickness; }
        char getType() { return _type; }
        double transformTo(double percent) { return _thickness * percent; }
        void updateThickness(double thickness) { _thickness += thickness; }
        void setThickness(double thickness) { _thickness = thickness; }
        void setType(char type) { _type = type; }
        virtual ~Layer() {}
        double newThickness = 0;
        
};


// Class OzoneLayer
//
// This class is the derived class of the Layer class.
// It has a constructor with the type and the thickness.
// It has a method to transform the layer according the weather.
// It has a destructor.
class OzoneLayer: public Layer {
    public:
        OzoneLayer(char type, double thickness): Layer('Z', thickness) {}
        Layer* transformLayer(char weather) override {
            switch (weather) {
                case 'T':
                    // Return this layer
                    return this;
                case 'S':
                    // Return this layer
                    return this;
                case 'O':
                    // Return new instance of OxygenLayer with newThickness
                    newThickness = transformTo(0.05);
                    updateThickness(-newThickness);
                    return OxygenLayer::instance(newThickness);
            }
            return this;
        }
        virtual ~OzoneLayer() {}
        static OzoneLayer* instance(double tickness);
        static void destroy();
    private:
        static OzoneLayer* _instance;

};

OzoneLayer* OzoneLayer::_instance = nullptr;
OzoneLayer* OzoneLayer::instance(double tickness) {
    if (_instance == nullptr) {
        _instance = new OzoneLayer('Z', tickness);
    }
    return _instance;
}


void OzoneLayer::destroy() {
    if (_instance != nullptr) {
        delete _instance;
        _instance = nullptr;
    }
}


// Class OxygenLayer
//
// This class is the derived class of the Layer class.
// It has a constructor with the type and the thickness.
// It has a method to transform the layer according the weather.
// It has a destructor.
class OxygenLayer: public Layer {
    public:
        OxygenLayer(char type, double thickness): Layer('X', thickness) {}
        Layer* transformLayer(char weather) override {
            switch (weather) {
                case 'T':
                    // Return new instance of OxygenLayer with updated thickness
                    newThickness = transformTo(0.5);
                    updateThickness(-newThickness);
                    return OzoneLayer::instance(newThickness);
                case 'S':
                    // Return new instance of OxygenLayer with updated thickness
                    newThickness = transformTo(0.05);
                    updateThickness(-newThickness);
                    return OzoneLayer::instance(newThickness);
                case 'O':
                    // Return new instance of OxygenLayer with updated thickness
                    newThickness = transformTo(0.1);
                    updateThickness(-newThickness);
                    return CarbonDioxideLayer::instance(newThickness);
            }
            return this;
        }
        virtual ~OxygenLayer() {}
        static OxygenLayer* instance(double tickness);
        static void destroy();
    private:
        static OxygenLayer* _instance;
};


OxygenLayer* OxygenLayer::_instance = nullptr;
OxygenLayer* OxygenLayer::instance(double tickness) {
    if (_instance == nullptr) {
        _instance = new OxygenLayer('X', tickness);
    }
    return _instance;
}


void OxygenLayer::destroy() {
    if (_instance != nullptr) {
        delete _instance;
        _instance = nullptr;
    }
}


// Class CarbonDioxideLayer
//
// This class is the derived class of the Layer class.
// It has a constructor with the type and the thickness.
// It has a method to transform the layer according the weather.
// It has a destructor.
class CarbonDioxideLayer: public Layer {
    public:
        CarbonDioxideLayer(char type, double thickness): Layer('C', thickness) {}
        Layer* transformLayer(char weather) override {
            switch (weather) {
                case 'T':
                    // Return new instance of CarbonDioxideLayer with updated thickness
                    return this;
                case 'S':
                    // Return new instance of CarbonDioxideLayer with updated thickness
                    newThickness = transformTo(0.05);
                    updateThickness(-newThickness);
                    return OxygenLayer::instance(newThickness);
                case 'O':
                    // Return new instance of CarbonDioxideLayer with updated thickness
                    return this;
            }
            return this;
        }
        virtual ~CarbonDioxideLayer() {}
        static CarbonDioxideLayer* instance(double tickness);
        static void destroy();
    private:
        static CarbonDioxideLayer* _instance;
};


CarbonDioxideLayer* CarbonDioxideLayer::_instance = nullptr;
CarbonDioxideLayer* CarbonDioxideLayer::instance(double tickness) {
    if (_instance == nullptr) {
        _instance = new CarbonDioxideLayer('C', tickness);
    }
    return _instance;
}


void CarbonDioxideLayer::destroy() {
    if (_instance != nullptr) {
        delete _instance;
        _instance = nullptr;
    }
}


int main ( int argc, char *argv[] ) {
    string filename = "input.txt";
    
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "File not found" << endl;
        return 1;
    }
    // Get layers
    int nLayers;
    file >> nLayers;
    cout << nLayers << endl;
    vector<Layer*> layers;
    for (int i = 0; i < nLayers; i++) {
        cout << "Layer " << i + 1 << endl;
        char type;
        double thickness;
        file >> type >> thickness;
        if (type == 'Z') {
            layers.push_back(new OzoneLayer(type, thickness));
            layers[i]->setThickness(thickness);
            cout << "Ozone layer created " << layers[i]->getThickness() << endl;
        } else if (type == 'X') {
            layers.push_back(new OxygenLayer(type, thickness));
            layers[i]->setThickness(thickness);
            cout << "Oxygen layer created " << layers[i]->getThickness() << endl;
        } else if (type == 'C') {
            layers.push_back(new CarbonDioxideLayer(type, thickness));
            layers[i]->setThickness(thickness);
            cout << "Carbon dioxide layer created " << layers[i]->getThickness() << endl;

        } else {
            cout << "Invalid layer type" << endl;
        }
    }
    // Get the weather as a char, and store it in a vector of chars
    string weather;
    file >> weather;
    vector<char> weatherVector;
    for (int i = 0; i < weather.size(); i++) {
        weatherVector.push_back(weather[i]);
    }
    // Print the weather
    cout << "Weather: ";
    for (int i = 0; i < weatherVector.size(); i++) {
        cout << weatherVector[i];
    }
    cout << endl;

    // Transform the layers according the weather
    for (int i = 0; i < weatherVector.size(); i++) {
        cout << "Weater: " << weatherVector[i] << endl;
        for (int j = 0; j < layers.size(); j++) {
            layers[j] = layers[j]->transformLayer(weatherVector[i]);
            cout << "Prev layer: " << layers[j]->getThickness() << "trype: "<< layers[j] -> getType() <<endl;
            cout << "New layer: " << layers[j]->getThickness() << "type: "<< layers[j] -> getType() <<endl;
        }

    }
    file.close();
    cout << 22 << endl;
    return 1;
}



