#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;

	while (t--) {
		int num_lecture, num_class;
		int pen, pencil;
		int case_capacity;

		cin >> num_lecture >> num_class;
		cin >> pen >> pencil;
		cin >> case_capacity;

		int num_pen = (num_lecture % pen) ? num_lecture / pen + 1 : num_lecture / pen;
		int num_pencil = (num_class % pencil) ? num_class / pencil + 1 : num_class / pencil;

		if (num_pen + num_pencil > case_capacity) {
			cout << "-1\n";
		} else {
			cout << num_pen << " " << num_pencil << "\n";
		}
	}

	return 0;
}
