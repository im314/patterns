#include "stdafx.h"
#include "human_state_machine.h"

using std::cout;
using std::endl;



//
//
//    Базовый класс состояния человека
//
//


void human_state::move()
{
	std::cout <<  "\tдвигаться: ";
}

void human_state::eat()
{
	std::cout <<  "\tкушать:    ";
}

void human_state::dream()
{
	std::cout <<  "\tмечтать:   ";
}

void human_state::sleep()
{
	std::cout <<  "\tспать:     ";
}

const std::string human_state::state_name()
{
	return name;
}





//
//
//    Состояние 'НА РАБОТЕ'
//
//


state_work::state_work()
{
	name = "Состояние 'НА РАБОТЕ'";
}

void state_work::move()
{
	human_state::move();
	cout <<  "не могу двигаться, т.к. должен сидеть у монитора" << endl;
}

void state_work::eat()
{
	human_state::eat();
	cout <<   "пообедал" << endl;
}

void state_work::dream()
{
	human_state::dream();
	cout << "мечтать тут некогда, надо писать код" << endl;
}

void state_work::sleep()
{
	human_state::sleep();
	cout << "спать тут можно, только если только ты Валера" << endl;
}


human_state& state_work::instance()
{
	static state_work wrk;
	return wrk;
}

human_state& state_work::finish()
{
	cout << "завершаю " << state_name() << endl;
	return state_home::instance();
}





//
//
//    Состояние 'ДОМА'
//
//


state_home::state_home()
{
	name = "Состояние 'ДОМА'";
}

void state_home::move()
{
	human_state::move();
	cout <<  "могу ходить от туалета к холодильнику" << endl;
}

void state_home::eat()
{
	human_state::eat();
	cout <<   "поужинал" << endl;
}

void state_home::dream()
{
	human_state::dream();
	cout << "мечтать можно, но недолго" << endl;
}

void state_home::sleep()
{
	human_state::sleep();
	cout << "спать некогда" << endl;
}

human_state& state_home::instance()
{
	static state_home hm;
	return hm;
}

human_state& state_home::finish()
{
	cout << "завершил " << state_name() << endl;
	return state_sleep::instance();
}





//
//
//    Состояние 'СОН'
//
//


state_sleep::state_sleep()
{
	name = "Состояние 'СОН'";
}

void state_sleep::move()
{
	human_state::move();
	cout <<  "двигаюсь во сне" << endl;
}

void state_sleep::eat()
{
	human_state::eat();  cout <<   "кушать вряд ли получится" << endl;
}

void state_sleep::dream()
{
	human_state::dream();  cout << "целых 4 часа для мечт" << endl;
}

void state_sleep::sleep()
{
	human_state::sleep();  cout << "я и так сплю! )))" << endl;
}

human_state& state_sleep::instance()
{
	static state_sleep slp; return slp;
}

human_state& state_sleep::finish()
{
	cout << "завершаю " << state_name() << endl;
	return state_work::instance();
}





//
//
//    Класс-контекст ЧЕЛОВЕК
//
//


void human::change_state(human_state *new_state)
{
	state = new_state;
	cout << endl << "перешёл в " << state->state_name() << endl;
}

human::human()
{
	change_state(&state_sleep::instance());
}

void human::move()
{
	state->move();
}

void human::eat()
{
	state->eat();
}

void human::dream()
{
	state->dream();
}

void human::sleep()
{
	state->sleep();
}

void human::finish()
{
	change_state(&state->finish());
}

void human::live()
{
	dream();
	move();
	eat();
	sleep();
	finish();
}