//
//  solve_coin_change_fb.cc
//  
//
//  Created by Felipe Moraes.
//
//
//

#include "solve_coin_change_fb.h"

SolveCoinChangeFb::SolveCoinChangeFb(string changes_file, string coins_file, string output_file) : SolveCoinChange(changes_file,coins_file, output_file) {
    backtrack_nodes = 0;
}

void SolveCoinChangeFb::solve(){

    std::vector<int> solution;
    std::string line;   
    ifstream fchange(changes_file_);
    ofstream foutput(output_file_);
    for (int i = 0; i < coins_->size(); ++i){
        solution.push_back(0);
    }

    if (fchange.is_open()){
        while (getline(fchange,line)){
            int best_fewest_coins = -1;
            bool solution_found = false;
            backtrack(stoi(line),solution,0,solution_found,best_fewest_coins,solution);
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
            backtrack_nodes = 0;
       }
    } else {
        std::cout << "File not found: " << changes_file_ << std::endl;
    }
}

void SolveCoinChangeFb::backtrack(int change, vector<int> coin_type, int coins_so_far, bool &solution_found, int& best_fewest_coins, vector<int> &best_coin_type){
    backtrack_nodes++;
    for (int i = 0; i< coins_->size();++i) {
        int smaller_change = change - (*coins_)[i];
       if (promising(smaller_change, coins_so_far+1, solution_found, best_fewest_coins)){
           if ( smaller_change == 0){ // a solution is found
                if ((solution_found == false) || ((coins_so_far + 1) < best_fewest_coins)){ // check if its best
                    best_fewest_coins = coins_so_far+1;
                    best_coin_type = coin_type;
                    best_coin_type[i]++;
                    solution_found = true;
                }
            } else {
                    // call child with updated state information
                    vector<int> smaller_coin_type = coin_type;
                    smaller_coin_type[i] += 1;
                    backtrack(smaller_change, smaller_coin_type, coins_so_far + 1, solution_found, best_fewest_coins, best_coin_type);
            }
       
        }
    }
}

bool SolveCoinChangeFb::promising(int change, int coins_returned, bool solution_found, int best_fewest_coins){
   if (change < 0){
        return false;
    } else if (change == 0){
        return true;
    } else {
        if (solution_found && coins_returned+1 >= best_fewest_coins){
            return false;
        } else {
            return true;
        }
    }

}
