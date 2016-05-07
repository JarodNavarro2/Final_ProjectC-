// Final_C++_Clean.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <time.h> //needed for random generators
#include <array>
using namespace std;

class Ant
{
private:
	int blue_ants; //the two sides of the ant colony
	int red_ants;

public:
	int Generate_ants(int difficulty); //Generates the number of ants needed for the simulation
	int TurnBase(int steps); //Turn base function for steps per day
	//int Battle(int blue, int red);

};

int Ant::Generate_ants(int difficulty)
{
	srand(time(NULL)); //setting time to null

	if (difficulty == 1) // If they want a short battle, make it short
	{
		blue_ants = 100;//Setting both sides
		red_ants = 100;//equal to what was wanted
		cout << "Red and blue ants have been set to 100" << endl;
	}
	else if (difficulty == 2) //If they want a long battle, make it long
	{
		blue_ants = 500; //Setting both sides
		red_ants = 500;//ewual to what was wanted
		cout << "Red and blue ants have been set to 500" << endl;
	}
	else if (difficulty == 3) //If they want an even longer battle, make it long
	{
		blue_ants = 1000;//Setting both sides
		red_ants = 1000;//equal to what was wanted
		cout << "Red and blue ants have been set to 1000" << endl;
	}
	else if (difficulty ==4) //If they want a random battle, make it random
	{
		blue_ants = rand() % 1000 + 1;//Random generator will make it random
		red_ants = rand() % 1000 + 1;//to boths sides of the colony.
		cout << "Red ants have been set to " << red_ants << " " << "and blue ants have been set to " << blue_ants << endl;
	}
	else//User inputs everything
	{
		cout << "Please set the number of Blue ants" << endl;
		cin >> blue_ants;
		cout << "Please set the number of Red ants" << endl;
		cin >> red_ants;
	}
	return 1;
}

int Ant::TurnBase(int steps)
{
	srand(time(NULL)); //setting time to null
	int blue_steps, red_steps; //steps per day for each colony
	int Blue = 0; //For math purposes
	int Red = 0;//For math purposes
	blue_steps = red_steps = 0; //setting the steps to 0
	if (steps == 1)//If they wanted a short battle, make it short.
	{
		cout << "Since you've chosen a short battle, each colony can only take 5 steps per day" << endl;
		blue_steps = 5; //each colony can only take 5 steps.
		red_steps = 5;
		Blue= 25; //The colony is 100. since there are 4 directions, 100/4 = 25
		Red= 25;

	}
	else if (steps == 2) //Since they wanted a medium battle, make it meduim
	{
		cout << "Since you've chosen a medium length battle, each colony can only take 10 steps per day" << endl;
		blue_steps = 10; //setting each steps to 10
		red_steps = 10;
		Blue=125; //500/4=125. 
		Red= 125;
	}
	else if (steps == 3)//Since they wanted a long battle, make it long
	{
		cout << "Since you've chosen a long battle, each colony can only take 20 steps per day" << endl;
		blue_steps = 20; //setting each step to 20
		red_steps = 20;
		Blue = 250; //1000/4=250.
		Red= 250;
	}
	else if (steps ==4)//Random battle
	{
		cout << "Since you've chosen a random battle, everything is going to be randomly generated." << endl;
		int set_steps = rand() % 100 + 5;//The steps are now random
		int colony = blue_ants / 4; //Whatever their total ants are, the colony represents the 4 directions.
		int colony1 = red_ants / 4;
		Blue= colony; //Setting Blue equal to the division method
		Red= colony1;
		blue_steps = red_steps = set_steps; //Setting the steps
		cout << "Each colony can only take " << set_steps << " steps per day" << endl;
	}
	else//User inputs everything
	{
		cout << "Please set the number of steps per day each colony can take" << endl;
		cout << "Blue:";
		cin >> blue_steps;
		cout << "Red:";
		cin >> red_steps;
		cout << endl;
		cout << "Please set the death penalty (how many ants lost if a colony battles)" << endl;
		cout << "Blue:";
		cin >> Blue;
		cout << "Red:";
		cin >> Red;
		
	}
	int day_count = 0; //Day counter

	cout << "The battle shall begin!!" << endl; //Fight!

	
	int blue_north, blue_south, blue_west, blue_east;//Integers controlling the BLUE directions
	int red_north, red_south, red_west, red_east;//Integers controlling the RED directions
	blue_north = blue_south = blue_west = blue_east = 0; //setting them all
	red_north = red_south = red_west = red_east = 0;//equal to 0
	while (blue_ants != 0 || red_ants != 0)//While either side doesn't equal 0
	{
		int dir = rand() % 4 + 1; //Blue random direction generator
		int red_dir = rand() % 4 + 1; //Red random direction generator
		if (dir == 0) //If for some reason the generator fails, break
		{
			break;
		}
		else
		{
			if (dir == 1) //If the generator chooses 1, move north
			{
				
				blue_north += blue_steps; //Adding to the direciton counter.
				cout << "The Blue team moved North(" << blue_north << ")" << endl; //Showing how many steps total they took in that direciton
				day_count++; //adding a day
			}
			else if (dir == 2) //If the generator chooses 2, move south
			{
				
				blue_south += blue_steps;//adding to the south direction
				cout << "The Blue team moved South(" << blue_south << ")" << endl; //Showing how many steps total they took in that direction
				day_count++;//adding a day
			}
			else if (dir == 3) //If the generator chooses 3, move east
			{
				
				blue_east += blue_steps;//adding to the east direction counter
				cout << "The Blue team moved East(" << blue_east << ")" << endl;//Showing how many steps total they took in that direction
				day_count++;//adding a day
			}
			else if (dir == 4)//If the generator chooses 4, move west
			{
				
				blue_west += blue_steps;//Adding to the dirction counter
				cout << "The Blue team moved West(" << blue_west << ")" << endl; //Showing how many total steps they took in that direction
				day_count++;//adding a day
			}
		}
		if (red_dir == 0)//If the Red random generator fails, break
		{
			break;
		}
		else
		{
			if (red_dir == 1)//If the red random generator chooses 1, move north
			{
				
				red_north += red_steps;//adding to the direction counter
				cout << "The Red Team moved North(" << red_north << ")" << endl;//showing how many total steps they took in that direction
				day_count++;//adding a day
			}
			else if (red_dir == 2)//If the red random generator chooses 2, move south
			{
				
				red_south += red_steps;//adding to the direction counter
				cout << "The Red Team moved South("<< red_south <<")" << endl;//showing how many steps total
				day_count++;//adding a day
			}
			else if (red_dir == 3)//If the red random generator chooses 3, move east
			{
				
				red_east += red_steps;//adding to the direction counter
				cout << "The Red Team moved East(" << red_east << ")" << endl;//showing the total steps taken
				day_count++;//adding a day
			}
			else if (red_dir == 4)//If the red random generator chooses 4, move west
			{
				
				red_west += red_steps;//adding to the direction counter
				cout << "The Red Team moved West(" << red_west << ")" << endl;//showing the total steps in that direction
				day_count++;//adding a day
			}
		}

		if (blue_north == red_north && blue_north !=0 && red_north !=0)//when the ants meet (if the step counters are the same) and they both are NOT 0
		{
			int dec = rand() % 2 + 1; //Battle decision
			if (dec == 1)//If it's 1, the blue colony 1
			{
				cout << "The Blue colony won this battle" << endl;
				red_ants -= Blue;//subtracting the red colonys total ant's
				if (red_ants >= 0)//IF the red colony is still greater or equal to 0
				{
					cout << "The Red colony has " << red_ants << " ants left" << endl;//display how many ants left
					system("pause");//pause so the user can read
					red_north = 0; //The north squad was wiped out, so north is now reset
				}
				else if (red_ants < 0) //If the red colony is NEGATIVE (for random generator purposes)
				{
					cout << "The Red Colony has been eliminated!" << endl; //they died 
				}
				else
				{
					cout << "Nothing" << endl; //test
				}
			}
			else if (dec == 2)//If it's 2, the Red colony won
			{
				cout << "The Red Colony won this battle" << endl;
				blue_ants -= Red;//subtract total number of ants from blue colony
				if (blue_ants >= 0) //If they still stand
				{
					cout << "The Blue Colony has " << blue_ants << " ants left" << endl;//display their total
					system("pause");//so the user can read
					blue_north = 0;//reset north
				}
				else if (blue_ants < 0)//if it's negative
				{
					cout << "The Blue Colony has been eliminated!" << endl; //they died
				}
				else
				{
					cout << "Nothing" << endl;//test
				}
			}
			else
			{
				break;
			}

		}
		else if (blue_south == red_south && blue_south !=0 && red_south !=0) //If the south team meets up with each other
		{
			int dec = rand() % 2 + 1;//battle decision
			if (dec == 1)//Chooses the Blue colony in favor
			{
				cout << "The Blue colony won this battle" << endl;
				red_ants -= Blue;
				if (red_ants >= 0)
				{
					cout << "The Red colony has " << red_ants << " ants left" << endl;
					system("pause");
					red_south = 0;
				}
				else if (red_ants < 0)
				{
					cout << "The Red Colony has been eliminated!" << endl;
				}
				else
				{
					cout << "Nothing" << endl;
				}
			}
			else if (dec == 2) //Chooses the red colony in favor
			{
				cout << "The Red Colony won this battle" << endl;
				blue_ants -= Red;
				if (blue_ants >= 0)
				{
					cout << "The Blue Colony has " << blue_ants << " ants left" << endl;
					system("pause");
					blue_south = 0;
				}
				else if (blue_ants < 0)
				{
					cout << "The Blue Colony has been eliminated!" << endl;
				}
				else
				{
					cout << "Nothing" << endl;
				}
			}
			else
			{
				break;
			}
		}
		else if (blue_east == red_east && blue_east != 0 && red_east != 0)//If the East team meets up, battle
		{
			int dec = rand() % 2 + 1;//Battle decision
			if (dec == 1)//Random generator chooses the Blue colony in favor
			{
				cout << "The Blue colony won this battle" << endl;
				red_ants -= Blue;
				if (red_ants >= 0)
				{
					cout << "The Red colony has " << red_ants << " ants left" << endl;
					system("pause");
					red_east = 0;
				}
				else if (red_ants < 0)
				{
					cout << "The Red Colony has been eliminated!" << endl;
				}
				else
				{
					cout << "Nothing" << endl;
				}
			}
			else if (dec == 2)//Random generator chooses the Red colony in favor
			{
				cout << "The Red Colony won this battle" << endl;
				blue_ants -= Red;
				if (blue_ants >= 0)
				{
					cout << "The Blue Colony has " << blue_ants << " ants left" << endl;
					system("pause");
					blue_east = 0;
				}
				else if (blue_ants < 0)
				{
					cout << "The Blue Colony has been eliminated!" << endl;
				}
				else
				{
					cout << "Nothing" << endl;
				}
			}
			else
			{
				break;
			}
		}
		else if (blue_west == red_west && blue_west !=0 && red_west !=0)//If the West team meets up, BATTLE
		{
			int dec = rand() % 2 + 1;//Battle decision
			if (dec == 1)//Random generator chooses the Blue colony in favor
			{
				cout << "The Blue colony won this battle" << endl;
				red_ants -= Blue;
				if (red_ants >= 0)
				{
					cout << "The Red colony has " << red_ants << " ants left" << endl;
					system("pause");
					red_west = 0;
				}
				else if (red_ants < 0)
				{
					cout << "The Red Colony has been eliminated!" << endl;
				}
				else
				{
					cout << "Nothing" << endl;
				}
				
			}
			else if (dec == 2)//Random generator chooses the Red colony in favor
			{
				cout << "The Red Colony won this battle" << endl;
				blue_ants -= Red;
				if (blue_ants >= 0)
				{
					cout << "The Blue Colony has " << blue_ants << " ants left" << endl;
					system("pause");
					blue_west = 0;
				}
				else if (blue_ants < 0)
				{
					cout << "The Blue Colony has been eliminated!" << endl;
				}
				else
				{
					cout << "Nothing" << endl;
				}
			}
			else
			{
				break;
			}
		}

		if (blue_ants <= 0 || red_ants <= 0)//IF there are no more ants, break out of loop
		{
			break;
		}
	}
	if (blue_ants <= 0)//If the Blue ants have been wiped out, claim victory for Red ants
	{
		cout << "The Red Colony has won with "<<red_ants<<" remaining ants!" << endl;
		cout << "The war was " << day_count << " days long" << endl;
		cout << "You should probably call an exterminator for the rest of the ants." << endl;
		return true;
	}
	else if (red_ants <= 0)//If the Red ants have been wiped out, claim victory for the Blue Ants
	{
		cout << "The Blue Colony has won with "<<blue_ants<<" remaining ants!" << endl;
		cout << "The war was " << day_count << " days long" << endl;
		cout << "You should probably call an exterminator for the rest of the ants." << endl;
		return true;
	}
	else//Testing purposes
	{
		cout << "test" << endl;
	}

	
	return 1;
}

	
int main()
{
	Ant a;
	cout << "Welcome to the battle of the ants. The rules are simple. You control the blue ants." << endl;
	cout << "You decide a few things, then let the ants do the rest" << endl;
	cout << "You select the difficulty. Based on the difficulty will determine how hard the battle is. Your goal is to hope the Blue Colony kills the Red Colony!" << endl;


	cout << "Please select the length of battle you would like to see" << endl;
	cout << "1) A short battle (100 ants)" << endl;
	cout << "2) A lengthy battle (500 ants)" << endl;
	cout << "3) A supreme battle (1000 ants)" << endl;
	cout << "4) A random battle (all ants will be randomly generated)" << endl;
	cout << "5) You decide everything(Please note, the #Ants:#Steps:#Death Penalty ratio" << endl;
	cout << "Will determine how long it is. It may take seconds, or even hours" << endl;
	cout << "for the war to end)" << endl;
	int decision;
	cin >> decision;
	cout << decision << " has been chosen" << endl;
	
	a.Generate_ants(decision);
	a.TurnBase(decision);
	
    return 0;
}

