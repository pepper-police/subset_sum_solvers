#include <iostream>
#include <sstream>
#include <vector>
#include <map>
#include <list>
#include <set>

struct TABLE {
  int sum;
  std::vector<int> item;
};
typedef struct TABLE table;

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
  std::vector<std::vector<bool>> dp(s.size()+1, std::vector<bool>(B+1, false));

  dp[0][0] = true;

  for (int i = 1; i < dp.size(); i++) {
    for (int j = 0; j < dp[i].size(); j++) {
      if (j < s[i-1]) {
	if (dp[i-1][j]) {
	  dp[i][j] = true;
	}
      }
      if (j >= s[i-1]) {
	if (dp[i-1][j] || dp[i-1][j-s[i-1]]) {
	  dp[i][j] = true;
	}
      }
    }
  }
  /*
  // show dp table
  for (int i = 0; i < dp.size(); i++) {
    for (int j = 0; j < dp[i].size(); j++) {
      std::cout << dp[i][j] << " ";
    }
    std::cout << std::endl;
  }
  */
  
  if (dp[s.size()][B]) {
    // find pair
    std::cout << "====find solution====" << std::endl;
    int i = s.size(), j = B;
    while (j != 0) {
      if (dp[i-1][j]) {
	i--;
      } else {
	std::cout << s[i-1] << " ";
	j -= s[i-1];
      }
    }
    std::cout << std::endl;
  } else {
    std::cout << "can't find solution!" << std::endl;
  }

}

int main() {
  std::vector<int> s;
  int B;

  input(&s, &B);
  subset_sum(s, B);
}
