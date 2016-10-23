#include <string>
#include <vector>

using std::string;
using std::vector;

class MatchState{
public:
    int firstPattern;
    int lastPattern;

    int firstChr;
    int lastChr;

    MatchState(int _firstPattern, int _lastPattern, int _firstChr, int _lastChr)
        :firstPattern(_firstPattern), lastPattern(_lastPattern), firstChr(_firstChr), lastChr(_lastChr) {}
};
/*
	主要思路：将pattern以*号为分隔符进行拆分，再用KMP对每个子串进行匹配。
	TODO：超时。只能通过75%数据。
*/
class Solution {
private:
    vector<vector<int> > subPatternsNext;

public:
    /**
     * @param s: A string
     * @param p: A string includes "?" and "*"
     * @return: A boolean
     */
    int check(string &s, string &pat, int startPos){
        int res = 0;
        for(int i=0; i<pat.length()&&(startPos+i<s.length()); ++i){
            if(s[startPos+i]==pat[i]||pat[i]=='?') { res++; }
            else { break; }
        }

        return res;
    }

    int rcheck(string &s, string &pat, int startPos){
        int res = 0;
        for(int i=0; i<pat.length()&&(startPos-i>=0); ++i){
            if(s[startPos-i]==pat[pat.length()-1-i]||pat[pat.length()-1-i]=='?') { res++; }
            else { break; }
        }

        return res;
    }

    bool dfs(string &s, vector<string> &pats, MatchState &ms){
        if(ms.firstPattern<=ms.lastPattern){
            string &pat = pats[ms.firstPattern];

            // KMP
            vector<int> &next = subPatternsNext[ms.firstPattern];

            int i = ms.firstChr, j = 0;
            for(int k=ms.firstChr; k<=ms.lastChr; ){
                while(i<=ms.lastChr&&j<pat.length()&&(s[i]==pat[j]||pat[j]=='?')) { i++; j++; }
                if(j==pat.length()){
                    MatchState ms1(ms.firstPattern+1, ms.lastPattern, i, ms.lastChr);
                    bool res = dfs(s, pats, ms1);

                    if(res) { return true; }
                    else{
                        k += j-next[j-1];
                        j = next[j-1];
                    }
                }else if(j==0){
                    ++k;
                    ++i;
                }else{
                    k += j-next[j-1];
                    j = next[j-1];
                }
            }

            return false;
        }
        return true;
    }

    bool isMatch(const char *s, const char *p) {
        // write your code here
        string pattern(p);
        string str(s);

        if(!pattern.length()&&str.length()) { return false; }
        if(!pattern.length()&&!str.length()) { return true; }

        vector<string> subPatterns;

        int subPatternStartPos = 0, subPatternLen = 0;
        for(int i=0; i<pattern.length(); ++i){
            if(pattern[i]=='*'){
                string subPattern = pattern.substr(subPatternStartPos, subPatternLen);
                if(subPattern.length()){
                    subPatterns.push_back(subPattern);
                }
                subPatternStartPos = i+1;
                subPatternLen = 0;
            }else{
                subPatternLen++;
            }
        }

        if(pattern[pattern.length()-1]!='*'){
            string subPattern = pattern.substr(subPatternStartPos, subPatternLen);
            if(subPattern.length()){
                subPatterns.push_back(subPattern);
            }
        }

        int firstPattern = 0, lastPattern = subPatterns.size()-1;
        int firstChr = 0, lastChr = str.length()-1;
        if(pattern[0]!='*'){
            firstPattern++;
            string &pat = subPatterns[0];
            int num = check(str, pat, 0);
            if(num!=pat.length()||subPatterns.size()==1&&pattern[pattern.length()-1]!='*'&&num!=str.length()) { return false; }
            firstChr += num;
        }
        if(subPatterns.size()>1&&pattern[pattern.length()-1]!='*'){
            lastPattern--;
            string &pat = subPatterns[subPatterns.size()-1];
            int num = rcheck(str, pat, str.length()-1);
            if(num!=pat.length()) { return false; }
            lastChr -= num;
        }

        if(subPatterns.size()==2){
            int sumLen = 0;
            for(int i=0; i<subPatterns.size(); ++i) { sumLen += subPatterns[i].length(); }
            if(sumLen>str.length()) { return false; }
        }
        if(subPatterns.size()>2&&firstChr>lastChr) { return false; }

        // get next arrays of subPatterns
        for(int j=0; j<subPatterns.size(); ++j){
            subPatternsNext.push_back(vector<int>());
            string &pat = subPatterns[j];
            vector<int> &next = subPatternsNext[j];
            next.push_back(0);
            for(int i=1; i<pat.length(); ++i){
                int k = next[i-1];
                while(k!=0&&pat[i]!=pat[k]) { k = next[k-1]; }
                next.push_back(pat[i]==pat[k]?k+1:0);
            }
        }

        MatchState ms(firstPattern, lastPattern, firstChr, lastChr);

        return dfs(str, subPatterns, ms);
    }

};