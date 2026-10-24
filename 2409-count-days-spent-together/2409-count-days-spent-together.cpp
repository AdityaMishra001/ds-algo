class Solution {
    inline static vector<int>cal_days={ 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};
public:
    int days(const string& s){
        int m=(s[0]-'0') *10 + (s[1]-'0');
        int d=(s[3]-'0') *10 + (s[4]-'0');
        return cal_days[m-1]+d;
    }
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        int a1=days(arriveAlice);
        int a2=days(leaveAlice);
        int b1=days(arriveBob);
        int b2=days(leaveBob);

        return max(0, min(a2,b2)-max(a1,b1)+1);
        
    }
};