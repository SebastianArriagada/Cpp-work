# include "Layer.h"

// Create a class that manages the layers
class Atmosphere {
    public:
        // Constructor
        Atmosphere();
        // Destructor
        ~Atmosphere();
        // transform 
        Layer* transform( OzoneLayer ozone);
        Layer* transform( CarbonDioxideLayer carbonDioxide);
        Layer* transform( WaterLayer water);
}
