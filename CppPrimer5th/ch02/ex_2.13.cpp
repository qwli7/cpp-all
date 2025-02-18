#include <iostream>

int j = 42;
int main() {
  
  int i = 100; // 当前定义会隐藏全局定义
  int j = i; // 100
  return 0;
}
