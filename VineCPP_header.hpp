#ifndef _VINECPP_HEADER_HPP_
#define _VINECPP_HEADER_HPP_

// headers
#include <iostream>
#include <string>
#define _USE_MATH_DEFINES
#include <cmath>
#include <vector>
#include <nlopt.hpp>
#include <algorithm>
#include <utility>
#include <omp.h>

#include <stdlib.h>
#include <stdio.h>

#include<fstream>
#include<time.h>

// headers from the boost library
#include <boost/math/distributions/normal.hpp>
#include <boost/math/distributions/students_t.hpp>
//#include <boost/math/special_functions/detail/t_distribution_inv.hpp>
#include <boost/math/tools/roots.hpp>
#include <boost/random.hpp>

// gsl library
//#include <stdio.h>
//#include <gsl/gsl_cdf.h>

#ifndef DBL_MAX
#define DBL_MAX 1.79769e+308
#endif

// User written headers
#include "VineCPP_helper.hpp"
#include "PC.hpp"
#include "PathToBoundsAndSeed.hpp"


#endif
