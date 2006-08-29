#ifndef _SimTK_SIMMATH_H_
#define _SimTK_SIMMATH_H_

/* Portions copyright (c) 2006 Stanford University and Jack Middleton.
 * Contributors:
 *
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files (the
 * "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sublicense, and/or sell copies of the Software, and to
 * permit persons to whom the Software is furnished to do so, subject
 * to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included
 * in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 * IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
 * CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
 * TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
 * SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */
typedef void* smHandle; 
typedef int  smStatus;

enum { 	OPTIMIZER, ROOT_FINDER };
enum { LBFGS, POWELL, GRADIENT_DESENT };
enum { SUCCESS, MALLOC_FAILED, UNKNOWN_OPTIMIZER, UNKNOWN_PARAMETER, INVALID_VALUE };
enum { TRACE, MAX_FUNCTION_EVALUATIONS, DEFAULT_STEP_LENGTH, LINE_SEARCH_ACCURACY, GRADIENT_CONVERGENCE_TOLERANCE };

#ifdef __cplusplus
namespace SimTK {
class smObject {
   public:
    void *data;
};

} //  namespace SimTK

extern "C" {
#endif

extern smHandle smMallocOptimizer(int, smStatus*);
extern smStatus smDumpOptimizerState( smHandle);
extern smStatus smSetOptimizerParameters( smHandle, unsigned int, double*);
extern smStatus smGetOptimizerParameters( smHandle, unsigned int, double*);
extern smStatus smSetCostFunction( smHandle, void (*costFunction)(int, double*,double*,double*, void*) );
extern smStatus smRunOptimizer( smHandle, double * );
extern void     smFreeOptimizer( smHandle );

#ifdef __cplusplus
}  /* extern "C" */

#endif


#endif //_SimTK_SIMMATH_H_
