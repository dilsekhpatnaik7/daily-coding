// Problem Link: https://practice.geeksforgeeks.org/problems/d54c71dc974b7db3a200eb63f34e3d1cba955d86/1

class Solution {
public:
    long long maxTripletProduct(long long arr[], int n) {
        long long largest = LLONG_MIN, slargest = LLONG_MIN, tlargest = LLONG_MIN;
        long long smallest = LLONG_MAX, ssmallest = LLONG_MAX;
        
        for (int i = 0; i < n; i++) {
            long long el = arr[i];

            if (el > largest) {
                tlargest = slargest;
                slargest = largest;
                largest = el;
            } else if (el > slargest) {
                tlargest = slargest;
                slargest = el;
            } else if (el > tlargest) {
                tlargest = el;
            }

            if (el < smallest) {
                ssmallest = smallest;
                smallest = el;
            } else if (el < ssmallest) {
                ssmallest = el;
            }
        }

        if (smallest != LLONG_MAX && ssmallest != LLONG_MAX) {
            return max(smallest * ssmallest * largest, largest * slargest * tlargest);
        }
        return largest * slargest * tlargest;
    }
};