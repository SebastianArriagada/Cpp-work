# include "Layer.h"

// Ozone layer
// Layer* OzoneLayer::transformLayer(char weather) {
//     switch (weather) {
//         case 'T':
//             Return this layer
//             return this;
//         case 'S':
//             Return this layer
//             return this;
//         case 'O':
//             Return new instance of OxygenLayer with newThickness
//             newThickness = transformTo(0.05);
//             updateThickness(-newThickness);
//             return OxygenLayer::instance(newThickness);
//     }
//     Raise an exception if the weather is not valid
//     throw "Invalid weather";
// }

OzoneLayer* OzoneLayer::_instance = nullptr;
OzoneLayer* OzoneLayer::instance(double tickness) {
    if (_instance == nullptr) {
        _instance = new OzoneLayer(tickness);
    }
    return _instance;
}


void OzoneLayer::destroy() {
    if (_instance != nullptr) {
        delete _instance;
        _instance = nullptr;
    }
}

// Oxygen layer

// Layer* OxygenLayer::transformLayer(char weather) {
//     switch (weather) {
//         case 'T':
//             // Return new instance of OzoneLayer with newThickness
//             newThickness = transformTo(0.5);
//             updateThickness(-newThickness);
//             return OzoneLayer::instance(newThickness);
//         case 'S':
//             // Return new instance of OzoneLayer with newThickness
//             newThickness = transformTo(0.05);
//             updateThickness(-newThickness);
//             return OzoneLayer::instance(newThickness);
//         case 'O':
//             // Return new instance of CarbonDioxideLayer with newThickness
//             newThickness = transformTo(0.1);
//             updateThickness(-newThickness);
//             return CarbonDioxideLayer::instance(newThickness);
//     }
//     // Raise an exception if the weather is not valid
//     throw "Invalid weather";
// }

OxygenLayer* OxygenLayer::_instance = nullptr;
OxygenLayer* OxygenLayer::instance(double tickness) {
    if (_instance == nullptr) {
        _instance = new OxygenLayer(tickness);
    }
    return _instance;
}


void OxygenLayer::destroy() {
    if (_instance != nullptr) {
        delete _instance;
        _instance = nullptr;
    }
}

// Carbon dioxide layer
// Layer* CarbonDioxideLayer::transformLayer(char weather) {
//     switch (weather) {
//         case 'T':
//             // Return this layer
//             return this;
//         case 'S':
//             // Return new instance of OxygenLayer with newThickness
//             newThickness = transformTo(0.05);
//             updateThickness(-newThickness);
//             return OxygenLayer::instance(newThickness);
//         case 'O':
//             // Return this layer
//             return this;
//     }
//     // Raise an exception if the weather is not valid
//     throw "Invalid weather";
// }


CarbonDioxideLayer* CarbonDioxideLayer::_instance = nullptr;
CarbonDioxideLayer* CarbonDioxideLayer::instance(double tickness) {
    if (_instance == nullptr) {
        _instance = new CarbonDioxideLayer(tickness);
    }
    return _instance;
}


void CarbonDioxideLayer::destroy() {
    if (_instance != nullptr) {
        delete _instance;
        _instance = nullptr;
    }
}

