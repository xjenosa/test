/* Citation and Sources...
-----------------------------------------------------------
Workshop 01
Module: io
Filename: io.cpp
-----------------------------------------------------------
Author: Christian Rafael
Student number: 139492243
Email: crafael@myseneca.ca
Subject: OOP244 - NCC
-----------------------------------------------------------
Revision History
------- --------- ------------------------------------------
Version Date      Reason
V1.0    2026/19/1  Initial version
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my work for function whatever.
-----------------------------------------------------------
*/

#include "io.h"
#include "cstr.h"
#include <iostream>
using namespace std;
using namespace seneca;

namespace seneca {
	void read(char* name) {
		cout << "name>\n";
		cin >> name;
	}

	void print(long long phoneNum) {
		long long first3digit = phoneNum / 10000000;
		long long mid3digit = (phoneNum / 10000) % 1000;
		long long last4digit = phoneNum % 10000;

		cout << "(" << first3digit << ") ";
		cout << mid3digit << "-";
		cout << last4digit << endl;
	}

	void print(const PhoneRec& rec, size_t& rowNum, const char* filter) {
		if(filter == nullptr || strstr(rec.firstName, filter) != nullptr|| strstr(rec.lastName, filter) != nullptr) {
			cout << rowNum << ": " << rec.firstName << " " << rec.lastName << " ";
			print(rec.phoneNum);
			rowNum++;
		}
	}

	bool read(PhoneRec& rec, FILE* fp) {
		if(fscanf(fp, "%s %s %lld", rec.firstName, rec.lastName, &rec.phoneNum) == 3) {
			return true;
		}
		else {
			return false;
		}
	}

	void print(const PhoneRec* recs[], size_t size, const char* filter) {
		size_t rowNum = 1;
		for(size_t i = 0; i < size; i++) {
			print(*recs[i], rowNum, filter);
		}
	}

	void setPointers(PhoneRec* recs[], PhoneRec rec[], size_t size) {
		for(size_t i = 0; i < size; i++) {
			recs[i] = &rec[i];
		}
	}
	
	void sort(PhoneRec* recs[], size_t size, bool byLastName) {
		for(size_t i = 0; i < size - 1; i++) {
			for(size_t j = i + 1; j < size; j++) {
				int cmp = 0;
				if(byLastName) {
					cmp = strcmp(recs[i]->lastName, recs[j]->lastName);
				} else {
					cmp = strcmp(recs[i]->firstName, recs[j]->firstName);
				}

				if(cmp > 0) { // if not ascending
					PhoneRec* tempRec = recs[i];
					recs[i] = recs[j];
					recs[j] = tempRec;
				}
			}
		}
	}

}
