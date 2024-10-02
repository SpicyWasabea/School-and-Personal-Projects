#include<iostream>

using namespace std;

void PrintMonth(string month, int year) {

	string temp_day = "";
	string day = "";
	bool day_count = true;
	bool leap_year = false;
	bool first_line = true;
	int total_days = 0;
	int month_num = 0;
	int weekday = 0;
	int count = 0;

	//printing the the month and year and the days of the week
	cout << month << " " << year << endl;
	string days[7] = { "S", "M", "Tu", "W", "Th", "F", "S" };
	for (int i = 0; i < 7; i++) {
		if (day_count) {
			cout << " ";
			cout << days[i];
			cout << " ";
			day_count = false;
		}
		else {
			temp_day = days[i];
			if (temp_day.length() == 1) {
				cout << " ";
				cout << days[i];
				cout << " ";
			}
			else if (temp_day.length() > 1) {
				cout << days[i];
				cout << " ";
			}
		}
	}
	cout << endl;

	//seeing is its a leap year
	if (year % 4 == 0 && year % 100 != 0) {
		leap_year = true;
	}
	else if (year % 100 == 0) {
		if (year % 400 == 0) {
			leap_year = true;
		}
	}
	else {
		leap_year = false;
	}

	//figuring how many days are in the year
	if (month == "January" || month == "january") {
		total_days = 31;
		month_num = 0;
	}
	else if (month == "February" || month == "february") {
		if (leap_year) {
			total_days = 29;
		}
		else {
			total_days = 28;
		}
		month_num = 3;
	}
	else if (month == "March" || month == "march") {
		total_days = 31;
		if (leap_year) {
			month_num = 4;
		}
		else {
			month_num = 3;
		}
	}
	else if (month == "April" || month == "april") {
		total_days = 30;
		if (leap_year) {
			month_num = 0;
		}
		else {
			month_num = 6;
		}
	}
	else if (month == "May" || month == "may") {
		total_days = 31;
		if (leap_year) {
			month_num = 2;
		}
		else {
			month_num = 1;
		}
	}
	else if (month == "June" || month == "june") {
		total_days = 30;
		if (leap_year) {
			month_num = 5;
		}
		else {
			month_num = 4;
		}
	}
	else if (month == "July" || month == "july") {
		total_days = 31;
		if (leap_year) {
			month_num = 0;
		}
		else {
			month_num = 6;
		}
	}
	else if (month == "August" || month == "august") {
		total_days = 31;
		if (leap_year) {
			month_num = 3;
		}
		else {
			month_num = 2;
		}
	}
	else if (month == "September" || month == "september") {
		total_days = 30;
		if (leap_year) {
			month_num = 6;
		}
		else {
			month_num = 5;
		}
	}
	else if (month == "October" || month == "october") {
		total_days = 31;
		if (leap_year) {
			month_num = 1;
		}
		else {
			month_num = 0;
		}
	}
	else if (month == "November" || month == "movember") {
		total_days = 30;
		if (leap_year) {
			month_num = 4;
		}
		else {
			month_num = 3;
		}
	}
	else if (month == "December" || month == "december") {
		total_days = 31;
		if (leap_year) {
			month_num = 6;
		}
		else {
			month_num = 5;
		}
	}
	weekday = (int)((1 + month_num + 5 * ((year - 1) % 4) + 4 * ((year - 1) % 100) + 6 * ((year - 1) % 400)) % 7);

	/*
		if weekday = 0, == sunday
		if weekday = 1, == monday
		if weekday = 2, == tuesday
		if weekday = 3, == wednesday
		if weekday = 4, == thursday
		if weekday = 5, == friday
		if weekday = 6, == saturday
		these determines the amount of spaces needed before the first number
	*/

	//need to fix the amount of spaces
	if (weekday == 0) {
		cout << " ";
	}
	else if (weekday == 1) {
		cout << "    ";
	}
	else if (weekday == 2) {
		cout << "       ";
	}
	else if (weekday == 3) {
		cout << "          ";
	}
	else if (weekday == 4) {
		cout << "             ";
	}
	else if (weekday == 5) {
		cout << "                ";
	}
	else if (weekday == 6) {
		cout << "                   ";
	}


	//outputting the numbers on the amount of days
	for (int i = 1; i <= total_days; i++) {
		if (i < 9) {
			cout << i;
			count++;
			cout << "  ";
			if (first_line) {
				if (weekday == 0) {
					if (i % 7 == 0) {
						cout << endl;
						count = 0;
						first_line = false;
						cout << " ";
					}
				}
				else if (weekday == 1) {
					if (i % 6 == 0) {
						cout << endl;
						count = 0;
						first_line = false;
						cout << " ";
					}
				}
				else if (weekday == 2) {
					if (i % 5 == 0) {
						cout << endl;
						count = 0;
						first_line = false;
						cout << " ";
					}
				}
				else if (weekday == 3) {
					if (i % 4 == 0) {
						cout << endl;
						count = 0;
						first_line = false;
						cout << " ";
					}
				}
				else if (weekday == 4) {
					if (i % 3 == 0) {
						cout << endl;
						count = 0;
						first_line = false;
						cout << " ";
					}
				}
				else if (weekday == 5) {
					if (i % 2 == 0) {
						cout << endl;
						count = 0;
						first_line = false;
						cout << " ";
					}
				}
				else if (weekday == 6) {
					if (i % 1 == 0) {
						cout << endl;
						count = 0;
						first_line = false;
						cout << " ";
					}
				}
			}
			else {
				if (count % 7 == 0) {
					cout << endl;
					count = 0;
					cout << " ";
				}
			}
		}
		else {
			cout << i;
			count++;
			cout << " ";
			if (count % 7 == 0) {
				cout << endl;
				count = 0;
			}
		}
	}
	cout << endl << endl;

}

//printing out the yearly calendar by printing out the monthly calendar 12 times for each different month
void PrintYear(int year) {
	string months[12] = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };
	for (int i = 0; i < 12; i++) {
		PrintMonth(months[i], year);
	}
}


int main() {
	string month;
	int year;
	char choice;
	cout << "Do you want a month calendar or a year calendar?(M/Y) ";
	cin >> choice;

	if (choice == 'M' || choice == 'm') {
		cout << "Which month? (Full month name) ";
		cin >> month;
		cout << "Which year? ";
		cin >> year;
		cout << endl << endl;
		PrintMonth(month, year);
	}
	else if (choice == 'Y' || choice == 'y') {
		cout << "Which year? ";
		cin >> year;
		cout << endl;
		cout << "----------------------------\n\tYear of " << year << "\n----------------------------" << endl << endl;
		PrintYear(year);
	}
}