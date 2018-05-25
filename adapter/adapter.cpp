#include "stdafx.h"
#include <memory>
#include <conio.h>
#include <iostream>



// Адаптер — это структурный паттерн проектирования, который позволяет
// объектам с несовместимыми интерфейсами работать вместе.
// 




// Уже существующий класс температурного датчика, со следующими особенностями:
//
//    1. имеет "свой" интерфейс
//    2. измерения температуры по Фаренгейту
//    3. возвращает температуру во float
//
class fahrenheit_sensor
{
protected:
	float current_temp;
public:
	fahrenheit_sensor() = default;
	fahrenheit_sensor(float t) : current_temp{t} {}
	// Получить показания температуры в градусах Фаренгейта
	float get_temperature_fahr() const
	{
		// ... какой то код
		return current_temp;
	}
};




// 'Наш' интерфейс датчика температуры:
//    1. работает с температурой по Цельсию
//    2. работает с типом double
//
class i_temp_sensor
{
public:
	virtual ~i_temp_sensor() {}
	virtual double get_temperature() = 0;
};





// Адаптер: преобразует интерфейс датчика в понятный нам интерфейс i_sensor
//
// Вариант №1 (адаптер объекта)
// Основан на композиции, т.е. адаптер содержит ссылку (указатель) на адаптируемый объект
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





// Адаптер: преобразует интерфейс датчика в понятный нам интерфейс i_sensor
// Вариант №2 (адаптер класса)
// Основан на наследовании, т.е. адаптер наследует и 'старый', адаптируемый интерфейс и 'новый'
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

// создаём объект имеющегося датчика температуры (Фаренгейт)
	auto fahr_sensor = make_unique<fahrenheit_sensor>(36.6f);

// создаём адаптер №1 (адаптер объекта)
	unique_ptr<i_temp_sensor> sensor1 = make_unique<sensor_adapter>(std::move(fahr_sensor));

// создаём адаптер №2 (адаптер класса)
	unique_ptr<sensor_adapter2> sensor2 = make_unique<sensor_adapter2>(36.6f);


// используем адаптеры
	cout << "Celsius temperature = " << sensor1->get_temperature() << endl;

	cout << "Celsius temperature = " << sensor2->get_temperature() << endl;

	_getch();
	
	return 0;
}

