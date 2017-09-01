#include<iostream>
#include<sstream>
#include<memory>
#include<vector>

using namespace std;

class StrBlob {
public:
	typedef vector<string>::size_type size_type;
	StrBlob();
	StrBlob(initializer_list<string> li);
	size_type size() { return date->size(); }
	bool empty() { return date->empty(); }
	void push_back(const string &s) { return date->push_back(s); }
	void pop_back();
	string& front();
	string& back();
	const string& cfront() const;
	const string& cback() const;
	void out(ostream &os);
private:
	shared_ptr<vector<string>> date;
	void check(size_t i, const string &msg) const;
};

StrBlob::StrBlob() :date(make_shared<vector<string>>()) {};
StrBlob::StrBlob(initializer_list<string> li) :date(make_shared<vector<string>>(li)) {};

void StrBlob::check(size_t i, const string &msg) const {
	if (i >= date->size())
		throw out_of_range(msg);
}

string& StrBlob::front() {
	check(0, "front on empty StrBlob");
	return date->front();
}

const string& StrBlob::cfront() const{
	check(0, "front on empty StrBlolb");
	return date->front();
}

string& StrBlob::back() {
	check(0, "back on empty StrBlob");
	return date->back();
}

const string& StrBlob::cback() const {
	check(0, "back on empty StrBlob");
	return date->back();
}

void StrBlob::pop_back() {
	check(0, "pop on empty StrBlob");
	date->pop_back();
}

void StrBlob::out(ostream& os) {
	for(string s:*date)
	os << s << endl;
}

int main() {
	StrBlob b1;
	const StrBlob b2 = { "a","an","the" };
	const string s(b2.cfront());
	//b1 = b2;

	/*b2.push_back("about");
	b1.out(cout);
	b2.out(cout);*/

	cout << s;
}
