// Raphael S. Andaya
// CPSC 353-01
// 2021-06-25
// raphyand@csu.fullerton.edu
// @raphyand
//
// Assignment 02
//
// Run_cmd file concatenate strings until segmentation fault
//
#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

/// Given the number \p n_repeat, repeat the string \p s that many
/// times and return it as a new string.
/// \param n_repeat The number of times to repeat the string \p s
/// \param s The string to repeat, must be 1 byte or larger.
/// \returns the string \p s repeated \p n_repeat times
string BigString(int n_repeat, const string& s) {
  string x = s;
  for (int i = 0; i < n_repeat; i++) {
    x += s;
  }
  return x;
}

// ./run_cmd ./overflow whatever_string_to_use
/// Entry point to the test harness which repeated executes the
/// program provided as an argument with arguments that increase in
/// length. Reports when the target program exits with an abnormal
/// return code.
int main(int argc, char const* argv[]) {
  if (argc < 2) {
    cout << "Provide two arguments. The first is the command to run."
            "The second is the string to repeat.\n";
    return 1;
  }

  string base_cmd = string(argv[1]);
  string base_str = string(argv[2]);
  int rv = 0;
  int n_repeat = 0;
  do {
    string repeated = BigString(n_repeat, base_str);
    n_repeat++;
    // Concatenate the command and the repeated string as a
    // single string. Redirect all output to /dev/null to run
    // the program silently. We are only interested in when
    // the target program fails.
    // Run it repeatedly until it exit does return 0
    string cmd = base_cmd + " " + repeated + " > /dev/null";
    cout << "Running the command: " << cmd << "\n";
    cout << "Trying " << repeated.size() << " bytes. ";
    cout << endl << repeated;
    rv = system(cmd.c_str());
    cout << "Exited with status " << rv << "\n";
  } while (rv == 0);
  return 0;
}