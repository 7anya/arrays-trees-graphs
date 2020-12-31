#include <bits/stdc++.h>
using namespace std;
 #define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
 #define int long long
double findMean(int a[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += a[i];
 
    return (double)sum / (double)n;
}
 int minProduct(int arr[], int n, int k) 
{ 
    priority_queue<int, vector<int>, greater<int> > pq; 
    for (int i = 0; i < n; i++) 
        pq.push(arr[i]); 
  
    int count = 0, ans = 1; 
  
    // One by one extract items from max heap 
    while (pq.empty() == false && count < k) { 
        ans = ans * pq.top(); 
        pq.pop(); 
        count++; 
    } 
  
    return ans; 
} 

  void fillPrefixSum(int a[],int n,int prefix[])
  {
  	prefix[0]=a[0];
  	for (int i = 1; i < n; ++i)
  	{
  		prefix[i]=prefix[i-1]+a[i];
  		/* code */
  	}
  }
  void equilibrium(int a[],int n)
{
	int prefix[n];
	fillPrefixSum(a,n,prefix);
	cout<<"half sum="<<prefix[n-1]/2<<endl;

	for (int i = 0; i <n-1; ++i)
	{
		cout<<prefix[i]<<" ";
		if(prefix[i]==prefix[n-1]/2)
		{
			cout<<"\nanswer"<<i;
			return;
		}
		/* code */
	}
	cout<<"no equilibrium index!";
	return;

}
void check0sum(int a[],int n)
{
	int p[n];
	fillPrefixSum(a,n,p);
	for (int i = 0; i < n; ++i)
	{
		if(p[i]==0)
		{
			cout<<"yes";
			return;
		}
		/* code */
	}
	unordered_set <int> s;
	for (int i = 0; i < n; ++i)
	 {
	 	s.insert(p[i]);
	 	/* code */
	 } 
	 if(s.size()<n)
	 	cout<<"yes";
	 else
	 	cout<<"no";
	 return;
}
int kthSmallestElement(int arr[], int n, int k) 
{ 
    // Insert all elements into the set 
    set<int> s; 
    for (int i = 0; i < n; i++) 
        s.insert(arr[i]); 
  
    // Traverse set and print k-th element 
    auto it = s.begin(); 
    for (int i = 0; i < k - 1; i++) 
        it++; 
    return *it; 
} 
  
int gcd(int a,int b)
{
	if(b==0)
		return a;
	return gcd(b,a%b);
}
void rotateRight(int a[],int n,int d)
{	d=n-d;
	d%=n;
		int g=gcd(n,d);
		for(int i=0;i<g;i++)
		{
			int t=a[i];
			int j=i;
			while(1)
			{
				int k=j+d;
				if(k>=n)
					k-=n;
				if(k==i)
					break;
				a[j]=a[k];
					j=k;
			}
			a[j]=t;
		}
}
void rotateLeft(int a[],int n,int d)
{
		d%=n;
		int g=gcd(n,d);
		for(int i=0;i<g;i++)
		{
			int t=a[i];
			int j=i;
			while(1)
			{
				int k=j+d;
				if(k>=n)
					k-=n;
				if(k==i)
					break;
				a[j]=a[k];
					j=k;
			}
			a[j]=t;
		}

}
int SieveOfSundaram(int n) 
{ 
    // In general Sieve of Sundaram, produces primes smaller 
    // than (2*x + 2) for a number given number x. 
    // Since we want primes smaller than n, we reduce n to half 
    int nNew = (n-1)/2; 
  
    // This array is used to separate numbers of the form i+j+2ij 
    // from others where  1 <= i <= j 
    bool marked[nNew + 1]; 
  
    // Initialize all elements as not marked 
    memset(marked, false, sizeof(marked)); 
  
    // Main logic of Sundaram.  Mark all numbers of the 
    // form i + j + 2ij as true where 1 <= i <= j 
    for (int i=1; i<=nNew; i++) 
        for (int j=i; (i + j + 2*i*j) <= nNew; j++) 
            marked[i + j + 2*i*j] = true; 
  
    // Since 2 is a prime number 
    if (n > 2) 
        cout << 2 << " "; 
  
    // Print other primes. Remaining primes are of the form 
    // 2*i + 1 such that marked[i] is false. 
    for (int i=1; i<=nNew; i++) 
        if (marked[i] == false) 
            cout << 2*i + 1 << " "; 
} 
void minSubarraywithsumk(int a[],int n)
{
	//window sliding technique
	;
}
void longestCommonSum(bool b[],bool c[],int n)
{
	int a[n];
	for(int i=0;i<n;i++)
	{
		a[i]=b[i]-c[i];

	}
	unordered_map<int,int> mp;
	int sum=0;
	int max_len=0;
	for (int i = 0; i < n; ++i)
	{
		sum+=a[i];
		if(mp.find(sum)!=mp.end())
			max_len=max(max_len, i-mp[sum]);
		else 
			mp[sum]=i;
		/* code */
	}
	cout<<max_len;
}
int32_t main()
{
	int n,d;
	cin>>n;
	int a[n];
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];
		/* code */
	}
	// rotateRight(a,n,d);
	check0sum(a,n);
	// for (int i = 0; i < n; ++i)
	// {
	// 	cout<<a[i]<<" ";
	// 	/* code */
	// }
	

	return 0;
}
