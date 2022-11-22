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