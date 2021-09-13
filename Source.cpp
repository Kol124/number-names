#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

std::vector <std::string> names{ "Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten",
	"Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen" };

std::vector<std::string> tens{ "Zero", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety" };

std::string unit(int number) {
	// = = = = = = = = = = = = = = = = 0 - 19 = = = = = = = = = = = = = = = =
	std::string name;
	int unit1 = 0;	int unit2 = 0;
	if ((number < 20)) {
		name = names[number];
		return name;
	}
	// = = = = = = = = = = = = = = = = 20 - 99 = = = = = = = = = = = = = = = =
	else if ((number >= 20) & (number < 100)) {
		if (number % 10 == 0) {
			unit1 = number / 10;
			name = tens[unit1];
			return name;
		}
		else {
			unit1 = number / 10;
			unit2 = number % 10;
			name = tens[unit1] + " " + names[unit2];
			return name;
		}
	}
}

std::string hundred(int number) {
	// = = = = = = = = = = = = = = = = 100 - 999 = = = = = = = = = = = = = = = =
	std::string hundred = " Hundred";
	std::string nand = " and ";
	std::string name;
	int unit1 = 0;	int unit2 = 0;
	// If divisible by a 100
	if (number % 100 == 0) {
		unit1 = number / 100;
		name = names[unit1] + hundred;
		return name;
	}
	else {
		unit1 = number / 100;
		unit2 = number % 100;
		name = names[unit1] + hundred + nand + unit(unit2);
		return name;
	}
}

std::string thousand(int number) {
	// = = = = = = = = = = = = = = = = 1000 - 9999 = = = = = = = = = = = = = = = =
	std::string thousand = " Thousand";
	std::string nand = " and ";
	std::string name;
	int unit1 = 0;	int unit2 = 0;
	// If divisible by a 1000
	if (number % 1000 == 0) {
		unit1 = number / 1000;
		name = names[unit1] + thousand;
		return name;
	}
	else {
		unit1 = number / 1000;
		unit2 = number % 1000;
		// If number is less than 100
		if (unit2 < 100) {
			name = names[unit1] + thousand + nand + unit(unit2);
			return name;
		}
		else {
			name = names[unit1] + thousand + " " + hundred(unit2);
			return name;
		}
	}
}

std::string TenOfThousand(int number) {
	// = = = = = = = = = = = = = = = = 10,000 - 99,999 = = = = = = = = = = = = = = = =
	std::string thsand = " Thousand";
	std::string nand = " and ";
	std::string name;
	int unit1 = 0;	int unit2 = 0;
	// If divisible by 1000
	if (number % 1000 == 0) {
		unit1 = number / 1000;
		name = unit(unit1) + thsand;
		return name;
	}
	else {
		unit1 = number / 1000;
		unit2 = number % 1000;
		// If remainder is less than 1 - 99
		if (unit2 < 100) {
			name = unit(unit1) + thsand + nand + unit(unit2);
			return name;
		}
		// If remainder is 100 - 999
		else {
			name = unit(unit1) + thsand + " " + hundred(unit2);
			return name;
		}
	}
}

std::string HundredOfThousand(int number) {
	// = = = = = = = = = = = 100,000 - 999,999 = = = = = = = = = = =
	std::string thsand = " Thousand";
	std::string hundr = " Hundred";
	std::string nand = " and ";
	std::string name;
	int unit1 = 0;	int unit2 = 0;
	// If divisible by 1000
	if (number % 1000 == 0) {
		unit1 = number / 1000;
		name = hundred(unit1) + thsand;
		return name;
	}
	else {
		unit1 = number / 1000;
		unit2 = number % 1000;
		// If remainder is less than 100
		if (unit2 < 100) {
			name = hundred(unit1) + thsand + nand + unit(unit2);
			return name;
		}
		// If remainder is 100 - 999
		else {
			name = hundred(unit1) + thsand + " " + hundred(unit2);
			return name;
		}
	}
}

void NumberName(const int number) {
	if(number < 100) {
		std::cout << unit(number) << "!" << std::endl;
	}
	else if ((number >= 100) & (number <= 999)) {
		std::cout << hundred(number) << "!" << std::endl;
	}
	else if ((number >= 1000) & (number <= 9999)) {
		std::cout << thousand(number) << "!" << std::endl;
	}
	else if ((number >= 10000) & (number <= 99999)) {
		std::cout << TenOfThousand(number) << "!" << std::endl;
	}
	else if ((number >= 100000) & (number <= 999999)) {
		std::cout << HundredOfThousand(number) << "!" << std::endl;
	}
	else if (number == 1000000) {
		std::cout << "A Million" << std::endl;
	}
	else {
		std::cout << "Not Available" << std::endl;
	}
}

int main() {
	int num = 190009;
	NumberName(num);

	/*
	for (int index = 0; index <= 9999; index++) {
		std::cout << index << ": ";
		NumberName(index);
	}
	*/
}
