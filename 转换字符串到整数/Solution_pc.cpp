class Solution {
public:
    /**
     * @param str: A string
     * @return An integer
     */
    int atoi(string str) {
        // write your code here
        bool isNegative = false;
        int pos = 0;
        
        int r = str.length()-1;
        while(str[r]==' '){
            r--;
        }
        int l = 0;
        while(str[l]==' '){
            l++;
        }
        str = str.substr(l, r+1);

        if(str[0]=='-'){
            isNegative = true;
        }
        if(str[0]=='+'||str[0]=='-'){
            pos++;
        }

        while(str[pos]=='0'){
            pos++;
        }

        if(str[pos]=='.'||str[pos]<'0'||str[pos]>'9'){
            return 0;
        }else{
            str = str.substr(pos);
            pos = 0;
            int ans = 0;
            while(str[pos]>='0'&&str[pos]<='9'){
                if(ans<=214748364)  ans *= 10;
                else{
                    ans = 2147483647;
                    break;
                }
                if(!isNegative&&ans==2147483640&&str[pos]>='7'){
                    ans = 2147483647;
                    break;
                }
                if(isNegative&&ans==2147483640&&str[pos]>='8'){
                    ans = -2147483648;
                    break;
                }
                ans += str[pos]-'0';
                pos++;
            }
            if(pos<str.length()){
                if(ans==2147483647){
                    while(pos<str.length()){
                        if(str[pos]>='0'&&str[pos]<='9'){
                            pos++;
                        }else if(str[pos]=='.'){
                            pos++;
                            while(pos<str.length()){
                                if(str[pos]!='0'){
                                    return 0;
                                }
                            }
                        }else{
                            return 0;
                        }
                    }
                }else if(str[pos]=='.'){
                    pos++;
                    while(pos<str.length()){
                        if(str[pos]!='0'){
                            return 0;
                        }
                        pos++;
                    }
                }else{
                    //return 0;
                }

            }
            
            return isNegative&&ans!=-2147483648?-ans:ans;
        }
    }
};