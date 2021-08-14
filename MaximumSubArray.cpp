// Find out the maximum sub-array of non negative numbers from an array.

// The sub-array should be contiguous i.e., a sub-array created by choosing the second and fourth element and skipping the third element is invalid.

// Maximum sub-array is defined in terms of the sum of the elements in the sub-array. Sub-array A is greater than sub-array B if sum(A) > sum(B).

// Example:
// A : [1, 2, 5, -7, 2, 3]
// The two sub-arrays are [1, 2, 5] [2, 3].
// The answer is [1, 2, 5] as its sum is larger than [2, 3]

// this algorithm computes the solution in O(n) time


class Solution{
public:
    
	vector<int> findSubarray(int a[], int n) {
	    // code here
	    int m1 = 0;
	    int begin, end, count, i=0, m2;
	    
	    while(a[i] >= 0 && i<n){
	        m1 += a[i];
	        i++;
	    }
	    
	    
	    end = i;
	    begin = 0;
	    m2 = 0;
	    
	    for(i; i<n; i++){
	        if(a[i] < 0)
	            continue;
	        count = 0;
	        m2 = 0;
	        while(a[i] >= 0 && i<n){
	            m2 += a[i];
	            count++;
	            i++;
	        }
	        
	        if(m2 > m1 || m2 == m1 && end - begin < i - count){
	            m1 = m2;
	            end = i;
	            begin = i - count;
	        }
	        
	    }
	    
	   // cout << "begin = " << begin << " end = " << end << endl;
	    
	    vector<int> v;
	    if(m1 == 0 && m2 == 0)
	   {
	       v.push_back(-1);
	       return v;
	   }

	    for(int i=begin; i<end; i++){
	        v.push_back(a[i]);
	    }
	    
	    return v;
	}
};





