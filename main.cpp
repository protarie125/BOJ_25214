#include <algorithm>
#include <bit>
#include <chrono>
#include <cmath>
#include <cstdint>
#include <deque>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <ranges>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

using namespace std;

using ll = int64_t;
using vl = vector<ll>;

constexpr auto kMax = ll{1234567890};

ll n;
vl dp1, dp2;

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  cin >> n;
  dp1 = vl(n + 1, 0);
  dp2 = vl(n + 1, kMax);

  for (auto i = 1; i <= n; ++i) {
    ll a;
    cin >> a;

    dp1[i] = max(dp1[i - 1], a - dp2[i - 1]);
    dp2[i] = min(dp2[i - 1], a);

    cout << dp1[i] << ' ';
  }

  return 0;
}