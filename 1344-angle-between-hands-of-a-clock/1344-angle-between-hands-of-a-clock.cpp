class Solution {
public:
    double angleClock(int hour, int minutes) {
        double angle= abs( (60* hour - 11* minutes)/2.0);

        
        if(angle>180){
            return 360.0-angle;
        }
        return angle;

        // double h=0,m=0;
        // h= (30)*hour + (0.5)*minutes;
        // m= (6) *minutes;

        // return (abs(h-m)<=180)? abs(h-m): 360-abs(h-m);
    }
};