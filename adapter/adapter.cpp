#include "stdafx.h"
#include <memory>
#include <conio.h>
#include <iostream>



// ������� � ��� ����������� ������� ��������������, ������� ���������
// �������� � �������������� ������������ �������� ������.
// 




// ��� ������������ ����� �������������� �������, �� ���������� �������������:
//
//    1. ����� "����" ���������
//    2. ��������� ����������� �� ����������
//    3. ���������� ����������� �� float
//
class fahrenheit_sensor
{
protected:
	float current_temp;
public:
	fahrenheit_sensor() = default;
	fahrenheit_sensor(float t) : current_temp{t} {}
	// �������� ��������� ����������� � �������� ����������
	float get_temperature_fahr() const
	{
		// ... ����� �� ���
		return current_temp;
	}
};




// '���' ��������� ������� �����������:
//    1. �������� � ������������ �� �������
//    2. �������� � ����� double
//
class i_temp_sensor
{
public:
	virtual ~i_temp_sensor() {}
	virtual double get_temperature() = 0;
};





// �������: ����������� ��������� ������� � �������� ��� ��������� i_sensor
//
// ������� �1 (������� �������)
// ������� �� ����������, �.�. ������� �������� ������ (���������) �� ������������ ������
//
class sensor_adapter : public i_temp_sensor
{
	
public:
	sensor_adapter(std::unique_ptr<fahrenheit_sensor> ptr) : p_fsensor(std::move(ptr)) {}
	double get_temperature() override
	{
		return (static_cast<double>(p_fsensor->get_temperature_fahr()) - 32.0)*5.0/9.0;
	}
private:
	std::unique_ptr<fahrenheit_sensor> p_fsensor;
};





// �������: ����������� ��������� ������� � �������� ��� ��������� i_sensor
// ������� �2 (������� ������)
// ������� �� ������������, �.�. ������� ��������� � '������', ������������ ��������� � '�����'
//
class sensor_adapter2 : public i_temp_sensor, public fahrenheit_sensor
{

public:
	sensor_adapter2(float temp) : fahrenheit_sensor(temp) {}
	
	double get_temperature() override
	{
		return (static_cast<double>(get_temperature_fahr()) - 32.0)*5.0/9.0;
	}
};





int _tmain(int argc, _TCHAR* argv[])
{
	using namespace std;

// ������ ������ ���������� ������� ����������� (���������)
	auto fahr_sensor = make_unique<fahrenheit_sensor>(36.6f);

// ������ ������� �1 (������� �������)
	unique_ptr<i_temp_sensor> sensor1 = make_unique<sensor_adapter>(std::move(fahr_sensor));

// ������ ������� �2 (������� ������)
	unique_ptr<sensor_adapter2> sensor2 = make_unique<sensor_adapter2>(36.6f);


// ���������� ��������
	cout << "Celsius temperature = " << sensor1->get_temperature() << endl;

	cout << "Celsius temperature = " << sensor2->get_temperature() << endl;

	_getch();
	
	return 0;
}

