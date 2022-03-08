#include "std_lib_facilities.h"

class B1{
	public:
			virtual void vf(){cout<<"b1::vf()\n";}	
			void f() {cout <<"b1::f()\n";}	
			void pvf() {cout << "b1::pvf()\n";}	}	;	
class D1: public B1{
	public:
		virtual void vf(){cout<<"b1::vf()\n";}	
			void f() {cout <<"b1::f()\n";}
		};
class D2: public D1{
	public:
				void pvf(){cout << "b1::pvf()\n";}
};
class B2{
	public:
		virtual void pvf(){cout << "b1::pvf()\n";}
};
class D21: public B2{
	public: void pvf(){cout<<s<<endl;}
	string s;
};
class D22: public B2{
	public: void pvf(){cout<<b<<endl;}
	int b;
};
void f(B2& b2){
	b2.pvf();
}


int main(){
	B1 b1;
	b1.vf();
	b1.f();
cout<<endl;
	D1 d1;
	d1.vf();
	d1.f();
cout<<endl;
	B1 & ref =d1;
	ref.vf();
	ref.f();
cout<<endl;
	b1.pvf();
cout<<endl;
	D2 d2;
	d2.pvf();
cout<<endl;
	D21 d21;
	d21.s="ASD";
	d21.pvf();	
cout<<endl;
	D22 d22;
	d22.b=5;
	d22.pvf();
cout<<endl;
f(d21);
cout<<endl;
f(d22);
cout<<endl;

}
