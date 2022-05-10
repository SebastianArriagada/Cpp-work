#ifndef LAYER_H
#define LAYER_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include "Atmosphere.h"


using namespace std;

class Layer {
    protected:
        double _thickness;
        Layer(double thickness):  _thickness(thickness) {}
    public:
        virtual ~Layer() {}
        virtual Layer* transformLayer(char weather) = 0;
        double getThickness() { return _thickness; }
        double transformTo(double percent) { return _thickness * percent; }
        void updateThickness(double thickness) { _thickness += thickness; }
        void setThickness(double thickness) { _thickness = thickness; }
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
        OzoneLayer(double thickness): Layer( thickness) {}
        Layer* transformLayer(char weather) override{
            Atmosphere atmosphere;
            Layer* layer = atmosphere.transform(OzoneLayer( _thickness));
            return layer;
        }
        static OzoneLayer* instance(double tickness);
        static void destroy();
    private:
        static OzoneLayer* _instance;

};

// Class OxygenLayer
//
// This class is the derived class of the Layer class.
// It has a constructor with the type and the thickness.
// It has a method to transform the layer according the weather.
// It has a destructor.
class OxygenLayer: public Layer {
    public:
        OxygenLayer(double thickness): Layer( thickness) {}
        Layer* transformLayer(char weather) override{
        Atmosphere atmosphere;
        Layer* layer = atmosphere.transform(OxygenLayer( _thickness));
        return layer;
        }
        static OxygenLayer* instance(double tickness);
        static void destroy();
    private:
        static OxygenLayer* _instance;
        
};


// Class CarbonDioxideLayer
//
// This class is the derived class of the Layer class.
// It has a constructor with the type and the thickness.
// It has a method to transform the layer according the weather.
// It has a destructor.
class CarbonDioxideLayer: public Layer {
    public:
        CarbonDioxideLayer( double thickness): Layer( thickness) {}
        Layer* transformLayer(char weather) override{
            Atmosphere atmosphere;
            Layer* layer = atmosphere.transform(CarbonDioxideLayer( _thickness));
            return layer;
    }
            static CarbonDioxideLayer* instance(double tickness);
        static void destroy();
    private:
        static CarbonDioxideLayer* _instance;
};

#endif // LAYER_H
