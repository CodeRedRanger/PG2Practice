#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <map>


class Suspect
{
	//serialize and deserialize functions
	//create new map of characters

private: //make private later
	//instead of string, use enum??
	std::string m_name;
	std::string m_sex; 
	std::string m_height;
	std::string m_hairColor; 
	std::string m_eyeColor; 

	std::map <std::string, Suspect> m_suspects;

	//took out const because couldn't assign iterator value to map 
	std::vector<std::string> NAMES = { "Albert", "Betty", "Chris", "Diane", "Eddy", "Fran", "Gary", "Helga",
	"Ian", "Jenny" ,"Kent" , "Lakshmi" , "Mike", "Nancy" ,"Oscar" ,"Patty" ,"Quincy" , "Rita", "Steve" , "Tina",
	"Umar" ,"Vanessa" , "Walt" , "Xena" , "Yan" , "Zelda" }; 
	std::vector<std::string> SEXES = { "Male", "Female" }; 
	std::vector<std::string> HEIGHTS = { "Tall", "Short" };
	std::vector<std::string> HAIRCOLORS = { "Blond", "Brown", "Bald" };
	std::vector<std::string> EYECOLORS = { "Blue", "Brown", "Green" };	

public:

	Suspect()
	{

	}

	Suspect(std::string csvData, char delimiter)
	{
		Deserialize(csvData, delimiter); 
	}

	std::map<std::string, Suspect> LoadSuspects(std::string file, char tratDelimiter);

	void PrintSuspects(); 

	void AddSuspect(const std::string& file, const char traitDelimiter);

	void RemoveSuspect(const std::string& file, const char traitDelimiter); 

	void NewSuspectList(const std::string& file, const char traitDelimiter); 


	//Serialize/deserialize functions

	void Serialize(std::ofstream& outFile, char delimiter); 

	void Deserialize(std::string csvData, char delimiter); 


	//Getters and setters

	const std::string& GetName()
	{
		return m_name; 
	}

	void SetName(const std::string& name)
	{
		m_name = name; 
	}

	const std::string& GetSex()
	{
		return m_sex;
	}

	void SetSex(const std::string& sex)
	{
		m_sex = sex;
	}

	const std::string& GetHeight()
	{
		return m_height;
	}

	void SetHeight(const std::string& height)
	{
		m_height = height;
	}

	const std::string& GetHairColor()
	{
		return m_hairColor;
	}

	void SetHairColor(const std::string& hairColor)
	{
		m_hairColor = hairColor;
	}

	const std::string& GetEyeColor()
	{
		return m_eyeColor;
	}

	void SetEyeColor(const std::string& eyeColor)
	{
		m_eyeColor = eyeColor;
	}


	std::map<std::string, Suspect>& GetSuspectMap()
	{
		return m_suspects; 
	}

	void SetSuspectMap(const std::map<std::string, Suspect>& suspectMap)
	{
		m_suspects = suspectMap; 
	}

	const std::vector<std::string>& GetNAMES()
	{
		return NAMES;
	}

	const std::vector<std::string>& GetSEXES()
	{
		return SEXES;
	}

	const std::vector<std::string>& GetHEIGHTS()
	{
		return HEIGHTS;
	}


	const std::vector<std::string>& GetHAIRCOLORS()
	{
		return HAIRCOLORS;
	}

	const std::vector<std::string>& GetEYECOLORS()
	{
		return EYECOLORS;
	}



};

