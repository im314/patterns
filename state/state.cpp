// state.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cstdint>
#include <string>
#include <conio.h> // _getch()
#include "human_state_machine.h"




int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "Russian");

	human person;
	uint32_t i=0;

	do
	{
		person.live();
	}
	while(_getch() != 'q');

	return 0;
}

