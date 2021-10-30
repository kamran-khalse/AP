#include <iostream>
#include <vector>

using namespace std;

vector<int> most_frequent(const vector<int> &numbers);
void print_vector(vector<int> numbers);

int main(){
	vector<int> vec1 {1,1,2,3,3,4,4,4};
	print_vector(most_frequent(vec1));
}

vector<int> most_frequent(const vector<int> &numbers) {
    int counter ;
    int frequency =0;
    vector<int> most_occurred;
    for (int i = 0; i < numbers.size(); ++i) {
        counter = 0;

        for (int j = i+1; j < numbers.size(); ++j) {
            if (numbers[i] == numbers[j]){
                counter++;
            }
        }

        if (counter > frequency){
            frequency = counter;
            most_occurred.erase(most_occurred.begin(), most_occurred.end());
            most_occurred.push_back(numbers[i]);
        }else if (counter == frequency){
            most_occurred.push_back(numbers[i]);
        }
    }
    return most_occurred;
}

void print_vector(vector<int> numbers){
    for (int i = 0; i < numbers.size(); ++i) {
        cout << numbers[i] << "  ";
    }
    cout << endl;
}
