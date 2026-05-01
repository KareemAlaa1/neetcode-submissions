class Solution {
public:
    double findMedianSortedArrays(vector<int>& A, vector<int>& B) {
        if (A.size() > B.size())
            return findMedianSortedArrays(B, A);

        int total = A.size() + B.size();
        int half = total / 2;

        int l = 0, r = A.size() - 1;

        while (true) {
            int i = (l <= r) ? (l + r) / 2 : -1;
            int j = half - i - 2;

            int Aleft  = (i >= 0) ? A[i] : INT_MIN;
            int Aright = (i + 1 < A.size()) ? A[i + 1] : INT_MAX;
            int Bleft  = (j >= 0) ? B[j] : INT_MIN;
            int Bright = (j + 1 < B.size()) ? B[j + 1] : INT_MAX;

            if (Aleft <= Bright && Bleft <= Aright) {
                if (total % 2) {
                    return min(Aright, Bright);
                } else {
                    return (max(Aleft, Bleft) + min(Aright, Bright)) / 2.0;
                }
            }
            else if (Aleft > Bright) {
                r = i - 1;
            }
            else {
                l = i + 1;
            }
        }
    }
};