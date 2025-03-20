#pragma once
#include <string>
#include <fstream>
#include <vector>
#include <sstream>

//Enums for names, sex, height, hair and eye color; use vectors of strings

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

public: 
	const std::vector<std::string> HEIGHTS = { "Tall", "Short"};
	const std::vector<std::string> HAIRCOLOR = { "Blond", "Brown", "Bald"};
	const std::vector<std::string> EYECOLOR = { "Blue", "Brown", "Green"};


public:

	Suspect()
	{

	}

	Suspect(std::string csvData, char delimiter)
	{
		Deserialize(csvData, delimiter); 
	}

	void Serialize(std::ofstream& outFile, char delimiter); 

	void Deserialize(std::string csvData, char delimiter); 

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



};

