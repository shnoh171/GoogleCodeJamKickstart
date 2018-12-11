#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

bool CanMoveUp(vector<int> instance);
bool CanMoveDown(vector<int> instance);
bool CanMoveRight(vector<int> instance);
bool CanMoveLeft(vector<int> instance);
vector<int> MoveUp(vector<int> instance);
vector<int> MoveDown(vector<int> instance);
vector<int> MoveRight(vector<int> instance);
vector<int> MoveLeft(vector<int> instance);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<int> init(9);
	for (int i = 0; i < 9; ++i) cin >> init[i];

	vector<int> desired;
	for (int i = 1; i < 9; ++i) desired.push_back(i);
	desired.push_back(0);

	map<vector<int>, int> counts;

	queue<vector<int> > q;
	q.push(init);
	counts[init] = 0;


	while (!q.empty()) {
		vector<int> now = q.front();
		q.pop();

		/*
		for (int i = 0; i < 9; ++i) {
			cout << now[i] << " ";
			if (i%3 == 2) cout << endl;
		}
		cout << endl;
		*/

		if (now == desired) {
			cout << counts[now] << "\n";
			return 0;
		}

		if (CanMoveUp(now)) {
			vector<int> next = MoveUp(now);
			if (counts.find(next) == counts.end()) {
				q.push(next);
				counts[next] = counts[now] + 1;
			}
		}
		if (CanMoveDown(now)) {
			vector<int> next = MoveDown(now);
			if (counts.find(next) == counts.end()) {
				q.push(next);
				counts[next] = counts[now] + 1;
			}
		}
		if (CanMoveLeft(now)) {
			vector<int> next = MoveLeft(now);
			if (counts.find(next) == counts.end()) {
				q.push(next);
				counts[next] = counts[now] + 1;
			}
		}
		if (CanMoveRight(now)) {
			vector<int> next = MoveRight(now);
			if (counts.find(next) == counts.end()) {
				q.push(next);
				counts[next] = counts[now] + 1;
			}
		}
	}

	cout << "-1\n";

	return 0;
}

bool CanMoveDown(vector<int> instance)
{
	int idx = 0;
	while (instance[idx] != 0) ++idx;

	if (idx == 0 || idx == 1 || idx == 2)
		return false;
	else
		return true;
}

bool CanMoveUp(vector<int> instance)
{
	int idx = 0;
	while (instance[idx] != 0) ++idx;

	if (idx == 6 || idx == 7 || idx == 8)
		return false;
	else
		return true;
}

bool CanMoveRight(vector<int> instance)
{
	int idx = 0;
	while (instance[idx] != 0) ++idx;

	if (idx == 2 || idx == 5 || idx == 8)
		return false;
	else
		return true;
}

bool CanMoveLeft(vector<int> instance)
{
	int idx = 0;
	while (instance[idx] != 0) ++idx;

	if (idx == 0 || idx == 3 || idx == 6)
		return false;
	else
		return true;
}

vector<int> MoveUp(vector<int> instance)
{
	int idx = 0;
	while (instance[idx] != 0) ++idx;

	instance[idx] = instance[idx+3];
	instance[idx+3] = 0;

	return instance;
}

vector<int> MoveDown(vector<int> instance)
{
	int idx = 0;
	while (instance[idx] != 0) ++idx;

	instance[idx] = instance[idx-3];
	instance[idx-3] = 0;

	return instance;
}

vector<int> MoveRight(vector<int> instance)
{
	int idx = 0;
	while (instance[idx] != 0) ++idx;

	instance[idx] = instance[idx-1];
	instance[idx-1] = 0;

	return instance;
}

vector<int> MoveLeft(vector<int> instance)
{
	int idx = 0;
	while (instance[idx] != 0) ++idx;

	instance[idx] = instance[idx+1];
	instance[idx+1] = 0;

	return instance;
}

