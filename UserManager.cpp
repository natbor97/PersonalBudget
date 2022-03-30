#include "UserManager.h"

User UserManager::insertNewUsersData(){
    User user;

    user.setUserId(getNewUserId());
    string login="", password="", name="", surname="";

    do{
        cout<<"Podaj login: ";
        cin>>login;
        user.setLogin(login);
    } while (loginExists(user.getLogin())==true);

    cout<<"Podaj haslo: ";
    cin>>password;
    user.setPassword(password);

    cout<<"Podaj imie: ";
    cin>>name;
    user.setName(name);

    cout<<"Podaj nazwisko: ";
    cin>>surname;
    user.setSurname(surname);

    return user;
}

int UserManager::getNewUserId(){
    if (users.empty() == true)
        return 1;
    else
        return users.back().getUserId() + 1;
}

bool UserManager::loginExists(string login){
    for(int i=0; i<users.size(); i++) {
        if (users[i].getLogin()==login) {
            cout<<endl<<"Istnieje uzytkownik o takim loginie. "<<endl;
            return true;
        }
    }
    return false;
}

void UserManager::userRegistration(){
    User user = insertNewUsersData();

    users.push_back(user);
    usersFile.addUserToFile(user);

    cout << endl << "Konto zalozono pomyslnie" << endl << endl;
    system("pause");
}

int UserManager::getLoggedUserId(){
    return loggedUserId;
}

int UserManager::userLogin(){
    string login = "", password = "";

    cout << endl << "Podaj login: ";
    cin >> login;

    vector <User>::iterator itr = users.begin();
    while (itr != users.end()) {
        if (itr -> getLogin() == login) {
            for (int numberOfAttemps = 3; numberOfAttemps > 0; numberOfAttemps--) {
                cout << "Podaj haslo. Pozostalo prob: " << numberOfAttemps << ": ";
                password = AuxiliaryMethods::readLine();

                if (itr -> getPassword() == password) {
                    cout << endl << "Zalogowales sie." << endl << endl;
                    system("pause");
                    loggedUserId= itr -> getUserId();
                    return loggedUserId;
                }
            }
            cout << "Wprowadzono 3 razy bledne haslo." << endl;
            system("pause");
            return 0;
        }
        itr++;
    }
    cout << "Nie ma uzytkownika z takim loginem" << endl << endl;
    system("pause");
    return 0;
}

bool UserManager::isUserLogged(){
    if (loggedUserId > 0)
        return true;
    else
        return false;
}

void UserManager::changeLoggedUserPassword(){
    string newPassword = "";
    cout << "Podaj nowe haslo: ";
    newPassword = AuxiliaryMethods::readLine();

    for (int i=0; i<users.size(); i++) {
        if (users[i].getUserId() == loggedUserId) {
            users[i].setPassword(newPassword);
            cout << "Haslo zostalo zmienione." << endl << endl;
            system("pause");
        }
    }
    usersFile.saveAllUsersToFile(users);
}

void UserManager::userLogout(){
    loggedUserId=0;
}

char UserManager::selectOptionFromMainMenu()
{
	char choice;

	system("cls");
	cout << "    >>> MENU GLOWNE <<<" << endl;
	cout << "---------------------------" << endl;
	cout << "1. Rejestracja" << endl;
	cout << "2. Logowanie" << endl;
	cout << "9. Koniec programu" << endl;
	cout << "---------------------------" << endl;
	cout << "Twoj wybor: ";
	choice = AuxiliaryMethods::readCharacter();

	return choice;
}

char UserManager::selectOptionFromUserMenu()
{
	char choice;

	system("cls");
	cout << " >>> MENU UZYTKOWNIKA <<<	" << endl;
	cout << "---------------------------" << endl;
	cout << "1. Dodaj przychod" << endl;
	cout << "2. Dodaj wydatek" << endl;
	cout << "3. Bilans z biezacego miesiaca" << endl;
	cout << "4. Bilans z poprzedniego miesiaca" << endl;
	cout << "5. Bilans z wybranego okresu" << endl;
	cout << "---------------------------" << endl;
	cout << "6. Zmien haslo" << endl;
	cout << "7. Wyloguj sie" << endl;
	cout << "---------------------------" << endl;
	cout << "Twoj wybor: ";
	choice = AuxiliaryMethods::readCharacter();

	return choice;
}
