/*
    g++ main.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o main `fltk-config --ldflags --use-images`
*/
#include "Simple_window.h"
#include "Graph.h"

using Graph_lib::Font;

double one(double) { return 1; }

double square(double x) { return x*x; }

int main()
{
    using namespace Graph_lib;



    int xmax = 1200;
    int ymax = 1200;

    int x_orig = xmax/2;
    int y_orig = ymax/2;

    int rmin = -11;
    int rmax = 11;
    
    int n_points = 600;

    Simple_window win {Point{100,100}, xmax, ymax, "Elso_Ablak"};

	Point origo {x_orig, y_orig};

	int xlength = xmax - 40;
	int ylength = ymax - 60;

	int xscale = 30, yscale = 30;

	Function s (one, rmin, rmax, origo, n_points, xscale, yscale);
	Function sq (square, rmin, rmax, origo, n_points, xscale, yscale);
	Function cos_func ( [] (double x) { return cos(x); },
						rmin, rmax, origo, n_points, xscale, yscale);
	Function sin_func( [](double x) {return sin(x);}, 
						rmin, rmax, origo,n_points, xscale, yscale+50);
	
	sin_func.set_style(Line_style(Line_style::dash, 3));


	Axis x {Axis::x, Point{20, y_orig}, xlength, xlength/xscale, "x"};
	Axis y {Axis::y, Point{x_orig, ylength + 20}, ylength, ylength/yscale, "y"};

	Rectangle r {Point{200,200}, 150, 100};

	r.set_fill_color(Color::yellow);
	r.set_style(Line_style(Line_style::dash, 2));

	Text t {Point{200,400}, "Szia Lajos!"};
	t.set_font(Font::symbol);
	t.set_font_size(70);

	Image ii {Point{100,100}, "badge.jpg"};
	Image riven{Point{500,500}, "Riven.jpg"};	

	Circle c {Point{700,700}, 100};
	c.set_fill_color(Color::cyan);

	Ellipse e {Point{500,500}, 100, 50};
	e.set_fill_color(Color::red);
	e.set_style(Line_style(Line_style::dash ,1));

	win.attach(e);
	win.attach(ii);
	win.attach(riven);
	win.attach(c);
	win.attach(t);
	win.attach(r);
	win.attach(s);
	win.attach(sq);
	win.attach(cos_func);
	win.attach(sin_func);
	win.attach(x);
	win.attach(y);

    win.wait_for_button();

}
