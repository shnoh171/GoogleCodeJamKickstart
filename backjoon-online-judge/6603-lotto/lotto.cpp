#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int k;
	while (cin >> k && k > 0) {
		int s[k];
		for (int i = 0; i < k; ++i) cin >> s[i];

		for (int i1 = 0; i1 < k-5; ++i1)
			for (int i2 = i1+1; i2 < k-4; ++i2)
				for (int i3 = i2+1; i3 < k-3; ++i3)
					for (int i4 = i3+1; i4 < k-2; ++i4)
						for (int i5 = i4+1; i5 < k-1; ++i5)
							for (int i6 = i5+1; i6 < k; ++i6)
								cout << s[i1] << " " << s[i2] << " " << s[i3] << " "
								     << s[i4] << " " << s[i5] << " " << s[i6] << "\n";

		cout << "\n";
	}

	return 0;
}
