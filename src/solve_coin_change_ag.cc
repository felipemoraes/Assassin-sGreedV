//
//  solve_coin_change.cc
//  
//
//  Created by Felipe Moraes.
//
//
//

#include "solve_coin_change_ag.h"

SolveCoinChangeAg::SolveCoinChangeAg(string changes_file, string coins_file, string output_file) : SolveCoinChange(changes_file,coins_file, output_file) {
}


void SolveCoinChangeAg::solve(){

    std::vector<int> solution;
    std::string line;   
    ifstream fchange(changes_file_);
    ofstream foutput(output_file_);
    for (int i = 0; i < coins_->size(); ++i){
        solution.push_back(0);
    }
    std::sort(coins_->begin(),coins_->end(), std::greater<int>());
    if (fchange.is_open()){
        while (getline(fchange,line)){
            int change = stoi(line);
            int best_fewest_coins = 0;
       
            for (int i = 0; i<coins_->size();++i){
                while (change>= 0){
                    change -= (*coins_)[i]; 
                    if (change >=0){
                        solution[i]++;
                        best_fewest_coins++;
                    }
                }
                if (change < 0){
                    change += (*coins_)[i];
                }
            }
            foutput << best_fewest_coins << " ";
            for (int i = 0; i<solution.size() ;++i){
                if (solution[i] != 0) {
                    while (solution[i]>0){
                        foutput << (*coins_)[i] << " ";
                        solution[i]--;
                    }
                }     
            }         
            foutput << std::endl;        
       }
    } else {
        std::cout << "File not found: " << changes_file_ << std::endl;
    }
}
