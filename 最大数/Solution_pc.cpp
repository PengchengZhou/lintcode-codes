// �����ݽ�������Ȼ���������ӣ����ȥ��ǰ������0����
// �ؼ����������ʱ�����ȷ�����������Ⱥ���λ�Ƚϣ�ֱ���Ƚϳ���С������������ÿһλ���ȽϽ���

struct cmp{
    bool operator()(int a, int b){
        char sa[11], sb[11];
        sprintf(sa, "%d", a);
        sprintf(sb, "%d", b);
        int i=0, j=0;
        while(true){
            if(sa[i]=='\0'&&sb[j]=='\0'){
                return false;
            }else if(sa[i]=='\0'){
                i = 0;
            }else if(sb[j]=='\0'){
                j = 0;
            }else{
                if(sa[i]!=sb[j]){
                    return sa[i]>sb[j];
                }else{
                    i++;
                    j++;
                }
            }
        }
    }
}myCmp;

class Solution {
public:
    /**
     *@param num: A list of non negative integers
     *@return: A string
     */
    string largestNumber(vector<int> &nums) {
        // write your code here
        string res = "";
        char buf[11];
        
        sort(nums.begin(), nums.end(), myCmp);
        
        for(int i=0; i<nums.size(); ++i){
            sprintf(buf, "%d", nums[i]);
            res.append(buf);
        }
        
        int j = 0;
        
        for(int i=0; i<res.size()-1; ++i){
            if(res[i]=='0'){
                j++;
            }else{
                break;
            }
        }
        
        return res.substr(j);
    }
};