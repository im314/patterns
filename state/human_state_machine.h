#pragma once
#ifndef __HUMAN_STATE_MACHINE__
#define __HUMAN_STATE_MACHINE__
#include <iostream>
#include <cstdint>
#include <string>


class state_work;
class state_home;
class state_sleep;



// ������� ����� ��������� ��������
//
class human_state
{

protected:
	std::string name;

public:
	virtual void move();
	virtual void eat();
	virtual void dream();
	virtual void sleep();

	virtual const std::string state_name();
	virtual human_state& finish() = 0;
};




// ��������� '�� ������'
//
class state_work : public human_state
{
public:
	state_work();
	void move()           override;
	void eat()            override;
	void dream()          override;
	void sleep()          override;
	human_state& finish() override;

	inline static human_state& instance();
};





// ��������� '����'
//
class state_home : public human_state
{
public:
	state_home();
	void move()           override;
	void eat()            override;
	void dream()          override;
	void sleep()          override;
	human_state& finish() override;

	inline static human_state& instance();
};




// ��������� '���'
//
class state_sleep : public human_state
{
public:
	state_sleep();
	void move()           override;
	void eat()            override;
	void dream()          override;
	void sleep()          override;
	human_state& finish() override;

	inline static human_state& instance();
};





// �����-�������� �������
//
class human
{
protected:
	human_state *state;	// ������� ��������� ��������
protected:
	void move();		// ������� '��������'
	void eat();			// ������� '������'
	void dream();		// ������� '���������'
	void sleep();		// ������� '�����'
	void finish();		// ������� '��������� ������� ���������'

	void change_state(human_state *new_state);
public:
	human();

	void live();		// ������� ���� )
};


#endif