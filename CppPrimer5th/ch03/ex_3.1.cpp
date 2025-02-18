#include <iostream>

// 使用 using 来声明，避免每次都需要写域作用符 std::cout std::cin std::endl
// 暂时不使用 using namespace std; 这种写法本身就是一种不太好的写法

using std::cout;
using std::cin;
using std::endl;
int main() {
  int value;
  cin >> value;
  cout << "input value is " << value << endl;
  return 0;
}
