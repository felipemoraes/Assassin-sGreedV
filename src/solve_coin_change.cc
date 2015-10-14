//
//  solve_coin_change.cc
//  
//
//  Created by Felipe Moraes.
//
//
//

#include "solve_coin_change.h"

SolveCoinChange::SolveCoinChange(string changes_file, string coins_file, string output_file) {
    coins_ = new vector<int>();
    changes_file_ = changes_file;
    output_file_ = output_file;
    string line;
    ifstream cfile(coins_file);
    if (cfile.is_open()){
        while (getline(cfile,line)){
            coins_->push_back(stoi(line));
        }
        cfile.close();
    } else {
        std::cout << "File not found" << std::endl;
    }
}

SolveCoinChange::~SolveCoinChange(){
    delete coins_;
}
