#include <string>
using namespace std;

// Base class
class work{
private: 
	string id_;
	string title_;
public:
	work():id_(),title_() {}
	work(string const& id,string const& title): id_(id),title_(title){}
	string id()const{
		return id_;
	}
	string title()const{
		return title_;
	}
};

// Derived class
class book: public work{
private:
	string author_;
	int pubyear_;
public:
	book(): author_(),pubyear_() {}
	book(string const& id,string const& title,string const& author,int const& pubyear)
		: work(id,title),author_(author),pubyear_(pubyear) {}
};

int main(){

	return 0;
}