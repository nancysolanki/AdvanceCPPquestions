
#include <bits/stdc++.h> 
using namespace std; 

// Structure for storing meeting pair(start, finish) position of meeting. 
struct meeting { 
	int start; 
	int end; 
	int pos; 
}; 

// Sorting meetings based on finish time
bool endSort(struct meeting m1, meeting m2) 
{ 
	return (m1.end < m2.end); 
} 

// Function for finding maximum meeting in one room 
void maximumMeetings(int s[], int f[], int n) 
{ 
	struct meeting meet[n];
	int c = 1;
	// Creating pairs of meeting(start,end) and position
	for (int i = 0; i < n; i++) 
	{ 
		meet[i].start = s[i]; 
		meet[i].end = f[i]; 
		meet[i].pos = i + 1; 
	} 

	// Sorting of meetings in ascending order according to their finish time 
	sort(meet, meet + n, endSort); 

	// Vector for storing selected meeting. 
	vector<int> m; 

	// First meeting is always selected 
	m.push_back(meet[0].pos); 
 
	int prev_end = meet[0].end; 

	// Checking if meeting can take place or not 
	for (int i = 1; i < n; i++) { 
		if (meet[i].start >= prev_end) 
		{ 
			m.push_back(meet[i].pos); 
			prev_end = meet[i].end; 
			c++;
		} 
	} 
cout<<"Maximum meetings that can take place are: "<<c;
	cout<<"\nSelected meetings: ";

	for (int i = 0; i < m.size(); i++) { 
		cout << m[i] << " "; 
	} 
} 
