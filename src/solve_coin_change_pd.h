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
#include <sys/time.h>
#include <sys/resource.h>
#include <limits>
#include <cstdint>
#include <vector>

using namespace std;

class SolveCoinChangePd : public SolveCoinChange {
public:
    SolveCoinChangePd(string changes_file, string coins_file, string output_file);
    void solve();
};

#endif /* defined(__solve_coin_change_pd__) */

