#include <iostream>
#include <vector>

int main(int argc, char **argvx) {
  int mdepth = atoi(argvx[1]);

  float cur, prev;
  std::cin >> prev;
  int cnt = 0;
  int state = 1;
  float threshold = 1.5;

  std::vector<int> vec;

  for (int i = 0; i < mdepth - 1; i++) {
    std::cin >> cur;
    cnt++;
    if (cur < threshold && state == 1) {
      vec.push_back(cnt);
      cnt = 0;
      state = 0;
    } else if (threshold < cur && state == 0) {
      vec.push_back(cnt);
      cnt = 0;
      state = 1;
    }
  }

  if (!(vec.size() > 6 && vec.size() % 2 == 0)) {
    std::cerr << "failed" << std::endl;
    return 1;
  }

  std::vector<unsigned char> bits;
  for (int i = 3; i < vec.size() - 2; i += 2) {
    if (vec[i + 1] > vec[i] * 1.5) {
      bits.push_back(1);
    } else {
      bits.push_back(0);
    }
  }

  if (bits.size() % 8 != 0) {
    std::cerr << "failed" << std::endl;
    return 1;
  }

  std::vector<unsigned char> data;

  for (int i = 0; i < bits.size() / 8; i++) {
    unsigned char d = 0;
    for (int j = 7; j >= 0; j--) {
      d <<= 1;
      d |= bits[i * 8 + j];
    }
    data.push_back(d);
  }

  for (auto d : data) {
    printf("%02x ", d);
  }
  printf("\n");

  return 0;
}