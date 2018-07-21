#include "int_seq_array.h"

#include <stdarg.h>
#include <stdlib.h>

status initialize(array* a, const int dim, ...)
{
    int total_element_count = 1, i = 0;
    va_list list;

    if(dim < 1 || dim > array_max_dim)
        return FAILED;

    a->_dim = dim;
    a->_bound = (int*)malloc(dim * sizeof(int));
    if(a->_bound == NULL)
        return FAILED;

    // assign boundary and get total element count of whole dimensionality.
    va_start(list, dim);
    for(i = 0; i < dim; ++i)
    {
        a->_bound[i] = va_arg(list, int);
        if(a->_bound < 0)
            return FAILED;
        
        total_element_count *= a->_bound[i];
    }
    va_end(list);

    // initialize data of array.
    a->_data = (type*)malloc(total_element_count * sizeof(type));
    if(a->_data == NULL)
        return FAILED;

    // initialize mapping address of array.
    a->_mapping = (int*)malloc(dim * sizeof(int));
    if(a->_mapping == NULL)
        return FAILED;

    a->_mapping[dim-1] = 1;
    for(i = dim-2; i >= 0; --i)
    {
        a->_mapping[i] = a->_bound[i+1] * a->_mapping[i+1];
    }

    return SUCCESS;
}

status destroy(array* a)
{
    // destroy data of array.
    if(a->_data == NULL)
        return FAILED;

    free(a->_data);
    a->_data = NULL;

    // destroy boundary of array.
    if(a->_bound == NULL)
        return FAILED;

    free(a->_bound);
    a->_bound = NULL;

    // destroy mapping address of array.
    if(a->_mapping == NULL)
        return FAILED;

    free(a->_mapping);
    a->_mapping = NULL;

    return SUCCESS;
}

status value_of(array a, type* e, ...)
{
    int offset = 0, i = 0, bound = 0;
    va_list list;

    // get mapping address of current array.
    va_start(list, e);
    for(i = 0; i < a._dim; ++i)
    {
        bound = va_arg(list, int);
        if(bound < 0 || bound > a._bound[i])
            return FAILED;
        offset += a._mapping[i] * bound;
    }

    *e = *(a._data + offset);
    return SUCCESS;
}

status assign(array* a, type e, ...)
{
    int offset = 0, i = 0, bound = 0;
    va_list list;

    // get mapping address of current array.
    va_start(list, e);
    for(i = 0; i < a->_dim; ++i)
    {
        bound = va_arg(list, int);
        if(bound < 0 || bound > a->_bound[i])
            return FAILED;

        offset += a->_mapping[i] * bound;
    }

    *(a->_data + offset) = e;
    return SUCCESS;
}