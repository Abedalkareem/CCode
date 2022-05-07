//
//  profiling.c
//  CCode
//
//  Created by abedalkareem omreyh on 07/05/2022.
//

#include "profiling.h"

// profiling (dynamic analysis) is a form of dynamic program analysis that measures:
// - space (memory)
// - time complexity off a program (efficiency)
// - usage of particular instrctions
// - the frequency and duration of function calls

// tools for profiling: gprof, valgrind.
// to check for memory leaks:
// $ valgrind --leak-check=yes ./test
