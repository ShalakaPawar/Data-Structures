#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int main(){
    string str(5, 'n');
    cout<<str<<"\nEnter: ";

  //  getline(cin, str);
    cout<<str;
    string s1="fam";
    string s2="ily";
    cout<<s1+s2;
    cout<<s1.append(s2)<<endl;
    cout<<s1<<s2;
    s1.clear();
    cout<<"\nAfter using clear, s1 = "<<s1<<endl;

    //compare
    cout<<s1.compare(s2);
    s1.clear();
    //empty
    if(s1.empty())
        cout<<"string is empty";
    s1="shalakapawar";
    //erase
    s1.erase(3, 3);
    cout<<s1;

    cout<<s1.find("paw")<<endl;
    s1.insert(2, "lol");
    cout<<s1;

    cout<<s1.size()<<endl;

    cout<<s1.substr(6, 5);

    //int to str
    string a1="56";
    int a = stoi(a1);
    cout<<a;

    cout<<to_string(a)+"67";

    s1="ahbdkikunm";
    sort(s1.begin(), s1.end());
    cout<<s1;

    cout<<"==============";
    string nstr="ABC";
    cout<<nstr.substr(0,1);
}
