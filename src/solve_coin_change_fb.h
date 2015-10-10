//
//  solve_coin_change_fb.h
//  
//
//  Created by Felipe Moraes.
//
//
//

#ifndef __solve_coin_change_fb__
#define __solve_coin_change_fb__


#include "solve_coin_change.h"
#include <vector>

using std::vector;



class SolveCoinChangeFb : public SolveCoinChange {
public:
    SolveCoinChangeFb(string changes_file, string coins_file, string output_file);
    void solve();
    void backtrack(int change, vector<int> coin_type, int coins_so_far, bool &solution_found, int &best_fewest_coins, vector<int> &best_coin_type);
    bool promising(int change, int coins_returned, bool solution_found, int best_fewest_coins);
    int backtrack_nodes;
};

#endif /* defined(__solve_coin_change_fb__) */

