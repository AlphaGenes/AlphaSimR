#include <R.h>
#include <Rinternals.h>
#include <stdlib.h> // for NULL
#include <R_ext/Rdynload.h>

/* .Call calls */
extern SEXP AlphaSimR_AlphaFormatter();
extern SEXP AlphaSimR_calcChrMinorFreq(SEXP, SEXP);
extern SEXP AlphaSimR_calcG(SEXP);
extern SEXP AlphaSimR_calcGenParam(SEXP, SEXP);
extern SEXP AlphaSimR_calcGIbs(SEXP);
extern SEXP AlphaSimR_calcPopGC(SEXP, SEXP, SEXP);
extern SEXP AlphaSimR_calcPopGIbsC(SEXP, SEXP, SEXP);
extern SEXP AlphaSimR_callRRBLUP(SEXP, SEXP, SEXP, SEXP, SEXP);
extern SEXP AlphaSimR_callRRBLUP_GCA(SEXP, SEXP, SEXP, SEXP, SEXP, SEXP);
extern SEXP AlphaSimR_callRRBLUP_MV(SEXP, SEXP, SEXP, SEXP, SEXP);
extern SEXP AlphaSimR_callRRBLUP_SCA(SEXP, SEXP, SEXP, SEXP, SEXP, SEXP);
extern SEXP AlphaSimR_convToImat(SEXP);
extern SEXP AlphaSimR_createDH2(SEXP, SEXP, SEXP);
extern SEXP AlphaSimR_cross2(SEXP, SEXP, SEXP, SEXP, SEXP);
extern SEXP AlphaSimR_crossPedigree(SEXP, SEXP, SEXP, SEXP);
extern SEXP AlphaSimR_fastDist(SEXP);
extern SEXP AlphaSimR_fastPairDist(SEXP, SEXP);
extern SEXP AlphaSimR_gaussKernel(SEXP, SEXP);
extern SEXP AlphaSimR_gebvGCA(SEXP, SEXP, SEXP);
extern SEXP AlphaSimR_gebvRR(SEXP, SEXP);
extern SEXP AlphaSimR_gebvSCA(SEXP, SEXP);
extern SEXP AlphaSimR_getDomGeno(SEXP);
extern SEXP AlphaSimR_getGeno(SEXP, SEXP, SEXP);
extern SEXP AlphaSimR_getGvA(SEXP, SEXP);
extern SEXP AlphaSimR_getGvAD(SEXP, SEXP);
extern SEXP AlphaSimR_getGvADG(SEXP, SEXP, SEXP);
extern SEXP AlphaSimR_getGvAG(SEXP, SEXP, SEXP);
extern SEXP AlphaSimR_getHaplo(SEXP, SEXP, SEXP);
extern SEXP AlphaSimR_getHybridGvA(SEXP, SEXP, SEXP, SEXP, SEXP);
extern SEXP AlphaSimR_getHybridGvAD(SEXP, SEXP, SEXP, SEXP, SEXP);
extern SEXP AlphaSimR_getHybridGvADG(SEXP, SEXP, SEXP, SEXP, SEXP, SEXP);
extern SEXP AlphaSimR_getHybridGvAG(SEXP, SEXP, SEXP, SEXP, SEXP, SEXP);
extern SEXP AlphaSimR_getOneHaplo(SEXP, SEXP, SEXP, SEXP);
extern SEXP AlphaSimR_mergeGeno(SEXP, SEXP);
extern SEXP AlphaSimR_popVar(SEXP);
extern SEXP AlphaSimR_readAF(SEXP, SEXP, SEXP, SEXP, SEXP);
extern SEXP AlphaSimR_sampAllComb(SEXP, SEXP, SEXP);
extern SEXP AlphaSimR_sampHalfDialComb(SEXP, SEXP);
extern SEXP AlphaSimR_solveMKM(SEXP, SEXP, SEXP, SEXP);
extern SEXP AlphaSimR_solveMVM(SEXP, SEXP, SEXP, SEXP, SEXP);
extern SEXP AlphaSimR_solveUVM(SEXP, SEXP, SEXP, SEXP);
extern SEXP AlphaSimR_tuneTraitA(SEXP, SEXP, SEXP);
extern SEXP AlphaSimR_tuneTraitAD(SEXP, SEXP, SEXP, SEXP);
extern SEXP AlphaSimR_writeASGenotypes(SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP);
extern SEXP AlphaSimR_writeASHaplotypes(SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP);

static const R_CallMethodDef CallEntries[] = {
  {"AlphaSimR_AlphaFormatter",    (DL_FUNC) &AlphaSimR_AlphaFormatter,    0},
  {"AlphaSimR_calcChrMinorFreq",  (DL_FUNC) &AlphaSimR_calcChrMinorFreq,  2},
  {"AlphaSimR_calcG",             (DL_FUNC) &AlphaSimR_calcG,             1},
  {"AlphaSimR_calcGenParam",      (DL_FUNC) &AlphaSimR_calcGenParam,      2},
  {"AlphaSimR_calcGIbs",          (DL_FUNC) &AlphaSimR_calcGIbs,          1},
  {"AlphaSimR_calcPopGC",         (DL_FUNC) &AlphaSimR_calcPopGC,         3},
  {"AlphaSimR_calcPopGIbsC",      (DL_FUNC) &AlphaSimR_calcPopGIbsC,      3},
  {"AlphaSimR_callRRBLUP",        (DL_FUNC) &AlphaSimR_callRRBLUP,        5},
  {"AlphaSimR_callRRBLUP_GCA",    (DL_FUNC) &AlphaSimR_callRRBLUP_GCA,    6},
  {"AlphaSimR_callRRBLUP_MV",     (DL_FUNC) &AlphaSimR_callRRBLUP_MV,     5},
  {"AlphaSimR_callRRBLUP_SCA",    (DL_FUNC) &AlphaSimR_callRRBLUP_SCA,    6},
  {"AlphaSimR_convToImat",        (DL_FUNC) &AlphaSimR_convToImat,        1},
  {"AlphaSimR_createDH2",         (DL_FUNC) &AlphaSimR_createDH2,         3},
  {"AlphaSimR_cross2",            (DL_FUNC) &AlphaSimR_cross2,            5},
  {"AlphaSimR_crossPedigree",     (DL_FUNC) &AlphaSimR_crossPedigree,     4},
  {"AlphaSimR_fastDist",          (DL_FUNC) &AlphaSimR_fastDist,          1},
  {"AlphaSimR_fastPairDist",      (DL_FUNC) &AlphaSimR_fastPairDist,      2},
  {"AlphaSimR_gaussKernel",       (DL_FUNC) &AlphaSimR_gaussKernel,       2},
  {"AlphaSimR_gebvGCA",           (DL_FUNC) &AlphaSimR_gebvGCA,           3},
  {"AlphaSimR_gebvRR",            (DL_FUNC) &AlphaSimR_gebvRR,            2},
  {"AlphaSimR_gebvSCA",           (DL_FUNC) &AlphaSimR_gebvSCA,           2},
  {"AlphaSimR_getDomGeno",        (DL_FUNC) &AlphaSimR_getDomGeno,        1},
  {"AlphaSimR_getGeno",           (DL_FUNC) &AlphaSimR_getGeno,           3},
  {"AlphaSimR_getGvA",            (DL_FUNC) &AlphaSimR_getGvA,            2},
  {"AlphaSimR_getGvAD",           (DL_FUNC) &AlphaSimR_getGvAD,           2},
  {"AlphaSimR_getGvADG",          (DL_FUNC) &AlphaSimR_getGvADG,          3},
  {"AlphaSimR_getGvAG",           (DL_FUNC) &AlphaSimR_getGvAG,           3},
  {"AlphaSimR_getHaplo",          (DL_FUNC) &AlphaSimR_getHaplo,          3},
  {"AlphaSimR_getHybridGvA",      (DL_FUNC) &AlphaSimR_getHybridGvA,      5},
  {"AlphaSimR_getHybridGvAD",     (DL_FUNC) &AlphaSimR_getHybridGvAD,     5},
  {"AlphaSimR_getHybridGvADG",    (DL_FUNC) &AlphaSimR_getHybridGvADG,    6},
  {"AlphaSimR_getHybridGvAG",     (DL_FUNC) &AlphaSimR_getHybridGvAG,     6},
  {"AlphaSimR_getOneHaplo",       (DL_FUNC) &AlphaSimR_getOneHaplo,       4},
  {"AlphaSimR_mergeGeno",         (DL_FUNC) &AlphaSimR_mergeGeno,         2},
  {"AlphaSimR_popVar",            (DL_FUNC) &AlphaSimR_popVar,            1},
  {"AlphaSimR_readAF",            (DL_FUNC) &AlphaSimR_readAF,            5},
  {"AlphaSimR_sampAllComb",       (DL_FUNC) &AlphaSimR_sampAllComb,       3},
  {"AlphaSimR_sampHalfDialComb",  (DL_FUNC) &AlphaSimR_sampHalfDialComb,  2},
  {"AlphaSimR_solveMKM",          (DL_FUNC) &AlphaSimR_solveMKM,          4},
  {"AlphaSimR_solveMVM",          (DL_FUNC) &AlphaSimR_solveMVM,          5},
  {"AlphaSimR_solveUVM",          (DL_FUNC) &AlphaSimR_solveUVM,          4},
  {"AlphaSimR_tuneTraitA",        (DL_FUNC) &AlphaSimR_tuneTraitA,        3},
  {"AlphaSimR_tuneTraitAD",       (DL_FUNC) &AlphaSimR_tuneTraitAD,       4},
  {"AlphaSimR_writeASGenotypes",  (DL_FUNC) &AlphaSimR_writeASGenotypes,  7},
  {"AlphaSimR_writeASHaplotypes", (DL_FUNC) &AlphaSimR_writeASHaplotypes, 7},
  {NULL, NULL, 0}
};

void R_init_AlphaSimR(DllInfo *dll)
{
  R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
  R_useDynamicSymbols(dll, FALSE);
}