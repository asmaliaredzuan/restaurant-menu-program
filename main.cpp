#include <iostream>
#include <fstream>
#include <iomanip>
#include <windows.h>

void write_to_file();
void menu_display();
double find_total_cost (double PRICES[5][3]);
void display_receipt(double TOTALCOST);

using namespace std;

int main()
{
	double prices[5][3]= { {6.50,2.49,1.99},
                     	   {5.50,2.00,1.99},
					       {6.50,1.49,2.49},
					       {7.00,2.00,2.49},
					       {3.49,1.49,1.99}
	                     };
	double totalCost;
	
	Beep(1568,400);
	
	write_to_file();
	menu_display();
	totalCost = find_total_cost(prices);
	display_receipt (totalCost);
	
	return 0;
}

//write to file
void write_to_file()
{
	ofstream outFile;
	outFile.open("Menu.txt");
	outFile << setprecision (2)
	        << setiosflags(ios::showpoint)
	        << setiosflags (ios::fixed);
	outFile << "(a)Chicken Special     $" << 6.50 << "   (a)Apple Pie      $" << 2.49 << "   (a)Café Mocha    $" << 1.49 << endl
            << "(b)Chicken Nuggets     $" << 5.50 << "   (b)Butter Bread   $" << 2.00 << "   (b)Café Late     $" << 1.99 << endl
            << "(c)Rainbow Fillet      $" << 6.50 << "   (c)No-salt Fries  $" << 1.49 << "   (c)Orange juice  $" << 2.49 << endl
            << "(d)Double Cheeseburger $" << 7.00 << "   (d)Fun ice Cream  $" << 2.00 << "   (d)Ice Lemon Tea $" << 2.49 << endl
            << "(e)Tofu Burger         $" << 3.49 << "   (e)Rice Cracker   $" << 1.49 << "   (e)Pepsi         $" << 1.99 << endl;
    outFile.close();   
}

//display menu to customer
void menu_display()
{
	cout << "                             WELCOME TO JOLIBEE!                                " << endl
	     << endl;
	     
	cout << "                                Type of Menu                                    " << endl
	     << "--------------------------------------------------------------------------------" << endl
	     << "1- Entree                       2- Side Dish             3- Drink               " << endl
	     << endl;

    cout << setprecision (2)
	     << setiosflags(ios::showpoint)
	     << setiosflags (ios::fixed);
	cout << "(1)Chicken Special     $" << 6.50 << "   (1)Apple Pie      $" << 2.49 << "   (1)Cafe Mocha    $" << 1.49 << endl
         << "(2)Chicken Nuggets     $" << 5.50 << "   (2)Butter Bread   $" << 2.00 << "   (2)Cafe Late     $" << 1.99 << endl
         << "(3)Rainbow Fillet      $" << 6.50 << "   (3)No-salt Fries  $" << 1.49 << "   (3)Orange juice  $" << 2.49 << endl
         << "(4)Double Cheeseburger $" << 7.00 << "   (4)Fun ice Cream  $" << 2.00 << "   (4)Ice Lemon Tea $" << 2.49 << endl
         << "(5)Tofu Burger         $" << 3.49 << "   (5)Rice Cracker   $" << 1.49 << "   (5)Pepsi         $" << 1.99 << endl
         << "-------------------------------------------------------------------------------" << endl;
   
	system("COLOR 5f");
}

/*//declaring prices in an array
double array_prices(double PRICES[5][3])
{
	PRICES [5][3]= { {6.50,2.49,1.99},
                     {5.50,2.00,1.99},
					 {6.50,1.49,2.49},
					 {7.00,2.00,2.49},
					 {3.49,1.49,1.99}
	                };
	return;
}*/

//calculating total cost 
double find_total_cost (double PRICES[5][3])
{
	int menu, item, numOrder;
	double totalPrice=0.0;
	double totalCost=0.0;
	char moreItem, otherMenu;
	do
	{
		cout << "\nChoose the type of menu you want to eat(1-3): ";
		cin >> menu;
		if (menu != 0 && menu <=3)
		{
			do 
			{
				cout << "\nChoose the item(1-5): ";
				cin >> item;
				if (item != 0 && item <=5)
				{
					cout << "Number of order: ";
					cin >>numOrder;
				}
				else 
				cout << "You've entered the wrong number! Please try again!" << endl;
				totalPrice= numOrder*(PRICES[item-1][menu-1]);
				totalCost += totalPrice;
				cout << "Total Price: " << totalPrice << endl;
				cout << "More item from the same menu? (Y-Yes,N-No): ";
				cin >> moreItem;
				if (moreItem != 'N' && moreItem != 'Y')
				cout << "You've the wrong the letter! Please try again!" << endl;
			}
			while (moreItem=='Y');
		}
		else 
		cout << "You've entered the wrong number! Please try again!" << endl;
		cout << "\nOther menu? (Y-Yes,N-No): ";
		cin >> otherMenu;
		if (otherMenu != 'N' && otherMenu != 'Y')
		cout << "You've entered the wrong letter! Please try again!" << endl;
	}
	while (otherMenu=='Y');
	return totalCost;
}

//display the receipt and total cost with gst
void display_receipt(double TOTALCOST)
{
	double totalCharge;
    totalCharge= TOTALCOST + (TOTALCOST*0.06);
    cout << setprecision (2)
	     << setiosflags(ios::showpoint)
	     << setiosflags (ios::fixed);
	cout << "\nHere's your receipt: " << endl;
	cout << "Your total charge (plus 6% GST) is $" << totalCharge <<endl;
}
