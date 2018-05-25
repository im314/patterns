#include "stdafx.h"
#include "human_state_machine.h"

using std::cout;
using std::endl;



//
//
//    ������� ����� ��������� ��������
//
//


void human_state::move()
{
	std::cout <<  "\t���������: ";
}

void human_state::eat()
{
	std::cout <<  "\t������:    ";
}

void human_state::dream()
{
	std::cout <<  "\t�������:   ";
}

void human_state::sleep()
{
	std::cout <<  "\t�����:     ";
}

const std::string human_state::state_name()
{
	return name;
}





//
//
//    ��������� '�� ������'
//
//


state_work::state_work()
{
	name = "��������� '�� ������'";
}

void state_work::move()
{
	human_state::move();
	cout <<  "�� ���� ���������, �.�. ������ ������ � ��������" << endl;
}

void state_work::eat()
{
	human_state::eat();
	cout <<   "��������" << endl;
}

void state_work::dream()
{
	human_state::dream();
	cout << "������� ��� �������, ���� ������ ���" << endl;
}

void state_work::sleep()
{
	human_state::sleep();
	cout << "����� ��� �����, ������ ���� ������ �� ������" << endl;
}


human_state& state_work::instance()
{
	static state_work wrk;
	return wrk;
}

human_state& state_work::finish()
{
	cout << "�������� " << state_name() << endl;
	return state_home::instance();
}





//
//
//    ��������� '����'
//
//


state_home::state_home()
{
	name = "��������� '����'";
}

void state_home::move()
{
	human_state::move();
	cout <<  "���� ������ �� ������� � ������������" << endl;
}

void state_home::eat()
{
	human_state::eat();
	cout <<   "��������" << endl;
}

void state_home::dream()
{
	human_state::dream();
	cout << "������� �����, �� �������" << endl;
}

void state_home::sleep()
{
	human_state::sleep();
	cout << "����� �������" << endl;
}

human_state& state_home::instance()
{
	static state_home hm;
	return hm;
}

human_state& state_home::finish()
{
	cout << "�������� " << state_name() << endl;
	return state_sleep::instance();
}





//
//
//    ��������� '���'
//
//


state_sleep::state_sleep()
{
	name = "��������� '���'";
}

void state_sleep::move()
{
	human_state::move();
	cout <<  "�������� �� ���" << endl;
}

void state_sleep::eat()
{
	human_state::eat();  cout <<   "������ ���� �� ���������" << endl;
}

void state_sleep::dream()
{
	human_state::dream();  cout << "����� 4 ���� ��� ����" << endl;
}

void state_sleep::sleep()
{
	human_state::sleep();  cout << "� � ��� ����! )))" << endl;
}

human_state& state_sleep::instance()
{
	static state_sleep slp; return slp;
}

human_state& state_sleep::finish()
{
	cout << "�������� " << state_name() << endl;
	return state_work::instance();
}





//
//
//    �����-�������� �������
//
//


void human::change_state(human_state *new_state)
{
	state = new_state;
	cout << endl << "������� � " << state->state_name() << endl;
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