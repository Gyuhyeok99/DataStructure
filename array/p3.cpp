#include <iostream>
using namespace std;
int main() {
    int num;
    cin >> num;
    for(int i = 0; i < num; i++) {
        int size;
        cin >> size;
        int arr[size];
        int kSum = 0, jSum = 0, cSum = 0;
        for(int i = 0; i < size; i++) {
            int money;
            cin >> money;
            arr[i] = money;
            if(i % 3 == 0){
                kSum += arr[i];
            }else if(i % 3 == 1) {
                jSum += arr[i];
            }else {
                cSum += arr[i];
            }
        }
        cout << kSum << " " << jSum << " " << cSum << endl;

    }
}
