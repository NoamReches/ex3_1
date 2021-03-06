#ifndef MTMPARKINGLOT_PARKINGLOT_H
#define MTMPARKINGLOT_PARKINGLOT_H


#include "ParkingLotTypes.h"
#include "Time1.h"
#include "ParkingSpot.h"
#include "UniqueArray.h"
#include "Vehicle.h"

namespace MtmParkingLot {

/*
    typedef unsigned int cash;

    const cash FINE_PRICE = 250;
    const unsigned int MOTORBIKE_MAX_HOURS_TO_PAY = 6;
    const cash MOTORBIKE_FIRST_HOUR_PRICE = 10;
    const cash MOTORBIKE_EXTRA_HOUR_PRICE = 5;
    const unsigned int CAR_MAX_HOURS_TO_PAY = 6;
    const cash CAR_FIRST_HOUR_PRICE = 20;
    const cash CAR_EXTRA_HOUR_PRICE = 10;
    const cash HANDICAPPED_CONSTANT_PRICE = 15;
*/


    using namespace ParkingLotUtils;
    using std::ostream;

    class ParkingLot {



         UniqueArray<Motorbike, Vehicle::Compare> motorbikeParking;
         UniqueArray<Car, Vehicle::Compare> carParking;
        UniqueArray<Handicapped, Vehicle::Compare> handicappedParking;
        bool vehicleIsInParking(const Vehicle& vehicle) const ;
        friend ostream& operator<<(ostream& os, const Vehicle& vehicle);
        const Vehicle *findVehicle(LicensePlate& licensePlate);
		const Vehicle* getVehicleBySpot(const ParkingSpot* parkingSpot);
		
    public:

        ParkingLot(unsigned int parkingBlockSizes[]);
        ~ParkingLot()= default;
        ParkingResult enterParking(VehicleType vehicleType, LicensePlate licensePlate, Time1 entranceTime);
        ParkingResult exitParking(LicensePlate licensePlate, Time1 exitTime);
        ParkingResult getParkingSpot(LicensePlate licensePlate, ParkingSpot& parkingSpot) const;
        void inspectParkingLot(Time1 inspectionTime);
        //friend ostream& operator<<(ostream& os, const ParkingLot& parkingLot);



    };


}

#endif //MTMPARKINGLOT_PARKINGLOT_H
