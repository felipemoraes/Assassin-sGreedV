//
//  solve_coin_change.h
//  
//
//  Created by Felipe Moraes.
//
//
//

#ifndef __solve_coin_change__
#define __solve_coin_change__

#include <vector>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class SolveCoinChange {
public:
    SolveCoinChange(string changes_file, string coins_file, string output_file);
    ~SolveCoinChange();
    virtual void solve() = 0;
    vector<int>* coins_;
    string changes_file_;
    string output_file_;
};

#endif /* defined(__solve_coin_change__) */

