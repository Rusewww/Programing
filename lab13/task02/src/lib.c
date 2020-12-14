//
// Created by Rusewww on 12/13/20.
//

int deleteRepeat(char** arr,int size){
        for(int i = 0; i < size; i++){
                for(int j = i + 1; j < size; j++){
                        if(! strcmp(arr[j], arr[i])){
                                free(arr[j]);
                                arr[j] = arr[--size];
                                j--;
                        }
                }
        }
        return (size);
}
