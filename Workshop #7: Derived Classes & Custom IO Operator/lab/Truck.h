/**********************************************************
 * Name: Xuewei Sheng
 * Student ID: 061745121
 * Seneca email: xsheng3@myseneca.ca
 * Section: NFF
 **********************************************************/
#ifndef SDDS_TRUCK_H__
#define SDDS_TRUCK_H__
#include <iostream>
#include "MotorVehicle.h"
namespace sdds {
	class Truck : public MotorVehicle {
		double m_capacity;
		double m_cargoLoad;
	public:
		Truck(const char* plate, const int year, const double capacity, const char* address);
		bool addCargo(double cargo);
		bool unloadCargo();
		std::ostream& write(std::ostream& os)const;
		std::istream& read(std::istream& in);

	};
	std::ostream& operator<<(std::ostream& os, const Truck& truck);
	std::istream& operator>>(std::istream& is, Truck& truck);
}
#endif
