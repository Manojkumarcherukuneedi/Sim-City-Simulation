##Feature Summary – Environmental Zone (E)

This milestone introduces a new zone type: the Environmental Zone, represented as 'E' in the region map. Environmental Zones reduce the pollution level of the 8 cells surrounding them by 2 units each simulation step.
This functionality is now fully integrated into the simulation loop and affects the behavior of other zones indirectly by lowering pollution, creating cleaner areas, and slowing down pollution growth.

## Implemented Functionality

- environmental_zone.cpp / .h: Implements updateEnvironmentalZones() function.

- main.cpp: Updated to include the environmental zone header and function call within the time-step loop.

- Environmental Zones are recognized in region1.csv.

- Pollution is reduced around 'E' zones by 2 units per step.

## Files Included

- environmental_zone.cpp

- environmental_zone.h

- Modified main.cpp (includes the updateEnvironmentalZones call)

- All other zone growth, pollution spread, and simulation logic from Project 1 remains unchanged at this milestone stage

## How to compile 

 g++ main.cpp commercial_zone.cpp region_analysis.cpp region.cpp config.cpp pollution.cpp residential_zone.cpp industrial_zone.cpp environmental_zone.cpp

## Status

- Environmental Zone logic completed

- Integrated into simulation loop

- Pollution reduction verified

- Zone growth bonus for R/C near E — NOT implemented in milestone

(Planned for final submission.)

## Notes

This milestone demonstrates that the new zone type is functioning, properly integrated, and affecting simulation output as expected. Enhancements and additional interactions will follow in the final version.