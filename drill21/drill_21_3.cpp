#include "std_lib_facilities.h"


template<class iter>
void print(iter first, iter last)
{
    while (first!=last) {
        cout << *first << '\n';
        ++first;
    }
}

template<class T>
class Less_than {
    T v;
public:
    Less_than(T val) :v(val) { }
    bool operator()(T x) const { return x < v; }
};



int main(){

	const string fname = "float.txt";
    ifstream ifs(fname.c_str());
    if (!ifs) error("can't open ",fname);
    vector<double> vd;
    double d;
    while (ifs>>d) vd.push_back(d);
    cout<<"vd: "<< endl;
    //print(vd.begin(),vd.end());
cout<<endl;
    cout<<"vi: "<<endl;
    vector<int> vi(vd.size());
    copy(vd.begin(),vd.end(),vi.begin());
    //print(vi.begin(),vi.end());

    cout << "\n(vd,vi) pairs:\n";
    for (int i = 0; i<vd.size(); ++i) {
        cout << '(' << vd[i] << ',' << vi[i] << ")\n";
    }
cout<<endl;
      double sum_vd = 0;
    sum_vd = accumulate(vd.begin(),vd.end(),sum_vd);
    cout << "Sum  of vd: " << sum_vd << endl;
       int sum_vi = 0;   
    sum_vi = accumulate(vi.begin(),vi.end(),sum_vi);
    cout<<" sum of vi: "<< sum_vi<<endl;
    cout << " sum_vd - sum_vi: " << sum_vd - sum_vi << endl<<endl;

	reverse(vd.begin(),vd.end());
	cout<<"forditott vd: "<<endl;
	print(vd.begin(),vd.end());


    double vd_mean = sum_vd / vd.size();
    cout << "Mean values in vd: " << vd_mean << endl;

    vector<double> vd2(count_if(vd.begin(),vd.end(),Less_than<double>(vd_mean)));
    copy_if(vd.begin(),vd.end(),vd2.begin(),Less_than<double>(vd_mean));
    cout << "vd2: "<<endl;
    print(vd2.begin(),vd2.end());

cout<<endl;
   sort(vd.begin(),vd.end());
    cout << "vd: "<<endl;
    print(vd.begin(),vd.end());

	return 0;
}