
#ifndef CONSTANTS_H
#define CONSTANTS_H

#define  RADIAN 57.29577951308232087684
#define PI_2    90/RADIAN
  /*  функция ABS  */
#define ABS(x) (((x)<0) ? -(x):(x))
#define _ABS(x) (((x)<0) ? -(x):(x))
  /*  функция MIN  */
#define MIN(x,y)  (((x)<(y)) ? (x):(y))
  /*  функция MAX  */
#define MAX(x,y)  (((x)>(y)) ? (x):(y))

namespace constants
{
	inline constexpr double pi {3.14159265};
	inline constexpr double grav_accelerate{9.81};
	inline constexpr double steel_density{7850};

}
#endif
