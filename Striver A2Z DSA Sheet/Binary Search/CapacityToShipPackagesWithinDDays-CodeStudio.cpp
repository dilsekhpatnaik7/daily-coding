// Problem Link: https://www.codingninjas.com/studio/problems/capacity-to-ship-packages-within-d-days_1229379?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTab=0

bool shipDays(const vector<int>& weights, long long shipCapacity, int days) {
    int calculatingDays = 1, capacity = 0;
    for(const int weight : weights) {
        if(capacity + weight > shipCapacity) {
            ++calculatingDays;
            capacity = weight;
        }
        else capacity += weight;
        if(calculatingDays > days) return false;
    }
    return true;
}

int leastWeightCapacity(vector<int> &weights, int d) {
    int low = *max_element(weights.begin(), weights.end());
    int high = accumulate(begin(weights), end(weights), 0);
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if(shipDays(weights, mid, d)) high = mid - 1;
        else low = mid + 1;
    }
    return low;
}