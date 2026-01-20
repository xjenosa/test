#ifndef SENECA_IO_H
#define SENECA_IO_H

#define MAX_FIRSTNAME_LEN 15
#define MAX_LASTNAME_LEN 25

namespace seneca {
	struct PhoneRec {
		char firstName[MAX_FIRSTNAME_LEN + 1];
		char lastName[MAX_LASTNAME_LEN + 1];
		long long phoneNum;
	};

	void read(char* name);
	void print(long long phoneNum);
	void print(const PhoneRec& rec, size_t& rowNum, const char* filter = nullptr);
	bool read(PhoneRec& rec, FILE* fp);
	void print(const PhoneRec* recs[], size_t size, const char* filter = nullptr);
	void setPointers(PhoneRec* recs[], PhoneRec rec[], size_t size);
	void sort(PhoneRec* recs[], size_t size, bool byLastName);
}

#endif //!SENECA_IO_H
