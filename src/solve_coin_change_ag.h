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
#include <vector>
class SolveCoinChangeAg : public SolveCoinChange {
public:
    SolveCoinChangeAg();
    std::vector<int>* solve();
};

#endif /* defined(__solve_coin_change_ag__) */

