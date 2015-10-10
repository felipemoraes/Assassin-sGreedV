//
//  solve_coin_change_ag.h
//  
//
//  Created by Felipe Moraes.
//
//
//

#ifndef __solve_coin_change_ag__
#define __solve_coin_change_ag__


#include "solve_coin_change.h"

class SolveCoinChangeAg : public SolveCoinChange {
public:
    SolveCoinChangeAg(string changes_file, string coins_file, string output_file);
    void solve();
};

#endif /* defined(__solve_coin_change_ag__) */

