#ifndef PHONERECORD_H
#define PHONERECORD_H


using namespace std;

class Phonerecord {
private:
    string name, surname, phone;
public:
	Phonerecord();
	Phonerecord(string n, string s, string p);
	Phonerecord(const Phonerecord &copyPhonerecord);

	void SetName(string n);
	string GetName();
	void SetSurname(string s);
	string GetSurname();
	void SetPhone(string p);
	string GetPhone();

	void print();
};

#endif //PHONERECORD_H
