//#include <stdio.h>
//#include <limits.h>

int myAtoi(char* str) {
	int pos = 0;
	int temp[12];
	int count = 0;
	// Ignore all empty space at the begining
	while (str[pos] == ' ') pos++;

	// "" or " " return 0
	if (str[pos] == '\0') return 0;

	// To see if the first element is number or sign or not
	if (strchr("-+0123456789", str[pos]) == NULL) return 0;


	// The first element
	if (str[pos] == '-') { temp[0] = -1; pos++; }
	else if (str[pos] == '+') { temp[0] = 1; pos++; }
	else temp[0] = 1;
	while (str[pos] == '0') pos++;


	// From the second element
	while (count < 11 && strchr("0123456789", str[pos]) != NULL && str[pos] != '\0') {
		count++;
		if (str[pos] == '0') temp[count] = 0;
		if (str[pos] == '1') temp[count] = 1;
		if (str[pos] == '2') temp[count] = 2;
		if (str[pos] == '3') temp[count] = 3;
		if (str[pos] == '4') temp[count] = 4;
		if (str[pos] == '5') temp[count] = 5;
		if (str[pos] == '6') temp[count] = 6;
		if (str[pos] == '7') temp[count] = 7;
		if (str[pos] == '8') temp[count] = 8;
		if (str[pos] == '9') temp[count] = 9;
		pos++;
	}


	// Deal with temp
	if (count == 11) {
		if (temp[0] == 1) return INT_MAX;
		if (temp[0] == -1) return INT_MIN;
	}

	int intmaxnumber[10] = { 2,1,4,7,4,8,3,6,4,7 };

	if (count == 10) {
		for (int j = 0; j < 10; j++) {
			if (temp[j + 1] < intmaxnumber[j]) j = 10;
			else if (temp[j + 1] == intmaxnumber[j])
				;
			else {
				if (temp[0] == 1) return INT_MAX;
				if (temp[0] == -1) return INT_MIN;
			}
		}
	}

	int number = 0;
	for (int i = 1; i <= count; i++) {
		number = number * 10;
		number += temp[i];
	}
	return temp[0] * number;
}


int main(){
	char* A = "1095478645p";
	myAtoi(A);

}
