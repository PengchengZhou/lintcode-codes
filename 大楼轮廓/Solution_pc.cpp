#define MAXN 1000005
#define INF 0x7fffffff


// 线段树节点
struct SegNode
{
    // value记录区间当前的最大值
    int left, right, value;
    // 懒标记
    bool lazy;
};

// 线段树
struct SegTree
{
    SegNode t[MAXN<<2];
    
    // 初始化，建树
    void build(int i, int l, int r)
    {
        t[i].left = l;
        t[i].right = r;
        t[i].value = 0;
        t[i].lazy = false;
        if(l<r)
        {
            int m = (l+r)>>1;
            build(i<<1, l, m);
            build(i<<1|1, m+1, r);
        }
    }
    
    // 查询点
    int query(int i, int x)
    {
        if(t[i].lazy) pushdown(i);
        if(t[i].left==t[i].right)   return t[i].value;
        int m = (t[i].left+t[i].right)>>1;
        return x<=m?query(i<<1, x):query(i<<1|1, x);
    }
    
    // 更新区间
    void update(int i, int l, int r, int v)
    {
        if(t[i].lazy) pushdown(i);
        if(t[i].left==l&&t[i].right==r)
        {
            if(v>t[i].value)
            {
                t[i].value = v;
                t[i].lazy = true;
            }
        }
        else
        {
            int m = (t[i].left+t[i].right)>>1;
            if(l>m) update(i<<1|1, l, r, v);
            else if(r<=m) update(i<<1, l, r, v);
            else
            {
                update(i<<1, l, m, v);
                update(i<<1|1, m+1, r, v);
            }
        }
    }
    
    // 传递懒标记
    void pushdown(int i)
    {
        t[i].lazy = false;
        if(t[i].left<t[i].right)
        {
            if(t[i].value>t[i<<1].value)
            {
                t[i<<1].value = t[i].value;
                t[i<<1].lazy = true;
            }
            if(t[i].value>t[i<<1|1].value)
            {
                t[i<<1|1].value = t[i].value;
                t[i<<1|1].lazy = true;
            }
        }
    }
}tree;

class Solution {
public:
    /**
     * @param buildings: A list of lists of integers
     * @return: Find the outline of those buildings
     */
    vector<vector<int> > buildingOutline(vector<vector<int> > &buildings) {
        // write your code here
        int max_x = 0, min_x = INF;
        int n = buildings.size();
        for(int i=0; i<n; ++i)
        {
            if(buildings[i][1]>max_x)   max_x = buildings[i][1];
            if(buildings[i][0]<min_x)   min_x = buildings[i][0];
        }
        
        int offset = 0;
        if(min_x<=0)
        {
            offset = 1-min_x;
            min_x = 1;
            max_x += offset;
        }
        
        tree.build(1, 1, max_x<<1);
        
        for(int i=0; i<n; ++i)
            tree.update(1, (buildings[i][0]+offset)<<1, (buildings[i][1]+offset)<<1, buildings[i][2]);
        
        int x1, x2, val;
        
        x1 = min_x<<1;
        val = tree.query(1, min_x);
        
        vector<vector<int> > ret;
        
        for(int i=(min_x<<1)+1; i<=(max_x<<1); ++i)
        {
            int tmpval = tree.query(1, i);
            if(tmpval!=val)
            {
                if(val!=0)
                {
                    vector<int> vec;
                    vec.push_back((x1>>1)-offset);
                    vec.push_back((i>>1)-offset);
                    vec.push_back(val);
                
                    ret.push_back(vec);
                }
                x1 = i;
                val = tmpval;
            }
        }
        
        if(val!=0)
        {
            vector<int> vec;
            vec.push_back((x1>>1)-offset);
            vec.push_back(max_x-offset);
            vec.push_back(val);
                
            ret.push_back(vec);
        }
        
        return ret;
    }
};