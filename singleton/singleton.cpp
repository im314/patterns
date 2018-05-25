#include "stdafx.h"
#include <cstdint>
#include <iostream>
#include <bitset>
#include <array>
#include <numeric>
#include <conio.h> // _getch()



// ќдиночка Ч это порождающий паттерн проектировани€, который гарантирует, 
// что у класса есть только один экземпл€р, и
// предоставл€ет к нему глобальную точку доступа.




class singleton
{
public:
	// classic Meyers singleton
	static singleton& instance()
	{
		static singleton inst;
		return inst;
	}
	uint8_t get_value(uint8_t v) const { return values[v]; }

private:
	singleton()
	{
		prepare_data();
	}
	~singleton() = default;
	singleton(const singleton &) = delete;
	singleton& operator=(const singleton &) = delete;

	void prepare_data()
	{
		auto reverse_byte = [this](uint8_t b)
		{
			b = (b & 0xF0) >> 4 | (b & 0x0F) << 4;
			b = (b & 0xCC) >> 2 | (b & 0x33) << 2;
			b = (b & 0xAA) >> 1 | (b & 0x55) << 1;
			return b;
		};
		
		// fill values with 0,1,2,3...255
		std::iota(values.begin(), values.end(), 0); 
		// reversing values: 01010111-> 11101010
		std::transform(values.begin(), values.end(), values.begin(), reverse_byte);
	}

private:
	std::array<uint8_t, 256> values; // array to store reverse bytes
};






int _tmain(int argc, _TCHAR* argv[])
{
	singleton &rev1 = singleton::instance();
	singleton &rev2 = singleton::instance();

	auto to_bin =[](uint8_t val){return std::bitset<8>(val).to_string();};

	// access through rev1:
	for(auto i=0;i<128;i++)
		std::cout << to_bin(i) << " -> " << to_bin(rev1.get_value(i)) << std::endl;

	std::cout << std::endl << "----------------------------------------" << std::endl << std::endl;

	// access through rev2:
	for(auto i=128;i<256;i++)
		std::cout << to_bin(i) << " -> " << to_bin(rev2.get_value(i)) << std::endl;

	_getch();
	return 0;
}

