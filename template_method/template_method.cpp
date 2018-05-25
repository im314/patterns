#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include "conio.h"



// Ўаблонный метод Ч это поведенческий паттерн проектировани€, который определ€ет скелет алгоритма,
// перекладыва€ ответственность за некоторые его шаги на подклассы.
// ѕаттерн позвол€ет подклассам переопредел€ть шаги алгоритма, не мен€€ его общей структуры.




// Template Method for processing files
//
class process_file
{
protected:
	std::string		f_name;

private:
	virtual void file_open() = 0;
	virtual void extract_data() = 0;
	virtual void file_close() = 0;

	virtual void analyze_data()
	{
		// analyze data
	}
	virtual void save_results()
	{
		// save results
	}

	virtual bool need_send_report()
	{
		// by default - not sending reports
		return false;
	}
	virtual void send_report()
	{
		// send defult report
		std::cout << "DEFAULT REPORT: " << f_name << std::endl;
	}

public:
	virtual ~process_file() = default;

	//	TEMPLATE METHOD
	//
	void execute(const std::string &fname)
	{
		f_name = fname;
		file_open();
		extract_data();
		analyze_data();
		save_results();

		// send report if required
		if(need_send_report())
			send_report();		// optional method

		file_close();
	}
};





class process_pdf : public process_file
{
// Override only required parts of algorithm
	void file_open() override {}
	void extract_data() override {}
	void file_close() override {}
};




class process_json : public process_file
{
// Override only required parts of algorithm
	void file_open() override {}
	void extract_data() override {}
	void file_close() override {}
	
// Override optional parts of algorithm
	bool need_send_report() override
	{
		return true;
	}
};




class process_doc : public process_file
{
// Override required parts of algorithm
	void file_open() override {}
	void extract_data() override {}
	void file_close() override {}


// Override optional parts of algorithm
	bool need_send_report() override
	{
		return true;
	}
	void send_report() override
	{
		// send DOC-specific report
		std::cout << "DOC REPORT: " << f_name << std::endl;
	}
};







int _tmain(int argc, _TCHAR* argv[])
{
	std::vector<std::unique_ptr<process_file>> processors;
	processors.push_back(std::move(std::make_unique<process_pdf>()));
	processors.push_back(std::move(std::make_unique<process_json>()));
	processors.push_back(std::move(std::make_unique<process_doc>()));

	std::vector<const std::string> filenames = {"filename.pdf", "filename.json", "filename.doc"};
	auto it_file = filenames.begin();
	for(auto &d: processors)
	{
		std::cout << *it_file << std::endl;
		d->execute(*it_file++);
		std::cout << std::endl;
	}

	_getch();

	return 0;
}

