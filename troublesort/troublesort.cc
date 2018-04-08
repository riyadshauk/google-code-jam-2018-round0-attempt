// Google Code Jam 2018, Round 0, Problem 2/4

// ====== THIS SOLUTION IS WRONG!!! I'M JUST SAVING IT HERE FOR REFERENCE ======

#include <cstdio>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

bool idk = false; // toggle standard outputs that would invalidate solution

void troublesort(int * arr, int n) {
  bool done = false;
  while (!done) {
    done = true;
    for (int i = 0; i < n - 2; i++) {
      if (arr[i] > arr[i + 2]) {
        done = false;
        int t = arr[i];
        arr[i] = arr[i + 2];
        arr[i + 2] = t;
      }
    }
  }

  if (idk) {
    cout << "troublesorted arr: ";
    for (int i = 0; i < n - 1; i++) {
      cout << arr[i] << ", ";
    }
    cout << arr[n - 1] << endl;
  }
}

int main() {
  string line;
  int t;
  cin >> t;
  cin.ignore(); // https://stackoverflow.com/questions/12691316/getline-does-not-work-if-used-after-some-inputs
  if (idk) cout << "t: " << t << endl;
  int n = 0;
  int tc = 1;
  while (getline(cin, line)) { // https://stackoverflow.com/questions/3910326/c-read-file-line-by-line-then-split-each-line-using-the-delimiter
    stringstream   linestream(line);
    string         data;

    if (idk) cout << "line: " << line << endl;
    if (idk) cout << "n: " << n << endl;

    if (n) {
      int arr[n];
      if (idk) cout << "nums: ";
      for (int i = 0; i < n; i++) {
        linestream >> arr[i];
        if (idk) cout << arr[i] << ", ";
      }
      if (idk) cout << endl;

      /* ===== check troublesort condition ===== */

      bool idxFound = false;
      troublesort(arr, n); // is this way too slow / easy? probably, but might work for 5pts to start...
      for (int i = 0; i < n - 1; i++) {
        if (idk) cout << "tc: " << tc << ", e: " << arr[i] << endl;
        if (arr[i] > arr[i + 1]) {
          cout << "Case #" << tc << ": " << i + 1 << endl;
          idxFound = true;
        }
      }
      if (!idxFound) {
          cout << "Case #" << tc << ": OK" << endl;
      }


      // if (arr[n - 2] > arr[n - 1]) {
      //   cout << "Case #" << tc << ": " << n - 1 << endl;
      // } else {
      //   cout << "Case #" << tc << ": OK" << endl;
      // }
      /* ======================================= */

      tc++;
      n = 0;
    } else {
      linestream >> n;
    }
  }
  return 0;
}