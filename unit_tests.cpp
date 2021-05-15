#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "functions.hpp"
#include <vector>

TEST_CASE("Tikrinama Student klase")
{
	Student Students;
	std::vector<int> grades = { 10,8,8,7,6,4,10,4 };

	REQUIRE(Students.getName().size() == 0);
	REQUIRE(Students.getLastName().size() == 0);
	SECTION("Vardo ir pavardes nuskaitymas")
	{
		Students.setName("Aiste");
		Students.setLastName("Stonciute");
		REQUIRE(Students.getName() == "Aiste");
		REQUIRE(Students.getLastName() == "Stonciute");
	}

	SECTION("Gaunamas egzamino pazymys")
	{
		Students.setExam(4);
		REQUIRE(Students.getExam() == 4);
	}

	SECTION("Gaunamas galutinis studento pazymys")
	{
		Students.setFinalGrade(7);
		REQUIRE(Students.getFinalGrade() == 7);
	}

	SECTION("Gaunamí namu darbu pazymiai")
	{
		Students.setHw(grades);
		REQUIRE(Students.getHw() == grades);
	}

}
