 #include<stdio.h>

//Function to merge two subarrays
void merge(int arr[],int left,int mid,int right){
	
	int i,j,k;
	int n1 = mid - left +1;
	int n2 = right - mid;
	
	int L[n1],R[n2];
	
	for(i = 0;i<n1;i++){
		L[i] = arr[left + i];
	}
	
	//copy data 
	for(j=0;j<n2;j++){
	  R[j] = arr[mid + 1 +j];
}
	 //merge the temp arrays back into arr[]
	 i = 0;
	 j = 0;
	 k = left;
	 
	 while(i < n1 && j < n2){
	 	if(L[i] <= R[j]){
	 		arr[k] = L[i];
	 		i++;
		 }else{
		 	arr[k] = R[j];
		 	j++;
		 }
	 k++;
}

	//copy remaining elements of L[],if any
	while(i < n1){
		arr[k] = L[i];
		i++;
		k++;
	}
	
	// coping remaining elements of R[] , if any
	while(j < n2){
		arr[k] = R[j];
		j++;
		k++;
	}
}
    
    //merge sort function
void mergeSort(int arr[] , int left , int right){
	if(left < right){
		int mid = left + (right - left)/2;
		
		mergeSort(arr,left,mid); // sort first half
		mergeSort(arr,mid+1,right); // sort second half
		
		merge(arr,left,mid,right); // merge the sorted halves
	}
}

int main(){
	int n,i;
	int arr[100];
  	
  	printf("Enter number of elements: ");
  	scanf("%d",&n);
  	
  	printf("Enter %d element:\n",n);
  	for(i =0;i<n;i++);
  	    scanf("%d",&arr[i]);
  	    
  	mergeSort(arr,0,n - 1);    

   printf("Sorted array:\n");
   for(i=0;i<n;i++)
      printf("%d",arr[i]);
      
      return 0;
}


