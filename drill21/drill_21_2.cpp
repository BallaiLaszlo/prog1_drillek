#include "std_lib_facilities.h"
#include <map>
#include <numeric>


void read_pair(map<string,int>& msi)
{
    string s;
    int i;
    cin >> s >> i;
    if (!cin) error("Problem reading from cin");
    msi[s] = i;
}


template<class T, class U>
ostream& operator<<(ostream& os, const pair<T,U>& p)
{
    os << setw(12) << left << p.first << '\t' << p.second;
    return os;
}


template<class T>
struct Map_add {
    T operator()(T v, const pair<string,T>& p)
    {
        return v + p.second;
    }
   };

template<class iter>
void print(iter first, iter last)
{
    while (first!=last) {
        cout << *first << '\n';
        ++first;
    }
}


int main(){


	 map<string,int> msi;

    msi["lecture"] = 21;
    msi["university"] = 35;
    msi["education"] = 15;
    msi["school"] = 99;
    msi["kindergarten"] = 105;
    msi["river"] = 5;
    msi["city"] = 10;
    msi["capital"] = 70;
    msi["software"] = 88;
    msi["hardware"] = 43;

    print(msi.begin(),msi.end());

  typedef map<string,int>::const_iterator MI;
    MI p = msi.begin();
    while (p!=msi.end()) p = msi.erase(p);
    cout << "torles utan a size: " << msi.size() << '\n';
	
    cout<<"beolvasin 10 cuccot: "<<endl;
    for (int i = 0; i < 10; ++i)
    {
    	read_pair(msi);
    }
cout<<endl;
    print(msi.begin(),msi.end());
  	 int msi_sum = 0;
    msi_sum = accumulate(msi.begin(),msi.end(),msi_sum,Map_add<int>());
    cout<<endl<<"osszeg: " <<msi_sum<<endl;

	map<int,string> mis;

    for (p = msi.begin(); p!=msi.end(); ++p)
        mis[p->second] = p->first;

    cout << "\nContents of mis:\n";
    print(mis.begin(),mis.end());



	return 0;
}