// Problem Link: https://practice.geeksforgeeks.org/problems/convert-an-array-to-reduced-form1101/1
// GFG I'd: https://auth.geeksforgeeks.org/user/dilsekhpatnaik7

class Solution{
public:
	void convert(int arr[], int n) {
	    vector<int> v(arr, arr + n);
	    sort(begin(v), end(v));
	    unordered_map<int, int> m;
	    for(int i = 0; i < v.size(); i++){
	        m[v[i]] = i;
	    }
	    for(int i = 0; i < n; i++){
	        arr[i] = m[arr[i]];
	    }
	}
};