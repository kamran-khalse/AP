#include <iostream>
#include <vector>

using namespace std;

int most_frequent_C(const vector<int> &numbers);

int main(){
	vector<int> vec1 {1,1,2,3,3,4,4,4};
	cout << most_frequent(vec1);
}

int most_frequent_C(const vector<int> &numbers) {
    int counter = 1;
    int most_occurred, frequency=0;
    vector<int> copy_vector = numbers;

    while (!copy_vector.empty()) {
        counter = 1;

        for (int j = 1; j < copy_vector.size(); ++j) {

            if (copy_vector[0] == copy_vector[j]){
                counter++;
                copy_vector.erase(copy_vector.begin() + (j--));
            }
        }

        if (frequency < counter){
            frequency = counter;
            most_occurred = copy_vector[0];
        }
        copy_vector.erase(copy_vector.begin());
    }

    return most_occurred;
}


