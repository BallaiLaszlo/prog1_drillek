#include "std_lib_facilities.h"

// Class template
template <class T>
class drill {
   private:
    T val;
   public:
    drill(T n) : val(n) {}
    T kiiras() {
        return val;
    }
};
 template<class T>
 T& get(){
    	return val;
    }

int main() {

    drill<int> drillInt(7);
    drill<double> drillDouble(7.7);
    drill<char> drillChar('S');
    drill<string> drillString("Ez a drill...");
    /*vector<int> vek;
    vek.push_back(1);
    vek.push_back(5);
    vek.push_back(7);
    vek.push_back(9); 
    int meret=5; // ? a vector.size()- nem megy
    drill<vector<int>> drillVektor(vek);*/

    cout << "int szam = " << drillInt.kiiras() << endl;
    cout << "double egeszszam = " << drillDouble.kiiras() << endl;
    cout << "char karakter: "<<drillChar.kiiras()<<endl;
    cout << "string string:" <<drillString.kiiras()<<endl;
    //for (int i = 0; i < meret ; ++i)
   // {
   // 	cout<<i<<".ik eleme"<<drillVektor[i]<<endl;
   // }
    cout<<drillInt.get()<<endl;
  
    return 0;
}