#include <iostream>
#include <vector>

using namespace std;

//int most_frequent(const vector<int> &numbers);
//vector<int> most_frequent(const vector<int> &numbers);
//void print_vector(vector<int> numbers);
int most_frequent(const vector<int> &numbers);

int main(){
    vector<int> vec1 {1,1,2,3,3,4,4,4};
    vector<int> vec2 {1,2,3,3,4,4,5,5};
    int res1 = most_frequent(vec1);
    int res2 = most_frequent(vec2);
    cout << res1 << endl;
    cout << res2 << endl;
}

//int most_frequent(const vector<int> &numbers) {
//    int counter ;
//    int frequency =0 , most_occurred;
//    for (int i = 0; i < numbers.size(); ++i) {
//        counter = 0;
//        for (int j = i+1; j < numbers.size(); ++j) {
//            if (numbers[i] == numbers[j]){
//                counter++;
//            }
//        }
//
//        if (counter > frequency){
//            frequency = counter;
//            most_occurred = numbers[i];
//        }
//    }
//    return most_occurred;
//}

//vector<int> most_frequent(const vector<int> &numbers) {
//    int counter ;
//    int frequency =0;
//    vector<int> most_occurred;
//    for (int i = 0; i < numbers.size(); ++i) {
//        counter = 0;
//
//        for (int j = i+1; j < numbers.size(); ++j) {
//            if (numbers[i] == numbers[j]){
//                counter++;
//            }
//        }
//
//        if (counter > frequency){
//            frequency = counter;
//            most_occurred.erase(most_occurred.begin(), most_occurred.end());
//            most_occurred.push_back(numbers[i]);
//        }else if (counter == frequency){
//            most_occurred.push_back(numbers[i]);
//        }
//    }
//    return most_occurred;
//}

//void print_vector(vector<int> numbers){
//    for (int i = 0; i < numbers.size(); ++i) {
//        cout << numbers[i] << "  ";
//    }
//    cout << endl;
//}

int most_frequent(const vector<int> &numbers) {
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
