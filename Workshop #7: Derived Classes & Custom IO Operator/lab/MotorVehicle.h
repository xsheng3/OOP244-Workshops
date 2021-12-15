/**********************************************************
 * Name: Xuewei Sheng
 * Student ID: 061745121
 * Seneca email: xsheng3@myseneca.ca
 * Section: NFF
 **********************************************************/
#ifndef SDDS_MOTORVEHICLE_H__
#define SDDS_MOTORVEHICLE_H__
#include <iostream>
namespace sdds {
	class MotorVehicle {
		char m_plate[9];
		char m_address[64] ;
		int m_year;
	public:
		MotorVehicle(const char* plate, const int year);
		void moveTo(const char* address);
		std::ostream& write(std::ostream& os)const;
		std::istream& read(std::istream& in);

	};
	std::ostream& operator<<(std::ostream& os, const MotorVehicle& vehicle);
	std::istream& operator>>(std::istream& in, MotorVehicle& vehicle);
}
#endif
