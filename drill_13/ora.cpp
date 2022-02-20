/*
    g++ ora.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o ora `fltk-config --ldflags --use-images`
*/
#include "Simple_window.h"
#include "Graph.h"
#include "std_lib_facilities.h"

using Graph_lib::Font;

double one(double) { return 1; }

double square(double x) { return x*x; }

int main()
{
    using namespace Graph_lib;


 		random_device rd;
		mt19937 gen(rd());
		uniform_int_distribution<> dis(1,640);
		int random=dis(gen);	

    int xmax=800;
    int ymax=1000;

    int x_size=xmax;
    int y_size=ymax;

    int x_grid=100;
    int y_grid=100;

 Simple_window win {Point{100,100}, xmax, ymax, "Drill13"};

 Lines grid;
		for (int x=x_grid; x<=x_size; x+=x_grid)
			grid.add(Point{x,0},Point{x,y_size-200});
		for (int y = y_grid; y<y_size-100; y+=y_grid)
			grid.add(Point{0,y},Point{x_size,y}); 

		Vector_ref<Rectangle> rect;
		for(int i=0;i<8;++i){
			rect.push_back(new Rectangle{Point{i*100,i*100},x_grid,y_grid});
			rect[rect.size()-1].set_fill_color(Color::red);
			win.attach(rect[rect.size()-1]);
		}

		Image sz{Point(0,y_grid+200),"samar.gif"};
		Image sza{Point(0,y_grid+400),"samar.gif"};
		Image szm{Point(400,y_grid),"samar.gif"};
 				win.attach(sz);
 				win.attach(sza);
 				win.attach(szm);
 				win.attach(grid);
 				win.wait_for_button();

 				srand((unsigned)time(0));
			
			for(;;){
				Image hol{Point(0,0),"szaz.jpg"} ;			
				int randx=rand()%8;
				int randy=rand()%8;
				win.attach(hol);

				hol.move(randx*100,randy*100);
				win.wait_for_button();
				}
		}
			

