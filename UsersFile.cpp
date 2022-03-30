#include "UsersFile.h"

void UsersFile::addUserToFile(User user){
    CMarkup xml;
    bool fileExist=xml.Load(getFileName());
    if(!fileExist){
        xml.AddElem("Users");
    }

    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("User");
    xml.IntoElem();
    xml.AddElem("id", user.getUserId());
    xml.AddElem("login", user.getLogin());
	xml.AddElem("password", user.getPassword());
	xml.AddElem("name", user.getName());
	xml.AddElem("surname", user.getSurname());

	xml.Save(getFileName());

}

vector<User>UsersFile::readUsersFromFile(){
    CMarkup xml;
	User user;
	vector <User> users;
	xml.Load(getFileName());

	xml.FindElem();
	xml.IntoElem();
	while (xml.FindElem("User")) {
		xml.IntoElem();

		xml.FindElem("id");
		MCD_STR strSN = xml.GetData();
		user.setUserId(AuxiliaryMethods::stringToInt(strSN));
		xml.FindElem("login");
		strSN = xml.GetData();
		user.setLogin(strSN);

		xml.FindElem("password");
		strSN = xml.GetData();
		user.setPassword(strSN);

		xml.FindElem("name");
		strSN = xml.GetData();
		user.setName(strSN);

		xml.FindElem("surname");
		strSN = xml.GetData();
		user.setSurname(strSN);
		xml.OutOfElem();

		users.push_back(user);
	}
	return users;
}

void UsersFile::saveAllUsersToFile(vector<User>&users){
    CMarkup xml;
	User user;

	bool fileExists = xml.Load(getFileName());

	xml.ResetMainPos();
	while (xml.FindElem())
		xml.RemoveElem();


	xml.AddElem("Users");
	for (int i = 0; i < users.size(); i++) {
		xml.FindElem();
		xml.IntoElem();
		xml.AddElem("User");
		xml.IntoElem();
		xml.AddElem("id", users[i].getUserId());
		xml.AddElem("login", users[i].getLogin());
		xml.AddElem("password", users[i].getPassword());
		xml.AddElem("name", users[i].getName());
		xml.AddElem("surname", users[i].getSurname());
		xml.OutOfElem();
		xml.AddNode(CMarkup::MNT_COMMENT, "/User");
		xml.Save(getFileName());
	}
}
