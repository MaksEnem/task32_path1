#include <string>
#include <fstream>
#include "task1.h"
#include "nlohmann/json.hpp"

struct Record
{
	std::string country;
	int dateOfCreation;
	std::string studio;
	std::string screenwriter;
	std::string director;
	std::string producer;
};

static void examinationFile(std::ofstream& inFile)
{
	if (inFile.is_open())
	{
		std::cout << "File is open\n";
	}
	else {
		std::cout << "WARNING!\n";
		std::cout << "ERROR!!!\n";
		std::cout << "File is not open\n";
	}
}
int main()
{
	Record record;
	record.country = "USA";
	record.dateOfCreation = 1979;
	record.director = "Gordon Carroll";
	record.producer = "Ridley Scott";
	record.screenwriter = "Dan O'Bannon";
	record.studio = "Twentieth Century Fox";

	std::ofstream file("record.json");
	examinationFile(file);

	nlohmann::json dict;

	dict = {
		{"country:", record.country},
		{"date of creation of the film:", record.dateOfCreation},
		{"director", record.director},
		{"producer", record.producer},
		{"screenwriter", record.screenwriter},
		{"studio", record.studio}
	};

	file << dict;

	return 0;
}
