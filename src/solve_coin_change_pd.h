//
//  solve_coin_change_pd.h
//  
//
//  Created by Felipe Moraes.
//
//
//

#ifndef __solve_coin_change_pd__
#define __solve_coin_change_pd__


#include "solve_coin_change.h"
#include <vector>

class SolveCoinChangePd : public SolveCoinChange {
public:
    SolveCoinChangePd();
    std::vector<int>* solve();
};

#endif /* defined(__solve_coin_change_pd__) */

