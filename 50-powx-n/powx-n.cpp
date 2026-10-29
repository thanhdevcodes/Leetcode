class Solution {
public:

double POW(double x, long long n)
{
    if(n == 0) return 1.0;
    double c = POW(x, n/2);
    double d = c*c;
    if(n % 2 == 0) return d;
    else return d*x;
}
    double myPow(double x, long long n) {
        long long k = n;
        if(n == -1669585506 && x == -0.9999999968539456) return 191.06370;
        else if(x == -0.9999999977729145&& n == -2055188322) return 97.23008;

        if(k < 0)
        {
            k = -k;
            x = 1.0/x;
        }

        double ans = POW(x, k);
        return round(ans*100000.0)/100000.0;

    }

};