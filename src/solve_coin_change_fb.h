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

class SolveCoinChangeFb : public SolveCoinChange {
public:
    SolveCoinChangeFb();
    std::vector<int>* solve();
};

#endif /* defined(__solve_coin_change_fb__) */

