#include <iostream>
// https://www.learncpp.com/cpp-tutorial/overloading-the-io-operators/
class Point
{
private:
    double m_x{};
    double m_y{};
    double m_z{};
 
public:
// Constructor con parámetros
    Point(double x=0.0, double y=0.0, double z=0.0): m_x{x}, m_y{y}, m_z{z}
    {
    }
// getter's
		double getX()const { return m_x;}
    double getY()const{ return m_y;}
		double getZ()const{ return m_z;}
// set's
		void setXYZ(double x, double y, double z){
			m_x = x;
			m_y = y;
			m_z = z;
		}
};

// sobrecarga de operator<< y operator>> con funciones normales
std::ostream& operator<< (std::ostream &out, const Point &point);
std::istream& operator>> (std::istream &in, Point &point);


std::ostream& operator<< (std::ostream &out, const Point &point)
{
    // Since operator<< is normal, we can´t access Point's members directly.
    out << "Point(" << point.getX() << ", " << point.getY() << ", " << point.getZ() << ')';
    return out;
}
 
std::istream& operator>> (std::istream &in, Point &point)
{double _x, _y, _z;
    // Since operator>> is a normal, we can't access Point's members directly.
    // note that ***parameter point must be non-const** so we can modify the class members with the input values
    in >> _x;
    in >> _y;
    in >> _z;
		point.setXYZ(_x, _y, _z);

    return in;
}
//Here’s a sample program using both the overloaded operator<< and operator>>:
int main()
{
    std::cout << "Enter a point: \n";
 
    Point point{};

		// lee un objeto de la clase Point usando cin >>
    std::cin >> point;
		// despliega un objeto de la clase Point usando cout <<
    std::cout << "You entered: " << point << '\n';
 
    return 0;
}