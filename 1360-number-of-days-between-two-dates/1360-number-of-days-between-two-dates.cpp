class Solution {
    static inline vector<int> monthDays=
    {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};
public:
    static bool is_leap(const int &y){
        if(y%400==0)return 1;
        if(y%100==0)return 0;
        return (y%4==0);
    }
    int f(const string &date){
        int y=stoi(date.substr(0,4));
        int m=stoi(date.substr(5,2));
        int d=stoi(date.substr(8,2));
        int days=monthDays[m-1]+d+(m>2&&is_leap(y))+
        (y-1-1900)*365+ (y-1)/4-(y-1)/100+(y-1)/400;
        return days;
    }
    int daysBetweenDates(const string &date1,const  string &date2) {
        if(date1==date2)return 0;
        return abs(f(date1)-f(date2));
    }
};