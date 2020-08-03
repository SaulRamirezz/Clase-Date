#include <iostream>
#include <sstream>
using namespace std;

	class Date
	{
		//COMIENZAN LOS ELEMENTOS PUBLICOS
	public:

		Date(int inDay, int inMont, int inYear) :
			month(inMont), day(inDay), year(inYear) {
		} //constructor


		void MasDias(int adddays) {
			day += adddays;
			if (day > 30) {
				day %= 30;
			}
		}
		void MasMes(int addmonths) {
			month += addmonths;
			if (month > 12) {
				month %= 12;
			}
		}
		void MasYear(int addyears) {
			year += addyears;
		}

		Date operator += (int daysToAdd) { //adelante de Date tenía &
			day += daysToAdd;
			return*this;
		}//operador +=

		Date operator -= (int daysToExtract) {
			day -= daysToExtract;
			return *this;
		}//operador -=

		Date operator =(int newdays) {
			day = newdays;
			return *this;
		}//operador =

		operator const char* ()
		{
			ostringstream formattedDate;
			formattedDate << day << "/" << month << "/" << year;
			dateInString = formattedDate.str();
			return dateInString.c_str();
		}
		~Date() {}
		void displayDate() {
			cout << day << "/" << month << "/" << year;
		}

	//COMIENZAN LOS ELEMENTOS PRIVADOS
	private:
		int day, month, year;
		string dateInString;
	};

	//INICIO DEL MAIN
	int main() {

		Date d(1, 1, 2000);
		d.displayDate();
	

		return 1;
	};