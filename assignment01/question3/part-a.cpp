#include <iostream>
#include <vector>

using namespace std;

int most_frequent(const vector<int> &numbers);
 
int main(){
	vector<int> vec1 {1,1,2,3,3,4,4,4};
	vector<int> vec2 {1,2,3,3,4,4,5,5};
	int res1 = most_frequent(vec1);
	int res2 = most_frequent(vec2);
	cout << res1 << endl;
	cout << res2 << endl;
}

int most_frequent(const vector<int> &numbers) {
    int counter ;
    int frequency =0 , most_occurred;
    for (int i = 0; i < numbers.size(); ++i) {
        counter = 0;
        for (int j = i+1; j < numbers.size(); ++j) {
            if (numbers[i] == numbers[j]){
                counter++;
            }
        }

        if (counter > frequency){
            frequency = counter;
            most_occurred = numbers[i];
        }
    }
    return most_occurred;
}
