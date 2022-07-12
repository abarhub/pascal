#define pluralsuffix(num,suffix)	((num)==1?"":(suffix))
#define plural(num)	pluralsuffix(num,"s")
#define item int