// Problem Link: https://practice.geeksforgeeks.org/problems/maximum-number-of-toys/1
// GFG I'd: https://auth.geeksforgeeks.org/user/dilsekhpatnaik7

class Solution
{
public:
    int binary_search(long long l, long long h, int mid, long long target, vector<long long> &A) {
        while (l <= h) {
            mid = (l + h) / 2;
            if (A[mid] <= target)
                l = mid + 1;
            else
                h = mid - 1;
        }
        return l - 1;
    }
    vector<int> maximumToys(int N, vector<int> &B, int Q, vector<vector<int>> &q) {
        vector<long long> A(begin(B), end(B));
        sort(begin(A), end(A));
        for (int i = 1; i < N; i++)
            A[i] += A[i - 1];
        vector<int> ans;

        for (auto &x : q) {
            long long c = x[0];
            int idx = binary_search(0, N - 1, 0, c, A);
            int i = 2, k = x[1];
            if (idx == -1) {
                ans.push_back(0);
                continue;
            }

            priority_queue<int> pq;
            while (k--)
                pq.push(-B[x[i++] - 1]);
            c -= A[idx];
            idx++;
            while (!pq.empty()) {
                int a = -pq.top();
                pq.pop();
                long long last = 0;
                if (idx == 1)
                    last = A[0];
                else
                    last = A[idx - 1] - A[idx - 2];
                if (a > last) {
                    pq.push(0);
                    break;
                }

                c += a;
                while (idx < N && c >= A[idx] - A[idx - 1]) {
                    c -= (A[idx] - A[idx - 1]);
                    idx++;
                }
            }
            ans.push_back(idx - (x[1] - pq.size()));
        }
        return ans;
    }
};