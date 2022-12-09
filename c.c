/**
 * The myfunction function is susceptible to a memory leak because myarray is never freed after it is used.
 * Overtime if myfunction is continuously called this would lead to the heap being full leading to segmentation faults
 * or other unexpected behaviors.
*/

int myfunction(int *array, int len){
    int *myarray, i;
    myarray = malloc(len * sizeof(int));
    if(myarray == NULL){
        return -1;
    }
    for(i = 0; i < len; i++){
        myarray[i] = array[i];
    }

    return myarray;
}