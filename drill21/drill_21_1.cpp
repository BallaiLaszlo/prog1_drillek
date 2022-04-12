#include "std_lib_facilities.h"


	struct Item{
		string name;
		int iid;
		double value;
		  Item() :name(), iid(0), value(0) { }
    Item(string n, int i, double v) :name(n), iid(i), value(v) { }
	};

	istream& operator>>(istream& is, Item& it)
{
    string name;
    int iid;
    double value;
    is >> name >> iid >> value;
    if (!is) return is;
    it = Item(name,iid,value);
    return is;
}

ostream& operator<<(ostream& os, const Item& it)
{
    return os << it.name << '\t' << it.iid << '\t' << it.value;
}	

	template<class iter>
void print(iter first, iter last)
{
    while (first!=last) {
        cout << *first << '\n';
        ++first;
    }
}


	struct  Comp_by_name {
    bool operator()(const Item& a, const Item& b) const
    {
        return a.name < b.name;
    }
};

struct Comp_by_iid {
    bool operator()(const Item& a, const Item& b) const
    {
        return a.iid < b.iid;
    }
};

bool comp_by_value(const Item& a, const Item& b)
{
    return a.value < b.value;
}


class Find_by_name {
    string name;
public:
    Find_by_name(const string& s) :name(s) { }
    bool operator()(const Item& it) const
    {
        return it.name == name;
    }
};

class Find_by_iid {
    int iid;
public:
    Find_by_iid(int i) :iid(i) { }
    bool operator()(const Item& it) const
    {
        return it.iid == iid;
    }
};

void f1(){
/*
        HA LISTÁT KELL ÍRNI AKKOR DEFINELÜNK EGY LISTÁT ÉS MINDEN HELYEN ÁTÍRJUK A "vi"
        STRINGET A LISTA NEVÉRE (list<Item> li akkor li.begin() etc...)

*/
	 vector<Item> vi;
	 const string ifname="drill_21.txt";
	 cout<<"drill_21.txt:"<<endl;
	  {
        ifstream ifs(ifname.c_str());
        if (!ifs) error("can't open ",ifname);
        Item i;
        while (ifs>>i) vi.insert(vi.end(),i);
    }
    print(vi.begin(),vi.end());

    cout<<"sorted by name: "<<endl;
    sort(vi.begin(),vi.end(),Comp_by_name());
        print(vi.begin(),vi.end());
    cout<<"sorted by iid: "<<endl;
    sort(vi.begin(),vi.end(),Comp_by_iid());
        print(vi.begin(),vi.end());
      cout<<"sorted by value decreasing: "<<endl;
   sort(vi.begin(),vi.end(),comp_by_value);
    reverse(vi.begin(),vi.end());
    print(vi.begin(),vi.end());

    cout << " insert two items"<<endl;
    vi.insert(vi.end(),Item("Horsesh",99,12.34));
    vi.insert(vi.end(),Item("C S400",9988,499.95));
    sort(vi.begin(),vi.end(),comp_by_value);
    reverse(vi.begin(),vi.end());
    print(vi.begin(),vi.end());

    // 1.6
    cout << " remove two items identified by name"<<endl;
    vector<Item>::iterator vi_it =
        find_if(vi.begin(),vi.end(),Find_by_name("a"));
    vi.erase(vi_it);
    vi_it = find_if(vi.begin(),vi.end(),Find_by_name("b"));
    vi.erase(vi_it);
    print(vi.begin(),vi.end());

    // 1.7
    cout << " remove two tems identified by iid "<<endl;
    vi_it = find_if(vi.begin(),vi.end(),Find_by_iid(5));
    vi.erase(vi_it);
    vi_it = find_if(vi.begin(),vi.end(),Find_by_iid(6));
    vi.erase(vi_it);
    print(vi.begin(),vi.end());
}





int main(){


		f1();
	

	return 0;
}