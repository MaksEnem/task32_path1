#include <string>
#include <fstream>
#include <vector>
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
	std::vector<std::string> actors;
	std::vector<std::string> roles;
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
	record.country = "Great Britain, USA";
	record.dateOfCreation = 1979;
	record.director = "Gordon Carroll, David Giler, Walter Hill";
	record.producer = "Ridley Scott";
	record.screenwriter = "Dan O'Bannon, Ronald Shusett";
	record.studio = "Twentieth Century Fox";	
	
	record.actors.push_back("Sigourney Weaver");
	record.actors.push_back("Tom Skerritt");
	record.actors.push_back("Ian Holm");
	record.actors.push_back("John Hurt");
	record.actors.push_back("Harry Dean Stanton");
	record.actors.push_back("Veronica Cartwright");
	record.actors.push_back("Yaphet Kotto");
	record.actors.push_back("Bolaji Badejo");
	record.actors.push_back("Helen Horton");	
	
	record.roles.push_back("Ripley");
	record.roles.push_back("Dallas");
	record.roles.push_back("Ash");
	record.roles.push_back("Kane");
	record.roles.push_back("Brett");
	record.roles.push_back("Lambert");
	record.roles.push_back("Parker");
	record.roles.push_back("Alien");
	record.roles.push_back("Mother");	

	std::ofstream file("record.json");
	examinationFile(file);

	nlohmann::json dict;

	dict = {
		{"country", record.country},
		{"date of creation of the film", record.dateOfCreation},
		{"director", record.director},
		{"producer", record.producer},
		{"screenwriter", record.screenwriter},
		{"studio", record.studio},
		{"actors", record.actors},
		{"roles", record.roles}
	};

	file << dict;	
	
	return 0;
}
