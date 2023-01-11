void swap(int& x, int& y){
    
    int temp = x;
    x = y;
    y = temp;
}

int partition(int arr[], int start, int end){
    
    int pivot = arr[start], i = start, j = end;
    
    while (i <= j){
        
        while (arr[i] <= pivot)
            i++;
        while (arr[j] > pivot)
            j--;
            
        if (i < j)
            swap(arr[i], arr[j]);
    }
    
    swap(arr[j], arr[start]);
    
    return j;
}

void QuickSort(int arr[], int start, int end){
    
    if (start >= end)
        return;
        
    int pivot = partition(arr, start, end);
    
    QuickSort(arr, start, pivot);
    QuickSort(arr, pivot + 1, end);
}

void Merge(int arr[], int start, int Mid, int end){
    
    int* subarr1 = new int[Mid - start + 1];
    int* subarr2 = new int[end - Mid];
    
    for (int i = 0; i < Mid - start + 1; i++)
        subarr1[i] = arr[start + i];
        
    for (int i = 0; i < end - Mid; i++)
        subarr2[i] = arr[Mid + 1 + i];
        
    int i = 0, j = 0, curr = start;
    while (i < Mid - start + 1 && j < end - Mid){
        
        if (subarr1[i] < subarr2[j]){
            
            arr[curr] = subarr1[i];
            i++;
        }
        
        else{
            
            arr[curr] = subarr2[j];
            j++;
        }
        
        curr++;
    }
    
    while (i < Mid - start + 1){
        
        arr[curr] = subarr1[i];
        i++;
        curr++;
    }
    
    while (j < end - Mid){
        
        arr[curr] = subarr2[j];
        j++;
        curr++;
    }
}

void MergeSort(int arr[], int start, int end){
    
    if (start >= end)
        return;
        
    int Mid = (end + start)/2;
    
    MergeSort(arr, start, Mid);
    MergeSort(arr, Mid + 1, end);
    
    Merge(arr, start, Mid, end);
}