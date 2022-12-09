/**
 * There is a buffer overflow vulnerability in the function.
 * The 'if' statement only checks if it is greater then 800 but not less then 0.
 * If pos is less then 0 it will try and index a negative index which will cause unexpected behavior. 
 * 
 * Additionally the code could potentially be susceptible to race conditions that access the global variable table.
*/

int table[800];
int insert_in_table(int val, int pos){
    if(pos > sizeof(table) / sizeof(int)){ // if int > 800 return -1
        return -1;
    }
    table[pos] = val; // table[800 or less] = val
    return 0; // EXIT_SUCCESS
}