struct Fraction {
	ll x, y;

	inline void reduce() {
		if (y<0) y=-y, x=-x;
		ll d=__gcd(x, y);
		x/=d, y/=d;
	}

	Fraction(ll x=0, ll y=1) : x(x), y(y) {
		reduce();
	}

	bool operator < (const Fraction &o) const {
		if (x>=oo) return 0;
		if (o.x>=oo) return 1;
		return x*o.y < y*o.x;
	}

	Fraction operator + (const Fraction &o) const {
		return Fraction(x*o.y+y*o.x, y*o.y);
	}

	Fraction operator - (const Fraction &o) const {
		return Fraction(x*o.y-y*o.x, y*o.y);
	}

	Fraction operator * (const Fraction &o) const {
		return Fraction(x*o.x, y*o.y);
	}

	Fraction operator / (const Fraction &o) const {
		return (*this) * Fraction(y, x);
	}
};