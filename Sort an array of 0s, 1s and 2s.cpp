// T.C = O(2n)
// S.C = O(1)
// First sort zeroes and then sort ones. Twos will be sorted automatically at the end.
void sort012(int a[], int n)
    {
        int i=0,j=0,count=0;
        // Focus on sorting only zeroes, and for that keep one pointer i at next ele of zero so that we can swap it later with any zero in array.
        // Traverse array using j pointer and keep incrementing it if we don't encounter zeroes.
        while(j<n){
            if (a[j] == 0){
                swap(a[i++],a[j++]);
                count++;
            }
            else{
                j++;
            }
        }
        // Now we need to traverse array from the index after last zero.
        i=count;
        j=count;
        // Now sort the ones, same as we did with zeroes.
        while(j<n){
            if (a[j] == 1){
                swap(a[i++],a[j++]);
            }
            else{
                j++;
            }
        }
    }

////////////////////////////////////////////////////////////////////////
// T.C = O(n)
// S.C = O(1)
// Using DNF algo.
class Solution
{
    public:
    void sort012(int a[], int n)
    {
        int zero=0, one=0, two=n-1;
        
        while (two>=one){
            if (a[one]==0){
                swap(a[one++], a[zero++]);
            }
            else if (a[one]==1){
                one++;
            }
            else{
                swap(a[one], a[two--]);
            }
        }
    }
    
};
