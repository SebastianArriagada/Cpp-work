
#include "Layer.h"

using namespace std;

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
            layers.push_back(new OzoneLayer( thickness));
            layers[i]->setThickness(thickness);
            cout << "Ozone layer created " << layers[i]->getThickness() << endl;
        } else if (type == 'X') {
            layers.push_back(new OxygenLayer(thickness));
            layers[i]->setThickness(thickness);
            cout << "Oxygen layer created " << layers[i]->getThickness() << endl;
        } else if (type == 'C') {
            layers.push_back(new CarbonDioxideLayer( thickness));
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