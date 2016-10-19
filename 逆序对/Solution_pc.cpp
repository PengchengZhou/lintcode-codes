class Solution {
public:
    /**
     * @param A an array
     * @return total of reverse pairs
     */
    long long cnt;
    
    // ��״����ķ������������������ƣ�ֻ��Ϊ�������ҷ�Χ����̫��
    // �ʲ������ù鲢������������
    void mergeSort(vector<int> &a, int l, int r){
        if(l>=r){
            return;
        }
        
        int m = (l+r)/2;
        
        mergeSort(a, l, m);
        mergeSort(a, m+1, r);
        
        vector<int> a1, a2;
        for(int i=l; i<=m; ++i){
            a1.push_back(a[i]);
        }
        for(int i=m+1; i<=r; ++i){
            a2.push_back(a[i]);
        }
        
        int j = l, k = m+1, i = l;
        while(j<=m&&k<=r){
            if(a1[j-l]<=a2[k-m-1]){
                a[i++] = a1[(j++)-l];
            }else{
                // a1[j]>a2[k], ��ôa1[j...m]������a2[k]
                // ����cnt += m-j+1
                a[i++] = a2[(k++)-m-1];
                cnt += m-j+1;
            }
        }
        
        while(j<=m){
            a[i++] = a1[(j++)-l];
        }
        while(k<=r){
            a[i++] = a2[(k++)-m-1];
        }
    }
    
    long long reversePairs(vector<int>& a) {
        // Write your code here
        cnt = 0;
        
        mergeSort(a, 0, a.size()-1);
        
        return cnt;
    }
};