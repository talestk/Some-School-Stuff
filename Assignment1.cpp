#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;


class Passenger
{
		int board_num;
		int pass_num;
		int row_num;
		string ticket_type;
		string pos_seat;
		string name;
		
	public:
		void setAll(int a, int b, string c, int d, string e);
		int getBoard() { return board_num; }
		int getPass() { return pass_num; }
		string getTicket() { return ticket_type; }
		int getRow() { return row_num; }
		string getSeat() { return pos_seat; }		
};
	
void Passenger::setAll(int a, int b, string c, int d, string e)
{
	board_num = a;
	pass_num = b;
	ticket_type = c;
	row_num = d;
	pos_seat = e;
}

Passenger SeparateAirlines(Passenger pass_data)
{
  int i=0;
  Passenger all_by_flight[50];
  all_by_flight[i] = pass_data;
  i++;
  return *all_by_flight;
}

void PrintAll(Passenger pass_data[])
{
  for(int k = 0; k < 223; k++)
  {
    cout << pass_data[k].getBoard() << " "
         << pass_data[k].getPass() << " "
         << pass_data[k].getTicket() << " "
         << pass_data[k].getRow() << " "
         << pass_data[k].getSeat() << endl;
  }
  
}

void PrintTable(int first[][2], int coach[][2])
{
	for(int i = 0; i < 3; i++)
	{
		cout << first[i][0] << " " << first[i][1] << " " << first[i][2] << endl;
	}
  for(int k = 0; k < 7; k++)
  {
    cout << coach[k][0] << " " << coach[k][1] << " " << coach[k][2] << endl;
  }
}

void assignSeatsFirst(Passenger SpecificSeat, int i, int seats_first[][3],int p)
{ 

  i--;

 for(i; i < 3; i++)
 {

   if(seats_first[i][p] != -0) 
   {
     if(seats_first[i][0] == -0)
     {
       seats_first[i][0] = SpecificSeat.getBoard(); 
     
       break;
     }
     
    p++; 
    i--;   
   }

   else if(seats_first[i][p] == -0)
   {
     seats_first[i][p] = SpecificSeat.getBoard(); 

     break;
   }
 }
     
  cout << seats_first[0][2] << endl;
  for(int k = 0; k < 3; k++)
  {
   cout << seats_first[k][0] << " " << seats_first[k][1] 
     << " " << seats_first[k][2] << endl; 
  }

  
}

void SortTable(Passenger table[])
{
  Passenger Seating;
  int seats_first[3][3]={};
  int row = 0;
  
  for(int i = 0; i < 244; i++)
  {
    if(table[i].getTicket() == "F")
    { 
    	if(table[i].getSeat() == "L")
    	{
        Seating = table[i];
        row = table[i].getRow();
        assignSeatsFirst(Seating, row, seats_first, 0);
		  }
			if(table[i].getSeat() == "M")
    	{
        Seating = table[i];
        row = table[i].getRow();
        assignSeatsFirst(Seating, row, seats_first, 1);
		  }
		  if(table[i].getSeat() == "R")
    	{
        Seating = table[i];
        row = table[i].getRow();
        assignSeatsFirst(Seating, row, seats_first, 2);
		  }
    }
    
    if(table[i].getTicket() == "C")
    {
    	if(table[i].getSeat() == "L")
    	{
        // Seating = table[i];
        //        row = table[i].getRow();
        //        assignSeatsFirst(Seating, row);

		  }
			if(table[i].getSeat() == "M")
    	{
        // Seating = table[i];
        // row = table[i].getRow();
        // assignSeatsFirst(Seating, row);

		  }
		  if(table[i].getSeat() == "R")
    	{
        // Seating = table[i];
        // row = table[i].getRow();
        // assignSeatsFirst(Seating, row);

		  }
    }    
  }

  //PrintTable(seats_first, seats_coach);
}


void PrintChart(Passenger chart[], int a)
{
  cout << "Flight " << a << setw(50);
  
  if(a == 1010)
  {
    cout << "FROM: Jacksson, Mississipi" << endl;
    cout << setw(57) << "TO: Memphis, Tennessee" << endl;
 
    SortTable(chart);
  }
  
  //
  
}


void CheckFlights(Passenger pass_data[], int number)
{
  int x = 0;
  
  Passenger all_by_flight[244];
  
  for(int i = 0; i < 244; i++)
  {
    if(pass_data[i].getPass() == number) 
    { 
      all_by_flight[x] = SeparateAirlines(pass_data[i]); 
      x++; 
    }
    
  }
  PrintChart(all_by_flight, number);
}

Passenger Read(Passenger pass_data[], ifstream &filename)
{
	int a = 0 , b = 0, d = 0;

	string c, e;
  
	for (int i = 0; a!= -999; i++)
	{
		filename >> a;
		if(a == -999) {break;}
		else
    {
		  filename >> b >> c >> d >> e;
			pass_data[i].setAll(a, b, c, d, e);
    
    } 	
	}
  
  return *pass_data;
}

int main()
{
  
	ifstream filename;
	Passenger pass_data[224];
	
	filename.open("data1");
	
	Read(pass_data, filename);
  CheckFlights(pass_data, 1010);

	filename.close();
    
	return 0;
}
	
  
