#include <iostream>
using namespace std;

int duplicate(int[], int);
void show(int);

void merge(int [], int ,int);
void merge_sort(int[] ,int ,int ,int );

int main()
{
    int T;
    cout << "Enter number of test cases : ";
    cin >> T;

    while (T-- > 0)
    {
        int n;
        cout << "Enter the number elements : ";
        
        cin >> n;
        int arr[n];

        cout<<"Enter the element : "<<endl;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        merge(arr, 0, n);
        
        int dp = duplicate(arr, n);
        show(dp);
    }
}

int duplicate(int arr[], int n)
{
    int f = 0;
    for (int i = 0; i < n - 1; i++)
    {
            if (arr[i]==arr[i+1])
            {
                f=1;
            }
        if(f==1)
           break;
    }
    return f;
}

void show(int dp)
{
    if(dp == 1)
       cout<<"YES"<<endl;
    else
       cout<<"NO"<<endl;
}

void merge(int arr[], int l,int r)
{
    if(l<r)
    {
        int mid = l + (r - l)/2;
        merge(arr,l,mid);
        merge(arr,mid+1,r);
        merge_sort(arr,l,mid,r);
    }
}

void merge_sort(int arr[],int l,int m,int r)
{
    int n1 = m - l+1;
    int n2 = r-m;

    int L[n1],R[n2];

    for(int i =0;i<n1;i++)
        L[i]=arr[l+i];
    for(int j = 0;j<n2;j++)
        R[j]=arr[m+j+1];

    int i=0,j=0,k=l;

    while(i<n1&&j<n2)
    {
        if(L[i]<R[j])
            arr[k++] = L[i++];
        else 
            arr[k++] = R[j++];
    }

    while(i<n1)
        arr[k++] = L[i++];

    while(j<n2)
        arr[k++] = R[j++];
}