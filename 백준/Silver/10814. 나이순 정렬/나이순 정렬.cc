#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Person {
	int age;
	string name;
};

bool cmp(Person a, Person b) {
	return a.age < b.age;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	int age; string name;

	vector<string> vec_tmp;
	vector<Person> vec_peoples(N);

	for (int i = 0; i < N; i++) {
		cin >> age >> name;
		vec_peoples[i] = { age, name };
	}

	stable_sort(vec_peoples.begin(), vec_peoples.end(), cmp);
	for (Person person : vec_peoples)
		cout << person.age << " " << person.name << "\n";
}