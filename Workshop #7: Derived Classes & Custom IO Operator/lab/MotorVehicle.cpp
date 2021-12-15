/**********************************************************
 * Name: Xuewei Sheng
 * Student ID: 061745121
 * Seneca email: xsheng3@myseneca.ca
 * Section: NFF
 **********************************************************/#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include"cstring.h"
#include "MotorVehicle.h"
using namespace std;
namespace sdds {
	MotorVehicle::MotorVehicle(const char* plate, const int year) {
		strCpy(m_plate, plate);
		m_year = year;
		strCpy(m_address, "Factory");
	}
	void MotorVehicle::moveTo(const char* address) {
		if (address && strCmp(m_address, address))
		{
			cout << "|";
			cout.width(8);
			cout << m_plate << "| |";
			cout.width(20);
			cout << m_address << " ---> ";
			cout.setf(ios::left);
			cout.width(20);
			cout << address << "|" << endl;
			cout.unsetf(ios::left);
			strCpy(m_address, address);
		}
	}
	std::ostream& MotorVehicle::write(std::ostream& os)const {
		os << "| " << m_year << " | " << m_plate << " | " << m_address;
		return os;
	}

	std::istream& MotorVehicle::read(std::istream& in) {
		cout << "Built year: ";
		in >> m_year;
		in.ignore(1000, '\n');
		cout << "License plate: ";
		in >> m_plate;
		in.ignore(1000, '\n');
		cout << "Current location: ";
		in >> m_address;
		in.ignore(1000, '\n');
		return in;
	}
	std::ostream& operator<<(std::ostream& os, const MotorVehicle& vehicle)
	{
		vehicle.write(os);
		return os;
	}
	std::istream& operator>>(std::istream& in, MotorVehicle& vehicle) {
		vehicle.read(in);
		return in;
	}



}