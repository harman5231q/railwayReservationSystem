#include "parentCode.cpp"
#include <conio.h>


void guidance()
{
	cout << "---USER GUIDE---" << endl;
	cout << "Use '-' instead of spaces" << endl;
	cout << "Avoid Using Invalid Inputs" << endl;
	cout << "Check for the data in files too" << endl
		 << endl;
	cout << "Press any key to continue....";
	getch();
	system("CLS");
}
void trainChoice()
{
	cout << "Press 1 to enter new train" << endl;
	cout << "Press 2 to check existing trains" << endl;
	cout << "Press 3 to search specific train" << endl;
	cout << "Press 4 back to dashboard" << endl;
	cout << endl;
}
void dashboard()
{
	cout << "Press 1 for train operations" << endl;
	cout << "Press 2 for booking options" << endl;
	cout << "Press 3 for logout" << endl;
	cout << endl;
}
void bookingChoiceFun()
{
	cout << "Press 1 for booking tickets" << endl;
	cout << "Press 2 for view booking" << endl;
	cout << "Press 3 for search booking" << endl;
	cout << "Press 4 back to dashboard" << endl;
	cout << endl;
}
int main()
{
	guidance();
	char choice;
	Auth auth;
back:
	cout << "----TRAIN BOOKING SYSTEM----" << endl
		 << endl;
	cout << "Press 1 to create new account" << endl;
	cout << "Press 2 to login existing account" << endl;
	cout << endl;
	choice = getch();
	system("CLS");
	switch (choice)
	{
	case '1':
		cout << "\n\n  ----SIGNUP----" << endl;
		if (auth.signup())
		{
			cout << "\n\nYour account has been created successfully" << endl;
			cout << "\n\nPress any key to continue.....";
			getch();
			goto label;
		}
		break;
	case '2':
	label:
		system("CLS");
		cout << "\n\nLOGIN" << endl;
		if (auth.login())
		{
			system("ClS");
		}
		else
		{
			cout << "\n\n\aInvalid username and password" << endl;
			cout << "\n\nPlease try again....";
			Sleep(2000);
			goto label;
		}
		break;
	default:
		cout << "\n\nInvalid input please try again...\a" << endl;
		Sleep(2000);
		system("CLS");
		goto back;
		break;
	}
	TrainOperations operations;
	TicketBooking booking;
	while (true)
	{
	dashboard:
		system("CLS");
		dashboard();
		cout << "";
		choice = getch();
		system("CLS");
		switch (choice)
		{
		case '1':
			trainChoice();
			choice = getch();
			cout << endl;
			if (choice == '1')
			{
				operations.addNewTrain();
				cout << "\n New train added...";
				Sleep(2000);
				goto dashboard;
			}
			else if (choice == '2')
			{
				operations.viewTrains();
			}
			else if (choice == '3')
			{
				operations.searchTrain();
			}
			else if (choice == '4')
			{
				goto dashboard;
			}
			else
			{
				cout << "\n Invalid input please try again...\a" << endl;
				Sleep(2000);
				goto dashboard;
			}
			cout << "\n Press any key to continue...";
			getch();
			break;
		case '2':
			bookingChoiceFun();
			choice = getch();
			cout << endl;
			if (choice == '1')
			{
				booking.bookTicket();
			}
			else if (choice == '2')
			{
				booking.viewBookings();
			}
			else if (choice == '3')
			{
				booking.searchBooking();
			}
			else if (choice == '4')
			{
				goto dashboard;
			}
			else
			{
				cout << "Invalid input please try again...\a" << endl;
				Sleep(2000);
				goto dashboard;
			}
			cout << "\n Press any key to continue...";
			getch();
			break;
		case '3':
			goto label;
			break;
		}
	}
	return 0;
}
