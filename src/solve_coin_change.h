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

class SolveCoinChange {
public:
    SolveCoinChange();
    virtual std::vector<int>* solve() = 0;
};

#endif /* defined(__solve_coin_change__) */

