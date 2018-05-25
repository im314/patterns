#pragma once
#ifndef __HUMAN_STATE_MACHINE__
#define __HUMAN_STATE_MACHINE__
#include <iostream>
#include <cstdint>
#include <string>


class state_work;
class state_home;
class state_sleep;



// Базовый класс состояния человека
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




// Состояние 'НА РАБОТЕ'
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





// Состояние 'ДОМА'
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




// Состояние 'СОН'
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





// Класс-контекст ЧЕЛОВЕК
//
class human
{
protected:
	human_state *state;	// текущее состояние человека
protected:
	void move();		// команда 'движение'
	void eat();			// команда 'кушать'
	void dream();		// команда 'помечтать'
	void sleep();		// команда 'спать'
	void finish();		// команда 'закончить текущее состояние'

	void change_state(human_state *new_state);
public:
	human();

	void live();		// функция жить )
};


#endif