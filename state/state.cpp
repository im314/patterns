#include "stdafx.h"
#include <iostream>
#include <cstdint>
#include <string>
#include <conio.h> // _getch()
#include "human_state_machine.h"



// Состояние (State) — это поведенческий паттерн проектирования, который позволяет объектам
// менять поведение в зависимости от своего состояния.
// Извне создаётся впечатление, что изменился класс объекта.




int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "Russian");

	human person; // Класс-контекст ЧЕЛОВЕК
	uint32_t i=0;

	do
	{
		person.live();
	}
	while(_getch() != 'q');

	return 0;
}

