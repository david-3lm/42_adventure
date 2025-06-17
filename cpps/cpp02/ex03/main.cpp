
#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point);

static void	printData(const Point& A, const Point& B, const Point& C, const Point& P)
{
	std::cout << "Triangle vertices are ";
	std::cout << "A(" << A.GetX().toFloat() << ", " << A.GetY().toFloat() << "), ";
	std::cout << "B(" << B.GetX().toFloat() << ", " << B.GetY().toFloat() << "), ";
	std::cout << "C(" << C.GetX().toFloat() << ", " << C.GetY().toFloat() << ")";
	std::cout << "\n" <<std::endl;
	std::cout << "Point P is ";
	std::cout << "P(" << P.GetX().toFloat() << ", " << P.GetY().toFloat() << ")\n" << std::endl;
}

int main( void ) 
{
	Point		A(0.f, 0.f);
	Point		B(10.f, 30.f);
	Point		C(20.f, 0.f);
	Point		P(16.f, 1.f);
	Point		P2(30.f, 100.f);
	std::string	answer;

	answer = bsp(A, B, C, P) ? " " : " not ";
	printData(A, B, C, P);
	std::cout << "Point P is" << answer << "in the triangle ABC!" << std::endl;
	answer = bsp(A, B, C, P2) ? " " : " not ";
	printData(A, B, C, P2);
	std::cout << "Point P2 is" << answer << "in the triangle ABC!" << std::endl;

	return 0;
}