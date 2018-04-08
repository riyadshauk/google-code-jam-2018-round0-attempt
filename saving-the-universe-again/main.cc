// Google Code Jam 2018, Round 0, Problem 1/4

// ====== THIS SOLUTION IS WRONG!!! IT'S CLOSE-ISH TO THE ANSWER, BUT WRONG ======

#include <cstdio>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

bool idk = false; // toggle standard outputs that would invalidate solution

int main() {
  string line;
  int t;
  cin >> t;
  if (idk) cout << "t: " << t << endl;
  for (int tc = 1; getline(cin, line); tc++) { // https://stackoverflow.com/questions/3910326/c-read-file-line-by-line-then-split-each-line-using-the-delimiter
    stringstream  linestream(line);
    int           d;
    string        str;
    cin >> d;
    cin >> str;
    if (idk) cout << "d: " << d << ", str: " << str << endl;
    int sCount = 0;
    int cCount = 0;
    int prod = 1;
    int damage = 0;
    for (int i = 0; i < str.length(); i++) {
      if (str[i] == 'C') {
        cCount++;
        prod *= 2;
      } else if (str[i] == 'S') {
        sCount++;
        damage += prod;
      }
    }

    if (idk) cout << "damage: " << damage << ", prod: " << prod << ", cCount: " << cCount << ", sCount: " << sCount << endl;

     // attempt to fix
    int swappableSCount = 0;
    int fixes = 0;
    int numCs = cCount; // important for not wasting time: still O(n), but conditionally faster.
    for (int i = str.length() - 1; (i > -1) && (damage > d) && (numCs > 0); i--) {
      if (str[i] == 'S') swappableSCount++;
      if (str[i] == 'C' && swappableSCount) {
        numCs--;
        prod /= 2;
        damage -= (prod * swappableSCount);
        fixes += swappableSCount;
        int optimalFixes = fixes;
        if (damage < d) {
          // fixes -= (d - damage) % prod;
          while (damage < d) { /* @todo: Use MODULO here!? but also think of more test cases too... */
            damage += prod;
            optimalFixes--;
          }
          fixes = optimalFixes;
        }
      } else if (str[i] == 'C') {
        numCs--;
        prod /= 2;
      }
      if (idk) cout << "damage: " << damage << ", prod: " << prod << ", numCs: " << numCs << ", swappableSCount: " << swappableSCount << ", fixes: " << fixes << ", str[" << i << "]: " << str[i] << endl;
    }

    // display conclusion
    if (damage <= d) cout << "Case #" << tc << ": " << fixes << endl;
    else cout << "Case #" << tc << ": IMPOSSIBLE" << endl;

  }
  return 0;
}