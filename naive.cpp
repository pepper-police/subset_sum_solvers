#include <iostream>
#include <sstream>
#include <vector>

void input(std::vector<int>* v, int* B) {
  std::string str;
  std::getline(std::cin, str);
  std::istringstream iss(str);
  int tmp;
  while (iss >> tmp) {
    (*v).push_back(tmp);
  }
  std::cin >> *B;
}

void subset_sum(std::vector<int> s, int B) {
  // make power set and solve (using bitwise AND)
  std::vector<std::vector<int>> ans;
  for (int i = 1; i <= (1 << s.size()); i++) {
    std::vector<int> v;
    int sum = 0;
    for (int j = 0; j < s.size(); j++) {
      if (i & (1 << j)) {
	v.push_back(s[j]);
	sum += s[j];
      }
    }
    if (sum == B) {
      ans.push_back(v);
    }
  }
  if (ans.size() != 0) {
    std::cout << "====solution====" << std::endl;
    for (int i = 0; i < ans.size(); i++) {
      for (int j = 0; j < ans[i].size(); j++) {
	std::cout << ans[i][j] << " ";
      }
      std::cout << std::endl;
    }
  } else {
    std::cout << "can't find solution" << std::endl;
  }
}


int main() {
  std::vector<int> s;
  int B;

  input(&s, &B);
  subset_sum(s, B);
}
