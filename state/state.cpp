#include "stdafx.h"
#include <iostream>
#include <cstdint>
#include <string>
#include <conio.h> // _getch()
#include "human_state_machine.h"



// —осто¤ние (State) Ч это поведенческий паттерн проектировани¤, который позвол¤ет объектам
// мен¤ть поведение в зависимости от своего состо¤ни¤.
// »звне создаЄтс¤ впечатление, что изменилс¤ класс объекта.




int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "Russian");

	human person; //  ласс-контекст „≈Ћќ¬≈ 
	uint32_t i=0;

	do
	{
		person.live();
	}
	while(_getch() != 'q');

	return 0;
}

