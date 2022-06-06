#include <iostream>
// Sobrecarga de operadores usando con funciones normales
// https://www.learncpp.com/cpp-tutorial/overloading-operators-using-normal-functions/
class Cents
{
private:
	int m_cents;
 
public:
	Cents(int cents) { m_cents = cents; }
 	int getCents()  const { return m_cents; }
};

// Need to explicitly provide prototype for operator+ so uses of operator+ in other files know this overload exists
// add Cents + Cents using a normal function
Cents operator+(const Cents &c1, const Cents &c2);
 
// subtract Cents - Cents using a normal function
Cents operator-(const Cents &c1, const Cents &c2);
 
// multiplicacion Cents * Cents using a normal function
Cents operator*(const Cents &c1, const Cents &c2);

// division Cents / Cents using a normal function
Cents operator/(const Cents &c1, const Cents &c2);
 
Cents operator%(const Cents &c1, const Cents &c2);

// note: this function is not a member function!
Cents operator+(const Cents &c1, const Cents &c2)
{
	// use the Cents constructor and operator+(int, int)
	// we can´t access m_cents directly because this is a friend function
	return Cents(c1.getCents() + c2.getCents());
}
 
// note: this function is not a member function!
Cents operator-(const Cents &c1, const Cents &c2)
{
	// use the Cents constructor and operator-(int, int)
	// we can´t access m_cents directly because this is a friend function
	return Cents(c1.getCents() - c2.getCents());
}

// note: this function is not a member function!
Cents operator*(const Cents &c1, const Cents &c2)
{
	// use the Cents constructor and operator*(int, int)
	// we can´t access m_cents directly because this is a friend function
	return {c1.getCents() * c2.getCents()};
}

// note: this function is not a member function!
Cents operator/(const Cents &c1, const Cents &c2)
{
	// use the Cents constructor and operator/(int, int)
	// we can´t access m_cents directly because this is a friend function
	if (c2.getCents() != 0)
		return Cents(c1.getCents()/ c2.getCents());
	return {-1};
}
 
Cents operator%(const Cents &c1, const Cents &c2)
{
	// use the Cents constructor and operator/(int, int)
	// we can´t access m_cents directly because this is a friend function
	if (c2.getCents() != 0)
		return Cents(c1.getCents() % c2.getCents());
	return {-1};
}
int main()
{
	Cents cents1{ 6 };
	Cents cents2{ 2 };
	Cents cents3{ 0 };
	Cents centsSuma{ cents1 + cents2}; // llama a la función operator+(cents1,cents2)
	Cents centsResta{ cents1 - cents2 };// llama a la función operator-(cents1,cents2)
  Cents centsMultiplicacion{ cents1 * cents2 };// llama a la función operator*(cents1,cents2)
	Cents centsDivision{ cents1 / cents2 };// llama a la función operator/(cents1,cents2)
	Cents centsDivision2{ cents1 / cents3 };// llama a la función operator/(cents1,cents3)
	Cents centsResiduo{cents2 % cents1};

	std::cout << "Suma " << centsSuma.getCents() << " cents.\n";
 	std::cout << "Resta " << centsResta.getCents() << " cents.\n";
	std::cout << "Multiplicación " << centsMultiplicacion.getCents() << " cents.\n";
	std::cout << "Division " << centsDivision.getCents() << " cents.\n";
	std::cout << "División / 0 " << centsDivision2.getCents() << " cents.\n";
	std::cout << "Residuo % " << centsResiduo.getCents() << " cents.\n";

	return 0;
}