#include <string>
#include <fstream>
#include <map>
#include "task1.h"
#include "nlohmann/json.hpp"

struct Film
{
	std::string name;
	std::string country;
	int dateOfCreation;
	std::string studio;
	std::string screenwriter;
	std::string director;
	std::string producer;	
	std::map<std::string, std::string> actors;
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
	Film film;
	film.name = "Alien";
	film.country = "Great Britain, USA";
	film.dateOfCreation = 1979;
	film.director = "Gordon Carroll, David Giler, Walter Hill";
	film.producer = "Ridley Scott";
	film.screenwriter = "Dan O'Bannon, Ronald Shusett";
	film.studio = "Twentieth Century Fox";	
	
	film.actors["Sigourney Weaver"] = "Ripley";
	film.actors["Tom Skerritt"] = "Dallas";
	film.actors["Ian Holm"] = "Ash";
	film.actors["John Hurt"] = "Kane";
	film.actors["Harry Dean Stanton"] = "Brett";
	film.actors["Veronica Cartwright"] = "Lambert";
	film.actors["Yaphet Kotto"] = "Parker";
	film.actors["Bolaji Badejo"] = "Alien";
	film.actors["Helen Horton"] = "Mother";

	std::ofstream file("record.json");	
	examinationFile(file);

	nlohmann::json dict;

	dict = {
		{"name", film.name},
		{"country", film.country},
		{"date of creation of the film", film.dateOfCreation},
		{"director", film.director},
		{"producer", film.producer},
		{"screenwriter", film.screenwriter},
		{"studio", film.studio},
		{"actors", film.actors}		
	};

	file << dict;		
	file.close();
	return 0;
}
