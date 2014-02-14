#pragma once
#include <string>
#include <map>
#include "curves.h"

namespace ALMANAC
{
    struct BiomassHolder
    {
        BiomassHolder();
        BiomassHolder(double Stem, double Roots, double Storage, double Fruits);
        double stem;
        double roots;
        double storageOrgan;
        double flowerAndfruits;
        double getBiomass() const;
        operator double() const;
    };

    /// This class has intristic properties that do not change over the lifetime of a plant, eg its max LAI, growth stages, and various constants.
    struct PlantProperties
    {
        std::string name;

        double maxLAI;
        std::map<int, double> growthStages;
        double baseTemp; // ��C, for GDD calcs
        double waterTolerence;
        double maxHeight; // mm
        double maxYearlyGrowth; // mm, trees only
        double maxRootDepth;
        SCurve HeatUnitFactorNums; // how fast it grows, shared atm
        SCurve CO2CurveFactors;  /// This one is shared for all plants.
        Parabola flowerTempCurve;
        Parabola tempCurve; //growing temp
        Parabola vernalizationCurve;
        LeafDistribution LAIGraph;
        SCurve nightLengthCurve;

        double startingNitrogenConcentration;
        double finalNitrogenConcentration;

        BiomassHolder baseRatios;
        BiomassHolder fruitingRatios;
        BiomassHolder finalRatios;

        double dormantHeightDecrease;
        double dormantRootDecrease;
        BiomassHolder dormantBiomassDecrease;

        double minimumTemperature;
        double optimalTemperature;

        double minGerminationTemp;
        double optimalGerminationTemp;
        double germinationThermalUnits;
        double averageFruitWeight; // kg
        double seedRatio;
        double seedViability; // 0 <= x <= 1
        int dormancy;

        double minFloweringTemp;
        double optimalFloweringTemp;

        double minVernalizationTemp; // default 0 C
        double optimalVernalizationTemp; // default 2.5 C
        double vernalizationThermalUnits; // default 45
        bool needsVernalization; // default FALSE
        bool isObligateVernalization; // default FALSE

        
        double floralInductionUnitsRequired; // defaults to 7
        bool dayNeutral;
        bool longDayPlant;
        double minimumInduction;
        double criticalNightLength;

        double biomassToVPD; // bc(3), =7

        bool isAnnual; // limits HU to the maturity HUs.    
        bool isTree;
        int yearsUntilMaturity; // trees only
        int vegetativeMaturity; // same
        int maxAge;
        int leafFallPeriod; // days. over how many days the plant loses its LAI.

    };
}