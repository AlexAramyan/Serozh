#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>

#include <SFML/Graphics.hpp>

#include "Player.hpp"
#include "Enemy.hpp"
#include "Bullet.hpp"
//#include "Lazer.hpp"
	
namespace utils
{
	#define PI 3.1415926535897932384626433832795
	#define arcsin(x) (180 / PI * std::asin(x))
	#define arccos(x) (180 / PI * std::acos(x))
	#define arctan(x) (180 / PI * std::atan(x))
	/*#define sin(x) std::sin(x / 180 * PI)
	#define cos(x) std::cos(x / 180 * PI)
	#define tan(x) std::tan(x / 180 * PI)*/

	/*auto tan = [](float x) { return (180 / PI * std::tan(x)); };
	auto sin = [](float x) { return (180 / PI * std::sin(x)); };
	auto cos = [](float x) { return (180 / PI * std::cos(x)); };*/

	double tan(float x) { return (180 / PI * std::tan(x)); }
	double sin(float x) { return (180 / PI * std::sin(x)); }
	double cos(float x) { return (180 / PI * std::cos(x)); }
}