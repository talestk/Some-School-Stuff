//*****************************************************************************
//*                                                                           *
//*   PROGRAM FILE NAME: assignment2.cpp                                      *
//*   ASSIGNMENT #: 2                                                         *
//*                                                                           *
//*   PROGRAM AUTHOR: _________________________________________               *
//*                            Tales Takemiya                                 *
//*                                                                           *
//*   COURSE #: CSC 36000 11              DUE DATE: February 17, 2012          *
//*                                                                           *
//*****************************************************************************

//*****************************************************************************
//*                                                                           *
//*   PROCESS: This program is designed to read a list of data and simulate a *
//*            small data base for a insurance company and provide various    *
//*            tasks such as delete records, update records, add new records, *
//*            and print the data base                                        *
//*                                                                           *
//*****************************************************************************


#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

// class of Policies objects
class AutoPolicy {
	private:
		// private variables
		int policyID;
		string name;
		float amountOfInsurance;
		float annualPremPaid;
		float amountDeductible;
		string licenseNum;
		string state;
	
	public:
		// "constructor"
		void setAll(int, string, float, float, float, string, string);
		
		// Setters
		void setID(int id) { policyID = id; }
		void setName(string new_name) { name = new_name; }
		
		void setAmountOfInsurance(float new_amt_insurance) 
						{ amountOfInsurance = new_amt_insurance; }
						
		void setAnnualPremPaid(float new_annual_prem) 
						{ annualPremPaid = new_annual_prem; }
						
		void setAmountDeductible(float new_amt_deduct) 
						{ amountDeductible = new_amt_deduct; }
						
		void setLicense(string new_license) { licenseNum = new_license; }
		void setState(string new_state) { state = new_state; }
		
		
		// getters
		int getID() { return policyID; }
		string getName() { return name; }
		float getAmountOfInsurance() { return amountOfInsurance; }
		float getAnnualPremPaid() { return annualPremPaid; }
		float getAmountDeductible() { return amountDeductible; }
		string getLicense() { return licenseNum; }
		string getState() { return state; }
		
};


//*********** setALL() function **********************************************//
// Function from AutoPolicy class that sets all values passed to it to private 
// members and receives 7 variables and print a assert message
//****************************************************************************//
void AutoPolicy::setAll(int id, string newName, float amountInsu,
											  float annualPrem,	float amountDeduct, string license, 
											  string newState)
{
	policyID = id;
	name = newName;
	amountOfInsurance = amountInsu;
	annualPremPaid = annualPrem;
	amountDeductible = amountDeduct;
	licenseNum = license;
	state = newState;
	cout << "New Policy successfully added to data base for " << name << "." 
		   << endl;
}


//*********** alertMessageUpdate() function ***********************************//
// Function that doesn't return or receive anything, and print a alert message 
// when called.
//*****************************************************************************//
void alertMessageUpdate()
{
	cout << "Attempt to update a non existent record. Attempt failed." << endl;
}


//*********** printSeparator() function ***************************************//
// Function that doesn't return or receive anything, and print a line used 
// to separate actions.
//*****************************************************************************//
void printSeparator()
{
	cout << "************************************************************" << endl;
}


//*********** printDatabase() function ***************************************//
// Function that receives a array of objects and a integer, and return nothing
// 
//****************************************************************************//
void printDatabase(AutoPolicy littleDatabase[], int position)
{
	cout << setprecision(2) << fixed;
	cout << "Policy Number: " << littleDatabase[position].getID() << setw(26);
	cout << "Policy Holder: " << littleDatabase[position].getName() << setw(25);
	cout << "Amount Of Insurance: " 
			 << littleDatabase[position].getAmountOfInsurance() << endl;
	cout << "Annual Premium: " << littleDatabase[position].getAnnualPremPaid() 
			 << setw(19);
	cout << "Deductible: " << littleDatabase[position].getAmountDeductible() 
			 << setw(30);
	cout << "License Number: " << littleDatabase[position].getLicense() << endl;
	cout << "State of Insured: " << littleDatabase[position].getState() << endl 
			 << endl;
}


//*********** checkDatabase() function **************************************//
// Function that receives a array of objects, two integers, and a char 
// variables. It doesn't return anything.
//***************************************************************************//
void checkDatabase(AutoPolicy littleDatabase[], int position,
									 char printHelper, int id)
{
	int i = 0;
	if(printHelper == 'S')
	{
		for(int k = 0; k < position; k++)
		{
			if(littleDatabase[k].getID() == id)
			{
				printDatabase(littleDatabase, k);
			}
		}
	}
	if(printHelper == 'E')
	{
		for(i ; i < position; i++)
		{
			printDatabase(littleDatabase, i);
		}
	}
}


//*********** checkexistance() function *************************************//
// Function that receives an array of objects and two integers variables and 
// return a boolean status.
//***************************************************************************//
bool checkexistance(AutoPolicy littleDatabase[],int position, int id)
{
	for(int k = 0; k < position; k++)
	{
		if(littleDatabase[k].getID() == id)
		{
			return false;
		}
	}
	return true;
}


//*********** PrintHeader() function ****************************************//
// Prints a Header for the program output.
//***************************************************************************//
void PrintHeader()
{
  cout << setw(30) << "Tales Takemiya";
  cout << setw(17) << "CSC 36000";
  cout << setw(15) << "Section 11" << endl;
  cout << setw(30) << "Spring 2012";
  cout << setw(20) << "Assignment # 2" << endl;
  cout << setw(35) << "-----------------------------------";
  cout << setw(35) << "-----------------------------------\n\n";
  return;
}


//*********** main() function ***********************************************//
// Beginning of Main Function.
//***************************************************************************//
int main()
{	

	// declaring variables
	int id;
	string name, lastName;
	float amountInsu;
	float annualPrem; 
	float amountDeduct; 
	string license; 
	string state;
	int field_id;
	int position = 0, index = 0;
	AutoPolicy littleDatabase[300];
	char command, printHelper;
	ifstream filename;
	bool flag = true, existance = true;
	
	// print header
  PrintHeader();
	
	// openning data
	filename.open("data2");
	
	// getting first character from file
	filename >> command;
	
	// while loop that loops til anything but the cases are found or a char Q 
	// is found
	while(flag == true)
	{
	
		// switching command according to inputed case
		switch(command)
		{
			// adding new entry to database.
			case 'A':
				// reading file...
				filename >> id;
				filename >> name >> lastName;
				filename >> amountInsu; 
				filename >> annualPrem;
				filename >> amountDeduct;
				filename >> license;
				filename >> state;
				
				// putting first and last name in one single variable.
				name = name + " " + lastName;
				
				// checking if a similar record is already in database.
				existance = checkexistance(littleDatabase, position, id);
				if(existance == true)
				{
					// adding it to the array of objects called littleDatabase.
					littleDatabase[position].setAll(id, name, amountInsu, annualPrem, 
																					amountDeduct, license, state);
					printSeparator(); 
					position++;
					break;
				}
				
				// if the id is already in the database print alert message and break;
				if(existance == false)
				{
					cout << "Attempt to add duplicate policy. Attempt failed" << endl;
					printSeparator();
					existance = true;
					break;
				}
				break;
				
			// Update case for modifying database	
			case 'U':
				filename >> id >> field_id;
				
				// switch the field_id that is supposed to be updated 
				switch(field_id)
				{
					case 1:
						filename >> name >> lastName;
						name = name + " " + lastName;
						
						// checking for existance
						for(index = 0; index < position; index++)
						{
							if(littleDatabase[index].getID() == id)
							{
								// calling setter from class structure to set new name.
								littleDatabase[index].setName(name);
								
								//print a success message
								cout << "Policy Number " << id << " updated" << endl;
								printSeparator();
								existance = true;
								break;
							}
							
							// if can't find the id in database set existance to false
							if(littleDatabase[index].getID() != id)
							{
								existance = false;
							}
							
						}
						
						// and then print message error if existance = false
						if(existance == false)
						{
							alertMessageUpdate();
							printSeparator();
							existance = true;
							break;
						}
						
						break;
						
					// same as case 1 but with amountOfInsurance parameter
					case 2:
						filename >> amountInsu;
					  for(index = 0; index < position; index++)
						{
							
							if(littleDatabase[index].getID() == id)
							{
								littleDatabase[index].setAmountOfInsurance(amountInsu);
								cout << "Policy Number " << id << " updated" << endl;
								printSeparator();
								existance = true;
								break;
							}
							else
								existance = false;
							
						}
						if(existance == false)
						{
							alertMessageUpdate();
							printSeparator();
							existance = true;
							break;
						}
						break;

					// same as case 1 but with setAnnualPremPaid parameter
					case 3:
						filename >> annualPrem;
					  for(index = 0; index < position; index++)
						{
							
							if(littleDatabase[index].getID() == id)
							{
								littleDatabase[index].setAnnualPremPaid(annualPrem);
								cout << "Policy Number " << id << " updated" << endl;
								printSeparator();
								existance = true;
								break;
							}
							else
							{
								existance = false;
							}
						}
						if(existance == false)
						{
							alertMessageUpdate();
							printSeparator();
							existance = true;
							break;
						}
						break;
						
					// case amount of deductable
					case 4:
						filename >> amountDeduct;
					  for(index = 0; index < position; index++)
						{
							
							if(littleDatabase[index].getID() == id)
							{
								littleDatabase[index].setAmountDeductible(amountDeduct);
								cout << "Policy Number " << id << " updated" << endl;
								printSeparator();
								existance = true;
								break;
							}
							if(littleDatabase[index].getID() != id)
							{
								existance = false;
							}
						}
						if(existance == false)
						{
							alertMessageUpdate();
							printSeparator();
							existance = true;
							break;
						}
						break;
						
					// case new license number	
					case 5:
						filename >> license;
					  for(index = 0; index < position; index++)
						{
							
							if(littleDatabase[index].getID() == id)
							{
								littleDatabase[index].setLicense(license);
								cout << "Policy Number " << id << " updated" << endl;
								printSeparator();
								existance = true;
								break;
							}
							if(littleDatabase[index].getID() != id)
							{
								existance = false;
							}
						}
						if(existance == false)
						{
							alertMessageUpdate();
							printSeparator();
							existance = true;
							break;
						}
						break;
				
					// case update State
					case 6:
						filename >> state;
					  for(index = 0; index < position; index++)
						{
							
							if(littleDatabase[index].getID() == id)
							{
								littleDatabase[index].setState(state);
								cout << "Policy Number " << id << " updated" << endl;
								printSeparator();
								existance = true;
								break;
							}
							if(littleDatabase[index].getID() != id)
							{
								existance = false;
							}
						}
						if(existance == false)
						{
							alertMessageUpdate();
							printSeparator();
							existance = true;
							break;
						}
				}
				
				// ********* END OF UPDATE SWITCH STATEMENT *************
				break;
				// ********* END OF CASE UPDATE *************************
			
			// case Delete, that deletes a record from database	
			case 'D':
			filename >> id;
			
				// check for id existance in database
				for(index = 0; index < position; index++)
				{
				
					// if found erase by substituting for next database entry, then  
					// print a success message.
					if(littleDatabase[index].getID() == id)
					{	
						for(int k = index; k < position; k++)
						{
							littleDatabase[k] = littleDatabase[k+1];
						}
						position--;
						cout << "Policy Number " << id << " successfully deleted." << endl;
						printSeparator();
						break;
					}
					if(littleDatabase[index].getID() != id)
					{
						cout << "Attempt to delete a non existent record. Attempt failed."
								 << endl;
						printSeparator();
						break;
					}
					
				}			
				break;
					
			// Case to print entire or singular database entry(ies).		
			case 'P':
				filename >> printHelper;
				if(printHelper == 'E')
				{
					cout << "Printing entire data base:" << endl;
					checkDatabase(littleDatabase, position, printHelper, id);
					printSeparator();
					break;
				}
				if(printHelper == 'S')
				{
					filename >> id;
					cout << "Printing information on Policy Number: " << id << endl;
					checkDatabase(littleDatabase, position, printHelper, id);
					printSeparator();
					break;
				}
				
			// QUIT CASE
			case 'Q':
				flag = false;
				break;
				
			// Default case to check for correctness of inputs
			default:
				flag = false;
				break;
		}
		
		// getting next command
		filename >> command;	
	}
		
	// closing file
	filename.close();
	cout << "END OF PROGRAM OUTPUT" << endl;
	
	return 0;
}
// ***************** END OF MAIN FUNCTION *************************************
