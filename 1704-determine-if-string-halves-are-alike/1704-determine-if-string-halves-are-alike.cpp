class Solution {
public:
    bool halvesAreAlike(string s) {
        if(s.size()&1){return false;}
		string p1=s.substr(0, s.size()/2), p2=s.substr(s.size()/2, s.size()/2);
		int cnt1=0, cnt2=0;
		for(int i=0; i<p1.size(); i++){
			if(p1[i]=='a' || p1[i]=='e' || p1[i]=='i' || p1[i]=='o' || p1[i]=='u' || p1[i]=='A' || p1[i]=='E' || p1[i]=='I' || p1[i]=='O' || p1[i]=='U'){cnt1++;}
		}
		for(int i=0; i<p2.size(); i++){
			if(p2[i]=='a' || p2[i]=='e' || p2[i]=='i' || p2[i]=='o' || p2[i]=='u' || p2[i]=='A' || p2[i]=='E' || p2[i]=='I' || p2[i]=='O' || p2[i]=='U'){cnt2++;}
		}
		return cnt1==cnt2;
    }
};