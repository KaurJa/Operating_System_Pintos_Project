#define frac (1<<14)

/* Convert an integer to its fixed-point value */
static int int_to_fixed (int n){
	return n * frac;
}

/* Convert a fixed-point value to an integer with rounding */
static int fixed_to_int (int x){
	if(x < 0){
		return ((x-frac/2)/frac);
	}
	else{
		return ((x+frac/2)/frac);
	}
}

/*Convert a fixed-point value to an integer without rounding */
static int fixed_to_int_straight(int x){
	return x/frac;
}

/* Arithmetic operations for two fixed-point values */
static int fixed_add(int x, int y){
	return (x + y);
}

static int fixed_sub(int x, int y){
	return (x - y);
}

static int fixed_mul(int x, int y){
	return  ((int64_t)x) *y / frac;
}

static int fixed_div(int x, int y){
	return ((int64_t) x) *frac /y;
}
