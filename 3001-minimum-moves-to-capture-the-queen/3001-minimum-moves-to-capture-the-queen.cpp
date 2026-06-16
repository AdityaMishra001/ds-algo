class Solution {
public:
    bool isBetweenLine(int a,int b,int c){
        return (a-b)*(c-b)<0;
    }
    bool isBetweenDiag(int a,int b,int c,int d,int e,int f){
        //a->row and b->col are in between
        return isBetweenLine(c,a,e)&&isBetweenLine(d,b,f);
        //check both row and col wise 
    }
    int minMovesToCaptureTheQueen(int a, int b, int c, int d, int e, int f) {
        //same col rook
        //if same col bishop check for in between case for row
        if( (b==f) && (b!=d || !isBetweenLine(a,c,e)) ) 
            return 1;
        //same row rook
        if( (a==e) && (a!=c || !isBetweenLine(b,d,f)) )
            return 1;
        

        //same diagonl bishop

        if((e+f == c+d)&& (c+d!=a+b || !isBetweenDiag(a,b,c,d,e,f)) )
            return 1;
        if(( 7+f-e==7+d-c)&& (7+d-c!=7+b-a||!isBetweenDiag(a,b,c,d,e,f)) )
            return 1;
        return 2;
    }
};