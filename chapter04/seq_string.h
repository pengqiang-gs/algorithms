#ifndef ADT_SEQ_STRING_H
#define ADT_SEQ_STRING_H

typedef int status;
typedef int position;
typedef int length;

typedef struct {
	char* _data;		// string content data.
	int _size;			// string content size.
}string;

#define string_init_size      10
#define string_increase_size  10

#ifndef TRUE
#define TRUE 1
#endif

#ifndef FALSE
#define FALSE 0
#endif

#ifndef SUCCESS
#define SUCCESS 0
#endif

#ifndef FAILED
#define FAILED -1
#endif

#ifdef NOT_FOUND
#define NOT_FOUND -1
#endif

// method: initialize a sequential string. 
// input : the address of string instance.
// return: return SUCCESS if succeed, otherwise return FAILED.
status init_string(string* s, const char* src);

// method: destroy a sequential string and free the element storage space.
// input : the address of string instance.
// return: return SUCCESS if succeed, otherwise return FAILED.
status destroy_string(string* s);

// method: clear the elements of sequential string, the size of string will be 0.
// input : the address of string instance.
// return: return SUCCESS if succeed, otherwise return FAILED.
status clear_string(string* s);

// method: copy the string to other.
// input : the address of dest string instance, the src string object.
// return: return SUCCESS if succeed, otherwise return FAILED.
status copy_string(string* t, string s);

// method: check the sequential string is empty or not.
// input : the string object.
// return: return TRUE if the string is empty, otherwise return FALSE.
int is_empty(string s);

// method: compare two string.
// input : the string object t, the string object s.
// return: return 1 if the string object t > s, return 0 if t = s, otherwise return -1.
int string_compare(string t, string s);

// method: obtain the element count of sequential string.
// input : the string object.
// return: the element count of string.
int string_size(string s);

// method: concat string s1 and s2 into string t.
// input : the address of dest string instance, the concated string object s1, s2.
// return: return SUCCESS if succeed, otherwise return FAILED.
status string_concat(string* t, string s1, string s2);

// method: concat string s1 and s2 into string t.
// input : the address of dest string instance, the concated string object s1, s2.
// return: return SUCCESS if succeed, otherwise return FAILED.
status string_sub(string* t, string s, position p, length l);

// method: find string t from string s begin position p.
// input : the src string object, the found string t, start position p.
// return: return specific position if found, otherwise return NOT_FOUND.
position string_find(string s, string t, position p);

// method: replace string t from string s to string v.
// input : the src string s, the replaced string t, the replace string v.
// return: return SUCCESS if succeed, otherwise return FAILED.
status string_replace(string* s, string t, string v);

// method: insert string t from position p into string s.
// input : the inserted string s, the inserted position p, the insert string t.
// return: return SUCCESS if succeed, otherwise return FAILED.
status string_insert(string* s, position p, string t);

// method: delete length l from string s start at position p.
// input : the deleted string s, the deleted position p, the deleted length l.
// return: return SUCCESS if succeed, otherwise return FAILED.
status string_delete(string* s, position p, length l);

// method: calculate the algorithm KMP next array.
// input : the matched string s, the next array that will be output.
// return: void
void kmp_next(string s, int* next);
#endif
