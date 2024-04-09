// T.C = O(n*n)
// S.C = O(1)
public:
void insert(int arr[], int i, int ele)
{
    int j = i-1, temp = ele;
    while(j>=0 and arr[j]>temp){
        arr[j+1] = arr[j];
        j--;
    }
    arr[j+1] = temp;
}

public:
void insertionSort(int arr[], int n)
{
    for (int i=1; i<n; i++){
        insert(arr, i, arr[i]);
    }
}
