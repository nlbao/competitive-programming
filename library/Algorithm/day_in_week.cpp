const int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const int months[12] = {0, 3, 3, 6, 1, 4, 6, 2, 5, 0, 3, 5};
const int months_leap[12] = {6, 2, 3, 6, 1, 4, 6, 2, 5, 0, 3, 5};

inline bool isLeap(int y) {	return (y%4==0 && y%100!=0) || y%400==0;	}

int dayInWeek(int y, int m, int d) {
	int r = (y/100)%4, c = r==0 ? 6 : r==1 ? 4 : r==2 ? 2 : 0;
	m = isLeap(y) ? months_leap[m-1] : months[m-1];
	y %= 100;
	return (d+m+y+(y/4)+c)%7;	// 0 = Sunday
}