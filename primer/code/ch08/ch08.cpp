
#include <iostream>
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
// ways to set argv in vs2022
// 1. How to open launch.vs.json?
// 2. open launch.vs.json, add "args": ["arg1", "arg2", "arg3"]
// 3. for example:
//"args": ["arg1", "arg2", "arg3"]
//{
//    "version": "0.2.1",
//        "defaults" : {},
//        "configurations" : [
//    {
//        "type": "default",
//            "project" : "CMakeLists.txt",
//            "projectTarget" : "code.exe",
//            "name" : "code.exe"
//    },
//    {
//      "type": "default",
//      "project" : "CMakeLists.txt",
//      "projectTarget" : "ch01.exe (ch01\\ch01.exe)",
//      "name" : "ch01.exe (ch01\\ch01.exe)"
//    },
//    {
//      "type": "default",
//      "project" : "CMakeLists.txt",
//      "projectTarget" : "ch06.exe (ch06\\ch06.exe)",
//      "name" : "ch06.exe (ch06\\ch06.exe)",
//      "args" : [
//        "arg1",
//        "arg2"
//      ]
//    },
//    {
//      "type": "default",
//      "project" : "CMakeLists.txt",
//      "projectTarget" : "ch08.exe (ch08\\ch08.exe)",
//      "name" : "ch08.exe (ch08\\ch08.exe)",
//      "args" : [
//        "arg1",
//        "arg2"
//      ]
//    }
//        ]
//}
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
	cout<<argv[2]<<endl;
	//ifstream input(argv[1]);
	//ofstream output(argv2]);
	
}