#pragma once
#include "enums.h"
#include <map>
#include "Weather.h"
#include "curves.h"
#include "plantproperties.h"
#include "seed.h"
#include <random>


namespace ALMANAC
{
    class SoilCell;
    class SoilGrid;

    class BasePlant
    {
        friend class SoilGrid;
    public:
        BasePlant(SoilCell* soil = 0);
        BasePlant(Seed seed, SoilCell* soil = 0);
        BasePlant(PlantProperties plantprop, PlantVisualProperties visualprop = PlantVisualProperties(), SoilCell* soil = 0);
        

        std::string getName();
        int geticon();
        void calculate(const WeatherData& data, const double& albedo, const double radiation = -1); // plug in today's weather :v. CO2 is in ppm
        void findREG(); // probably has params
        double getHU(); // heat units
        double findHUI(); // heat unit indx, basically % grown.
        double calcHeight();
        double calcRootDepth();
        double getBiomass();
        BiomassHolder getBiomassStruct();
        double getLAI(); // strictly for accessing the LAI of the plant.
        double getRequiredWater();

        bool readyForLeafShed;
        /** Returns:
        1 - if (1) no need for vernalization OR (2) has been fully vernalized
        0 < x < 1 - if partially vernalized AND is not obligate
        0 - if not vernalized OR (not vernalized sufficiently AND is obligate)
        **/
        double getVernalizedRatio();

        double getREG();
        double getWaterREG();

        double getNitrogen();

        double getInduction();
        bool canFlower();
        bool isDead();
        bool isDormant();

        void createSeeds(const Month& date);

        std::vector<Seed> seedlist;

        double deadBiomass;
        double removedNitrogen;

        PlantVisualProperties vp;
    private:
        mt19937 rng;
        double random(double min = 0, double max = 1);

        PlantProperties prop;
        

        bool dead;

        double previousHeatUnits, heatUnits;
        double REG; // Stress factor. Has to be set elsewhere.
        double requiredWater;
        double suppliedWater;

        
        double currentWaterlogValue;
        int consecutiveDormantDays;

        int getAge(); // in years
        int age; // incremented each time calculate() is called. Divide by 360 to get age in years.

        double height; // mm
        double rootDepth; // mm

        double LAI, prevLAI;
        double maxBiomass;
        double LAIShedPerDay;
        int daysLeftForShedding;

        double floralInductionUnits;
        double vernalizationUnits;

        static SCurve getSCurve(const bool dayNeutral, const bool longDayPlant, double minInduction, const double& optimalInductionNightLength);

        BiomassHolder Biomass;  // kg        

        double nitrogen; // kg/ha

        double flowerFactor; // % of flowering successfully done.

        SoilCell* soilPatch;

        double findHUF();
        double findPreviousHUF();
        double findPreviousHUI();
        double findVPD(const double& averageTemp, const double& humidity);
        double findPsychometricConstant(const double& temperature = 2.0f); // AKA 'gamma'
        double findSlopeOfSaturatedVaporCurve(const double& temperature);
        double findNetRadiation(const double& radiation, const double& albedo); //aka h(0)
        double findLatentHeat(const double& temperature);
        double findOptimalNitrogenConcentration(); // currently a dummy function
        double findRequiredNitrogen(); // finds the extra nitrogen the plant needs.
        double barometricPressure(const double& altitude);
        double getWaterStressFactor();
        double getWaterlogStressFactor();
        double getNitrogenStressFactor();
        double findFallenLeaves(); // A formula to make sure trees drop a constant weight in leaves each year. The ratio of leaves to total biomass decreases.
        // Non-trees don't use this function.

        double floweringHU;
        double endFloweringHU;
        double finalHU;
        double maxHU;

        void doWater(const WeatherData& data);
        void doNitrogen();
        void doFloralInduction(const WeatherData& data);
        void doVernalization(const WeatherData& data);
        void partitionBiomass(const double dBiomass);
        void doTempStress(const WeatherData& wd);
        void doDormancy();

        void reduceStandingBiomass(const WeatherData& data); // = die off, for annual plants.
        double tempstress;
    };
}