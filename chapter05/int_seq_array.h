#ifndef ADT_INT_SEQ_ARRAY
#define ADT_INT_SEQ_ARRAY

#define array_max_dim 8

typedef int type;
typedef struct 
{
    // the whole data of array.
    type* _data;

    // the demensionality of array.
    int _dim;

    // the boundary of each demensionalities.
    int* _bound;

    // the mapping address of array for each demensionalities.
    // formula: 
    //   LOC(s1, ..., sn) = LOC(0, ..., 0) + (b2 * ... * bn * s1 +
    //   b3 * ... * bn * s2 + ... + bn * s(n-1) + sn);
    // LOC(0, ..., 0) is base address of array with n demensionalities.
    // sample:
    //   array with 1 demensionality.
    //   LOC(s1) = LOC(0) + s1.
    //   array with 2 demensionalities.
    //   LOC(s1, s2) = LOC(0, 0) + (b * s1) + s2.
    int* _mapping;
}array;

typedef int status;

#ifndef SUCCESS
#define SUCCESS 0
#endif

#ifndef FAILED
#define FAILED -1
#endif

// method: initialize a array which has dim demensionalities and indefinite boundary 
//           of each demensionality.
// input : the address of array instance, the count of dememsionalities, ...
// return: return SUCCESS if succeed, otherwise return FAILED.
status initialize(array* a, const int dim, ...);

// method: destroy a array.
// input : the address of array instance.
// return: return SUCCESS if succeed, otherwise return FAILED.
status destroy(array* a);

// method: get the value of array in specific demensionality(indicated by indefinite 
//          parameters.).
// input : the array instance, the address of value, ...
// return: return SUCCCESS if succeed, otherwise return FAILED.
status value_of(array a, type* e, ...);

// method: assign the value of array in specific demensionality(indicated by indefinite
//          parameters.).
// input : the address of array instance, the assigned value, ...
// return: return SUCCESS if succeed, otherwise return FAILED.
status assign(array* a, type e, ...);

#endif