#include <stack>

using std::stack;

struct Strip
{
    // 横纵坐标
    int x, y;
    Strip(int _x, int _y){x = _x; y = _y;}
};

class Solution {
public:
    /**
     * @param height: A list of integer
     * @return: The area of largest rectangle in the histogram
     */
    int largestRectangleArea(vector<int> &h) {
        // write your code here
        int n = h.size();
        if(!n)  return 0;
        
        int res = 0;
        
        h.push_back(0);
        stack<Strip> s;
        
        for(int i=0; i<=n; ++i)
        {
            if(s.empty())
            {
                s.push(Strip(i, h[i]));
            }
            else
            {
                Strip *top = &s.top();
                if(h[i]>=top->y)
                {
                    s.push(Strip(i, h[i]));
                }
                else
                {
                    int x = top->x;
                    while(!s.empty())
                    {
                        top = &s.top();
                        if(h[i]>=top->y) break;
                        int tmp = (i-top->x)*top->y;
                        res = tmp>res?tmp:res;
                        x = top->x;
                        s.pop();
                    }
                    
                    // 这里push的是(x, h[i])而不是(i, h[i])，关键就在这里
                    s.push(Strip(x, h[i]));
                }
            }
            
        }
        
        return res;
    }
};
