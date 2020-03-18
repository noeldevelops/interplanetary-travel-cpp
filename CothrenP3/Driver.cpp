// A. Noel Cothren
// acothren1@cnm.edu
// Program 3: Planets


#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
using namespace std;

int main() {
	//Print out header and intro
	cout << "\n .     *        .   *     .    .  .        .            * ";
	cout << "\n    *.   *     .  .    .    *     .     .  . *    .    .    ";
	cout << setw(10) << "\n A. Noel Cothren";
	cout << setw(10) << "\n Program 3: Planetary Travel";
	cout << "\n  *  .  . *       *    .        .        .   *    ..    ";
	cout << setw(10) << "\n SPACEPORT CNM";
	cout << "\n Calculate the time it will take you to travel to another planet,\n and how much you'll weigh once you get there.";
	cout << "\n .      *       .   *     .     .  .        .     .       * ";
	cout << "\n    *.   *     .*      .     *       .  . *     .    .    \n";

	//Declare variables
	double newWeight = 0.0;
	int speed = 0;
	double earthWeight = 0.0;
	string name = "Traveler";
	vector <string> planets = { "Mercury", "Venus", "Earth", "Mars", "Jupiter", "Saturn", "Uranus", "Neptune" };
	vector <unsigned int> distanceFromSun = { 36, 67, 93, 141, 483, 886, 1782, 2793 };
	vector <double> relativeGravity = { 0.27, 0.86, 1.00, 0.37, 2.64, 1.17, 0.92, 1.44 };
	const int daysInYear = 365;
	const int hoursInDay = 24;
	const int hoursInYear = 8760;
	int travelTotal = 0;
	int travelDays = 0;
	int travelYears = 0;
	int travelHours = 0;
	string goAgain = "yes";
	int destination = 0;
	const int earthDistance = 93;

	//Request general user input
	cout << "\n Hello! Please enter your name:  ";
	getline(cin, name);
	cout << "\n .     *        .   *     .    .  .        .            * "
		<< "\n It's nice to meet you, " << name
		<< "\n    *.   *     .  .    .    *     .     .  . *    .    .    "
		<< " \n\n Please enter your weight in pounds:  ";
	cin >> earthWeight;
	cin.ignore();

	do
	{
		cout << "\n Alright, " << name << ", how many miles per hour would you like to travel?  ";
		cin >> speed;
		cin.ignore();

		cout << "\n Choose your destination planet\n";
		cout << setw(10) << "Number" << setw(16) << "Planet Name";

		for (unsigned int i = 0; i < planets.size(); i++)
		{
			cout << "\n" << setw(10) << i + 1 << " " << setw(15) << planets.at(i);
		}

		cout << "\n\n Enter the number of your choice: ";
		cin >> destination;
		cin.ignore();

		//only proceed if user entered valid destination
		if (destination >= 1 && destination <= 8) {
			destination--;

			//Make calculations
			newWeight = earthWeight * relativeGravity.at(destination);
			travelTotal = ((distanceFromSun.at(destination)) - earthDistance) * 1000000 / speed;
			travelHours = travelTotal % hoursInYear % hoursInDay;
			travelYears = travelTotal / hoursInYear;
			travelDays = travelTotal % daysInYear;
			//Give results
			//Format for two decimal places
			cout.precision(2);
			cout.setf(ios::fixed | ios::showpoint);
			cout << "\n .     *        .   *     .    .  .        .            * ";
			cout << "\n    *.   *     .  .    .    *     .     .  . *    .    .    ";

			if (destination == 2) {
				cout << "\n You won't have to go far, " << name << "! You weigh " << earthWeight << "lb and are already on planet Earth, so your travel time is zero.";
			}
			else {
				cout << "\n Get packing, " << name << "!";
				cout << "\n You weigh " << earthWeight << " lb now, but you'll weigh " << newWeight << " lb once you arrive on " << planets.at(destination) << ".\n It will take you "
					<< travelYears << " years, " << travelDays << " days, and " << travelHours << " hours to get there. Good luck!";
			}
			
			cout << "\n\n Do you want to calculate another option? yes/no\n";
			cin >> goAgain;
			cin.ignore();
		}
		else {
			cout << "\n\n That was not a vaild option. Please try again.";
		}

	} while (goAgain == "yes");

	cout << "\n Thanks for visiting SPACEPORT CNM! Good bye."
	 << "\n  *  .  . *       *    .        .        .   *    ..    "
	 << "\n .     *        .   *     .    .  .        .            * \n";
	return 0;
}