#include <iostream>
#include <cmath>
#include <iomanip>

double solution(double u, double b)
{
  const long div = pow(10, 9);
  double prev_x{}, x{u}, f_x{};

  for(int i=1; i<div; ++i)
  {
    f_x = std::floor(std::pow(2, (b - x*x))) / div;
    if(i>3 && (std::abs(f_x - prev_x) < 0.000000001 || std::abs(prev_x - x) < 0.000000001))
      return f_x + x;

    prev_x = x;
    x = f_x;
  }

  return f_x + x;
}

int main()
{
  double u{0.0}, b{0.0};
  std::cin >> u >> b;

  std::cout << std::setprecision(9) << std::fixed << solution(u, b) << std::endl;

  return 0;
}
