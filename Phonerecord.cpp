#include <string>
#include <iostream>
#include "Phonerecord.h"

Phonerecord::Phonerecord() {
	name = "Name";
	surname = "Surname";
	phone = "Number";
}

Phonerecord::Phonerecord(string n, string s, string p) {
	name = n;
	surname = s;
	phone = p;
}

Phonerecord::Phonerecord(const Phonerecord &copyPhonerecord) {
	SetName(copyPhonerecord.name);
	SetSurname(copyPhonerecord.surname);
	SetPhone(copyPhonerecord.phone);
}

void Phonerecord::print() {
	cout << name << " - " << surname << " - " << phone << endl;
}

void Phonerecord::SetName(string n) {
    name = n;
}

void Phonerecord::SetSurname(string s) {
    surname = s;
}

void Phonerecord::SetPhone(string p) {
	phone = p;
}

string Phonerecord::GetName() {
    return name;
}

string Phonerecord::GetSurname() {
    return surname;
}

string Phonerecord::GetPhone() {
    return phone;
}

