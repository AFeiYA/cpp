
#include <iostream>
#include <string>
#include <fstream>
#include <filesystem>
#include <direct.h> 

using namespace std;
//8.1
istream& read(istream& is) {
	string s;
	while(is>>s) {
		cout<<s<<endl;
	}
	is.clear();
	return is;
}

int main(int argc, char *argv[]) {
	cout<<"ch08"<<endl;
	//8.1
	//read(cin);
	cin.tie(&cout);//仅仅用来展示,标准库将cin和cout关联起来,这样cin和cout的缓冲区将会同步
	ostream *old_tie = cin.tie(nullptr);//cin不再与任何流关联
	cin.tie(&cerr); // cin和cerr关联 而不是和cout关联
	cin.tie(old_tie);// 重新将cin和cout关联
	cout<<argv[0]<<endl;
	cout<<argv[1]<<endl;
	auto path = __FILE__;
	cout<< path <<endl;
	filesystem::path full_path(path);
	filesystem::path dir = full_path.parent_path().parent_path();
	filesystem::path resources = dir / "resources";
	filesystem::path file = resources / "books.txt";
	cout<<dir<<endl;
	cout<<resources<<endl;
	//read file
	ifstream in(file);
	if (!in.is_open()) {
		cerr<<"can't open file"<<endl;
		return -1;
	}
	string line;
	while (getline(in, line)) {
		cout<<line<<endl;
	}
	in.close();
	ofstream out(file, ofstream::app);
	if (!out.is_open()) {
		cerr << "can't open file" << endl;
		return -1;
	}
	out << "new line" << endl;
	out.close();
}