/**********************************************************
 * Name: Xuewei Sheng
 * Student ID: 061745121
 * Seneca email: xsheng3@myseneca.ca
 * Section: NFF
 **********************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include"cstring.h"
#include "Truck.h"
#include "MotorVehicle.h"
using namespace std;
namespace sdds {
	Truck::Truck(const char* plate, const int year, const double capacity, const char* address):MotorVehicle(plate, year), m_cargoLoad(0.0) {
		m_capacity = capacity;
		MotorVehicle::moveTo(address);
	}
	bool Truck::addCargo(double cargo) {
		bool added = !(m_capacity == m_cargoLoad);

			if (m_capacity >= m_cargoLoad + cargo)
			{
				m_cargoLoad += cargo;
			}
			else
			{
				m_cargoLoad = m_capacity;
			}

		return added;
	}
	bool Truck::unloadCargo() {
		bool unloaded = (m_cargoLoad > 0.0);
		m_cargoLoad = 0.0;
		return unloaded;
	}
	std::ostream& Truck::write(std::ostream& os)const {
		MotorVehicle::write(os);
		os << " | " << m_cargoLoad << "/" << m_capacity;
		return os;
	}
	std::istream& Truck::read(std::istream& in) {
		MotorVehicle::read(in);
		double cargoInput = 0.0;
		cout << "Capacity: ";
		in >> m_capacity;
		in.ignore(1000, '\n');
		cout << "Cargo: ";
		in >> cargoInput;
		in.ignore(1000, '\n');
		if (cargoInput <= m_capacity)
		{
			m_cargoLoad = cargoInput;
		}
		else
		{
			m_cargoLoad = m_capacity;
		}
		return in;
	}
	std::ostream& operator<<(std::ostream& os, const Truck& truck) {
		truck.write(os);
		return os;
	}
	std::istream& operator>>(std::istream& in, Truck& truck) {
		truck.read(in);
		return in;
	}


}