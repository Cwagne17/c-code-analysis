/**
 * if pos = 800 it will try to insert table[800] which will cause index out of bound
 * if pos < 0 then an error will occur trying to index with a negative value
*/

int table[800];
int insert_in_table(int val, int pos){
    if(pos > sizeof(table) / sizeof(int)){ // if int > 800 return -1
        return -1;
    }
    table[pos] = val; // table[800 or less] = int
    return 0; // EXIT_SUCCESS
}