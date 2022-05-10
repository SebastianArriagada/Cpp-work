# inclide "Atmosphere.h"


using namespace std;


// transfor OxygenLayer
Layer* transform( OzoneLayer ozone) {
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
    // Raise an exception if the weather is not valid
    throw "Invalid weather";
}


// transfor CarbonDioxideLayer
Layer* transform( CarbonDioxideLayer carbonDioxide) {
    switch (weather) {
        case 'T':
            // Return new instance of OzoneLayer with newThickness
            newThickness = transformTo(0.5);
            updateThickness(-newThickness);
            return OzoneLayer::instance(newThickness);
        case 'S':
            // Return new instance of OzoneLayer with newThickness
            newThickness = transformTo(0.05);
            updateThickness(-newThickness);
            return OzoneLayer::instance(newThickness);
        case 'O':
            // Return new instance of CarbonDioxideLayer with newThickness
            newThickness = transformTo(0.1);
            updateThickness(-newThickness);
            return CarbonDioxideLayer::instance(newThickness);
        }
    // Raise an exception if the weather is not valid
    throw "Invalid weather";
}


// transfor WaterLayer
Layer* transform( WaterLayer water) {
    switch (weather) {
        case 'T':
            // Return new instance of OzoneLayer with newThickness
            newThickness = transformTo(0.5);
            updateThickness(-newThickness);
            return OzoneLayer::instance(newThickness);
        case 'S':
            // Return new instance of OzoneLayer with newThickness
            newThickness = transformTo(0.05);
            updateThickness(-newThickness);
            return OzoneLayer::instance(newThickness);
        case 'O':
            // Return new instance of CarbonDioxideLayer with newThickness
            newThickness = transformTo(0.1);
            updateThickness(-newThickness);
            return CarbonDioxideLayer::instance(newThickness);
        }
    // Raise an exception if the weather is not valid
    throw "Invalid weather";
}


