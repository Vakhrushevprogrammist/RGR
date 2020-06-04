
#include <fstream>
#include <iostream>
#include <windows.h>
#include <string>
#include <array>

#include "Phonerecord.h"

using namespace std;

int main() {
	string name,surname,phone,stroka,poisk;
	Phonerecord book;

	while(true){
        int menu = 0;
        cout << endl << endl << "Select a menu item: " << endl << endl;
		cout << "1. Output information about all contacts " << endl;
		cout << "2. To enter information about the contact" << endl;
		cout << "3. Search" << endl;
		cout << "4. Changing a contact" << endl;
		cout << "5. Delete contact" << endl;
		cout << "6. Clear your phone book" << endl;
		cout << "7. Exit" << endl ;

        cout << endl << "your choice: ";
		cin >> menu;

		if (menu == 1){
            system("cls");
			ifstream in("book.txt");
            while (getline(in, stroka)){
                cout << stroka << endl;
            }
            in.close();
		}else if (menu == 2){
		    system("cls");
            cout << "Input name: ";
			cin >> name;
			book.SetName(name);

			cout << "Input surname: ";
			cin >> surname;
			book.SetSurname(surname);

			cout << "Input number: ";
			cin >> phone;
			book.SetPhone(phone);

			cout << endl << "You entered the following information: " << endl;
			book.print();

			ofstream fout("book.txt" , ios::app);
            fout << book.GetName() << endl << book.GetSurname() << endl << book.GetPhone() << "\n***\n";
            fout.close();
        }else if (menu == 3){
            system("cls");
            ifstream in("book.txt");
            cout << "Enter your  name,  surname, or  number to search : " << endl;
            cin >> poisk;
            array <string,3> Information;
            int c = 0;

            while (in >> stroka){
                if(stroka != "***"){
                    Information[c] = stroka;
                    c++;
                }else{
                    for(int i=0;i<Information.size();i++){
                       if(Information[i]==poisk){
                           cout << endl;
                            for(int j=0;j<Information.size();j++){
                                cout << Information[j] << endl;
                            }
                            cout << "***" << endl;
                            break;
                            c=0;
                       }

                    }
                    c=0;
                }
            }

            in.close();
        }else if (menu == 4){
            system("cls");
            cout << "Enter your  name,  surname, or  number to change: " << endl;
            cin >> poisk;
            array <string,3> Information;
            ifstream text("book.txt");
            ofstream newtext("buffer.txt");
            int c = 0;
            while(text >> stroka){
                if(stroka != "***"){
                    Information[c] = stroka;
                    c++;
                }else{
                    for(int i=0;i<Information.size();i++){
                       if(Information[i]==poisk){
                            cout << endl;
                            for(int j=0;j<Information.size();j++){
                                cout << Information[j] << endl;
                            }
                            cout << endl << "To change this contact? (1 - yes, 2 - no)" << endl;
                            int menu2;
                            cin >> menu2;
                            if(menu2==1){
                                string ss;
                                cout << "Input new name: ";
                                cin >> ss;
                                newtext << ss << endl;
                                cout << "Input new surname: ";
                                cin >> ss;
                                newtext << ss << endl;
                                cout << "Input new number: ";
                                cin >> ss;
                                newtext << ss << endl << "***" <<  endl;
                            }else if(menu2==2){
                                for(int k=0;k<Information.size();k++){
                                    newtext << Information[k] << endl;
                                }
                                newtext << "***" <<  endl;
                            }
                            c=0;
                            break;
                       }
                    }
                    if(c!=0){
                        for(int k=0;k<Information.size();k++){
                            newtext << Information[k] << endl;
                        }
                        newtext << "***" <<  endl;
                        c=0;
                    }
                }
            }
            text.close();
            newtext.close();
            remove("book.txt");
            rename("buffer.txt", "book.txt");
        }else if (menu == 5){
            system("cls");
            cout << "Enter your  name,  surname, or  number to delete: " << endl;
            cin >> poisk;
            array <string,3> Information;
            int c = 0;
            ifstream text("book.txt");
            ofstream newtext("buffer.txt");
            while(text >> stroka){
                if(stroka != "***"){
                    Information[c] = stroka;
                    c++;
                }else{
                    for(int i=0;i<Information.size();i++){
                       if(Information[i]==poisk){
                            cout << endl;
                            for(int i=0;i<Information.size();i++){
                                cout << Information[i] << endl;
                            }
                            cout << "Delete this contact? (1 - yes, 2 - no)\n";
                            int menu2;
                            cin >> menu2;
                            if(menu2==2){
                                for(int i=0;i<Information.size();i++){
                                    newtext << Information[i] << endl;
                                }
                                newtext << "***" << endl;
                            }
                            c=0;
                            break;
                        }
                    }
                    if(c!=0){
                        for(int k=0;k<Information.size();k++){
                            newtext << Information[k] << endl;
                        }
                        newtext << "***" <<  endl;
                        c=0;
                    }
                }
            }
            text.close();
            newtext.close();
            remove("book.txt");
            rename("buffer.txt", "book.txt");
        }else if (menu == 6){
            system("cls");
            remove("book.txt");
            ofstream txt("book.txt");
            txt.close();
        }else if (menu == 7){
            system("cls");
            cout << "The program is finished..." << endl;
            return 0;
        }else{
            system("cls");
            cout << "Error when selecting a menu item! Try again..." << endl;
        }
    }
	return 0;
}
