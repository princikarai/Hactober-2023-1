//Leet code link:https://leetcode.com/problems/edit-distance/
//GFG link: https://practice.geeksforgeeks.org/problems/edit-distance3702/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

// A Space efficient Dynamic Programming
// based C++ program to find minimum
// number operations to convert str1 to str2
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	// space optimization
	int editDistance(string str1, string str2)
	{
		int m = str1.size();
		int n = str2.size();
		int previous;
		vector<int> curr(n + 1, 0);

		for (int j = 0; j <= n; j++) {
			curr[j] = j;
		}
		for (int i = 1; i <= m; i++) {
			previous = curr[0];
			curr[0] = i;
			for (int j = 1; j <= n; j++) {
				int temp = curr[j];
				if (str1[i - 1] == str2[j - 1]) {
					curr[j] = previous;
				}
				else {
					curr[j] = 1
							+ min({ previous, curr[j - 1],
									curr[j] });
				}
				previous = temp;
			}
		}
		return curr[n];
	}
};

int main()
{
	string str1 = "sit", str2 = "kiit";

	Solution ob;
	int ans = ob.editDistance(str1, str2);
	cout << ans << "\n";

	return 0;
}
