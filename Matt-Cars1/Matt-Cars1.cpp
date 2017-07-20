// Matt-Cars1.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <memory>
#include <string>
#include <string_view>
#include <utility>
#include <vector>

class car {
	friend std::ostream & operator<<(std::ostream & os, const car & c);
public:
	car(std::string_view brand) : brand(brand) {}
private:
	std::string brand;
};

std::ostream & operator<<(std::ostream & os, const car & c) {
	return os << c.brand;
}

int main() {
	std::vector<std::unique_ptr<car>> street; // initially empty
	std::vector<std::unique_ptr<car>> garage; // initially empty

											  // create a standalone car
	std::unique_ptr<car> car_ptr = std::make_unique<car>("brand_a");
	// `car_ptr` is a pointer to our car

	// create another car on the street
	street.push_back(std::make_unique<car>("brand_b"));
	// `street[0]` is a pointer to our car

	std::cout << *car_ptr << '\n';
	std::cout << "street[0] points to:" << *street[0] << '\n';

	// attempt to move standalone car to the garage:
  garage.push_back(car_ptr); // this will not work -- it's important to understand why
  std::cout << "garage[0] contains: " << *garage[0] << '\n';
  
	// this will work!!!
	garage.push_back(std::move(car_ptr));

}


//
//#include <cstddef>
//#include <iostream>
//#include <string>
//#include <string_view>
//#include <ostream>
//
//
//class car {
//	friend std::ostream & operator<<(std::ostream & os, const car & c);
//public:
//	car(std::string_view brand) : brand(brand) {}
//private:
//	std::string brand;
//
//};
//
//std::ostream & operator<<(std::ostream & os, const car & c) {
//	return os << c.brand;
//}
//
//int main() {
//	car car_a{ "brand_a" };
//	car car_b{ "brand_b" };
//	car car_c{ "brand_c" };
//	std::cout << car_a << ' ' << car_b << ' ' << car_c << '\n';
//}